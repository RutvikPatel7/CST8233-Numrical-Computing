
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {

	double number = 0;
	printf("Enter the values of x :");
	int i = scanf("%lf", &number);

	int terms = 10;
	double trueValue = log(number);

	double approxValue = 0;

	int  j = 1;
	while (j < terms)
	{
		approxValue = approxValue + (double)(pow((-1), (j - (double)1)) * pow((number - 1), j) / j);
		j++;
	}
	
	double absError = (trueValue - approxValue);
	absError = ((absError < 0) ? (absError *= (-1)) : absError);

	double relError = (absError / trueValue) * 100;
	relError = ((relError < 0) ? (relError *= (-1)) : relError);

	printf("The number of terms: %d \n", terms);
	printf("True value: %lf \n", trueValue);
	printf("Taylor value: %lf \n", approxValue);
	printf("Absolute error: %lf \n", absError);
	printf("Relative error : %lf \n", relError);

	getchar();
}
