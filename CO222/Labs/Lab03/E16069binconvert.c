/*
	CO222 - Programming Methodology
	Lab 03
	
	M.D.S. De Silva
	E/16/069
	
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

char Inp;           // to hold the input format
char Outp;          // to hold the output format
int BinVal = 0;     // to hold an intermediate sequence between input and output


// defining functions
void BinaryIn( char Buff[] );   // function ; when input format is Binary
void BinaryOut();               // function ; when output format is Binary
void IntegerIn(char Buff[] );   // function ; when input format is Integer
void IntegerOut();              // function ; when output format is Integer
void FloatIn(char Buff[]);      // function ; when input format is Float
void FloatOut();                // function ; when output format is Float
void HexIn(char Buff[]);        // function ; when input format is Hexadecimal
void HexOut();                  // function ; when output format is hexadecimal


int main(int argc, char* argv[])
{
   
    if(argc == 4 ) // checking the  amount of arguments
    {

      Inp = *(argv[1]+1); 
      Outp = *(argv[2]+1); 
      
      int c = 0 ; // to hold a count of size of argv[]
      
      char Buffer[32] ; //To store the input values
         
    // to count the number of characters in input
    while(*argv[3] != '\0')
    {
        c++;
        argv[3]++;
    }

    // setting '0' s for character array
    for(int j = 0; j < 32; j++)
    {
        Buffer[j] = '0'; 
    }

    //reading the input value and assign it to Buffer[] array
      for(int j = 0; j < c; j++)
      {
         argv[3]--;
         Buffer[j] = *argv[3];
         
      }

   // checking the input format
      switch(Inp)
      {
         case 'B':
            BinaryIn(Buffer);
            break;
            
         case 'H':
            HexIn(Buffer);
            break;

         case 'I':
            IntegerIn(Buffer);
            break;

         case 'F':
            FloatIn(Buffer);
            break;
        default:
		    fprintf( stderr, "Usage: ./binconvert -<input format> -<output format> <input> " );	// print error 
		    return 1;
      }
    // checking the output format
      switch(Outp)
      {
         case 'B':
            BinaryOut();
            break;

         case 'H':
            HexOut();
            break;

         case 'I':
            IntegerOut();
            break;

         case 'F':
            FloatOut();
            break;
        default:
		    fprintf( stderr, "Usage: ./binconvert -<input format> -<output format> <input> " );	// print error 
		    return 1;
      }
   }
   else
	{
      // print error 
		fprintf( stderr, "Usage: ./binconvert -<input format> -<output format> <input> " );	
		return 1;
	}  
   return 0;
}

// function ; when output format is Binary
void BinaryOut()
{
   for(int i = 31; i>=0; i--)
   {
      printf("%d", (BinVal >> i & 1) ); //outputs the value of BinVal
   }
   
   printf("\n");
}

// function ; when input format is Binary
void BinaryIn( char Buff[] )
{
   for(int i = 31; i >=0; i--)
   {
        // converting the char to decimal 
        //assign that to BinVal with a bitshift
        BinVal = BinVal | (Buff[i] - '0') << i ;
   }  
}


// function ; when output format is Integer
void IntegerOut()
{
   if(Inp == 'F')
   {
      printf("%d\n",(int)*(float *)&BinVal);
   }
   else
   {
      printf("%d\n",(int)BinVal);
   }
}

// function ; when input format is Int
void IntegerIn(char Buff[] )
{
    for(int i = 0; i<32; i++ )
    {
        if(Buff[i] == '-')      //  when input is negative 
        {
            BinVal = -BinVal;
        }
        else
        {
            BinVal += (int)((Buff[i] - '0')*pow(10,i)); // when input is positive
        }
    } 
  
}

// function ; when output format is Float
void FloatOut()
{
   if(Inp == 'I')
   {
      printf("%.2f\n",(float)BinVal);
   }
   else
   {
      printf("%.2f\n",*(float*)&BinVal);
   }
}

// function ; when input format is Float
void FloatIn(char Buff[])
{
    int c = 0;
    int decimal = 0;
   

      for(int i = 0; i<32; i++ )
      {
         if(Buff[i]=='.') // identify the decimal point
         {
            decimal = i;
            c--;
         }
         else
         {
            if(Buff[i] == '-') //  when input is negative
            {
               BinVal = -BinVal;
            }else
            {
               BinVal += (int)((Buff[i] - '0')*pow(10,c));
            }
         }
         c++;
      }
      float BinVal1 = (BinVal)/pow(10,decimal);
      BinVal = *(int *)&BinVal1;
}   



// function ; when output format is Heaxadecimal
void HexOut()
{
   int Hval = 0; 

   printf("0x");

   for(int i = 7; i>=0; i--)
   {
      Hval = BinVal >> i*4 & 15;
      if(Hval <= 9 && Hval >= 0)    // when value is between '0' and '9'
      {
        printf("%c",Hval + '0'); 
      }
      else if (Hval <= 15 && Hval >= 10)// when value is between '10' and '15'
      {
        printf("%c",Hval - 10 + 'A' );
      }
             
   }
   printf("\n");
}

// function ; when input format is Hexadecimal
void HexIn(char Buff[])
{
   int Hval = 0;
     
   for(int i = 0; i<8; i++)
   {
      if(Buff[i]>='0' && Buff[i]<='9' ) // when input is between '0' and '9'
      {
         Hval = Buff[i] - '0';
      }
      else if (Buff[i]>='A' && Buff[i]<='F' )    // when input is between 'A' and 'F'
      {
         Hval = Buff[i] - 'A' + 10;
      }    
        BinVal = BinVal | Hval << i*4;
   }
}

