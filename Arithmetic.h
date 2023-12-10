#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define max 50
//Simpler version for this program is commented below
void Arithmetic();
void Arithmetic_explain(){
    printf("You can use the following functions:\n");
    printf("+-*/^ with the format as:\n");
    printf("a+b-c*d/e^f...\n");
    printf("NOTE: The program will calculate from left to right without taking care of BODMAS\n\n");
    Arithmetic();
}
void Arithmetic(){
    char str[max];
    printf("Enter the operation:\n");
    scanf("%s",str);
    while(getchar()!='\n');
    float result = atoi(&str[0]);
    int i=1;
    while(i<strlen(str)){
        switch(str[i]){
            case '+':
                result+=atoi(&str[i+1]);
                break;
            case '-':
                result-=atoi(&str[i+1]);
                break;
            case '*':
                result*=atoi(&str[i+1]);
                break;
            case '/':
                result/=atoi(&str[i+1]);
                break;
            case '^':
                result=pow(result,atoi(&str[i+1]));
                break;
            default:
                printf("Problem in operators\n");
                printf("Check the explanation\n\n");
                Arithmetic_explain();
                return;
                break;
        }
        i+=2;
    }
    printf("The result of the operation: %f",result);
}
/*
void Arithmetic_explain(){
    printf("Here are the functions allowed here and the format is as:\n");
    printf("Addition: a+b\n");
    printf("Subtraction: a-b\n");
    printf("Multiplication: a*b\n");
    printf("Division: a/b\n");
    printf("Power: a^b\n");
    printf("Root of the function can be calculated as: a ^ 0.5\n\n");
    Arithmetic(); 
}
void Arithmetic(){
    float a=0,b=0;
    char c='A';
    printf("Enter the arithmetic operation:");
    scanf("%f%c%f",&a,&c,&b);
    while(getchar()!='\n');
    switch(c){
        case '+':
            printf("%f",a + b);
            break;
        case '-':
            printf("%f",a-b);
            break;
        case '*':
            printf("%f",a*b);
            break;
        case '^':
            printf("%f",pow(a,b));
            break;
        case '/':
            if(b!=0){
            printf("%f",a/b);
            }
            else{
                printf("Can't divide by 0");
            }
            break;
        case ' ':
            printf("\nDon't use spaces in between for calculation\n");
            Arithmetic();
            break;
        default:
            printf("\nPlease refer to the functions:\n");
            Arithmetic_explain();
            break;
    }
}*/