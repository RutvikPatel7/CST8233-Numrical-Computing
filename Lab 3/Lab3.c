#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long factorial(int n);
float strVal(int number);

int main() {
	printf("N \t n \t Stirling's \t Absolute Error \t Relative Error \n");
	for (int i = 1; i <= 10; i++) {
		printf("%d \t %ld \t %lf  \t %lf \t %lf \n", i, factorial(i), strVal(i), (factorial(i) - strVal(i)), ((factorial(i) - strVal(i)) / factorial(i)));
	}
}

float strVal(int number) {

	return (sqrt((2.0) * (number) * (3.14))
		* (pow(number, number))
		* (pow(2.718, (-1.0) * number)));
}

long factorial(int n) {
	n = (long)n;
	if (n == 1)
		return 1;
	if (n != 1) {
		return n * factorial(n - 1);
	}
}
