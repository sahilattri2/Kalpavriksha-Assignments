#include<stdio.h>
#include<string.h>
void removeDuplicates(char *str)
{
    int len=strlen(str);
    int seen[256]={0};
    int index=0;
    for(int i=0;i<len;i++)
    {
        if(!seen[str[i]])
        {
            seen[str[i]]=1;
            str[index++]=str[i];

        }
    }
    str[index]='\0';
}
int main()
{
    char str[100];
    printf("Enter a string:");
    scanf("%99s", str);
    removeDuplicates(str);
    printf("Output:%s", str);
}