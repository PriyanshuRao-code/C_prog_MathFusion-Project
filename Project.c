#include <stdio.h>
#include "Arithmetic.h"
#include "Complex.h"
#include "Matrix.h"
#include "Co_ordination.h"
int main(){
  int n,m;
  printf("Welcome to the world of calculation\n\n");
  printf("Which type of calculations would you like to perform:\n");
  printf("1. Arithmetic operations\n");
  printf("2. Complex number operations\n");
  printf("3. Matrix operations\n");
  printf("4. Co-ordination operations\n");
  scanf("%d",&n);

  printf("1. Proceed\n");
  printf("2. Explain operations\n");
  scanf("%d",&m);

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
        default:
          printf("Error\n");
          printf("Enter 1(Proceed) or 2(Explain) only\n");
          break;
      }
      break;

    case 2:
      switch(m){
        case 1:
          //Complex();
          break;
        case 2:
          //Complex_explain();
          break;
        default:
          printf("Error\n");
          printf("Enter 1(Proceed) or 2(Explain) only\n");
          break;
      }
      break;
    
    case 3:
      switch(m){
        case 1:
          //Matrix();
          break;
        case 2:
          //Matrix_explain();
          break;
        default:
          printf("Error\n");
          printf("Enter 1(Proceed) or 2(Explain) only\n");
          break;
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
        default:
          printf("Error\n");
          printf("Enter 1(Proceed) or 2(Explain) only\n");
          break;
      }
      break;
    
    default:
    printf("Error\n");
    printf("Enter correct value for operations\n");
    break;
  }
  return 0;
}