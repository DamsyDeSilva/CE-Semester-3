struct node { 
  void *data; // should work with any data
  struct node *next;
};

typedef struct node node_t; // node_t is now a type and is "struct node"
typedef node_t * list_t;    // list is address to first node 

/**************** New work *************************/
/* add the given data item to the tail of the list */
int tail_insert(void *data, list_t *list);

/* add the given item to the correct position in the list */
int insert_sorted(void *data, list_t *list);

/* delete all memory used by the list */
void delete_list(list_t *list); 

/******* From previous implementation ***********/
/* add the given data to head of the given list */
int head_insert(void *data, list_t *list);


/* remove head from the list
 * store removed value in data and return 1 if removed
 */
int remove_list(void **data, list_t *list); 




