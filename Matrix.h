#include <stdio.h>
void Matrix_explain();
void Matrix();
void Matrix_init();//For 2D matrix
void Matrix_input();//For 2D matrix
void Matrix_input3();//For 3D matrix
void Matrix_display();//For 2D matrix
void Addition();
void Subtraction();
void Multiplication();
void Determinant();
int deter();
void Add_Sub();
/*void Inverse();
void Transpose();*/


void Matrix_explain(){
    printf("Here are the functions allowed here and the format is as:\n");
    printf("Addition: +\n");
    printf("Subtraction: -\n");
    printf("Add_Sub as A+B-C-D.. : #\n");
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
            Determinant();
            break;
        case '~':
            //Inverse();
            break;
        case '!':
            //Transpose();
            break;
        case '#':
            Add_Sub();
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
void Matrix_input(int r,int c,int matrix[][c]){
        printf("Enter the matrix \n");
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                scanf("%d",&matrix[i][j]);
            }
        }
}
void Matrix_input3(int n,int r,int c,int matrix[][r][c]){
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
    Matrix_input3(n,r,c,matrix);
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
    Matrix_input3(n,r,c,matrix);
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
    int matrix1[r1][c1];
    int matrix2[r2][c2];
    Matrix_input(r1,c1,matrix1);
    Matrix_input(r2,c2,matrix2);
    int matrix[r1][c2];
    Matrix_init(r1,c2,matrix);

    //Multiplying matrices
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            for(int k=0;k<r2;k++){
                matrix[i][j]+=matrix1[i][k]*matrix2[k][j];
            }
        }
    }
    printf("Matrix after multiplication\n");
    Matrix_display(r1,c2,matrix);
}
void Determinant(){
    int n;
    printf("Enter the row/column [Square matrix] for the matrix:");
    scanf("%d",&n);
    if(n>10) {
        printf("Enter value of n less than 11");
        Determinant();
        return;
    }
    int matrix[10][10];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
//Matrix_input(n,n,matrix);->can use this as it will create a matrix of nxn and we want 10x10. Why? Refer to deter()

    int det=deter(n,matrix);
    printf("Determinant of the matrix is %d",det);
}
//Finding determinant using recursion
int deter(int n,int matrix[10][10]) {
    int det = 0;
    int submatrix[10][10]; //Should be constant at compilation time or use pointer BUT don't use submatrix[n][n];
    Matrix_init(10,10,submatrix); 
    if (n == 1) {
        return matrix[0][0];
    }
    else if (n == 2) {
        return ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
    }
    //Making a submatrix of (n-1)x(n-1) and then taking it to 2x2 or 1x1 for finding determinant
     else {
        for (int x = 0; x < n; x++) { 
            int subi = 0; // Index for submatrix row
            for (int i = 1; i < n; i++) { 
                int subj = 0; // Index for submatrix column
                for (int j = 0; j < n; j++) {
                    if (j == x) 
                        continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det += (x % 2 == 0 ? 1 : -1) * matrix[0][x] * deter(n-1,submatrix);
        }
    }
    return det;
}
void Add_Sub(){
    printf("Both add and subtract randomly\n");
    int n,r,c;
    printf("Enter the total number of matrices: ");
    scanf("%d",&n);
    printf("Enter rows and columns of matrix: ");
    scanf("%d %d",&r,&c);
    int matrix[n][r][c];
    Matrix_input3(n,r,c,matrix);
    int Ans_matrix[r][c];
    Matrix_init(r,c,Ans_matrix);
    char ch[2*n];
    printf("Enter the operations as A+B-C+D or 1+2-3+4 [Without using spaces][Without changing order of order]\n");
    scanf("%s",ch);
    while(getchar()!='\n');
    for(int i=0;i<(n-1);i++){
        if(ch[2*i+1]!='+' && ch[2*i+1]!='-'){
            printf("\nInvalid operation\n");
            return;
        }
    }
    //Operation started
    for(int i=0;i<n;i++){
        for(int j=0;j<r;j++){
            for(int k=0;k<c;k++){
                int p;
                if(i==0) p=1;
                else{
                    p= ch[2*i-1]=='+'?1:-1;
                }
                Ans_matrix[j][k]=Ans_matrix[j][k]+ p*matrix[i][j][k];
            }
        }
    }
    printf("Matrix after operations\n");
    Matrix_display(r,c,Ans_matrix);
}