#include <stdio.h>
#include <map.h>
#include <string.h>

int main()
{
  list_t list = create_list();

  char buff[100];

  while(1) {
    printf("Enter name (QUIT to exit): ");
    scanf("%s", buff);
    if(strcmp("QUIT", buff) == 0) break;
    add(list, buff);
  }

  while(!isEmpty(list)) {
    node_t * tmp = remove_list(list);
    printf("%s:%d\n",tmp->val, tmp->count);
  }

  return 0; 
}
