#include <stdio.h>
#include <math.h>
typedef struct{
    float real;
    float img;
}complex;

void Complex();
complex input();
void c_add();
void c_sub();
void c_mul();
void c_div();
void c_con();
void c_mag();

void Complex_explain(){
    printf("\n\nNOTE: Enter the input in a+bi or a-bi format only\n");
    printf("Enter 1: addition\n");
    printf("Enter 2: subtraction\n");
    printf("Enter 3: multiplication\n");
    printf("Enter 4: division\n");
    printf("Enter 5: conjugate\n");
    printf("Enter 6: magnitude\n\n");
    Complex();
}
void Complex(){
    int a;
    printf("Enter the operation to be performed\n");
    scanf("%d",&a);
    switch(a){
        case 1:
            c_add();
            break;
        case 2:
            c_sub();
            break;
        case 3:
            c_mul();
            break;
        case 4:
            c_div();
            break;
        case 5:
            c_con();
            break;
        case 6:
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
    char b;
    complex c;
    printf("Enter the complex number: ");
    scanf("%f%c%fi",&c.real,&b,&c.img);
    if (b=='-'){
        c.img=(-1)*c.img;
    }
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
    result.real=0;
    result.img=0;
    for(int i=0;i<n;i++){
        result.real+=c[i].real;
        result.img+=c[i].img;
    }
    //For printing purpose only [result.img is also changed]
    char s = result.img>=0?'+':'-';
    if(s=='-'){
        result.img=-1*result.img;
    }
    printf("The result(aprrox upto 2 digits) is: %.2f%c%.2fi",result.real,s,result.img);
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
    result.real=0;
    result.img=0;
    for(int i=0;i<n;i++){
        int sign = i==0?1:-1;
        result.real+=sign*c[i].real;
        result.img+=sign*c[i].img;
    }
    //For printing purpose only [result.img is also changed]
    char s = result.img>=0?'+':'-';
    if(s=='-'){
        result.img=-1*result.img;
    }
    printf("The result(aprrox upto 2 digits) is: %.2f%c%.2fi",result.real,s,result.img);
}
void c_mul(){
    complex c1,c2,result;
    c1=input();
    c2=input();
    result.real=0;
    result.img=0;
    result.real=c1.real*c2.real-c1.img*c2.img;
    result.img=c1.real*c2.img+c1.img*c2.real;
    //For printing purpose only [result.img is also changed]
    char s = result.img>=0?'+':'-';
    if(s=='-'){
        result.img=-1*result.img;
    }
    printf("Multiplication (approx till 2 digits): %.2f%c%.2fi",result.real,s,result.img);
}
void c_div(){
    complex c1,c2,result;
    c1=input();
    c2=input();
    result.real=0;
    result.img=0;
    result.real=(c1.real*c2.real+c1.img*c2.img)/(pow(c2.real,2)+pow(c2.img,2));
    result.img=(c1.img*c2.real-c1.real*c2.img)/(pow(c2.real,2)+pow(c2.img,2));
    //For printing purpose only [result.img is also changed]
    char s = result.img>=0?'+':'-';
    if(s=='-'){
        result.img=-1*result.img;
    }
    printf("Division (approx till 2 digits): %.2f%c%.2fi",result.real,s,result.img);
}
void c_con(){
    complex c,result;
    c=input();
    result.real=0;
    result.img=0;
    result.real=c.real;
    result.img=(-1)*c.img;
    //For printing purpose only [result.img is also changed]
    char s = result.img>=0?'+':'-';
    if(s=='-'){
        result.img=-1*result.img;
    }
    printf("Conjugate (approx till 2 digits): %.2f%c%.2fi",result.real,s,result.img);
}
void c_mag(){
    complex c;
    c=input();
    float result;
    result = pow((pow(c.real,2)+pow(c.img,2)),0.5);
    printf("Magnitude (approx till 2 digits): %.2f",result);
}