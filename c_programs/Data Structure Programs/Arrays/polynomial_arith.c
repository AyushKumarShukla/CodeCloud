/*progam to implement polynomial arithmetic*/

#include<stdio.h>
#include<stdlib.h>

typedef struct term
{
    int coeff;
    int pow;
}term;

int count=0;

void getpoly(term* poly,int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        printf("Enter Coefficient: ");
        scanf("%d",&poly[i].coeff);
        printf("Enter Exponent: ");
        scanf("%d",&poly[i].pow);
    }
}
void dispoly(term *poly,int len)
{
    int i;
    for(i=0;i<len;i++)
        if(poly[i].coeff!=0)
            printf("%+dx^%d ",poly[i].coeff,poly[i].pow);
}

term* poly_add(term *poly1,int size1,term *poly2,int size2)
{
    term *res=(term*)malloc((size1+size2)*sizeof(term));
    int i=0,j=0,k=0;
    while(i<size1 && j<size2)
    {
        if(poly1[i].pow==poly2[j].pow)
        {
            res[k].coeff = (poly1[i].coeff) + (poly2[j].coeff);
            res[k].pow = poly1[i].pow;
            i++;j++;k++;
        }
        else
        {
            if(poly1[i].pow>poly2[j].pow)
            {
                res[k].coeff = poly1[i].coeff;
                res[k].pow = poly1[i].pow;
                i++;k++;
            }
            else
            {
                res[k].coeff = poly2[j].coeff;
                res[k].pow = poly2[j].pow;
                j++;k++;
            }
        }
    }
    while(i<size1)
    {
        res[k].coeff=poly1[i].coeff;
        res[k].pow=poly1[i].pow;
        i++;k++;
    }
    while(j<size2)
    {
        res[k].coeff=poly2[j].coeff;
        res[k].pow=poly2[j].pow;
        j++;k++;
    }
    count=k;
    return res; 
}

term* poly_sub(term *poly1,int size1,term *poly2,int size2)
{
    term *res=(term*)malloc((size1+size2)*sizeof(term));
    int i=0,j=0,k=0;
    while(i<size1 && j<size2)
    {
        if(poly1[i].pow==poly2[j].pow)
        {
            res[k].coeff = (poly1[i].coeff) - (poly2[j].coeff);
            res[k].pow = poly1[i].pow;
            i++;j++;k++;
        }
        else
        {
            if(poly1[i].pow>poly2[j].pow)
            {
                res[k].coeff = poly1[i].coeff;
                res[k].pow = poly1[i].pow;
                i++;k++;
            }
            else
            {
                res[k].coeff = poly2[j].coeff;
                res[k].pow = poly2[j].pow;
                j++;k++;
            }
        }
    }
    while(i<size1)
    {
        res[k].coeff=poly1[i].coeff;
        res[k].pow=poly1[i].pow;
        i++;k++;
    }
    while(j<size2)
    {
        res[k].coeff=poly2[j].coeff;
        res[k].pow=poly2[j].pow;
        j++;k++;
    }
    count=k;
    return res; 
}

term* poly_mult(term *poly1,int size1,term *poly2,int size2)
{
    term *res=(term*)malloc((size1*size2)*sizeof(term));
    int i,j,k=0;
    for(i=0;i<size1;i++)
        for(j=0;j<size2;j++)
            {
                res[k].coeff=(poly1[i].coeff)*(poly2[j].coeff);
                res[k].pow=(poly1[i].pow)+(poly2[j].pow);
                k++;
            }
    count=k;
    return res;
}

void validate(term *poly,int size)
{
    int i;
    for(i=0;i<size-1;i++)
    {
        if(poly[i].pow<poly[i+1].pow)
        {
            printf("The terms must be in decending order of their exponents\nPlease Retry");
            exit(1);
        }
    }
}

int main(void)
{
    int size1,size2,ch;
    term *poly1,*poly2,*res;
    printf("To perfrom arithmetic operations on two polynomials \n");
    printf("Enter the number of terms in first polynomial: ");
    scanf("%d",&size1);
    printf("Enter the number of terms in second polynomial: ");
    scanf("%d",&size2);
    poly1=(term*)malloc(size1*sizeof(term));
    poly2=(term*)malloc(size2*sizeof(term));
    printf("\nPlease enter terms in decending order of their exponents: \n");
    printf("For the first polynomial: \n");
    getpoly(poly1,size1);
    validate(poly1,size1);
    printf("For the second polynomial: \n");
    getpoly(poly2,size2);
    validate(poly2,size2);
    printf("First polynomial: ");
    dispoly(poly1,size1);
    printf("\nSecond polynomial: ");
    dispoly(poly2,size2);
    printf("\nMENU:\n");
    printf("1.Addition\n2.Subtraction\n3.Multiplication");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
                res=poly_add(poly1,size1,poly2,size2);
                printf("SUM: ");
                dispoly(res,count);
                break;
        case 2:
                res=poly_sub(poly1,size1,poly2,size2);
                printf("DIFFERENCE: ");
                dispoly(res,count);
                break;
        case 3:
                res=poly_mult(poly1,size1,poly2,size2);
                printf("PRODUCT: ");
                dispoly(res,count);
                break;
        free(poly1);free(poly2);free(res);
    }
}

