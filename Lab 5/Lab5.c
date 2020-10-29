#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int factorial(int numb);

int main() {

	double input = 0;
	printf("Enter value of x (in radians) :");
	scanf("%lf", &input);

	double trueValue = cos(input);

	double relError = 0;
	double macSeries = 0;
	double absError = 0;
	int terms = 0;
	do {
		macSeries += (pow((-1), terms) * pow(input, (2.0 * terms))) / factorial(2 * terms);

		absError = (trueValue - macSeries);
		absError = ((absError < 0) ? (absError *= (-1)) : absError);
		relError = (absError / trueValue) * 100;
		relError = ((relError < 0) ? (relError *= (-1)) : relError);

		terms++;

	} while (relError > 0.5);


	printf("True value: %lf \n", trueValue);
	printf("Maclourin series: %lf \n", macSeries);
	printf("Absolute error: %lf \n", absError);
	printf("Relative error : %lf \n", relError);
	printf("Numbers of terms : %d ", terms);

	getchar();
}

int factorial(int numb) {
	if (numb == 0)
		return 1;
	if (numb == 1)
		return 1;
	else
		return numb * factorial(numb - 1);
}