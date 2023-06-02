#include <stdio.h>
#include "mat.h"

void fill_mat(int m[D][D]){
    int i, j;
    for(i=0;i<D;i++){
        for(j=0;j<D;j++){
            printf("Enter the No  in Elemnt [%d ,%d]: ",(i+1),(j+1));
            scanf("%d",&m[i][j]);
        }
    }
}
void print_mat( int a[D][D]){
    int i, j;
    for(i=0;i<D;i++){
        printf("|");
        for(j=0;j<D;j++){
            printf("%d ",a[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}
void tran( int t[D][D],int s[D][D]){
  int i, j;
  for (i=0; i<D; i++)
    for (j=0; j<D; j++)
      t[i][j] = s[j][i];
}
void multiply(int m1[D][D], int m2[D][D]){
  int result[D][D], i, j, k;
  for (i=0; i<D; i++)
    for (j=0; j<D; j++){
      int c = 0;
      for (k=0; k<D; k++)
        c+= m1[i][k]*m2[k][j]; 
      result[i][j] = c;
    }
  print_mat(result);
}
          
