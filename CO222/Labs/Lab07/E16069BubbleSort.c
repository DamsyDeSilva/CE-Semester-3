/*
    CO222 - Programming Methodology
    Author  :   E/16/069
    Lab 07  :   Bubble Sort
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>   // to get the current time as seed in srand function

void BubbleSort(int *a , int n);    //  Function for bubble sort
void swap(int *x , int *y);         //  Function to swap two elements
void printArray(int *b , int n);    //  Function to print the array

int main()
{
    //  Variable to hold the size of the array;
    int s; 

    //  Getting user input ; array size
    printf("Enter the array size : ");
    scanf("%d", &s);
    if (s <= 0)
    {
        printf("Invalid Array Size\n");
        return 1;
    }

    //  Dynamically allocate memory to hold s integers
    int *p = (int *) malloc(sizeof(int) * s);   

    if (p == NULL)
    {
        printf("Memory is not allocated\n");
        return 1;   
    }

    // Use current time as seed for random generator
    srand(time(0)); 

    // assigning random numbers to allocated memory 
    for (int i = 0; i < s; i++)
    {
        p[i] = rand();
    }
    
    //  print the random array
    //printf("Random Array : \n");
    //printArray(p, s);
    //printf("\n");

    //  Sorting the array;
    printf("Sorted Array : \n");
    BubbleSort(p, s);
    free(p);

    return 0; 
}


//  Function for bubble sort
void BubbleSort(int *a, int n) 
{ 
    int swapped =0; // if swap is occured swapped = 1; othrwise 0;

    for (int i = 0; i < n-1; i++) 
    { 
        swapped = 0;

        for (int j = 0; j < n-i-1; j++) 
        { 
            // if the left element is greater than adjacent right element swap them
            if (a[j] > a[j+1]) 
            { 
                swap(&a[j], &a[j+1]); 
                swapped = 1;    // swap occurred
            } 
        } 

        // if no elements are swapped by inner loop then array is sorted;
        if (swapped == 0)
        { 
            break; 
        }
    }

    //  Printing the sorted array
    printArray(a, n);   
}

//  Function to swap two elements
void swap(int *x, int *y) 
{ 
    // interchage two values via temp variable
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 

//  Function to print the array
void printArray(int *b , int n)
{
    for(int i = 0; i< n; i++) 
    {
        printf("%d ", b[i]);
    }

}      