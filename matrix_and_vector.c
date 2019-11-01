/*

 Sydney Derksen/V00910431/29/10/19

 This program was designed to be a matrix/vector library for the functions described by matrix_and_vector.h

 */

#include "matrix_and_vector.h"
#include <stdio.h>
#include <math.h>

//VECTOR FUNCTIONS

//will change Vout indices 0 to (vector_size - 1) to value
void set_vector(Vector Vout, int vector_size, double value) {
    int i;
    for (i = 0; i < vector_size; i++) {
        Vout[i] = value;
    }
}

//will change Vout values to V values plus value, for specified vector_size indices
void add_scalar_to_vector(Vector V, Vector Vout, int vector_size, double value) {
    int i;
    for (i = 0; i < vector_size; i++) {
        Vout[i] = V[i] + value;
    }
}

//will change Vout values to V values multiplied by value, for specified vector_size indices
void mul_vector_by_scalar(Vector V, Vector Vout, int vector_size, double value){
    int i;
    for (i = 0; i < vector_size; i++) {
        Vout[i] = V[i] * value;
    }
}

//Given a vector V and its size, return the sum of all elements of V.
double vector_sum(Vector V, int vector_size){
    int i;
    double sum = 0.0;
    for(i = 0; i < vector_size; i++){
        sum = sum + V[i];
    }
    return sum;
}

//calculates dot product of provided vectors
double dot_product(Vector V1, Vector V2, int vector_size) {
    int i;
    double result = 0;
    for (i = 0; i < vector_size; i++) {
        result = result + (V1[i]*V2[i]);
    }
    return result;
}

//calculates the length of vector V
double norm(Vector V, int vector_size){
    int i;
    double norm = 0;
    for(i = 0; i < vector_size; i++){
        norm = norm + V[i]*V[i];
    }
    norm = sqrt(norm);
    return norm;
}

//set vector Vout to be the sum of vectors V1 and V2
void add_vectors(Vector V1, Vector V2, Vector Vout, int vector_size){
    int i;
    for(i = 0; i < vector_size; i++){
        Vout[i] = V1[i] + V2[i];
    }
}

//set vector Vout to be the product of vectors V1 and V2
void elementwise_multiply_vectors(Vector V1, Vector V2, Vector Vout, int vector_size){
    int i;
    for(i = 0; i < vector_size; i++){
        Vout[i] = V1[i] * V2[i];
    }
}

//MATRIX FUNCTIONS

//sets a matrix M with indicated dimensions size by size to the identity matrix
void identity(Matrix M, int size){
    int i, j;
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            if(i == j){
                M[i][j] = 1;
            }else{
                M[i][j] = 0;
            }
        }
    }
}

/* matrix_copy(A, B, rows, cols)
   Given an input matrix A (with the provided number of rows and columns)
   and an output matrix B, copy all elements of A into B. Do not set any
   elements of B outside the bounds provided.
   Do not modify any elements of the input matrix A.
*/
void matrix_copy(Matrix A, Matrix B, int rows, int cols){
    int i, j;
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            B[i][j] = A[i][j];
        }
    }
}

//assign values to matrix T so that it is the transpose of matrix A
void transpose(Matrix A, Matrix T, int rows, int cols){
    int i, j;
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            T[j][i] = A[i][j];
        }
    }
}

//set matrix C equals to the sum of matrices A and B
void add_matrices(Matrix A, Matrix B, Matrix C, int rows, int cols){
    int i, j;
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

//set the vector Vout to be equal to the product of matrix A and vector V
void matrix_vector_multiply(Matrix A, Vector V, Vector Vout, int n, int k){
    int i, j;
    for(i = 0; i < n; i++){
        double sum = 0;
        for(j = 0; j < k; j++){
            sum = A[i][j]*V[j] + sum;
        }
        Vout[i] = sum;
    }
}

//set matrix C to be the product of matrices A and B
int matrix_multiply(Matrix A, Matrix B, Matrix C, int Arows, int Acols, int Brows, int Bcols) {
    if (Acols != Brows) {
        return 0;
    }
    int i, j, k;
    for(i = 0; i < Arows; i++){
        for(k = 0; k < Bcols; k++){
            double sum = 0;
            for(j = 0; j < Acols; j++){
                sum = sum + A[i][j]*B[j][k];
            }
            C[i][k] = sum;
        }
    }
    return 1;
}