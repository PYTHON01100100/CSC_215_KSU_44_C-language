#include <stdio.h>

int main(){
  int N, i, j;

  printf("Enter a positive integer:");
  scanf("%d", &N);
  
  for (i = -N; i <= N; i++){
    for (j = 0; j <= N-(i>0?i:-i); j++)
      printf("%d", j);
    printf("\n");
  }
  return 0;
}
