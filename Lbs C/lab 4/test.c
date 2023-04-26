#include <stdio.h>
#include "mat.h"
#include "mat.c"

int main(){
  int mat[DIM][DIM];
  fill_matrix(mat);
  print_matrix(mat);

  int tmat[DIM][DIM];
  transpose(tmat, mat);
  print_matrix(tmat);

  multiply(mat, tmat);
  return 0;
}