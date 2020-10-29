/***************************************************************************************************************************************************************
Filename:				ass3.cpp
Version: 				1.0
Author:					Rutvik Patel
Student No:  			040915445
Course Name/Number:		CST 8233 (Numerical Computing)
Lab Secttion: 			303
Assignment #:			03
Assignment name:		Euler's method & Runge-Kutta 4th method
Due Date:				10 April,2020
Submission Date:		10 April,2020
Professor:				Dr.Hala Own
Purpose:				To find Euler's method & Runge-Kutta 4th method
****************************************************************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <crtdbg.h>

using namespace std;

bool running = true;
void eluer();
void kutta();

/***********************************************************************************************************************************************
Function Name: main()
Purpose: Main method to excute the program
In Parameters: None
Out Parameters: None
Version: 1.0
Author:			Rutvik Patel
************************************************************************************************************************************************/
int main(void) {

	char select;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	while (running) {
		cout << ">> Choose the method for solveing the ODE:" << endl;
		cout << "1. Eluer's Method" << endl;
		cout << "2. Runge-Kutta 4th Order Method" << endl;
		cout << "3. Quit\n>>" << endl;
		cin >> select;

		switch (select) {

		case '1':
			eluer();
			break;

		case '2':
			kutta();
			break;

		case '3':
			cout << "Exiting.....";
			running = false;
			break;
		default:
			cout << endl << "Invalid Selection" << endl << endl;
			break;
		}
		cout << endl;
	}
}

/***********************************************************************************************************************************************
Function Name: find()
Purpose: returns cos[(4*thita) - (2*t_0)]
In Parameters: yes
Out Parameters: None - float
Version: 1.0
Author:			Rutvik Patel
************************************************************************************************************************************************/
float find(float t, float t_0)
{
	return cos(4 * t) - (2 * t_0);
}
/***********************************************************************************************************************************************
Function Name: eluer()
Purpose: program that computes the solution 𝜃(𝑡) using Euler’s Method.
In Parameters: None
Out Parameters: None - void
Version: 1.0
Author:			Rutvik Patel
************************************************************************************************************************************************/

void eluer() {

	double y_ax0 = 3;
	double y_ax1;
	double x_ax1;
	double thita = 0;
	double thita_new = 2;
	double h;
	int i;
	
	cout << "\n>> Choose step size h (0.8, 0.2, 0.05)\n>> ";
	cin >> h;
	cout << "\nTime(second)  Exact Temp(C)  Estimated Temp(C)  Percentage Error(%)" << endl;
	
	for (x_ax1 = thita; x_ax1 + h <= thita_new; x_ax1 = x_ax1 + h)
	{
		y_ax1 = y_ax0 + h * find(x_ax1, y_ax0);
		double temp = ((0.1 * cos(4 * (x_ax1 + h))) + (0.2 * sin(4 * (x_ax1 + h))) + (2.9 * exp(-2 * (x_ax1 + h))));
		double error = (temp - y_ax1) / temp * 100;
		
		printf("%.1lf \t\t %.3lf \t\t %.3lf \t\t %.2lf\n", x_ax1 + h, temp, y_ax1, abs(error));
		y_ax0 = y_ax1;

	}
}

/***************************************************************************************************************
* Function name:	kutta()
* Purpose:			implement Runge-Kutta 4th method to solve the ODE information in PDF,
					and Find the discrete values of 𝜃(𝑡) at each ℎ step value.
* In parameters:	none
* Out parameters:	none
* Version:			1.0
* Author:			Rutvik Patel
********************************************************************************************************************/
void kutta() {
	double y_ax0 = 3;
	double x_ax1;
	double thita = 0;
	double thita_new = 2;
	double h;
	double y_ax2, tmp, tmp2, tmp3, tmp4;
	int i;
	
	cout << "\n>> Choose step size h (0.8, 0.2, 0.05)\n>> ";
	cin >> h;
	cout << endl;
	cout << "Time(second)  Exact Temp(C)  Estimated Temp(C)  Percentage Error(%)" << endl;
	
	for (x_ax1 = thita; x_ax1 + h <= thita_new; x_ax1 = x_ax1 + h)

	{
		tmp = h * (find(x_ax1, y_ax0));
		tmp2 = h * (find((x_ax1 + h / 2), (y_ax0 + tmp / 2)));
		tmp3 = h * (find((x_ax1 + h / 2), (y_ax0 + tmp2 / 2)));
		tmp4 = h * (find((x_ax1 + h), (y_ax0 + tmp3)));
		y_ax2 = (tmp + 2 * tmp2 + 2 * tmp3 + tmp4) / 6;
		
		double temp = ((0.1 * cos(4 * (x_ax1 + h))) + (0.2 * sin(4 * (x_ax1 + h))) + (2.9 * exp(-2 * (x_ax1 + h))));
		double error = (temp - (y_ax2 + y_ax0)) / temp * 100;
		
		printf("%.1lf \t\t %.3lf \t\t %.3lf \t\t\t %.2lf\n", x_ax1 + h, temp, y_ax2 + y_ax0, abs(error));
		y_ax0 += y_ax2;

	}
	
}
