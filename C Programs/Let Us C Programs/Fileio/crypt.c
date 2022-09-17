#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *filename) {
    FILE *fp, *ft;
    int key = 1;
    int ch=0;
    fp = fopen(filename, "r+");
    ft = fopen("temp.txt", "w+");
    if (fp == NULL) {
        printf("Unable to open file");
        exit(1);
    }
    if (ft == NULL) {
        printf("Unable to generate encryption key");
        exit(2);
    }
    //modifying ASCII values and storing it in temp.txt
    while (1) {
        ch = fgetc(fp);
        if (ch == EOF)
            break;
        ch = ch + key; //offset
        fputc(ch, ft);
    }
    rewind(fp);
    rewind(ft);
    //copying temp to original file
    while (1) {
        ch = fgetc(ft);
        if (ch == EOF)
            break;
        fputc(ch, fp);
    }
    printf("The file has been encrypted successfully");
    fclose(fp);
    fclose(ft);
}

void decrypt(char *filename) {
    FILE *fp, *ft;
    int ch=0;
    fp = fopen(filename, "r+");
    ft = fopen("temp.txt", "w+");
    if (fp == NULL) {
        printf("Unable to open file");
        exit(1);
    }
    if (ft == NULL) {
        printf("Unable to access encryption key");
        exit(2);
    }
    //decrementing the chars by the same ASCII value to get back original text into temp.txt
    while (1) {
        ch = fgetc(fp);
        if (ch == EOF)
            break;
        ch = ch - 1;
        fputc(ch, ft);
    }
    rewind(fp);
    rewind(ft);
    //copying decrypted data to original file
    while (1) {
        ch = fgetc(ft);
        if (ch == EOF)
            break;
        fputc(ch, fp);
    }
    printf("File Decrypted Successfully");
}

int main(void) {
    int choice;
    char name[100];
    FILE *fs, *ft;
    printf("To encrypt/decrypt a file: ");
    while (1) {
        printf("\nMENU");
        printf("\n1.Encrypt\n2.Decrypt\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
          case 1:
            printf("Enter the name of the file to be encrypted: ");
            fgets(name, 99, stdin);
            strtok(name,"\n");
            encrypt(name);
            return 0;
            break;
          case 2:
            printf("Enter the name of the file to be decrypted: ");
            fgets(name, 99, stdin);
            strtok(name,"\n");
            decrypt(name);
            return 0;
            break;
        }
    }
}