#include<stdio.h>
#include<ctype.h>
int countwords(const char*str)
{
    int count=0;
    int inword=0;
    while(*str){
        if(!isspace(*str))
        {
            if(!inword)
            {
                inword=1;
                count++;
            }
        }
        else{
            inword=0;
        }
        str++;
    }
    return count;
}
int main()
{
    char input[100];
    printf("enter a string:");
    scanf(" %[^\n]",input);
    int wordcount =countwords(input);
    printf("no of words :%d\n",wordcount);
    return 0;
}