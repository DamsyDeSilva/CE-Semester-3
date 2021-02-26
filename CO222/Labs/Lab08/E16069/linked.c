#include <linked.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/********************************
 * add to head. Return 0 on success
 ********************************/
int head_insert(void *data, list_t *list) 
{
    list_t temp;
    temp = (list_t )malloc(sizeof(node_t));

    if (temp)
    {
        temp -> data = data;    // assign data to node
        temp -> next = *list;   // Link the node with the previous node 
        (*list) = temp;
        
        return 0;

    }

  return -1;
}


/********************************
 * Remove
 * Store value in data, free node and return 1
 ********************************/
int remove_list(void **data, list_t *list)
{
  // should free the node as well as the data stored in the node. 
    if ((*list) != NULL)
    {
        free(*data);    //free the data stored in the node
        list_t temp = *list;
        
        (*data) = (*list) ->data;
        (*list) = (*list) -> next;
        
        free(temp);     //free the node

        return 1;
    }
  return 0; 
}



