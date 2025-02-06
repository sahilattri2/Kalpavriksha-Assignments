#include<stdio.h>
#include<string.h>

char stack[50][50];
int top = -1;

void clear_stack() {
    top = -1 ;
}

void push(char *s)
{
    strcpy(stack[++top], s) ;
}

char* pop()
{
    return stack[top--];
}


int is_operator(char x)
{
    if(x == '+' ||x == '-'||x == '*'||x == '/'){
        return 1;
    }
    else{
        return 0;
    }
}



void convert(char *exp)
{
    clear_stack() ;

    int i,l;
    char op1[50],op2[50];

    l = strlen(exp);

    
    for(i = l - 1; i >= 0; i--)
    {
       
        if (is_operator(exp[i]))
        {
            
            strcpy(op1, pop()) ;
            strcpy(op2, pop()) ;;
            strcat(op1 , strcat(op2 , (char[2]) {(char)exp[i], '\0'})) ;
          
            push(op1);
        }
        else
        {
            push((char[2]){(char)exp[i], '\0'});
        }
    }
    printf("%s\n",stack[top]);
}


int main()
{
    convert("*-A/BC-/AKL");
    convert("+ab");
    convert("*+abc");
    convert("*a+bc");
    convert("+/ab/cd");
    convert("*+ab+cd");
    convert("-*+abcd");
    return 0;
}