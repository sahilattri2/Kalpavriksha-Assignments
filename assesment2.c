#include<stdio.h>
#include<string.h>

int isPrime(int num)
{
    if(num<2) return 0;
    for(int i=2;i*i<=num;i++)
    {
        if(num%i==0) return 0;
    }
    return 1;

}
char shift(char c,int k)
{
    if(!isalpha(c)) return c;
    char base=islower(c)?'a':'A';
    return base+(c-base+k)%26;
}
int main()
{
    char str[1000];
    scanf(" %[^\n]%*c",str);
    int k;
    scanf("%d",&k);
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        if(isPrime(i))
        {
           str[i]=shift(str[i],k);

        }
    }
printf("modified: %s\n",str);

}