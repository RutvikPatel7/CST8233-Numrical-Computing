#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<math.h>
using namespace std;
void Interpolate(int,double,int[],int[]);
int main()
{
	int numData = 0;
	double xP = 0.0;
	cout << "Enter number of data:";
	std::cin >> numData;
	cout << endl;
	int xPoint[10];
	int yPoint[10];
	cout << "Enter data:" << endl;
	for (int i = 0; i < numData; i++)
	{
		cout<<"x["<<i+1<<"]=";
		cin >> xPoint[i];
		//cout << endl;
		cout << "y[" << i+ 1 << "]=";
		cin >> yPoint[i];
		//cout << endl;
	}
	cout << "Enter interpolation point:";
	cin >> xP;
	cout<< endl;

	Interpolate(numData, xP, xPoint, yPoint);

	return 0;
}

void Interpolate(int numData, double xP, int xPoint[], int yPoint[])
{
	double yP = 0.0;
	for (int i = 0; i < numData; i++)
	{
		double p = 1.0;
		for (int j = 0; j < numData; j++)
		{
			if (i != j)
			{
				p *= ((double)xP - xPoint[j]) / ((double)xPoint[i] - xPoint[j]);
			}
		}
		yP = yP + (p * yPoint[i]);
	}
	printf("Interpolated value at %.3f is %.3f",xP,yP);
}