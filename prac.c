/*create a structure which have a string and a 2D array
dynamic memory allocation
read the value and print it*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct prac{
    char *str;
    int **arr;
    int r,c;
};
void readandprint(struct prac *s)
{
    printf("Enter the string");
    scanf("%s",s->str);
    printf("%s",s->str);
    printf("enter the no. of rows");
    scanf("%d",&s->r);
    printf("enter the no. of cols");
    scanf("%d",&s->c);

    s->arr = (int **)malloc(s->r * sizeof(int *));
    for (int i = 0; i < s->r; i++) 
    {
        s->arr[i] = (int *)malloc(s->c * sizeof(int));
    }
    for(int i=0;i<s->r;i++)
    {
        for(int j=0;j<s->c;j++)
        {
            scanf("%d",&s->arr[i][j]);
        }
    }
    for(int i=0;i<s->r;i++)
    {
        for(int j=0;j<s->c;j++)
        {
            printf("%d",s->arr[i][j]);
        }
    }
}
int main()
{
    struct prac *s= (struct prac*)malloc(sizeof(struct prac));
    s->str=(char*)malloc(100* sizeof(char));
    readandprint(&s);


}