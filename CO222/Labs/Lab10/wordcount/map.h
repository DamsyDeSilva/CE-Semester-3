#ifndef __H__MAP__
#define __H__MAP__


/* We want to count the number of time a string appear in 
 * So, each node has a string and a count of how may times 
 * the string appeared. 
 */ 
struct node {
  int count;
  char * val;
  struct node * next; 
};

typedef struct node node_t;


/* We create a linked list of nodes. Head is defined 
 * as another sturuct for which I can get a pointer
 */

struct list {
  node_t *head;
};

typedef struct list * list_t; 


/* Interface for using the linked list */

// create a new empty list
list_t create_list(void); 

// return 1 if the list is empty. 0 otherwise. 
int isEmpty(list_t list); 

// add the new value to the list. Return 1 if the list is modified 0 otherwise
// If the value is already there, do not add a new node; simply increase the
// word count; this case is considered as not modified list. 
// NOTE: THE VALUE SHOULD BE COPIED TO A NEW STRING.
int add(list_t list, char *value); 

// remove the first element in the list. Return NULL on empty list
// NOTE: return the least element in the list  
node_t * remove_list(list_t list);






#endif
