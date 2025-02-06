#include <stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int r;
    int f;
    int *arr;
};
void enqueue(struct queue*q,int val)
{
    if (q->r == q->size - 1)
       printf("Overflow \n");
    else
    {
        if (q->f == - 1)
        q->f = 0;
        q->r = q->r + 1;
        q->arr[q->r] = val;
    }
} 
 
void dequeue(struct queue*q)
{
    if (q->f == - 1 || q->f > q->r)
    {
        printf("Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted : %d\n", q->arr[q->r]);
        q->r = q->r - 1;
    }
} 
 
void show(struct queue*q)
{
    if (q->f == - 1)
        printf("Empty Queue \n");
    else
    {
        for (int i = q->f; i <= q->r; i++)
            printf("%d ", q->arr[i]);
        printf("\n");
    }
}
int main()
{
    struct queue*q=(struct queue*)malloc(sizeof(struct queue));
    q->size=80;
    q->r=-1;
    q->f=-1;
    q->arr=(int *)malloc(sizeof(int));
    enqueue(q,7);
    enqueue(q,6);
    enqueue(q,5);
    dequeue(q);
    show(q);
    
} 
 
