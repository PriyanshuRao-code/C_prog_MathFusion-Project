#include <stdio.h>
#include "Arithmetic.h"
#include "Complex.h"
#include "Matrix.h"
#include "Co_ordination.h"
int operation();
int explanation();


int operation(){
  int n;
  printf("Welcome to the world of calculation\n\n");
  printf("Which type of calculations would you like to perform:\n");
  printf("1. Arithmetic operations\n");
  printf("2. Complex number operations\n");
  printf("3. Matrix operations\n");
  printf("4. Co-ordination operations\n");
  scanf("%d",&n);
  if(n!=1 && n!=2 && n!=3 && n!=4) {
    printf("\nError\n");
    printf("Enter correct value for operations\n\n");
    return -1;
  }
  return n;
}


  int explanation(){
  int m;
  printf("1. Proceed\n");
  printf("2. Explain operations\n");
  scanf("%d",&m);

  if(m!=1 && m!=2){
    printf("\nError\n");
    printf("Enter 1(Proceed) or 2(Explain) only\n\n");

    return -1;
  }
  return m;
}

int main(){
  int n,m;
  n=operation();
  if(n==-1) n=operation();

  m=explanation();
  if (m==-1) m=explanation();


  //Just Executing the the above by sending the calculation to respective functions in their respective header files
  switch(n){
    case 1:
      switch(m){
        case 1:
          Arithmetic();
          break;
        case 2:
          Arithmetic_explain();
          break;
        //No default needed covered earlier.
      }
      break;

    case 2:
      switch(m){
        case 1:
          Complex();
          break;
        case 2:
          Complex_explain();
          break;
        //No default needed covered earlier.
      }
      break;
    
    case 3:
      switch(m){
        case 1:
          Matrix();
          break;
        case 2:
          Matrix_explain();
          break;
        //No default needed covered earlier.
      }
      break;

    case 4:
      switch(m){
        case 1:
          //Co_ordination();
          break;
        case 2:
          //Co_ordination_explain();
          break;
        //No default needed covered earlier.
      }
      break;
    //No default needed covered earlier.
  }
  return 0;
}