#include <stdio.h>
#include <string.h>


void reverse(char str[],int start,int end)
{
    while(start<end)
    {
        char temp =str[start];
        str[start++]=str[end];
        str[end--]=temp;
    }
}
void revw(char str[])
{
    int start=0;
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        if(str[i]==' '|| str=='\0')
        {
            reverse(str,start,i-1);
            start=i+1;
        }
    }
}
int main() {
    char str[] = "hello world program";
    revw(str);
    printf("Reversed words: %s\n", str);
    return 0;
}