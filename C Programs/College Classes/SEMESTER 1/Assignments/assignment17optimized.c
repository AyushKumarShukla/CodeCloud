/*TEST FILE*/
/*Write a program in C to print the elements of Pascal triangle (take number of lines from user):*/

#include<stdio.h>
#include<math.h>

int fact(int num)
{
    int product=1,i;
    for(i=num;i>=1;i--)
    {
        product = product*i;
    }
    return product;
}

int main(void)
{
    int num,i,row=0,ele=0,item;
    printf("Enter the number of elements of the Pascal's Triangle you need: ");
    scanf("%d",&num);
 
    for(i=1;i<=num;i++) // run num number of time
    {
        if(ele==row) // if the row and element become equal
        {
            item = fact(row)/(fact(ele)*fact(row-ele));
            printf("%d ",item);// calculate and print the value for that iteration
            ele=0; // set element to 0 for next row
            row++; // increment row by 1 for next row
            printf("\n");
        }
        
        item = fact(row)/(fact(ele)*fact(row-ele)); // finding nCr
        ele++;
        printf("%d ",item);
    }
	return 0;
}

/*The indexing has been considered to begin from 0th row and 0th element and a new row is formed when the value of element becomes equal
to that of row,till then, the value of element is incremented by 1*/
