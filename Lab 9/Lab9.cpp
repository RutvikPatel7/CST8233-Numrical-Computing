#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int numData = 0;
	cout << "Enter the no. of data pairs to be entered:"<<endl;
	std::cin >> numData;
	cout << endl;
	double xPoint[50];
	double yPoint[50];
	double y_final[50];
	double sumXpoint = 0, sumXpoint2 = 0, sumYpoint = 0, sumXYpoint = 0,yLog=0, calc_A, calc_B;
	cout << "Enter the x-axis values" << endl;
	for (int i = 1; i <= numData; i++)
	{
		cin >> xPoint[i];
	}
	cout << endl;
	cout << "Enter the y-axis values" << endl;
	for (int i = 1; i <= numData; i++)
	{
		cin >> yPoint[i];
	}
	
	/* Calculating Required Sum */
	for (int i = 1; i <= numData; i++)
	{
		sumXpoint = sumXpoint + xPoint[i];
		sumXpoint2 = sumXpoint2 + xPoint[i] * xPoint[i];
		sumYpoint = sumYpoint + yPoint[i];
		yLog += log(yPoint[i]);
		sumXYpoint = sumXYpoint + xPoint[i] * log(yPoint[i]);
	}
	
	calc_B = (numData * sumXYpoint - sumXpoint * yLog) / (numData * sumXpoint2 - sumXpoint * sumXpoint);
	calc_A = (yLog - calc_B * sumXpoint) / numData;
	
	cout << calc_A << "\t" << calc_A<<endl;
	cout << exp(calc_A) << "\t" << exp(calc_B) << endl;
	
	for (int i = 1; i <= numData; i++)
	{
		y_final[i] = calc_B * xPoint[i] + calc_A;
	}
	cout <<"S.no\t\t\t x \t\t\t y(observed) \t\t y(fitted)"<<endl;
	cout << "-----------------------------------------------------------------------------------"<<endl;
	for (int i = 1; i <= numData; i++)
	{
		cout<< i << "\t\t\t" << xPoint[i] << "\t\t\t" << yPoint[i] << "\t\t\t" << y_final[i]<<endl;
	}
	cout <<endl<< "The linear fit line is of the form"<<endl;
	cout <<endl<< "y= "<<calc_B<<"x + "<<calc_A<<endl;
	cout << log(calc_A) << endl;
	cout << log(calc_B) << endl;
	cout << log(yLog) << endl;
	cout << sumXpoint<< endl;
	cout << sumYpoint << endl;
	cout << sumXpoint2 << endl;
	cout << sumXYpoint << endl;
	cout << exp(calc_A )<< endl;

	return 0;
}