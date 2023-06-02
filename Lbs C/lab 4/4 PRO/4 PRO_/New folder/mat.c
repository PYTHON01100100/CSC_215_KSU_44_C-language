#include <stdio.h>
#include "mat.h"
void fill_matrix(int d, int matrix[d][d]);
void transpose(int d, int s[d][d], int t[d][d]);

int main() {
    int d;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &d);

    int s[d][d], t[d][d];
    printf("Enter the elements of the matrix:\n");
    fill_matrix(d, s);

    printf("Original matrix:\n");
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }

    transpose(d, s, t);

    printf("Transposed matrix:\n");
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}

void fill_matrix(int d, int matrix[d][d]) {
    int i, j;
    for (i = 0; i < d; i++) {
        for (j = 0; j < d; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void transpose(int d, int s[d][d], int t[d][d]) {
    int i, j;
    for (i = 0; i < d; i++) {
        for (j = 0; j < d; j++) {
            t[i][j] = s[j][i];
        }
    }
}
void transpose(int d, int s[d][d], int t[d][d]) {
    int i, j;
    for (i = 0; i < d; i++) {
        for (j = 0; j < d; j++) {
            t[i][j] = s[j][i];
        }
    }
}