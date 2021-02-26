/*	
	C0222 : Programming Methodology
	Lab 01
	E/16/069 
	M.D.S.De Silva
*/

#include<stdio.h>

int main(){
	
	int s_time;
	int duration;
	
	printf("Enter the start time : ");
	scanf("%d",&s_time);
	
	printf("Enter the duration : ");
	scanf("%d",&duration);
	
	int hours=0,minutes=0;
	
	hours = s_time/100;
	minutes = s_time%100;
	
	minutes = minutes+duration;
	
	hours = hours + (minutes/60);
	hours = hours%24;
	
	minutes = minutes%60;
	printf("End time is %02d%02d.\n",hours,minutes);
	
	
	
	
	return 0;
}