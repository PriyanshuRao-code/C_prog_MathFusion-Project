#include <stdio.h>
void Matrix_explain();
void Matrix();
void Matrix_init();
void Matrix_input();
void Matrix_display();
void Addition();
void Subtraction();
void Multiplication();
/*void Determinant();
void Inverse();
void Transpose();*/


void Matrix_explain(){
    printf("Here are the functions allowed here and the format is as:\n");
    printf("Addition: +\n");
    printf("Subtraction: -\n");
    printf("Multiplication: *\n");
    printf("Determinant: |\n");
    printf("Inverse: ~\n");
    printf("Transpose: !\n");

    // printf("+ - * will be performed between two matrices only\n");
    //printf("| ~ ! will be performed for 1 matrix only\n");
    Matrix();
}
void Matrix(){
    char c;
    printf("Enter the operator:\n");
    scanf(" %c",&c);
    while(getchar()!='\n');
    switch(c){
        case '+':
            Addition();
            break;
        case '-':
            Subtraction();
            break;
        case '*':
            Multiplication();
            break;
        case '|':
            //Determinant();
            break;
        case '~':
            //Inverse();
            break;
        case '!':
            //Transpose();
            break;
        default:
            printf("\nPlease refer to the functions:\n");
            Matrix_explain();
            break;
    }
}
void Matrix_init(int r,int c,int matrix[][c]){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            matrix[i][j]=0;
        }
    }
}
void Matrix_input(int n,int r,int c,int matrix[][r][c]){
    for(int i=0;i<n;i++){
        printf("Enter the matrix \n");
        for(int j=0;j<r;j++){
            for(int k=0;k<c;k++){
                scanf("%d",&matrix[i][j][k]);
            }
        }
    }
}
void Matrix_display(int r,int c,int matrix[][c]){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
}

void Addition(){
    printf("Operation performed will be A+B+C+D...\n");
    //Taking inputs
    int n;
    printf("Enter the number of matrices to be added:");
    scanf("%d",&n);
    int r,c;
    printf("Enter the number of rows and columns\n");
    scanf("%d %d",&r,&c);
    int matrix[n][r][c];
    Matrix_input(n,r,c,matrix);
    int Ans_matrix[r][c];
    Matrix_init(r,c,Ans_matrix);

    //Addition of matrices
    for(int i=0;i<n;i++){
        for(int j=0;j<r;j++){
            for(int k=0;k<c;k++){
                Ans_matrix[j][k]+=matrix[i][j][k];
            }
        }
    }
    printf("Matrix after addition\n");
    Matrix_display(r,c,Ans_matrix);
}
void Subtraction(){
    printf("Operation performed will be A-B-C-D...\n");
    //Taking inputs
    int n;
    printf("Enter the number of matrices to be added:");
    scanf("%d",&n);
    int r,c;
    printf("Enter the number of rows and columns\n");
    scanf("%d %d",&r,&c);
    int matrix[n][r][c];
    Matrix_input(n,r,c,matrix);
    int Ans_matrix[r][c];
    Matrix_init(r,c,Ans_matrix);

    //Subtraction of matrices
    for(int i=0;i<n;i++){
        for(int j=0;j<r;j++){
            for(int k=0;k<c;k++){
                int p= i==0?1:-1;//Important step for subtraction
                Ans_matrix[j][k]=Ans_matrix[j][k]+ p*matrix[i][j][k];
            }
        }
    }
    printf("Matrix after subtraction\n");
    Matrix_display(r,c,Ans_matrix);
}
void Multiplication(){
    printf("Operation performed will be A*B only\n");
    //Taking input
    int r1,c1,r2,c2;
    printf("Enter number of rows and columns in matrix 1\n");
    scanf("%d %d",&r1,&c1);
    printf("Enter number of rows and columns in matrix 2\n");
    scanf("%d %d",&r2,&c2);
    if (c1!=r2){
        printf("Matrix multiplication is not possible\n");
        return;
    }
    int matrix1[1][r1][c1];
    int matrix2[1][r2][c2];
    Matrix_input(1,r1,c1,matrix1);
    Matrix_input(1,r2,c2,matrix2);
    int matrix[r1][c2];
    Matrix_init(r1,c2,matrix);

    //Multiplying matrices
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            for(int k=0;k<r2;k++){
                matrix[i][j]+=matrix1[0][i][k]*matrix2[0][k][j];
            }
        }
    }
    printf("Matrix after multiplication\n");
    Matrix_display(r1,c2,matrix);
}
