/*
 * I declare that the attached assignment is wholly my own work in accordance 
 * with Seneca Academic Policy.  No part of this assignment has been copied 
 * manually or electronically from any other source (including web sites) or 
 * distributed to other students. 
 * 
 * Name   ___Jung Geon Choi_______   Student ID ___025651134_____ 
 */
 
/* Course Code		- BTP100
 * Assignment Number	- Assignment 3
 * Name			- Jung Geon Choi
 * File name		- a3.c
 * Due date		- Dec. 10, 2013
 * Pay calculator
 * Read database file, calculate, sort, record.
 */
 
//-----------------------------------------------------------------------------
//#list
#include <stdio.h>
#include "sales.h"
#define MAX_SIZE 100


//-----------------------------------------------------------------------------
//prototypes
void writePay(struct salesPerson sRec[], int rNum, FILE *fp);
void sortPay(struct salesPerson sRec[], int rNum);
void calcPay(struct salesPerson sRec[], float lvl[], int rNum);
int setArray(FILE *fp, struct salesPerson sRec[]);

//-----------------------------------------------------------------------------
//main function
int main(void)
{
	//valuable
	float level[5] = {0.02, 0.04, 0.06, 0.08, 0.10}; 
	int rNum;
	struct salesPerson sRec[MAX_SIZE];
	
	//file pointer
	FILE *fi=NULL;
	FILE *fo=NULL;
		
	//open
	fi = fopen("sales.dat","r");
	fo = fopen("pay.txt","w");
	
	//check if open fail
	if(fi == NULL)
		{
		printf("Program fail to open file \"sales.dat\"\n");return 1;
		}
	//check if write fail
	if(fo == NULL)
		{
		printf("Program fail to open file \"pay.txt\"\n");return 1;
		}
	//read file
		rNum = setArray(fi, sRec);
	
	//calculate w_pay
		calcPay(sRec, level, rNum);
		
	//sort
		sortPay(sRec, rNum);
		
	//display
		writePay(sRec, rNum, fo);
		
	//end(close)
		fclose(fi);
		fclose(fo);
	
	return 0;
}

//-----------------------------------------------------------------------------
//output result into file "pay.txt"
void writePay(struct salesPerson sRec[], int rNum, FILE *fp)
{
int i;

	fprintf(fp, "%53s","Weekly Payment Report\n");
	fprintf(fp, "--------------------------------------------------------------------------------\n"
		    "| SNum | Last Name          | First Name         | Lvl | Sales Amt  | Week Pay |\n"
		    "================================================================================\n");
		for(i=0;i<rNum;i++)
			{
			fprintf(fp, "|%5d | %-19s| %-19s| %-4d| $%-10.2lf| $%-8.2lf|\n"
				    "--------------------------------------------------------------------------------\n"
				    , sRec[i].salesNum
				    , sRec[i].lastName
				    , sRec[i].firstName
				    , sRec[i].salesLevel
				    , sRec[i].salesAmount
				    , sRec[i].salesPay);
			}
}

//-----------------------------------------------------------------------------
//sort order of salesperson by salesPay
void sortPay(struct salesPerson sRec[], int rNum) 
{
int i;
int j;
struct salesPerson tmp;

	for(i=0;i<rNum-1;i++)
		{
		for(j=i+1;j<rNum;j++)
			{
			if(sRec[i].salesPay < sRec[j].salesPay)
				{
				tmp=sRec[i];
				sRec[i]=sRec[j];
				sRec[j]=tmp;
				}
			}
		}
}

//-----------------------------------------------------------------------------
//calculation of salesPay based on salesLevel and salesAmount
void calcPay(struct salesPerson sRec[], float lvl[], int rNum) 
{
int i;

for(i=0;i<rNum;i++)
	sRec[i].salesPay = 200 + lvl[sRec[i].salesLevel-1] * sRec[i].salesAmount;
}

//-----------------------------------------------------------------------------
//read data from file
int setArray(FILE *fp, struct salesPerson sRec[]) 
{
int i = 0;

while(fscanf(fp, "%d:%20[^:]:%20[^:]:%d:%lf\n",&sRec[i].salesNum
					      , sRec[i].lastName
					      , sRec[i].firstName
					      ,&sRec[i].salesLevel
					      ,&sRec[i].salesAmount)==5)
	i++;
	return i;
}
