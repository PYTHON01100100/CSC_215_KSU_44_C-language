#include <stdio.h>
#include <math.h>
const float PI = 3.14;

int main(){
  int radius;
  char color[10];
  printf("Enter the circle radius > ");
  scanf("%d", &radius);
  printf("Enter the circle color > ");
  scanf("%s", color);

  printf("The %s circle are = %.2f\n", color, PI*radius*radius);

  /* The following works if the -ansi is omitted from compilation */
  printf("The %s circle are = %.2f\n", color, M_PI*radius*radius);
  return 0;
}