#include<stdio.h>
void flip(int n,int mat[n][n],int m, int s)
{
    if(m>=0 && m<n && s>=0 && s<n)
    {
        mat[m][s]=1-mat[m][s];
    }
}
void inMat(int n,int mat[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            mat[i][j]=0;
        }
    }
}
void disMat(int n, int mat[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d",mat[i][j]);
        }
        printf("\n");
    }
}
void hormat(int n, int mat[n][n])
{
    for(int i=0;i<n;i++)
    {
        int start=0;
        int end=n-1;
        while(start<end)
        {
            int temp=mat[i][start];
            mat[i][start]=mat[i][end];
            mat[i][end]=temp;
            start++;
            end--;
        }
    }
}
void rev(int n,int mat[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int temp=mat[i][j];
            mat[i][j]=mat[j][i];
            mat[j][i]=temp;
        }
    }
    for(int i=0;i<n;i++)
    {
        int start=0;
        int end=n-1;
        while(start<end)
        {
            int temp=mat[start][i];
            mat[start][i]=mat[end][i];
            mat[end][i]=temp;
            start++;
            end--;
        }
    }

}
int main()
{
    int n;
    scanf("%d",&n);
    int mat[100][100];
    inMat(n,mat);
    disMat(n,mat);
    int no;
    scanf("%d",&no);
    for(int i=0;i<no;i++)
    {
        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
    int m;
    scanf("%d",&m);
    int s;
    scanf("%d",&s);
    flip(n,mat,m,s);
    disMat(n,mat);
        }
        else if(ch==2)
        {
    hormat(n,mat);
    disMat(n,mat);
        }
        else if(ch==3)
        {
    rev(n,mat);
    disMat(n,mat);
        }
        else{
            printf("Invalid choice");
        }
    }
    return 0;
}