#include <linked.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/********************************
 * add to sorted list. Return 0 on success
 ********************************/
int insert_sorted(void *data, list_t *list)
{
    list_t temp = (list_t) malloc (sizeof(node_t));  //allocating temp memory size of node_t 
    if (!temp) return -1;

    //store the data in the temp node
    temp -> data = data;    
    temp -> next = NULL;

    if (*list == NULL)
    {
        (*list) = temp; //creating the first node 
        return 0;
    }   
        
    else 
    {
        //when the data should be added to the head
        if ((strcmp((*list) -> data , temp -> data)) > 0)
        {
            temp -> next = (*list);
            (*list) = temp;
            return 0;
        }

        list_t ref1 = *list;    //reference to the first node
        list_t ref2 = *list;    //reference to the next node

        while (ref2 -> next)
        {
            ref2 = ref1 -> next;
            
            //checking for the correct position
            if ((strcmp(ref2 -> data , temp -> data)) > 0) 
            {
                
                ref1 -> next = temp;
                temp -> next = ref2;
                return 0;
            }
            ref1 = ref1 -> next;    
        }
        ref1 -> next = temp;  
        return 0;  
    }
    
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
        
        (*data) = (*list) -> data;
        (*list) = (*list) -> next;
        
        free(temp);     //free the node

        return 1;
    }
  return 0; 
}

//delete all memory used by the list 
void delete_list(list_t *list)
{
    while (list != NULL)
    {
        list_t temp = *list;        
        (*list) = (*list) -> next;  //pass the list poiner to the next node
        free(temp -> data);         //free the data
        free(temp);                 //free the node
    }

}

// add to head. Return 0 on success
int head_insert(void *data, list_t *list) 
{
    list_t temp = (list_t )malloc(sizeof(node_t));  //allocating temp memory size of node_t 

    if (temp)
    {
        temp -> data = data;    // assign data to node
        temp -> next = *list;   // Link the node with the previous node 
        (*list) = temp;
        
        return 0;
    }
  return -1;
}

// add to tail. Return 0 on success
int tail_insert(void *data, list_t *list)
{
    list_t temp = (list_t)malloc(sizeof(node_t));   //allocating temp memory size of node_t 

    if(!temp) return -1;
    
    //store the data in the temp node
    temp -> data = data;
    temp -> data = NULL;

    if(*list == NULL)
    {
        *list = temp;   //if there is no previous list start with the temp
    } 
    else
    {
        list_t last = *list;

        //pointing to the existing list
        while (last -> next != NULL)
            last = last -> next;

        last -> next = temp;    //add the temp  at tail the tail of the existing list
    }

    return 0;
}

