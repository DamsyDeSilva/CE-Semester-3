#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <map.h>
#include <map.h>


list_t create_list()
{
  list_t list = (list_t)malloc(sizeof(struct list));
  if(list) list -> head = NULL;
  return list;
}

int isEmpty(list_t list)
{
#ifdef DEBUG
  assert(list); 
#endif
  if(list) return ((list -> head) == NULL);
  else     return 0;
}


int add(list_t list, char *val)
{
    #ifdef DEBUG
        assert(list);
        assert(val); 
    #endif

    // This function should be implemented during the class itself
    // show it to an instructor before leaving the class.

    char * temp = strdup(val);   //creating a duplicate of val

    node_t * new = (node_t *)malloc(sizeof(node_t));    //allocating temp memory size of node_t 
    if (!new) return -1;

    //store the data in the temp node
    new -> val = strdup(val);
    new -> count = 1;
    new -> next = NULL;

    // if no list is there; creating the first node 
    if (list -> head == NULL)
    {
        list -> head = new; 
        return 0;
    }   

    //when the data should be added to the head
    if ((strcmp((list -> head) -> val , temp)) > 0)
    {
        new -> next = list -> head;
        list -> head  = new;
        return 0;
    }
    
    //when the count should be increment at the head
    if (strcmp((list -> head) -> val , temp) == 0)
    {
        ((list -> head) -> count)++;

        //new node won't need anymore 
        free(new ->  val);
        free(new -> next);
        free(new);

        return 0;
    }

    node_t * ref1 = list -> head;    //reference to the first node
    node_t * ref2 = list -> head;    //reference to the next node

    while(ref2 -> next)
    {
        ref2 = ref1 -> next;

        // when the string is in the list ; count should be creased by 1
        if (strcmp(ref2 -> val , temp) == 0)
        {
            (ref2 -> count)++;

            //new node won't need anymore 
            free(new ->  val);
            free(new -> next);
            free(new);

            return 0;
        }

        // adding new node to the sorted array
        if ((strcmp(ref2 -> val , temp)) > 0) 
        {
            ref1 -> next = new;
            new -> next = ref2;
            return 0;
        }
        ref1 = ref1 -> next;
    } 

    ref1 -> next = new;    //adding to tail
    return 0; 
}


node_t * remove_list(list_t list)
{  
    #ifdef DEBUG
        assert(list); 
    #endif

    node_t * tmp = list -> head;
    list -> head = (list -> head) -> next;
    return tmp;
}

  
  
