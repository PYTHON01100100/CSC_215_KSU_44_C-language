#include <stdio.h>

int main(){
  int n, i, j;
  printf("Enter a positive integer:");
  scanf("%d", &n);

  for (i=n; i>0; i--){
    for (j=1; j<=i; j++)
      printf("*");
    printf("\n");
  }
  for (i=2; i<=n; i++){
    for (j=1; j<=i; j++)
      printf("*");
    printf("\n");
  }    

  return 0;
}