#include <stdio.h>
#include "mat.h"

void fill_matrix(int m[DIM][DIM]){
  int i, j;
  for (i=0; i<DIM; i++)
    for (j=0; j<DIM; j++){
      printf("\nEnter element 3*3 :", i, j);
      scanf("%d", &m[i][j]);
    }   
  printf("\n");
}

void transpose(int t[DIM][DIM], int s[DIM][DIM]){
  int i, j;
  for (i=0; i<DIM; i++)
    for (j=0; j<DIM; j++)
      t[i][j] = s[j][i];
}

void print_matrix(int m[DIM][DIM]){
  int i, j;
  for (i=0; i<DIM; i++){
    for (j=0; j<DIM; j++)
      printf("%d\t", m[i][j]);
    printf("\n");
  }
  printf("\n");
}

void multiply(int m1[DIM][DIM], int m2[DIM][DIM]){
  int result[DIM][DIM], i, j, k;
  for (i=0; i<DIM; i++)
    for (j=0; j<DIM; j++){
      int c = 0;
      for (k=0; k<DIM; k++)
        c+= m1[i][k]*m2[k][j]; 
      result[i][j] = c;
    }
  print_matrix(result);
}