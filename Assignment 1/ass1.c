/**************************************************************************************************************************************
FileName				:			main.c
Version					:			1.0
Author/Student Name		:			Rutvik Patel
Student Number			:			040915445
Course name and number	:			Numrical Computing (CST8233)
Lab Section Number		:			300
Assignment Number		:			1
Assignment Name			:			Evaluate the Maclaurin Series
Due Date				:			9th February, 2020
Submission Date			:			9th February, 2020
Professor Name			:			Hala Own
Purpose					:			You are employed by an architecture 
									company to write code for a building simulation. 
									The company wants to model the start of the motion 
									response of a tall building hit by strong winds that 
									set it in vibration that builds up catastrophically.
***************************************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********************************************************************
Function name:			main
Purpose:				main function Evaluate the Maclaurin Series.
In parameters:			none
Out parameters:			0 for successful
executionVersion:		1.0
Author:					Rutvik Patel
**********************************************************************/

int main(void)

{
	while (1)
	{
		int x,y, response;
		double arr[7];
		double range;
		double t = 0.0;
		double Rex, exa, series;
		double result = 0.0;
		int i;

		printf("Evalute the Maclaurin Series approximation to D(t) = exp(t) * cos(t)\n");
		printf("1: Evaluate the series\n");
		printf("2: quit\n");
		printf("> ");
		scanf("%d", &response);
		switch (response)
		{
		case 1:
			printf("Evaluating the series\n");
			printf("Please enter the number of (non - zero) terms in the series (1, 2, 3, 4, 5 or 6) :\n");
			scanf("%d",&x); /*To get non-zero terms from user*/
			printf("\n");
			while ((getchar()) != '\n'); // to clear the buffer value
			

			if (x>=1 && x<= 6) {
				/*checks if number of terms between 1 & 6*/
				printf("Please enter the range of t to evaluate in 10 increments (0.0 < t < +4.0):\n");
				scanf("%lf", &range);
				printf("\n");
				
				if (range >0 && range <= 4) {
					printf("\nMACLAURIN SERIES\n");
					printf("   t \t\tD(t) Series \t\tD(t) Exact \t\t%RExactE \t\t%RSerE\n");
				}
				else {
					printf("Please Enter Valid Range!!!		:( ");
					return 0;
				}
			}
			else {
				printf("Please Enter Values between 1 & 6 		:(  ");
				return 0;
			}
			/*To get values in array*/
			for (i = 0; i <= 10; i++) {
				
				result = 0.0;
				arr[0] = 1;
				arr[1] = t;
				arr[2] = (-1 * t * t * t ) / 3;
				arr[3] = (-1 * t * t * t * t) / 6;
				arr[4] = (-1 * t * t * t * t * t) / 30;
				arr[5] = (t * t * t * t * t * t * t) / 630;
				arr[6] = (t * t * t * t * t * t * t * t) / 2520;

				for (y = 0; y < x; y++) { 
					result += arr[y]; // add array trancated & save as result
				}

			/* The given equation*/

				Rex = exp(t) * cos(t);
				exa = 100 * (Rex - result) / Rex;
				series = 100 * (arr[x] / result);
				//	Print the values
				printf("%.3e\t", t);
				printf("%.5e\t\t",result);
				printf("%.5e\t\t", Rex);
				printf("%.5e\t\t", exa);
				printf("%.5e\n", series);
				t = t + (range / 10);
				
			}
			printf("\n");
			break;

		case 2:
			printf("Thank you for chosing our program :)\n");
			exit(0);
			break;
		
		default:
			printf("Please Enter the Valid Value :( \n");
		}
		while ((getchar()) != '\n'); // to clear the buffer value
	}
	return 0;
}