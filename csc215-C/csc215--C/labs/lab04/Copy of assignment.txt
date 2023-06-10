#include <stdio.h>

void avg(int, int, int, int);
int findLowest(int, int, int, int);

int main(){
  int g1, g2, g3, g4; /* can be replaced with an array int g[4] */
  
  printf("Enter score 1:");
  scanf("%d", &g1);

  printf("Enter score 2:");
  scanf("%d", &g2);

  printf("Enter score 3:");
  scanf("%d", &g3);

  printf("Enter score 4:");
  scanf("%d", &g4);

  avg(g1, g2, g3, g4);

  return 0;
}

void avg(int a, int b, int c, int d){
  int sum;
  float result;
  sum = a+b+c+d-findLowest(a, b, c, d);
  result = sum / 3.0;
  printf("The average is:%.2f", result);
}

int findLowest(int a, int b, int c, int d){
  int min = a;
  if (b < min) min = b;
  if (c < min) min = c;
  if (d < min) min = d;
  return min;
}