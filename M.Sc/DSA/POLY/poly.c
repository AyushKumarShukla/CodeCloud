/*Program for Polynomial computations using arrays as a data structure*/
#include<stdio.h>
#include<stdbool.h>

typedef struct Term{
    int coeff;
    int exp;
}Term;

void showMenu()
{
    printf("MENU:\n");
    printf("1.Input Polynomial A\n");
    printf("2.Input Polynomial B\n");
    printf("3.Show Polynomial A\n");
    printf("4.Show Polynomial A\n");
    printf("5.Compute A+B\n");
    printf("6.Compute A-B\n");
    printf("7.Compute A*B\n");
    printf("8.Compute A'\n");
}

void inputPolyA(){
}

void inputPolyB(){
}

void showPolyA(){
}

void showPolyB(){
}

int addPoly(){
}

int subPoly(){
}

int mulPoly(){
}

void diffPolyA(){
}

int main(void)
{
    int ch=0;
    int res;
    int MAX_SIZE = 100; 

    Term polyA[MAX_SIZE];
    Term polyB[MAX_SIZE];

    while(true){
        showMenu();
        printf("Select an Option:\t");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                inputPolyA();
                break;
            case 2:
                inputPolyB();
                break;
            case 3:
                showPolyA();
                break;
            case 4:
                showPolyB();
                break;
            case 5:
                res = addPoly();
                break;
            case 6:
                res = subPoly();
                break;
            case 7:
                res = mulPoly();
                break;
            case 8:
                diffPolyA();
                break;
            default:
                printf("Invalid Choice... Please Select From One Of The Options!\n");
        }
    }
    return 0;
}
