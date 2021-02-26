#include <stdio.h>

double power(double x, int y) ; //power function

void BinarytoInt(char buff[] , int n);   //function for binary to integer conversion
void IntoBinary(int N , int sign);   //function for integer to binary conversion

void BinToHex(char buff[], int n);  //function for binary to hexadecimal conversion
void HexaToBin(int buff[], int n); //function for hexadecimal to binary conversion

void BinToFloatORdouble(char buff[], int n);  //function for binary to float or double conversion

void floatOrdoubleToBinary(int num_1 , double num_2 , int n , int sign);  //function for float or double to binary conversion;
void printsame(char buff[], int n); // to output the same

int floatBinary[32];    // to hold the binary value int float to binary conversion
int doubleBinary[64];   // to hold the binary value int double to binary conversion
int binArray[32];       // to hold the binary value in IntoBinary function
int hexbinArray_8[32];  // to hold the binary array when hexadecimal input is 8 bits
int hexbinArray_16[64]; // to hold the binary array when hexadecimal input is 16 bits
double tot;             // to hold the decimal value in BinarytoInt function


int main(int argc , char* argv[])
{
    if (argc == 4)
    {
        //checcking the validity of the input and output formats
        int ci[2];
        for (int i = 1; i < 3;i++)
        {
            ci[i-1] = 0; //to hold the input & output argumnet sizes
            while (argv[i][ci[i-1]] != '\0')
            {
                ci[i-1]++;
            }
            if (ci[i-1] != 2 && i == 1)
            {
                fprintf( stderr, "ERROR: The input argument is wrong.\n");
                fprintf( stderr, "Possible input arguments are -B, -H, -I, -F and -D.");
                return 1;
            }
            if (ci[i-1] != 2 && i == 2)
            {
                fprintf( stderr, "ERROR: The output argument is wrong.\n");
                fprintf( stderr, "Possible output arguments are -B, -H, -I, -F and -D.");
                return 1;
            }
        }

        //counting the input char size
        int c = 0;
        while (argv[3][c] != '\0')
        {
            c++;
        } 
        int length = c; //length of input


        //when input is binary     
        if ((argv[1][1])== 'B' && (argv[1][0])== '-') 
		{
            //checking for invalid input formats
            for (int i = 0; i < length; i++)
            {
                if (argv[3][i] != '1' && argv[3][i] != '0')
                {
                    fprintf( stderr, "ERROR: Input format error at location %d.",i );	//print error  for invalid characters
                    return 1;
                }
            } 

            //checking input size
            if (length == 32 || length == 64)
            {
                //binary to binary
                if ((argv[2][1]) == 'B' && (argv[2][0])== '-')
                {
                    printsame(argv[3] , length);
                }
                //binary to int conversion
                else if ((argv[2][1]) == 'I' && (argv[2][0])== '-')
                {
                    if (length == 32)   // integer is 32bit
                    {
                        BinarytoInt(argv[3] , length);  //calling the binary to  integer function
                        fprintf( stdout, "%.0lf", tot);    //printing the integer
                    }
                    else
                    {
                        fprintf( stderr, "ERROR: This conversion is not possible.");
                        return 1;
                    }          
                }
                //binary to float
                else if ((argv[2][1]) == 'F' && (argv[2][0])== '-')
                {
                    if (length == 32)
                    {
                        BinToFloatORdouble(argv[3], length);
                    }
                    else
                    {
                        fprintf( stderr, "ERROR: This conversion is not possible.");
                        return 1; 
                    }
                }
                //binary to double
                else if ((argv[2][1]) == 'D' && (argv[2][0])== '-')
                {
                    if (length == 64)
                    {
                        BinToFloatORdouble(argv[3], length);
                    }
                    else
                    {
                        fprintf( stderr, "ERROR: This conversion is not possible.");
                        return 1; 
                    }
                    
                }
                //binary to hexadecimal
                else if ((argv[2][1]) == 'H' && (argv[2][0])== '-')
                {
                    BinToHex(argv[3], length);  
                }
                else
                {
                    fprintf( stderr, "ERROR: The output argument is wrong.\n");
                    fprintf( stderr, "Possible output arguments are -B, -H, -I, -F and -D.");
                    return 1;
                }
            }
            else
            {
                fprintf(stderr, "ERROR: The input size is wrong.");	// print error for wrong input size
                return 1;
            }
                  
        }

        //when input format is integer
        else if((argv[1][1])== 'I' && (argv[1][0])== '-')
        {
            int sign ; // 1 - negative; 0 - positive
            if(argv[3][0] == '-')
            {       //negative integer
                sign = 1; 
            }
            else    //positive integer
            {
                sign = 0;
            }  

            //checking for invalid input formats
            for (int i = sign; i < length; i++)
            {
                if (argv[3][i] >= '0' && argv[3][i] <= '9')
                {
                    continue;
                }
                else
                {
                    fprintf( stderr, "ERROR: Input format error at location %d.",i );	//print error  for invalid characters
                    return 1;
                }
            }

            double number = 0;
            int N = 0;
            for(int j = sign; j < length ; j++)
            {
                number = number + (argv[3][j] - '0')* power((double) 10 , (int) (length-1-j));   //converting char array to decimal number
            }
            
            N = (int)number;

            if (number > 2147483647)
            {
                fprintf( stderr, "ERROR: The input size is wrong." );	//print error  for invalid characters
                return 1;  
            }
            
            //integer to integer
            if ((argv[2][1]) == 'I' && (argv[2][0])== '-')
            {
                printsame(argv[3] , length);
            }

            //integer to binary
            else if ((argv[2][1]) == 'B' && (argv[2][0])== '-')
            {
                IntoBinary(N, sign);  //calling the binary to  integer function
                //printing the binary
                for(int j = 0; j < 32; j++)
                {
                    fprintf( stdout, "%d", binArray[j]); 
                }
            }
            //integer to float
            else if ((argv[2][1]) == 'F' && (argv[2][0])== '-')
            {
                if (sign == 1)
                {
                    number = number*(-1);
                }
                fprintf( stdout, "%.2lf",number);
            }

            //integer to double
            else if ((argv[2][1]) == 'D' && (argv[2][0])== '-')
            {
                fprintf( stderr, "ERROR: This conversion is not possible.");
                return 1;
            }

            //int  to hexadecimal
            else if ((argv[2][1]) == 'H' && (argv[2][0])== '-')
            {
                // first convert the integer to binary 
                // then convert the binary to hexadecimal
                char arr[32]; //to hold a character array
                IntoBinary ( N, sign);  // I to B 
                for(int j = 0; j < 32; j++)
                {
                    arr[j] = binArray[j] + '0'; //converting to character
                }
                BinToHex(arr , 32); // B to H
            }

            else
            {
                fprintf( stderr, "ERROR: The output argument is wrong.\n");
                fprintf( stderr, "Possible output arguments are -B, -H, -I, -F and -D.");
                return 1;
            }

        }
        //when input is single precision float
        else if((argv[1][1])== 'F' && (argv[1][0])== '-')
        {
            int sign ; // 1 - negative; 0 - positive
            if(argv[3][0] == '-')
            {       //negative integer
                sign = 1; 
            }
            else    //positive integer
            {
                sign = 0;
            }  

            int dotcount = 0;
            int dotlocation = 0;
            //checking for invalid input formats
            for (int i = sign; i < length; i++)
            {
                if (argv[3][i] >= '0' && argv[3][i] <= '9')
                {
                    continue;
                }
                else if(argv[3][i] == '.')
                {
                    dotcount++;
                    if (dotcount > 1)
                    {
                        fprintf( stderr, "ERROR: Input format error at location %d.",i );	//print error  for invalid characters
                        return 1;
                    }
                    dotlocation = i;
                    continue;
                }
                else
                {
                    fprintf( stderr, "ERROR: Input format error at location %d.",i );	//print error  for invalid characters
                    return 1;
                }
            }
            //when there is no decimal point
            if (dotcount == 0)
            {
                dotlocation = length;
            }
            
            double number = 0;
            int Ndec = 0;
            double Nfloat = 0;
            for(int j = sign; j < dotlocation ; j++)
            {
                number = number + (argv[3][j] - '0')* power((double) 10 , (int) (dotlocation-1-j));   //converting char array up to dotlocation to decimal number
            }

            Ndec = (int)number;
            for(int j = dotlocation+1 ; j < length ; j++)
            {
                Nfloat = Nfloat + (argv[3][j] - '0')* power((double) 10 , (int) (dotlocation -j));   //converting char array up to dotlocation to decimal number
            }

            /*if ((length- dotlocation-1) != 2)
            {
                fprintf( stderr, "ERROR: This conversion is not possible." );	//print error  for invalid characters
                return 1; 
            }*/

            /*if (number > 2147483647)
            {
                fprintf( stderr, "ERROR: This conversion is not possible." );	//print error  for invalid characters
                return 1;  
            }*/

            //float to float
            if ((argv[2][1]) == 'F' && (argv[2][0])== '-')
            {
                if (sign == 0)
                {
                    fprintf(stdout, "%.2lf", (number + Nfloat));
                }
                else if (sign == 1)
                {
                    fprintf(stdout, "%.2lf", (-1)*(number + Nfloat));
                }
            }
            //float to Int
            else if ((argv[2][1]) == 'I' && (argv[2][0])== '-')
            {
                if (number > 2147483647)
                {
                    fprintf( stderr, "ERROR: This conversion is not possible." );	//print error  for invalid characters
                    return 1;  
                }
                if (sign == 1)
                {
                    Ndec = Ndec*(-1);
                }
                fprintf( stdout, "WARNING:  There is a possibility for a precision loss.\n");
                fprintf( stdout, "%d",Ndec);
            }
            //float to double
            else if ((argv[2][1]) == 'D' && (argv[2][0])== '-')
            {
                fprintf( stderr, "ERROR: This conversion is not possible."); 
                return 1;  
            }
            //float to binary
            else if ((argv[2][1]) == 'B' && (argv[2][0])== '-')
            {
                floatOrdoubleToBinary(Ndec, Nfloat ,32 ,sign);  
                for (int i = 0 ; i < 32 ; i++ )
                {       
                    fprintf( stdout, "%d", floatBinary[i]); 
                }

            }
            //float to Hexadecimal
            else if ((argv[2][1]) == 'H' && (argv[2][0])== '-')
            {
                // first convert the float to binary 
                // then convert the binary to hexadecimal
                char arr[32]; //to hold a character array
                floatOrdoubleToBinary(Ndec, Nfloat ,32 ,sign);  // F to B 
                for(int j = 0; j < 32; j++)
                {
                    arr[j] = floatBinary[j] + '0'; //converting to character
                }
                BinToHex(arr , 32); // B to H
            }
            else
            {
                fprintf( stderr, "ERROR: The output argument is wrong.\n");
                fprintf( stderr, "Possible output arguments are -B, -H, -I, -F and -D.");
                return 1;
            }
        }
        //when input is double precision 
        else if((argv[1][1])== 'D' && (argv[1][0])== '-')
        {
            int sign ; // 1 - negative; 0 - positive
            if(argv[3][0] == '-')
            {       //negative integer
                sign = 1; 
            }
            else    //positive integer
            {
                sign = 0;
            }  

            int dotcount = 0;
            int dotlocation = 0;
            //checking for invalid input formats
            for (int i = sign; i < length; i++)
            {
                if (argv[3][i] >= '0' && argv[3][i] <= '9')
                {
                    continue;
                }
                else if(argv[3][i] == '.')
                {
                    dotcount++;
                    if (dotcount > 1)
                    {
                        fprintf( stderr, "ERROR: Input format error at location %d.",i );	//print error  for invalid characters
                        return 1;
                    }
                    dotlocation = i;
                    continue;
                }
                else
                {
                    fprintf( stderr, "ERROR: Input format error at location %d.",i );	//print error  for invalid characters
                    return 1;
                }
            }
            //when there is no decimal point
            if (dotcount == 0)
            {
                dotlocation = length;
            }

            double number = 0;
            int Ndec = 0;
            double Nfloat = 0;
            for(int j = sign; j < dotlocation ; j++)
            {
                number = number + (argv[3][j] - '0')* power((double) 10 , (int) (dotlocation-1-j));   //converting char array up to dotlocation to decimal number
            }
           
            Ndec = (int)number;
            for(int j = dotlocation+1 ; j < length ; j++)
            {
                Nfloat = Nfloat + (argv[3][j] - '0')* power((double) 10 , (int) (dotlocation -j));   //converting char array up to dotlocation to decimal number
            }
            /*if ((length- dotlocation-1) != 6)
            {
                fprintf( stderr, "ERROR: This conversion is not possible." );	//print error  for invalid characters
                return 1; 
            }*/

            

            //double to double
            if ((argv[2][1]) == 'D' && (argv[2][0])== '-')
            {
                if (sign == 0)
                {
                    fprintf(stdout, "%.6lf", (number + Nfloat));
                }
                else if (sign == 1)
                {
                    fprintf(stdout, "%.6lf", (-1)*(number + Nfloat));
                }
            }
            //double to Int
            else if ((argv[2][1]) == 'I' && (argv[2][0])== '-')
            {
                fprintf( stderr, "ERROR: This conversion is not possible.");
                return 1;
            }
            //double to float
            else if ((argv[2][1]) == 'F' && (argv[2][0])== '-')
            {
                fprintf( stderr, "ERROR: This conversion is not possible.");
                return 1;
            }
            //double to binary
            else if ((argv[2][1]) == 'B' && (argv[2][0])== '-')
            {
                floatOrdoubleToBinary(Ndec, Nfloat ,64 ,sign);  
                for (int i = 0 ; i < 64 ; i++ )
                {       
                    fprintf( stdout, "%d", doubleBinary[i]); 
                }
            }
            //double to Hexadecimal
            else if ((argv[2][1]) == 'H' && (argv[2][0])== '-')
            {
                // first convert the double to binary 
                // then convert the binary to hexadecimal
                char arr[32]; //to hold a character array
                floatOrdoubleToBinary(Ndec, Nfloat ,64 ,sign);  // D to B 
                for(int j = 0; j < 64; j++)
                {
                    arr[j] = doubleBinary[j] + '0'; //converting to character
                }
                BinToHex(arr , 64); // B to H
            }
            else
            {
                fprintf( stderr, "ERROR: The output argument is wrong.\n");
                fprintf( stderr, "Possible output arguments are -B, -H, -I, -F and -D.");
                return 1;
            }

        }
        //when input is hexadecimal
        else if((argv[1][1])== 'H' && (argv[1][0])== '-')
        {
            //check for invalid characters;
            for(int i = 0; i < length; i++)
            {
                if ((argv[3][i] >= '0' && argv[3][i] <= '9') || (argv[3][i] >= 'A' && argv[3][i] <= 'F'))
                {
                    continue;                    
                }
                else
                {
                    fprintf( stderr, "ERROR: Input format error at location %d.",i );	//print error  for invalid characters
                    return 1;
                }
            }
            if (length != 8 && length != 16)
            {
                fprintf( stderr, "ERROR: The input size is wrong." );	//print error  for invalid characters
                return 1;
            }

            int hexarray[length];

            for(int  i = 0; i < length ; i++)
            {
                if (argv[3][i] >= '0' && argv[3][i] <= '9')
                {
                    hexarray[i] = (argv[3][i]) - '0';
                }
                else if (argv[3][i] >= 'A' && argv[3][i] <= 'F')
                {
                    hexarray[i] = (argv[3][i]) - 'A' + 10;
                }
            }

            double number = 0;

            for(int j = 0; j < length ; j++)
            {
                number = number + (hexarray[j])* power((double) 16 , (int) (length-1-j));   //converting  array to decimal number
            }
            
    
            //hexa to hexa
            if ((argv[2][1]) == 'H' && (argv[2][0])== '-')
            {
                fprintf( stdout, "0x");
                printsame(argv[3] , length);
                
            }
            //Hexa to Int
            else if ((argv[2][1]) == 'I' && (argv[2][0])== '-')
            {
                if (length == 8) // integer is 32bit
                {
                    //fprintf( stdout, "%.0lf",number);
                    //HexaToBin

                    char hex_16[64]; // to hold char values
                    HexaToBin(hexarray, length); // calling the hexa to bin function

                    for (int  i = 0 ; i < 64 ; i++)
                    {
                        hex_16[i] = hexbinArray_8[i] + '0';  // converting to char
                    }
                    BinarytoInt(hex_16,32);  //calling the binary to  integer function
                    fprintf( stdout, "%.0lf", tot);
                }
                else
                {
                    fprintf( stderr, "ERROR: This conversion is not possible.");
                    return 1;
                }
                    
            }
            //hexa to binary
            else if ((argv[2][1]) == 'B' && (argv[2][0])== '-')
            {
                HexaToBin(hexarray, length); // calling the hexa to bin function

                //printing the corresponding array
                if (length == 8)
                {
                    for (int  i = 0 ; i < 32 ; i++)
                    {
                        fprintf(stdout, "%d", hexbinArray_8[i]); // 32 bit binary value
                    }
                }
                else
                {
                    for (int  i = 0 ; i < 64 ; i++)
                    {
                        fprintf(stdout, "%d", hexbinArray_16[i]); // 64 bit binary value
                    }
                }
            }
            //Hexa to float
            else if ((argv[2][1]) == 'F' && (argv[2][0])== '-')
            {
                
                if (length == 8)
                {
                    char hex_8[32]; // to hold char values
                    HexaToBin(hexarray, length); // calling the hexa to bin function

                    for (int  i = 0 ; i < 32 ; i++)
                    {
                        hex_8[i] = hexbinArray_8[i] + '0';  // converting to char
                    }
                    
                    BinToFloatORdouble(hex_8, 32);  // calling the hexa to bin function

                }
                else
                {
                    fprintf( stderr, "ERROR: This conversion is not possible.");
                    return 1; 
                }
                
            }
            //Hexa to double
            else if ((argv[2][1]) == 'D' && (argv[2][0])== '-')
            {
                if (length == 16)
                {
                    char hex_16[64]; // to hold char values
                    HexaToBin(hexarray, length); // calling the hexa to bin function

                    for (int  i = 0 ; i < 64 ; i++)
                    {
                        hex_16[i] = hexbinArray_16[i] + '0';  // converting to char
                    }
                    
                    BinToFloatORdouble(hex_16, 64);  // calling the hexa to bin function

                }
                else
                {
                    fprintf( stderr, "ERROR: This conversion is not possible.");
                    return 1; 
                }
                
            }
            else
            {
                fprintf( stderr, "ERROR: The output argument is wrong.\n");
                fprintf( stderr, "Possible output arguments are -B, -H, -I, -F and -D.");
                return 1;
            }
        }
        else
        {
            fprintf( stderr, "ERROR: The input argument is wrong.\n");
            fprintf( stderr, "Possible input arguments are -B, -H, -I, -F and -D.");
            return 1;
        }
        
    }
    else
    {
        // print error for wrong number of arguments
        fprintf(stderr, "ERROR: The number of arguments is wrong.\n");
		fprintf(stderr, "Usage: ./clc -<input format> -<output format> <input>");	
		return 1;
    }

    return 0;
}

