/*
	CO222-2019 Lab06
	Author: E16069

	Maze (Recursion)
*/

#include <stdio.h>

#define X_MAX   6
#define Y_MAX   6

/* These are called macros, do 'gcc -E maze.c | less' to see how they work 
 * They will be replaced before the code is compiled
 */
#define VISITED(x, y)      maze[x][y] = 2; 
#define CAN_VISIT(x, y)   (maze[x][y] == 0) 

/* MAKE SURE THE MATRIX MATCH X_ AND Y_MAX */
int maze[X_MAX][Y_MAX] = {{0, 0, 0, 0, 0, 1},
                          {1, 1, 1, 1, 0, 0},
                          {0, 0, 0, 0, 0, 0},
                          {0, 1, 1, 1, 1, 1},
                          {0, 0, 0, 0, 1, 1},
                          {1, 1, 1, 0, 0, 0}};


#define X_TARGET   (X_MAX - 1)
#define Y_TARGET   (Y_MAX - 1) 
#define X_START    0
#define Y_START    0
/* if you can find a path to given X_TARGET, Y_TARGET then 
 * findpath should  return 1. 
 * 0 otherwise
 */

int findpath(int x, int y) 
{
  if(x == X_TARGET && y == Y_TARGET && CAN_VISIT(x, y)) { 
    return 1; // we came to the point. Should display the path
  }
  
  VISITED(x,y); // make the problem small.
    // remove this and see what will happen
    /* implement the rest */
    //#error "Implement me"
  
  int path; // to hold a return value
  
  //right side cell
  if (x+1 < X_MAX && CAN_VISIT(x+1, y))
  {
    path = findpath(x+1, y);  //(return value from find path);
    if (path == 1)    //if there is a path available, path = 1;
    {
      printf("(%d, %d)", x+1, y);
      return 1;     //if path available return 1;
    }
  }

  //upside cell
  if (y+1 < Y_MAX && CAN_VISIT(x, y+1))
  {
    path = findpath(x, y+1);  //(return value from find path);
    if (path == 1)      //if there is a path available, path = 1;
    {
      printf("(%d, %d)", x, y+1);
      return 1;    //if path available return 1;
    }
    
  }

  //left cell
  if (x > 0 && CAN_VISIT(x-1, y))
  {
    path = findpath(x-1, y);  //(return value from find path);
    if (path == 1)    //if there is a path available, path = 1;
    {
      printf("(%d, %d)", x-1, y);
      return 1;    //if path available return 1;
    }
  }

  //down cell
  if(y > 0 && CAN_VISIT(x, y-1))
  {
    path = findpath(x, y-1);  //(return value from find path);
    if (path == 1)    //if there is a path available, path = 1;
    {
      printf("(%d, %d)", x, y-1);
      return 1;    //if path available return 1;
    }
  }
  return 0;  // tried all no path
}


int main()
{
  printf("%s", findpath(0, 0) == 1 ? "\n" : "No path\n");
}
      
