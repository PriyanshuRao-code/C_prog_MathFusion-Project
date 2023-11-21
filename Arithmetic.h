#include <math.h>
void Arithmetic();
void Arithmetic_explain(){
    printf("Here are the functions allowed here and the format is as:\n");
    printf("Addition: a + b\n");
    printf("Subtraction: a - b\n");
    printf("Multiplication: a * b\n");
    printf("Division: a / b\n");
    printf("Power: a ^ b\n");
    printf("Root of the function can be calculated as: a ^ 0.5\n");
    Arithmetic(); 
}
Arithmetic(){
    float a,b;
    char c;
    printf("Enter the arithmetic operation:");
    scanf("%d %c %d",&a,&c,&b);
    if(c=='+'){
        printf("%f",a+b);
    }
    else if(c=='-'){
        printf("%f",a-b);
    }
    else if(c=='*'){
        printf("%f",a*b);
    }
    else if(c=='^'){
        printf("%f",pow(a,b));
    }
    else if(c=='/'){
        printf("%f",a/b);
    }
    else {
        printf("Please refer to the functions:\n");
        Arithmetic_explain();
    }
}