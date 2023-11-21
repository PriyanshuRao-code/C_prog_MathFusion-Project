#include <stdio.h>
#include "Arithmetic.h"
#include "Complex.h"
#include "Matrix.h"
#include "Co_ordination.h"
int main(){
  int n,m;
printf("hello world");
  printf("Welcome to the world of calculation\n\n");
  printf("Which type of calculations would you like to perform:\n");
  printf("1. Arithmetic operations\n
          2. Complex number operations\n
          3. Matrix operations\n
          4. Co-ordination operations\n);
  scanf("%d",&n);
  printf("1. Proceed\n
          2. Explain operations\n");
  scanf("%d",&m);
  if(n==1){
    if(m==1){
      Arithmetic();
    }
    else if(m==2){
      Arithmetic_explain();
    }
    else {
      printf("Error\n
              Enter 1(Proceed) or 2(Explain) only\n");
    }
  }
  else if(n==2){
    if(m==1){
      Complex();
    }
    else if(m==2){
      Complex_explain();
    }
    else {
      printf("Error\n
              Enter 1(Proceed) or 2(Explain) only\n");
    }
  }
  else if(n==3){
    if(m==1){
      Matrix();
    }
    else if(m==2){
      Matrix_explain();
    }
    else {
      printf("Error\n
              Enter 1(Proceed) or 2(Explain) only\n");
    }
  }
  else if(n==4){
    if(m==1){
      Co_ordination();
    }
    else if(m==2){
      Co_ordination_explain();
    }
    else {
      printf("Error\n
              Enter 1(Proceed) or 2(Explain) only\n");
    }
  }
  else{
    printf("Error\n
            Enter correct value for operations\n");
  }
  return 0;
}
