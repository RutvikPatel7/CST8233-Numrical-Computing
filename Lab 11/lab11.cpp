#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

double xPoint[10];
double yPoint[10];
double firstDerivatives = 0.0;
int totalPoints = 0;

int main() {

	cout << "Enter the total no. of equally spaced data points:" << endl;
	cin >> totalPoints;

	cout << "Enter the value of x's :" << endl;
	for (int i = 0; i < totalPoints; i++)
		cin >> xPoint[i];

	cout << "Enter the point where  first derivative is calculated" << endl;
	cin >> firstDerivatives;

	cout << "the value of y's :" << endl;
	for (int i = 0; i < totalPoints; i++) {
		yPoint[i] = pow(xPoint[i], 3);
		cout << yPoint[i] << endl;
	}

	cout << "\nThe result is" << endl;
	
	/*FORWARD METHOD*/
	cout << "Forward method= " << yPoint[2] - yPoint[1];
	cout << " error = " << abs(yPoint[1] - (yPoint[2] - yPoint[1])) / yPoint[1] * 100 << "%" << endl;

	/*BACKWARD METHOD*/
	cout << "Backward method= " << yPoint[1] - yPoint[0];
	cout << " error = " << abs(yPoint[1] - (yPoint[1] - yPoint[0])) / yPoint[1] * 100 << "%" << endl;

	/*CENTRAL METHOD*/
	cout << "Central = " << (yPoint[2] - yPoint[0]) / 2;
	cout << " error = " << abs(yPoint[1] - ((yPoint[2] - yPoint[0]) / 2)) / yPoint[1] * 100 << "%" << endl;
	return 0;
}