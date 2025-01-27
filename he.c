#include<stdio.h>
#include<string.h>
#include<ctype.h>
void removeDuplicates(char str[])
{
    int seen[256]={0};
    int i,j=0;
    for(int i=0;str[i]!='\0';i++)
    {
        if(!seen[str[i]])
        {
            seen[str[i]]=1;
            str[j++]=str[i];
        }
    }
    str[j]='\0';
}
int main() {
    char str[] = "programming";
    removeDuplicates(str);
    printf("Without duplicates: %s\n", str);
    return 0;
}