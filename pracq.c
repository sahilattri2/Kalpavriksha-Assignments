#include <stdio.h>
# define SIZE 100
int inp_arr[SIZE];
int Rear = - 1;
int Front = - 1;
void enqueue(int insert_item)
{
    if (Rear == SIZE - 1)
       printf("Overflow \n");
    else
    {
        if (Front == - 1)
        Front = 0;
        Rear = Rear + 1;
        inp_arr[Rear] = insert_item;
    }
} 
 
void dequeue()
{
    if (Front == - 1 || Front > Rear)
    {
        printf("Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted : %d\n", inp_arr[Front]);
        Front = Front + 1;
    }
} 
 
void show()
{
    if (Front == - 1)
        printf("Empty Queue \n");
    else
    {
        for (int i = Front; i <= Rear; i++)
            printf("%d ", inp_arr[i]);
        printf("\n");
    }
}
int main()
{
    enqueue(5);
    enqueue(6);
    enqueue(7);
    dequeue();
    show();
    
} 
 
