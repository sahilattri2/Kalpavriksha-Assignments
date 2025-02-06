#include<stdio.h>
#include<string.h>
#include<stdlib.h>


// void converttotemp(char* temp) {
//     int num;
//     char tempu[20];
//     char new[20];
   
//     sscanf(temp, "%s(%s)", new, tempu);

//     if (strcmp(new, "add") == 0) {
//         printf("added:%s",tempu);
//     } else if (strcmp(new, "view") == 0) {
//         printf("%s",tempu);
//     }
// }

// int main() {
//     char input[] = "{add(Document1,5)},{add(Document2,10)},{view()},{update(Document1,6)},{view()},{process()},{view()},{add(Document3,12)},{process()},{view()}";
//     char *token = strtok(input, "{}");
 
//     while (token != NULL) {
//         printf("%s\n",token);
//         // converttotemp(token);
//         token =strtok(NULL, "{}");
//         token = strtok(NULL, "{}");
//     }
 
//     return 0;
// }

typedef struct dict{
    char key[10];
    char val[10];
}dict;
int main()
{
    dict *d = (dict*)malloc(sizeof(dict));
    int i = 0;
    int top = -1;
    char strp[] = "<name>Shubh</name><age>23</age><city>Bangalore</city>";
    char *ptr = strp;
    char *token = strtok(ptr, "></");
    while (token != NULL)
    {

        // i++;
        //  printf("%s\n", token);
         sscanf(token," %s",d->key);
         token = strtok(NULL,"></");
        //  printf("%s\n", token);
         sscanf(token,"%s",d->val);
         token = strtok(NULL,"></");
         token = strtok(NULL,"></");
         printf("Key %s value %s\n",d->key,d->val);

        // if (i % 2 == 1)
        //     sscanf(token, "%s", d.key);
        // else
        //     sscanf(token, "%s", d.val);
        // if (i % 2 == 0)
        //     printf("%s----%s\n", d.key, d.val);
        // token = strtok(NULL, "></");
        // if (i % 2 == 0)
        //     token = strtok(NULL, "></");
    }
 

    return 0;
}