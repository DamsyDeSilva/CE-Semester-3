#include <stdio.h>
#include <map.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char newBuff[100];  //to hold the word after modification

int strfree(char str[]);    //function to remove unwanted characters in the string

int main(int argc , char* argv[])
{
    list_t list = create_list();

    char * filepath = argv[1];
    char buff[100];

    FILE *fp = fopen(filepath, "r");

    if (!fp) return -1;

    while(1) {
        //printf("Enter name (QUIT to exit): ");
        int c = fscanf(fp, "%s", buff);
        if(c == EOF) break;
        
        //if modification is successful then add to the list
        if (strfree(buff)){
            add(list, newBuff);
        }    
    }

    while(!isEmpty(list)) {
        node_t * tmp = remove_list(list);
        printf("%s:%d\n",tmp->val, tmp->count);
    }

    return 0; 
}

int strfree(char str[])
{
    // initializing
    for (int h = 0; h < 100; h++){
        newBuff[h] = 0;
    }

    //counting non alphabatic characters at the begining
    int i = 0;
    while(isalpha(str[i]) == 0){
        i++;
    }

    //counting non alphabatic characters at the end
    int j = strlen(str);
    while(isalpha(str[j]) == 0){
        j--;
    }


    for (int k = 0; k < j-i+1; k++){
        newBuff[k] = str[k + i];
    }

    //if modified new string is null return 0 otherwise 1
    if (strlen(newBuff) == 0) return 0;

    return 1;
}

