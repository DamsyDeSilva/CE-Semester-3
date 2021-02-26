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

  
  
