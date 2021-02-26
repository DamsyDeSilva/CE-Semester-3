/*	
	C0222 : Programming Methodology
	Lab 01
	E/16/069 
	M.D.S.De Silva
*/

#include<stdio.h>
#include<math.h>
#include<complex.h>

int main(){
	
	double a,b,c = 0;
 	double complex critic,sol1,sol2=0;
	printf("Enter the coefficients : ");
	scanf("%lf %lf %lf",&a,&b,&c);
	
 	critic = (b*b) -(4*a*c);
 	sol1 = ((-1)*b + csqrt(critic))/(2*a);
	sol2 = ((-1)*b - csqrt(critic))/(2*a);
	
	if(creal(critic)< 0)
	{
		if(creal(sol1)==0)
		{
			printf("The solutions are : %.2lfi and %.2fi \n",cimag(sol1),cimag(sol2));	
		} 
		else
		{
			printf("The solutions are : %.2lf %+.2fi and %.2lf %+.2fi\n",creal(sol1),cimag(sol1),creal(sol2),cimag(sol2));
			
		}
		 
	}else if(creal(critic)== 0)
	{
		printf("The solutions are : %.2lf\n",creal(sol1));
	}else
	{
		printf("The solutions are : %.2lf and %.2f \n",creal(sol1),creal(sol2));
	}
	
	return 0; 
}