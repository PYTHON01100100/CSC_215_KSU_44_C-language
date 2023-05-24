#include <stdio.h>
#include <stdlib.h>

int main(){
  int num, i;
  int* grades;
  float sum=0, avg;

  printf("Enter the number of courses:");
  scanf("%d", &num);
  if ((grades = (int*)malloc(num*sizeof(int)))){
    for (i = 1; i <= num; i++){
      printf("Enter the grade of Course# %d:", i);
      scanf("%d", grades+i);
      sum += *(grades+i);
    }
    avg = sum / num;
    printf("The average of array elements :%.2f", avg);
    free(grades);
  }
  return 0;
}