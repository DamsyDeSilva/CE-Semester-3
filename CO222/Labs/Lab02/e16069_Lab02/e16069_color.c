/*
	CO222 - Programming Methodology
	Lab 02
	E/16/069
	M.D.S.De Silva
	
	Task 02;
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int color[3]; //color array (R G B)
	int compclr[3];//complement array of the color
	
	// user input of the color
	printf("Enter the color:");
	int i;
	for(i=0; i<3; i++)
	{
		scanf("%d",&color[i]); 
	}
	
	//invert the colors by substracting from 255
	for(i=0; i<3; i++)
	{
		compclr[i] = 255 - color[i]; 
	}
	
	//array for storing the differ of color component & corresponding complement
	int c[3]; 
	
	c[0] = abs(compclr[0]-color[0]); //differ of red
	c[1] = abs(compclr[1]-color[1]); //differ of green
	c[2] = abs(compclr[2]-color[2]); //differ of blue
	
	
	// checking each component of differ array for 32 or less differ
	for(i=0; i<3; i++)
	{
		if(c[i]<32 || c[i]== 32 )
		{
			// substract or add 128 to make complement a legal value
			if((color[i] ) > 127)
			{
				compclr[i] = color[i] - 128;
			}	
			else
			{
				compclr[i] = color[i] + 128;	
			}		
		}
		
	}
	
	// print the complement
	printf("The complement :");
	
	for(i=0; i<3; i++)
	{
		printf("%d ",compclr[i]);
	}
			
}