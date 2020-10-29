/***************************************************************************************************************************************************************
Filename:				ass2.cpp																															   
Version: 				1.0																																	   
Author:					Rutvik Patel																												   
Student No:  			040915445																															   
Course Name/Number:		CST 8233 (Numerical Computing)																										   
Lab Secttion: 			303																															   
Assignment #:			02																																	   
Assignment name:		linear regression least-squares method																							       
Due Date:				15 March,2020																												   
Submission Date:		16 March,2020																												   
Professor:				Dr.Hala Own																												   
Purpose:				data using linear regression least-squares method for an exponential function.											   
****************************************************************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS 
#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <crtdbg.h>
#include<iomanip>
using namespace std;

/*All the function declearation fo the program*/
void read_file();
void menu();
void calculate();

/*Global Variables*/
FILE* file;
int count_line = 0,choice;
char file_name[256];
double pntX = 0.0, pntY = 0.0,sumX = 0.0,sumY = 0.0,sumX2 = 0.0,sumXY = 0.0,pntX2 = 0.0,pntY2 = 0.0;
double a0 = 0.0, a1 = 0.0;

/********************************************************************************************************************************
Function name:		Main													  
Purpose:			To print menu
In parameters:		none														  
Out parameters:		none											  
Version:			1.0															  
Author:				Rutvik Patel											  
***********************************************************************************************************************************/
int main(void)
{
	bool running = true;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //to check memory leak
	
	while (running) 
	{
		cout << "LEAST_SQUARES LINEAR REGRESSION\n\nMENU\n1. Exponential Fit\n2. Quit\n>"<< endl;
		cin >> choice; 
		fflush(stdin);
		switch (choice)
		{
		case 1: 
			read_file(); 
			break;
		case 2: 
			running = false;
			cout << "Exiting...." << endl;
			break;
		default:
			printf("Please enter a valid option!\n\n");
			break;
		}
	}
	return 0;
}
/***************************************************************************************************************
Function name:		read_file											
Purpose:			open and read data from file and calculate non-linear exp regression mode.
In parameters:		none											
Out parameters:		none											
Version:			1.0												
Author:				Rutvik Patel							
********************************************************************************************************************/
void read_file() {
	int count = 0;
	printf("please enter the name of the file to open: ");
	cin >> file_name;
	fflush(stdin); // to clear buffer
	file = fopen(file_name, "r");
	
	if (file == NULL) { //check if the file  is valid or not

		perror(file_name); //print particuler message 
		cout << endl;
		return;
	}

	//if file is valid then it will read all the values 
	if (file != NULL) {      
		char line[1050];
		
		//store first line of text file
		char *text= fgets(line, 1050, file); 
		
		cout << text;                        
		while (fgets(line, sizeof line, file) != NULL) {   
			//Loop work until the end of the file
			count++;
			sscanf(line, "%lf %lf", &pntX, &pntY);
			
			cout << pntX << "\t\t" << pntY << "\n";
			fflush(stdin); // to clear buffer

			sumX += pntX;
			sumY += pntY;
			sumX2 += pntX * pntX;
			pntY2 += log(pntY);
			sumXY += pntX * log(pntY);
			pntX2 = sumX * sumX;
	
			a1 = ((count * sumXY) - (sumX * pntY2)) / (count * sumX2 - (pntX2));
			a0 = (pntY2 - a1 * sumX) / count;  
		}

		fclose(file); //Close the file
		cout << "There are "<<count<<" records."<<endl;
		printf("Linear Regression Fit:  Prognostic_index= %.1f*exp %.3f*days\n", exp(a0), a1); //N= ae^bx
		menu();
	}

}

/************************************************************************************************
* Function name:	Menu()																    
* Purpose:			to find extrapolation
* In parameters:    void																	    
* Out parameters:   void																		
* Version:			1.0																		    
* Author:			Rutvik Patel															
*************************************************************************************************/
void menu() {
	bool input = true;
	
	char choice2;
	while (input)
	{
		cout<<"MENU\n1. Extrapolation\n2. Main Menu\n> "<<endl;
		cin >> choice2;
		fflush(stdin); // to clear buffer
		switch (choice2)
		{
		case '1':
			calculate();
			break;
		case '2':
			input = false;
			break;
		default:
			fflush(stdin); // to clear buffer
			cout<<"Invalid option !!\n"<<endl;
			break;
		}
	}
}
/*****************************************************************************
* Function name:	calculate()											
* Purpose:			To find out thePrognastic index and rate of decrease 
* In parameters:	none											 
* Out parameters:	none													 
* Version:			1.0														 
* Author:			Rutvik Patel										 
******************************************************************************/
void calculate() {
	int days;
	cout << "Please enter the days to extrapolate to: ";
	cin >> days;
	cout<< "days = " << days<<endl;
	
	printf("Prognostic_index = %.1f\n",pow(2.718, a0) * pow(2.718, days * a1));
	printf("rate of decrease = %.3f\n\n ", a1 * pow(2.718, a0) * pow(2.718, days * a1));
	
	fflush(stdin); // to clear buffer
	
}