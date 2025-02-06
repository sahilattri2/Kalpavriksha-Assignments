/*{add(\"Hello\")},,{add(\"World\")},,{add(\"This is a test\")},,{undo()},,{redo()},,{add(\"Stack Implementation\")},,{undo()},,{undo()},,{redo()},,{add(\"New Edit\")},,{edit(\"World\", \"Universe\")},,{undo()},,{redo()},,{clear()},,{undo()}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char str[100];
    struct Node* next;
}node;
struct stack{
    node* top;
};


int main()
{
    char input[]="{add(\"Hello\")},,{add(\"World\")},,{add(\"This is a test\")},,{undo()},,{redo()},,{add(\"Stack Implementation\")},,{undo()},,{undo()},,{redo()},,{add(\"New Edit\")},,{printhistory()},,{undo()},,{redo()},,{clear()},,{undo()}";
    char *str=input;
    char *token=strtok(str,"{}");
    char op[10];
    char text[100];
    while(token!=NULL)
    {
        if(*token==' ')
        token++;
        if(strcmp(token,"add")==3)
        {
            printf("adding");
            sscanf(token," add(\"%[^\"]\")",text);
        }
        else if(strcmp(token,"undo")==4)
        {
            printf("undo");
        }
        else if(strcmp(token,"redo")==4)
        {
            printf("redo");
        }
        else if(strcmp(token,"edit")==4)
        {
            printf("edit");
        }
        else if (strcmp(token,"clear")==5)
        {
            printf("clear");
        }
        token= strtok(NULL,"{}");
        token= strtok(NULL,"{}");

    }
}