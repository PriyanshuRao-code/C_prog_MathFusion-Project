#include <stdio.h>
#include <math.h>
void Arithmetic();
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
}