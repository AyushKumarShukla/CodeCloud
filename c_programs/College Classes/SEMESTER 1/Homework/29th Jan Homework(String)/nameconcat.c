/*WAP in C to take first name and last name of a person,concatenate the two 
strings and save it in a single array named full name*/

#include<stdio.h>
#include<string.h>

int main(void)
{
    char fname[20],lname[20],full_name[39]="";

    printf("Enter your first name: ");
    fgets(fname,20,stdin);  //Taking first name

    fname[strlen(fname)-1]='\0'; // to eliminate the line feed
    
    printf("Enter your last name: ");
    fgets(lname,20,stdin);  //Taking last name

    strcat(full_name,fname); // Concatenating empty string with first name
    strcat(full_name," ");  // Concatenating full name with a blank space
    strcat(full_name,lname); // Concatenating above result with last name
    printf("Your Full Name -> %s",full_name);

    return 0;
}