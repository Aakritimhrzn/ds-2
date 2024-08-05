#include <stdio.h>

#define MAX_SIZE 10

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void booleanJoin(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] || B[i][j];
        }
    }
}

void booleanMeet(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] && B[i][j];
        }
    }
}

void booleanProduct(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = 0;
            for (int k = 0; k < size; k++) {
                C[i][j] = C[i][j] || (A[i][k] && B[k][j]);
            }
        }
    }
}

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
    int size;

    printf("Enter the size of the matrices (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    printf("Enter elements of matrix A (%d x %d):\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B (%d x %d):\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    printf("\nMatrix A:\n");
    printMatrix(A, size);
    
    printf("\nMatrix B:\n");
    printMatrix(B, size);

    printf("\nBoolean Join (A ? B):\n");
    booleanJoin(A, B, C, size);
    printMatrix(C, size);

    printf("\nBoolean Meet (A ? B):\n");
    booleanMeet(A, B, C, size);
    printMatrix(C, size);

    printf("\nBoolean Product (A • B):\n");
    booleanProduct(A, B, C, size);
    printMatrix(C, size);

    return 0;
}

