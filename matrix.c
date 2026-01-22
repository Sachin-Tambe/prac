#include <stdio.h>

#define SIZE 4

int main() {
    int mat1[SIZE][SIZE], mat2[SIZE][SIZE], result[SIZE][SIZE];
    int multiplications = 0, additions = 0;
    
    printf("Enter elements for Matrix 1 (4x4):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }
    
    printf("\nEnter elements for Matrix 2 (4x4):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }
    
    printf("\nMatrix 1:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d ", mat1[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMatrix 2:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d ", mat2[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
                multiplications++;
                if (k > 0) {
                    additions++;
                }
            }
        }
    }
    
    printf("\nResult Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d ", result[i][j]);
        }
        printf("\n");
    }
    
    printf("\nComplexity Analysis:\n");
    printf("Total Multiplications: %d\n", multiplications);
    printf("Total Additions: %d\n", additions);
    printf("Total Operations: %d\n", multiplications + additions);
    
    return 0;
}
