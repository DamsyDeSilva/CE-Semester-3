struct node { 
  void *data; // should work with any data
  struct node *next;
};

typedef struct node node_t; // node_t is now a type and is "struct node"
typedef node_t * list_t;    // list is address to first node 


/* add the given data to head of the given list */
int head_insert(void *data, list_t *list); 

/* remove head from the list
 * store removed value in data and return 1 if removed
 */
int remove_list(void **data, list_t *list); 




