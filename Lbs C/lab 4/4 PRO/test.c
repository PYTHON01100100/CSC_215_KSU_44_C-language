#include <stdio.h>
#include "mat.h"
#include "mat.c"

int main(){
  int mat[D][D];
  fill_mat(mat);
  print_mat(mat);

  int tmat[D][D];
  tran(tmat, mat);
  print_mat(tmat);

  multiply(mat, tmat);
  return 0;
}