//function to print the same array
void printsame(char buff[] , int n)
{
    //buff[] --> input char array
    //n     --> length of the input 
    for (int i = 0 ; i < n ; i++ )
    {       
        fprintf( stdout, "%c", buff[i]); //output the same 
    }
}
//function for conversion of binary to integer 
void BinarytoInt(char buff[] , int n)
{
    //buff[] --> input char array
    //n     --> bit size // 32 or 64

    int binArr[n];
    for(int j = 0; j < n; j++)
    {
        binArr[j] = 0; 
    }

    //char to int 
     for (int i = 0; i < n; i++)
    {
        binArr[i] = (buff[i] - '0'); 
    }
    
   if(binArr[0] == 0)     //positive
    {
        tot = 0;     // variable to hold the decimal value
        for(int j = 1; j < n ; j++)
	    {
		    tot = tot + binArr[j] * power((double) 2 , (int) (n-1-j));   //calculating the decimal value
	    }
       // fprintf( stdout, "%.0lf\n", tot);    //printing the integer when positive
    }
    else if (binArr[0] == 1)      //negative
    {
        tot = 0;
        for (int i = 0; i < n; i++)
        { 
            if (binArr[i] == 1) //flipping
            { 
                binArr[i] = 0;
            }
            else 
            {
                binArr[i] = 1;
            }
            tot = tot + binArr[i]*power((double) 2, (int) (n-1-i));
        }
        tot = (-1)*(tot + 1);
        //fprintf( stdout, "%.0lf", tot);    //printing the integer when negative
    }   
}
//function for conversion of integer to binary
void IntoBinary(int N, int sign)
{ 
    //N     --> positive decimal value
    //sign  --> positive(0) or negative (1) 
    
    for(int j = 0; j < 32; j++)
    {
        binArray[j] = 0;  // initializing global array
    }

    //converting to  bin
    for(int i = 31; i > 0; i--)
    {
        binArray[i] = (N % 2);
        N = N/2;
            
        if(N == 1)
        {
            binArray[i-1] = 1;
            break;
        }
    }

    if (sign == 1) 
    {
        //checking the index that ocuurs 1 at first place from right to left
        int c = 31;
        while (binArray[c] != 1)
        {
            c--;
        }
        //flipping the bits
        for(int i = 0; i < c; i++)
        {
            if (binArray[i] == 0)
            {
                binArray[i] = 1;
            }
            else
            {
                binArray[i] = 0;
            }
        } 
        
    }
}
//function for conversion of binary to HexaDecimal 
void BinToHex(char buff[], int n)
{
    //buff[] --> input char array
    //n     --> bit size // 32 or 64

    double totH;
    int size1 = n / 4;
    
    int hexArr[size1];

    for (int i = 0; i < size1; i++)
    {
        totH = 0;
        for (int j = 0; j < 4; j++)
        {
            totH = totH + (buff[(4*i) + 3 -j]-'0') * power((double) 2 , (int) (j));   //calculating the decimal value
        }
        hexArr[i] = (int) totH;
    }

    fprintf( stdout, "0x");
    for (int i = 0; i < size1 ; i++ ) 
    {
        if ((hexArr[i] >= 0 && hexArr[i] <= 9))
        {
            fprintf( stdout, "%d", hexArr[i]);      
        }
        else
        {
            switch (hexArr[i])
            {
                case 10:
                    fprintf( stdout, "A");
                    break;
                case 11:
                    fprintf( stdout, "B");
                    break;
                case 12:
                    fprintf( stdout, "C");
                    break;
                case 13:
                    fprintf( stdout, "D");
                    break;
                case 14:
                    fprintf( stdout, "E");
                    break;
                case 15:
                    fprintf( stdout, "F");
                    break;
                default:
                    break;
            }
        }   
    }
}

