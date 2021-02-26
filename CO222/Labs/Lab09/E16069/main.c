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
 
    int count = 0;
    while(1) {

        city = (char *)malloc(sizeof(char) * NAMESIZE);
        assert(city);


        if (scanf("%s", city) == 1 )
        {
            count++; // counting the number of inputs

            //checking the length of input
            if(strlen(city) > NAMESIZE)
            {
                printf("Maximum input size is %d \n", NAMESIZE);
                return -1;
            }

            if(!strcmp(city, "END")) break; // break out of loop
            assert(!insert_sorted(city, &list));
        } 
    }
    //checking the number of inputs
    if (count > MAX + 1) 
    {
        printf("Maximum input count is %d \n", MAX);
        return -1;
    }
    


    //delete_list(&list);   //function for delete the list

    printf("The way you took: "); 
    while(remove_list((void **)&city, &list)) 
        printf("%s -> ", city);
    printf("Thats it\n");
    return 0;
}

