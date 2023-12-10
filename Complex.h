#include <stdio.h>
#include <math.h>
typedef struct{
    float real;
    float img;
}complex;
//typedef complex complex;

void Complex();
complex input();
void c_add();
void c_sub();
void c_mul();
void c_div();
void c_con();
void c_mag();

void Complex_explain(){
    printf("\n\nNOTE: Enter the input in a+bi format only [For negative use a+-bi](without using brackets)\n");
    printf("Enter a: addition\n");
    printf("Enter s: subtraction\n");
    printf("Enter m: multiplication\n");
    printf("Enter d: division\n");
    printf("Enter c: conjugate\n");
    printf("Enter |: magnitude\n\n");
    Complex();
}
void Complex(){
    char a;
    printf("Enter the operation to be performed\n");
    scanf(" %c",&a);
    while(getchar()!='\n');
    switch(a){
        case 'a':
            c_add();
            break;
        case 's':
            c_sub();
            break;
        case 'm':
            c_mul();
            break;
        case 'd':
            c_div();
            break;
        case 'c':
            c_con();
            break;
        case '|':
            c_mag();
            break;
        default:
            printf("Error in entering\n");
            printf("See it for reference\n\n");
            Complex_explain();
            break;
    }
}
complex input(){
    complex c;
    printf("Enter the complex number: ");
    scanf("%f+%fi",&c.real,&c.img);
    return c;
}
void c_add(){
    int n;
    printf("Number of complex numbers to be added: ");
    scanf("%d",&n);
    complex c[n];
    for(int i=0;i<n;i++){
        c[i]=input();
    }
    complex result;
    for(int i=0;i<n;i++){
        result.real+=c[i].real;
        result.img+=c[i].img;
    }
    printf("The result(aprrox upto 2 digits) is: %.2f+i%.2f",result.real,result.img);
}
void c_sub(){
    int n;
    printf("Number of complex numbers to be added: (Format: a-b-c-d..)\n");
    scanf("%d",&n);
    complex c[n];
    for(int i=0;i<n;i++){
        c[i]=input();
    }
    complex result;
    for(int i=0;i<n;i++){
        int sign = i==0?1:-1;
        result.real+=sign*c[i].real;
        result.img+=sign*c[i].img;
    }
    printf("The result(aprrox upto 2 digits) is: %.2f+%.2fi",result.real,result.img);
}
void c_mul(){
    complex c1,c2,result;
    c1=input();
    c2=input();
    result.real=c1.real*c2.real-c1.img*c2.img;
    result.img=c1.real*c2.img+c1.img*c2.real;
    printf("Multiplication (approx till 2 digits): %.2f+%.2fi",result.real,result.img);
}
void c_div(){
    complex c1,c2,result;
    c1=input();
    c2=input();
    result.real=(c1.real*c2.real+c1.img*c2.img)/(pow(c2.real,2)+pow(c2.img,2));
    result.img=(c1.img*c2.real-c1.real*c2.img)/(pow(c2.real,2)+pow(c2.img,2));
    printf("Division (approx till 2 digits): %.2f+%.2fi",result.real,result.img);
}
void c_con(){
    complex c,result;
    c=input();
    result.real=c.real;
    result.img=(-1)*c.img;
    printf("Conjugate (approx till 2 digits): %.2f+%.2fi",result.real,result.img);
}
void c_mag(){
    complex c;
    c=input();
    float result;
    result = pow((pow(c.real,2)+pow(c.img,2)),0.5);
    printf("Magnitude (approx till 2 digits): %.2f",result);
}