//function for conversion of HexaDecimal to binary
void HexaToBin(int buff[], int n)
{
    //buff[] --> input char array
    //n     --> bit size // 8 or 16

    int size = 4 * n;
    int hexbinArray[size]; // to hold the binary array

    
    for (int i = 0 ; i < n; i++)
    {
                    
        for (int j = 0 ; j < 4 ; j++)
        {

            hexbinArray[(4*i) + 3 - j] = (buff[i] % 2);
            buff[i] = buff[i] / 2 ;
                        
        }
    }
    if (n == 8)
    {
        for (int  i = 0 ; i < size ; i++)
        {
            hexbinArray_8[i] = hexbinArray[i]; // store the value in global array
        }
    }
    else
    {
        for (int  i = 0 ; i < size ; i++)
        {
            hexbinArray_16[i] = hexbinArray[i];  // store the value in global array
        }
    }
}

//function for conversion of binary to float or double
void BinToFloatORdouble(char buff[], int n)
{
    //buff[] --> input char array
    //n     --> bit size // 32 or 64

    int expBits , mantBits , exp_bias;
    if (n == 32)    //32 bit  single precision floating point 
    {
        expBits = 8 ; mantBits = 23 ;exp_bias =  127;
    }
    else if(n == 64)    //64 bit  double precision floating point
    {
        expBits = 11 ; mantBits = 52 ; exp_bias =  1023;
    }
    int expArrray[expBits], mantissa[mantBits];
    int exp = 0;
    double e = 0; // dec value of exponent;
    double m = 0; // dec value of mantissa;

    int signf = (buff[0] - '0'); //sign bit

    // calculating the exponent value;
    for (int i = 0; i < expBits; i++)
    {
        expArrray[i] = (buff[i+1] - '0');
        e = e + expArrray[i] * power((double) 2 , (int) (expBits - 1 -i));
    }
    
    exp = (int)e - exp_bias; // exponent value;

    //calculating the mantissa value
    for (int i = 0; i < mantBits; i++)
    {
        mantissa[i] = (buff[i+1+expBits] - '0');
        m = m + mantissa[i] * power((double) 2 , (int) (0 - 1 -i));
    }

    if (n == 32)
    {
        float floatOrdoubleVal = 0;
        //  (-1)^signf * (1+m) * 2^exp
        floatOrdoubleVal = (float) (power((double) (-1) , (int) (signf)) * (1 + m) * power((double) 2 , (int) (exp)));
        fprintf( stdout , "%f" , floatOrdoubleVal); // when outputformat is float : two decimal points
    }
    else if (n == 64)
    {
        
        double floatOrdoubleVal1 = 0;
        //  (-1)^signf * (1+m) * 2^exp
        floatOrdoubleVal1 =  (power((double) (-1) , (int) (signf)) * (1 + m) * power((double) 2 , (int) (exp)));
        fprintf( stdout , "%.6lf", floatOrdoubleVal1);   // when outputformat is float : six decimal points
    }
}

