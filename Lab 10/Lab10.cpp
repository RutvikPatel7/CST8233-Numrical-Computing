#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <fstream>
#include <cmath>
int length = 7;

double x[7] = { 4,2.25,1.45,1.0,0.65,0.25,0.006 };
double y[7] = { 0.398,0.298,0.238,0.198,0.158,0.098,0.048 };

double calc_a1() {

	double sumXY = 0;
	for (int i = 0; i < length; i++)
		sumXY += log((double)x[i]) * log((double)y[i]);

	double sumX = 0;
	for (int i = 0; i < length; i++)
		sumX += log((double)x[i]);

	double sumY = 0;
	for (int i = 0; i < length; i++)
		sumY += (log((double)y[i]));

	double sumXSq = 0;
	for (int i = 0; i < length; i++)
		sumXSq += pow(log((double)x[i]), 2);

	double a1 = (((length)*sumXY) - (sumX * sumY)) / (((length)*sumXSq) - pow(sumX, 2));
	return a1;
}

double calc_a0(double a1) {
	double sumX = 0;
	for (int i = 0; i < length; i++)
		sumX += log((double)x[i]);

	double sumY = 0;
	for (int i = 0; i < length; i++) {
		sumY += log(((double)y[i]));
	}
	double a0 = (sumY - (a1 * sumX)) / (double)(length);
	return a0;
}


int main() {


	double a1 = calc_a1();
	double a0 = calc_a0(a1);

	printf("Non-linear regression:\n\n");
	std::cout << "K = " << exp(a0) << " n = " << a1 << std::endl;
	std::cout << " -r = " << exp(a0) << " x C ^ " << a1 << std::endl;
	getchar();
	return 0;
}