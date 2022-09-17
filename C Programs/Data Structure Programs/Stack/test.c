#include<stdio.h>
#include<stdlib.h>
#include<math.h>



int solve(int x,char opr,int y)
{
    int res;
    if(opr=='*')
        res = x*y;
    else if(opr=='/')
        res = x/y;
    else if(opr=='+')
        res = x+y;
    else
        res = x-y;
    return res;
}

void push(int *stack,int *top,int opr)
{
    (*top)++;
    stack[*top]=opr;
}

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
void disp(int *stack,int *top)
{
    int i;
    for(i=0;i<=(*top);i++)
        printf("%d ",stack[i]);
}
int evaluate(char *expr)
{
    int i=0,count=0,opr=0,x,y,res,stack[100],top=-1;
    while(expr[i]!='\0')
    {
        if(expr[i]>47 && expr[i]<58)
        {
            while(expr[i]!=' ')
            {
                opr=(opr*pow(10,count))+(expr[i]-48);
                count++;i++;
            }
            printf("OPR:%d ",opr);
            push(stack,&top,opr);
            opr=0;count=0;
            disp(stack,&top);
        }
        else
        {
            while(expr[i]!=' ' && expr[i]!='\0') //not getting executed
            {
                if(expr[i]>41 && expr[i]<48)
                {
                    y=pop(stack,&top);
                    x=pop(stack,&top);
                    printf("\n x:%d y:%d",x,y);
                    res=solve(x,expr[i],y);
                    printf("\nres: %d",res);
                    push(stack,&top,res);
                    printf("\nOPERATOR STACK: ");
                    disp(stack,&top);
                    i++;
                }
            }
        }
        if(expr[i]=='\0')
            break;
        else
            i++;
    }
    res=pop(stack,&top);
    return res;
}

int main(void)
{
    char expr[100],inp;
    int res,i=0;
    printf("Enter the postfix expression\nPlease separate adjacent numbers and operators using spaces:\n");
    while(1)
    {
        inp=getchar();
        if(inp=='\n')
        {
            expr[i+1]='\0';
            break;
        }
        expr[i]=inp;
        i++;
    }
    printf("Entered expression: ");
    puts(expr);
    res=evaluate(expr);
    printf("Result of expression: %d",res);
    return 0;

}