//function for conversion of float or double to binary
void floatOrdoubleToBinary(int num_1 , double num_2 ,int n, int sign)
{
    //num_1 --> value without floating points
    //num_2 --> floating point value
    //n     --> bit size // double or float
    //sign  --> positive (0) , negative (1)

    int binaryVal[n];
    for (int i = 0; i < n ; i++)
    {
        binaryVal[i] = 0; //intializing      
    }

    int expBits , exp_bias , ex = 0 , exponent = 0;
    int mantBits ; 

    if (n == 32)    //32 bit  single precision floating point 
    {
        expBits = 8; exp_bias =  127;  mantBits = 23 ;
    }
    else if(n == 64)    //64 bit  double precision floating point
    {
        expBits = 11; exp_bias =  1023; mantBits = 52 ;
    }
    if (!(num_1 == 0 && num_2 ==0))
    {
        binaryVal[0] = sign;    //signbit

        //considering num_2
        int k = 0;
        double nn_2 = num_2;
        double n_2 = num_2;

        //searching for first ocuurence of 1
        for (k = 0; k < 200; k++)
        {
            n_2 = n_2 * 2;
            if (n_2 > 1)
            {
                break;
            }
        }
        int bufferArray[200];  //buffer array to store the fraction part as binary 
        for (int i = 0; i < 200 ; i++)
        {
            bufferArray[i] = 0; //intializing      
        }

        for (int i = 0; i < 200; i++)
        {
            nn_2 = nn_2 * 2;
            if (nn_2 > 1)
            {
                bufferArray[i] = 1;
                nn_2 = nn_2 - 1;
            }
            else
            {
                bufferArray[i] = 0;
            }
        }

        int m = 0;  //variable to check overflow
        //considering num_1 
        if (num_1 == 0)
        {
            if (num_2 != 0)
            {
                ex = (-1) * (k+1); 
            }
            for (int i = k + 1 ; i < n ; i++)
            {
                binaryVal[expBits + 1 + i - k -1] = bufferArray[i];
            } 
            //checking for overflow
            if (bufferArray[n-k-1] == 1)
            {
                m=1;
            }  
        }  
        else if (num_1 > 0)
        {
            IntoBinary(num_1,0);    //converting num_1 to binary
            // o/p --> binArray[32];
            
            int c2 = 0;
            while (binArray[c2] == 0)
            {
                c2++;
            }
            ex = 31 - c2;  //number of bits should add to the mantissa ---> exponent before biasing
            //printf("%d\n",ex);
            for (int i = 0; i < ex  ; i++)
            {
                binaryVal[expBits + 1 + i] = binArray[c2 + 1 + i]; // adding those bits to the mantissa
            }
            for (int i = expBits + 1 + ex; i < n  ; i++)
            {
                binaryVal[i] = bufferArray[i - expBits -1 - ex]; // adding rest of bits to the mantissa
            }  
            //checking for overflow
            if (bufferArray[n - expBits - 1 - ex] == 1)
            {
                m=1;
            }  
        }

        //when there's an overflow 
        if (m == 1)
        {
            double  temp_Tot = 0;
            for (int i = 0; i < mantBits; i++)
            { 
                temp_Tot = temp_Tot + binaryVal[expBits + 1 + i]*power((double) 2, (int) (mantBits-1-i));
            }   
            int tempTot = (int)temp_Tot + 1; //adding 1 to mantissa
            for(int i = n-1; i >= expBits+1; i--)
            {
                binaryVal[i] = 0; 
            }
            //converting to  bin
            for(int i = n-1; i >= expBits+1; i--)
            {
                binaryVal[i] = (tempTot % 2);
                tempTot = tempTot/2;
                        
                if(tempTot == 1)
                {
                    binaryVal[i-1] = 1;
                    break;
                }
            }

        }

        exponent = exp_bias + ex; //exponent value
        //printf("%d\n",exponent);
        IntoBinary(exponent,0);    //converting exponent to binary
        // o/p --> binArray[32];

        for (int i = 0; i < expBits ; i++)
        {
            binaryVal[expBits- i] = binArray[31-i]; // adding those bits to the exponent bits
        }
    }
    //store the values globally
    if (n == 32)
    {
        for (int i = 0 ; i < n ; i++ )
        {       
            floatBinary[i] = binaryVal[i];  // when outputformat is float 
        }
    }
    else if (n == 64)
    {
        for (int i = 0 ; i < n ; i++ )
        {       
            doubleBinary[i] = binaryVal[i];   // when outputformat is double
        }
    }
}
//function for power
double power(double x, int y) 
{ 
    // x --> base
    // y --> exponent
    double temp; 
    if( y == 0)
    { 
       return 1; 
    }
    temp = power(x, y/2);        
    if (y%2 == 0)
    { 
        return temp*temp; 
    }
    else
    { 
        if(y > 0) 
        {
            return x*temp*temp; 
        }     
        else
        {
            return (temp*temp)/x; 
        }    
    } 
} 