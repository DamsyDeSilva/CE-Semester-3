/*
	CO222 - Programming Methodology
	Lab 02
	E/16/069
	M.D.S.De Silva
	
	Task 01
	
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	
	int x=0;
	
	
	printf("Enter the Number :");
	scanf("%d",&x);		// User input of the number
	
	// checking the quality "special"
	int s = 1;
	if(x%15 == 0) 	
	{
	  	printf("%d is special",x);
	  	s = 1; 
	}
	else
	{
		//printf("%d is not special",x);
		s = 0;
	}
	
	//checking the quality special
	if(x>999)
	{
		
		//checking the quality "weird" when it is "big"
		if(x%5 == 0 && x%6 == 0 && x%18 !=0)
		{
			printf(", big, weird and scary.\n");	// "scary" when 'weird' or 'big'	
		}
		else if(s)//if x is not "special", statement should change
		{
			printf(", big and scary but not weird.\n"); // "scary" , not 'weird' but big
		}
		else
		{
			printf("%d is big and scary but not special and not weird.\n",x); //getting all not qualities to the end
		}
	}
	
	else
	//checking the quality "weird" when it is "not big"
	{
		if(x%5 == 0 && x%6 == 0 && x%18 !=0)
		{
			printf(", weird and scary but not big.\n");	
		}
		else if(s)//if x is not "special", "not scary" statement should change
		{
			printf(" but not scary.\n");
		}
		else
		{
			printf("%d is not special and not scary.\n",x);
		}
	}
	
}