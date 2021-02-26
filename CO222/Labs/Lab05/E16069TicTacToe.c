/*
	CO222-2019 Lab05
	Author: E16069

	TicTacToe game
*/
#include<stdio.h>
#include<stdlib.h>

#define SIZE 3

void scanBoard(int a[SIZE][SIZE]);
void printBoard(int b[SIZE][SIZE]);
int getWinner(int b[SIZE][SIZE]);

int main(){

	int inBoard[SIZE][SIZE];	//declaring an array

	printf("Please enter the board:\n");
	scanBoard(inBoard);	//scanBoard
	printf("Here is the board:\n");
	printBoard(inBoard);	//printBoard

	//printing the result
	if(getWinner(inBoard)==0)	
		printf("Noughts win\n");
	else if(getWinner(inBoard)==1)
		printf("Crosses win\n");
	else
		printf("There are no winners\n");
	return 0;
} 

//scan function
void scanBoard(int board[SIZE][SIZE]){
	
	//check if the input is 0 || 1 || 2
	//else give the error message "Enter valid input." and terminate the program
   
   // two nested for loops for access 2d array
    for (int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            scanf("%d",&board[i][j]); //scanning user input 
        }   
    }  
    
  //checking for invalid inputs in 2d array
    for (int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if (board[i][j] != 0 && board[i][j] != 1 && board[i][j] != 2)
            {
                printf("Enter valid input.\n");
                exit(0);    // terminating the program
            }
        } 
    }  
}


//print function
void printBoard(int board[SIZE][SIZE]){
	//printing board

    // two nested for loops for access elements of 2d array
    for (int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            //checking the element 
            switch (board[i][j])
            {
                case 0:
                    printf("O ");   // O for 0s
                    break;
                case 1:
                    printf("X ");   // X for 1s
                    break;
                case 2:
                    printf(". ");   // . for 2s
                    break;
                default:
                    break;
            }
        }
        printf("\n");
    }
}


//find the winner of the game
//assume both two players can't win the game at the same time. It can't happen in a real game
int getWinner(int board[SIZE][SIZE]){
	
	int winner = 2;	
	
	//if winner is Noughts, winner = 0
	//if winner is Crosses, winner = 1
	//if there is no winner, winner = 2

    int nr=0 , cr=0 , nc=0 , cc=0; 

    // checking for winning in rows and columns
    for (int i = 0; i<SIZE; i++)
    {
        for(int j = 0; j< SIZE; j++)
        {
            if(board[i][j] == 0)    //checking noughts in rows
            {
                nr++;
            }
            else if(board[i][j] == 1)   //checking crosses in rows
            {
                cr++;
            }
            
            if(board[j][i] == 0)    //checking noughts in columns
            {
                nc++;
            }
            else if(board[j][i] == 1)   //checking crosses in columns
            {
                cc++;
            }
        }

        // if a count of 0s or 1s in particular row or column is equal to the SIZE of array ; that one is the winner
        if(nr == SIZE || nc == SIZE) //noughts
        {
            winner = 0;
            break;
        }
        if(cr == SIZE || cc == SIZE) //crosses
        {
            winner = 1;
            break;
        }
        else 
        {
            //initializing before iterating to new column or row
            nr = 0;
            cr = 0;
            nc = 0;
            cc = 0;
        }
    }

    
    // checking winners diagonally;

    int nd1=0 , cd1=0 , nd2=0 , cd2=0;

    for (int i = 0; i < SIZE; i++)
    {
        // checking through primary diagonal
        if(board[i][i] == 0)
        {
            nd1++;
        }
        else if(board[i][i] == 1)
        {
            cd1++;
        }

        // checking through secondary diagonal
        if (board[i][SIZE-1-i] == 0)
        {
            nd2++;
        }
        else if(board[i][SIZE-1-i] == 1)
        {
            cd2++;
        }
    }
    //checking the diagonal counts
    if(nd1 == SIZE || nd2 == SIZE) //noughts
    {
        winner = 0;         
    }
    if(cd1 == SIZE || cd2 == SIZE) //crosses
    {
        winner = 1;          
    }
	return  winner;
}