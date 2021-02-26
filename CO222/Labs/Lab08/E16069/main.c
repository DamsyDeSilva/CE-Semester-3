#include <linked.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5 // max number of cities.
#define NAMESIZE 20 // names should have this many or less chars

int main()
{
  list_t list = NULL; 
  char *city;

  printf("Enter city names. Enter \"END\" to break\n");

  while(city != NULL) { 

    city = (char *)malloc(sizeof(char) * NAMESIZE);
    assert(city);  
    
    if (scanf("%s", city) == 1)
    {
        if(!strcmp(city, "END")) break; // break out of loop

        assert(!head_insert(city, &list));
    } 
    
  }

  printf("Your way back: "); 
  while(remove_list((void **)&city, &list)) 
    printf("%s -> ", city);
  printf("Thats it\n");
  return 0;
}

