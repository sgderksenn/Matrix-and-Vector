/* matrix_tester.c
   CSC 111 - Fall 2019 - Assignment 5


   B. Bird - 10/13/2019
*/


//Warning: The tests below do not print any elements of the matrix outside
//of its "expected size". This means that if your code accidentally sets
//elements outside of the provided bounds, you will not be able to detect
//the error with this tester (but you should use your own testing
//to verify that your code stays within the provided bounds, since
//you will lose marks if it does not).

#include <stdio.h>
#include <math.h>
#include "matrix_and_vector.h"

//print_matrix(M, rows, columns)
//Print the contents of the vector V
void print_matrix(Matrix M, int rows, int columns){
    int i,j;
    for (i = 0; i < rows; i++){
        for (j = 0; j < columns; j++)
            printf("%7.2f ", M[i][j]);
        printf("\n");
    }
}

//print_column_vector(V, size)
//Print the contents of the vector V as a column (analogous to a 1 x size matrix)
void print_column_vector(Vector V, int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%7.2f\n", V[i]);
}

int main(){

    Matrix M1 = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    Matrix M2 = {
            {1, 1, 1},
            {0, 2, 2},
            {0, 0, 3}
    };

    Matrix M3 = {
            {6, 10, 17, 187, 225},
            {0.5, 0.25, 0.5, 0.25, 0.5},
    };

    Matrix M4 = {
            {1, 0},
            {0, 1},
            {1, 1},
            {-1, 1},
            {0, 0}
    };

    Matrix M5 = {
            {1, 0.5, 0.33},
            {0.5, 0.33, 0.25},
            {0.33, 0.25, 0.2},
            {0.25, 0.2, 0.16},
    };

    Matrix M6 = {
            {1, 0.5, 0.33, 0.25},
            {0.5, 0.33, 0.25, 0.2},
            {0.33, 0.25, 0.2, 0.16},
            {0.25, 0.2, 0.16, 0.14},
    };

    Matrix M7 = {
            {1, 1, 1},
            {1, 2, 2},
            {1, 2, 3},
            {1, 2, 3},
    };

    Vector V1 = {-0.5, 0.5};
    Vector V2 = {9, -9, 1};
    Vector V3 = {1, 2, 3, 4};

    Vector Vout;

    Matrix C;
    Matrix P;
    Matrix T;
    Matrix I;


    printf("Testing identity:\n");
    printf("3 x 3 identity matrix:\n");
    identity(I, 3);
    print_matrix(I, 3, 3);
    printf("\n");
    printf("5 x 5 identity matrix:\n");
    identity(I, 5);
    print_matrix(I, 5, 5);
    printf("\n");
    printf("\n");

    printf("Testing matrix_copy:\n");
    printf("Copy of M1:\n");
    matrix_copy(M1, C, 3, 3);
    print_matrix(C, 3, 3);
    printf("\n");
    printf("Copy of M5:\n");
    matrix_copy(M5, C, 4, 3);
    print_matrix(C, 4, 3);
    printf("\n");
    printf("\n");

    printf("Testing transpose:\n");
    printf("Transpose of M1:\n");
    transpose(M1, T, 3, 3);
    print_matrix(T, 3, 3);
    printf("\n");
    printf("Transpose of M3:\n");
    transpose(M3, T, 2, 5);
    print_matrix(T, 5, 2); //Note that that the row/column counts are swapped by transposing
    printf("\n");
    printf("\n");


    printf("Testing add_matrices:\n");
    printf("M1 + M2:\n");
    add_matrices(M1, M2, P, 3, 3);
    print_matrix(P, 3, 3);
    printf("\n");
    printf("M5 + M7:\n");
    add_matrices(M5, M7, P, 4, 3);
    print_matrix(P, 4, 3);
    printf("\n");
    printf("\n");


    printf("Testing matrix_vector_multiply:\n");
    printf("(The results of each part are printed as column vectors)\n");
    printf("M1 * V2:\n");
    matrix_vector_multiply(M1, V2, Vout, 3, 3);
    print_column_vector(Vout, 3);
    printf("\n");
    printf("M2 * V2:\n");
    matrix_vector_multiply(M2, V2, Vout, 3, 3);
    print_column_vector(Vout, 3);
    printf("\n");
    printf("M4 * V1:\n");
    matrix_vector_multiply(M4, V1, Vout, 5, 2);
    print_column_vector(Vout, 5);
    printf("\n");
    printf("M5 * V2:\n");
    matrix_vector_multiply(M5, V2, Vout, 4, 3);
    print_column_vector(Vout, 4);
    printf("\n");
    printf("M6 * V3:\n");
    matrix_vector_multiply(M6, V3, Vout, 4, 4);
    print_column_vector(Vout, 4);
    printf("\n");
    printf("M7 * V2:\n");
    matrix_vector_multiply(M7, V2, Vout, 4, 3);
    print_column_vector(Vout, 4);
    printf("\n");
    printf("\n");

    printf("Testing matrix_multiply:\n");
    int mm_result = 0;
    printf("M1 * M2:\n");
    mm_result = matrix_multiply(M1, M2, P, 3, 3, 3, 3);
    if (mm_result == 0){
        printf("matrix_multiply failed\n");
    }else{
        print_matrix(P, 3, 3);
    }
    printf("\n");
    printf("M1 * M3 (should fail):\n");
    mm_result = matrix_multiply(M1, M3, P, 3, 3, 2, 5);
    if (mm_result == 0){
        printf("matrix_multiply failed\n");
    }else{
        printf("matrix_multiply succeeded (but it shouldn't have...)\n");
    }
    printf("\n");
    printf("M3 * M4:\n");
    mm_result = matrix_multiply(M3, M4, P, 2, 5, 5, 2);
    if (mm_result == 0){
        printf("matrix_multiply failed\n");
    }else{
        print_matrix(P, 2, 2);
    }
    printf("\n");
    printf("M4 * M3:\n");
    mm_result = matrix_multiply(M4, M3, P, 5, 2, 2, 5);
    if (mm_result == 0){
        printf("matrix_multiply failed\n");
    }else{
        print_matrix(P, 5, 5);
    }
    printf("\n");
    printf("M6 * M6:\n");
    mm_result = matrix_multiply(M6, M6, P, 4, 4, 4, 4);
    if (mm_result == 0){
        printf("matrix_multiply failed\n");
    }else{
        print_matrix(P, 4, 4);
    }
    printf("\n");
    printf("M6 * M5:\n");
    mm_result = matrix_multiply(M6, M5, P, 4, 4, 4, 3);
    if (mm_result == 0){
        printf("matrix_multiply failed\n");
    }else{
        print_matrix(P, 4, 3);
    }
    printf("\n");
    printf("M6 * M7:\n");
    mm_result = matrix_multiply(M6, M7, P, 4, 4, 4, 3);
    if (mm_result == 0){
        printf("matrix_multiply failed\n");
    }else{
        print_matrix(P, 4, 3);
    }
    printf("\n");
    printf("\n");

    return 0;
}