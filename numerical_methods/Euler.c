#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float eq(float x,float y,float step)
{
                    //start expression at this position below
    float expr=(y-x)/(y+x);
    return (y + step*(expr));
}

float Euler(float initx,float inity,float finx,float step)
{
    int k=0;
    float i,res=0;
    res=inity;
    for(i=initx;(i+step)<=finx;i=i+step)
    {
        res=eq(i,res,step);
        //printf("i=%f",(i+step));
        printf("Y%d\t= Y(%.4f)\t= %.4f\n",++k,(i+step),res);
    }
    printf("Y(%.4f)=%.4f\n",finx,res);
}

int main(void)
{
    float initx,inity,finx,step;
    printf("To solve a differential equation using Euler's method: ");
    printf("\nEnter the initial value of x: ");
    scanf("%f",&initx);
    printf("Enter the initial value of y: ");
    scanf("%f",&inity);
    printf("Enter the final value of x: ");
    scanf("%f",&finx);
    printf("Enter the step length: ");
    scanf("%f",&step);
    Euler(initx,inity,finx,step);

}
