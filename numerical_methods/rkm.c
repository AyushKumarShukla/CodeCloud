#include <stdio.h>
#include<stdlib.h>
#include<math.h>

float f(float x, float y)
{
    return x*y;

}
void secondorder(float x, float y, float step, float finx)
{
    float k1, k2, k;
    while(x < finx)
    {
        k1 = step*f(x,y);
        k2 = step*f(x + step,y + k1);
        k = 0.5*(k1+k2);
        y = y + k;
        x = x + step;
        printf("F(%f)=%f\n", x, y);
    }
}

void fourthorder(float x, float y, float step, float finx)
{
    float k1, k2, k3, k4,k;
    while(x < finx)
    {
        k1 = step*f(x, y);
        k2 = step*f(x + step/2, y + k1/2);
        k3 = step*f(x + step/2, y + k2/2);
        k4 = step*f(x + step, y + k3);
        k = (k1 + 2*k2 + 2*k3 + k4)/6;
        y = y+k;
        x = x + step;
        printf("F(%f)=%f\n", x, y);
    }
}



int main()
{
    float initx, inity, step, finx;
    int ch;
    printf("To solve the differential equation dy/dx = xy, using Runge-Kutta Methods:\n");
    printf("Enter initial values of x and y: ");
    scanf("%f %f", &initx, &inity);
    printf("Enter final value of x: ");
    scanf("%f", &finx);
    printf("Enter step length: ");
    scanf("%f", &step);
    printf("MENU:\n1. Runge-Kutta Second Order Method\n2. Runge-Kutta Fourth Order Method\n");
    printf("Enter a choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
    	case 1:
    		secondorder(initx,inity,step,finx);
    		break;
    	case 2:
    		fourthorder(initx,inity,step,finx);
    		break;
    	default:
    		printf("Invalid Choice");
    }
    return 0;
}


