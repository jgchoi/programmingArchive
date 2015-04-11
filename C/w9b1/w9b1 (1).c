/*
 * Course Code 		- BTP100
 * Assignment Number	- Workshop Week 9 bonus 1
 * Name			- Jung Geon Choi
 * File name		- w9b1
 * Due date		- Nov. 12, 2013
 * 
 */

#include <stdio.h> 
 
void fill_array(int a[], int n); 
void display_array(int a[], int n); 
int appendArray(int a[],int size_a, int b[], int size_b, int c[], int size_c); 
 
int main() 
{ 
//valuable
int size1, size2, size3; 
 
	//input1
	printf("How many elements will be in 1st array? "); 
		scanf("%d", &size1); 
	//input2
	printf("How many elements will be in 2nd array? "); 
		scanf("%d", &size2); 
		
	//setting size3
	size3 = size1+size2; 
	
	//declare array 1,2,3   
	int first[size1], second[size2], result[size3]; 
	 
	//input array size1
	printf("Fill the first array: \n"); 
		fill_array(first, size1); 
	 
	printf("Fill the second array: \n"); 
		fill_array(second, size2); 
		
	//result
	printf("=======================\n"); 
	printf("Display the first array:\n"); 
	display_array(first, size1); 
	 
	printf("Display the second array:\n"); 
	display_array(second, size2); 
	 
	if (appendArray(first, size1, second, size2, result, size3)) 
		{ 
		printf("ERROR! Result array is not big enough. Exit the program. \n"); 
		return 1; 
		}
}

//-----------------------------------------------------------------------------
//filling array 
void fill_array(int a[], int n)
	{
	int i=0;
	for(i=0;i<n;i++)
		{
		printf("Enter a whole number to elements %d :",i+1);
			scanf("%d",&a[i]);
		}
	}
	
//-----------------------------------------------------------------------------
// array display
void display_array(int a[], int n)
	{
	int i=0;
	for(i=0;i<n;i++)
		{
		printf("%5d",a[i]);
		}
		putchar('\n');
	}
//-----------------------------------------------------------------------------
// display array with combined arraies
int appendArray(int a[],int size_a, int b[], int size_b, int c[], int size_c)
	{
	int i = 0;
	int j = 0;
	for(i=0;i<size_a;i++) //a[0~size_a-1]=c[0~size_a-1]
		{
		c[i]=a[i];
		}
		
	for(j=0;j<size_b;j++) //b[0~size_b-1]=c[size_a-1~size_c-1]
		{
		c[i+j]=b[j];
		}
/*
I still do not understand how appending array can have not enough space.
As far as I understood, because on main function, 
size of appended array is decided by (size a + size b)
and that size is used as parameter for appendArray function.
 Thus I simply made loop to check all value in 
 append array with original array A and B. 
*/	
	for(i=0;i<size_c;i++) // loop to check all value in appended array
		{
		for(j=0;j<size_a;j++) //check a[0]~a[size_a-1] with c[0]~c[size_a-1]
			{
			if(c[i]!=a[j]) //if any value is not correct
			return 1;
			i++;
			}
		for(j=0;j<size_b;j++) //check b[0]~b[size_b-1] with c[size_a~(size_a+size_b-1)]
			{			
			if(c[i]!=b[j])
			return 1;
			i++;
			}
		} // value check loop

	// following sequence will only proceed only if append completed successfuly
	printf("Display the result array:\n");
	for(i=0;i<size_c;i++)
		{
		printf("%5d",c[i]);
		}
	putchar('\n');
	return 0;
	}