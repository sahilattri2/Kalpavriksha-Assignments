#include<stdio.h>
#include<string.h>
#include<ctype.h>
int findsub(const char*str, const char*substr)
{
    int len1=strlen(str);
    int len2=strlen(substr);
    if(len2==0)
    return 0;
for(int i=0;i<len1-len2+1;i++)
{
    int j;
    for(j=0;j<len2;j++)
    {
        if(str[i+j]!=substr[j])
        {
            break;
        }
    }
    if(j==len2){
        return i;
    }
}
return -1;
    // char *result=strstr(str,substr);
    // if(result!=NULL)
    // return result-str;
    // else
    // return -1;
}
int main()
{
    char str[100],substr[100];
    printf("enter a string:");
    scanf(" %[^\n]",str);
    printf("enter a substring:");
    scanf(" %[^\n]",substr);
    int result = findsub(str, substr);
    if(result!=-1)
    printf("index :%d\n",result);
    else
    printf("not found\n");
    return 0;
}