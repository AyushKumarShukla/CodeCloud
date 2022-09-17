#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//function to solve for present operator and operands
int solve(int x,char opr,int y)
{
    int res;
    if(opr=='*')
        res = x*y;
    else if(opr=='/') 
    {
        if(y==0)
        {
            printf("Divide by zero error...please retry");
            exit(1);
        }
        res = x/y;
    }
    else if(opr=='+')
        res = x+y;
    else
        res = x-y;
    return res;
}
//function to push elements into stack
void push(int *stack,int *top,int opr)
{
    (*top)++;
    stack[*top]=opr;
}
//function to pop elements from stack
int pop(int *stack,int *top)
{
    int ele;
    if(*top==-1)
        printf("Empty Stack");
    else
    {
        ele=stack[*top];
        (*top)--;
    }
    return ele;
}
//function to evaluate a given postfix expression
int evaluate(char *expr)
{
    int i=0,count=0,opr=0,x,y,res,stack[100],top=-1;
    while(expr[i]!='\0') //while the end of string is not reached
    {
        if(expr[i]>47 && expr[i]<58) //if element at i is an operand
        {
            while(expr[i]!=' ') //while a space is not encountered
            {
                opr=(opr*pow(10,count))+(expr[i]-48); //calculate operand
                count++;i++;
            }
            push(stack,&top,opr); //push operand into stack
            opr=0;count=0;//reset opr and count to zero for next iteration
        }
        else //an operator is encountered
        {
            while(expr[i]!=' ' && expr[i]!='\0')
            {
                if(expr[i]>41 && expr[i]<48) //if element at i is operator
                {
                    y=pop(stack,&top); //pop second operand
                    x=pop(stack,&top); //pop first operand
                    res=solve(x,expr[i],y); //solve
                    push(stack,&top,res); //push result into stack
                    i++;
                }
            }
        } 
        if(expr[i]=='\0') //if end of the string is reached 
            break;
        else
            i++;
    }
    res=pop(stack,&top); //pop final result from the stack
    return res;
}

int main(void)
{
    char expr[100];
    int res;
    printf("Enter the postfix expression\nPlease separate adjacent numbers and operators using spaces:\n");
    gets(expr);
    printf("Entered expression: ");
    puts(expr);
    res=evaluate(expr);
    printf("Result of expression: %d",res);
    return 0;
}

