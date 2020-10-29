#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

float mean(float[], int);
float median(float[], int);
float mode(float[], int);
float range(float[], int);
float variance(float[], int,float);
int main()
{
	float array[100];
	float sum = 0;
	int inputData;
	cout << "Enter the number of data points:"<<endl;
	cin >> inputData;
	cout << "Enter your data:"<<endl;
	for (int i = 0; i < inputData; i++)
	{
		cin>>array[i];
	}

	float avg = mean(array, inputData);
	cout << "Mean="<<avg<<endl;
	cout << "Median="<<median(array, inputData)<<endl;
	cout << "Mode="<<mode(array, inputData)<<endl;
	cout << "Range="<<range(array,inputData)<<endl;
	cout << "Variance="<<variance(array,inputData, avg)<<endl;
	cout << "Standard deviatioin="<<sqrt(variance(array, inputData, avg));

	return 0;
}

float mean(float array[], int check)
{
	float sum = 0;
	for (int i = 0; i < check; i++)
		sum += array[i];

	return sum / check;
}

float median(float array[], int check)
{
	//sort the array
	
	sort(array, array + check);
	if (check % 2 == 0)
		return (array[check / 2 - 1] + array[check / 2]) / 2;
	return array[check / 2];
}

float mode(float array[], int check)
{
	int number = array[0];
	int mode = number;
	int count = 1;
	int countMode = 1;

	for (int i = 1; i < check; i++)
	{
		if (array[i] == number)
		{
			count++;
		}
		else
		{
			if (count > countMode)
			{
				countMode = count;
				mode = number;
			}
			count = 1;
			number = array[i];
		}
	}
	return mode;
}

float range(float array[], int temp)
{
	float max = array[0];
	for (int i = 0; i < temp; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	float min = array[0];
	for (int i = 0; i < temp; i++)
	{
		if (min > array[i])
			min = array[i];
	}
	return max-min;
}

float variance(float array[], int check, float avg)
{
	float sum = 0;
	for (int i = 0; i < check; i++)
	{
		sum = sum + pow((array[i] - avg), 2);
	}
	return sum / (check-1);
}