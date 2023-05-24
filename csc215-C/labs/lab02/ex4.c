#include <stdio.h>

int main(){

  printf("%f\n", 22/7.0);

  printf("%.10f\n", 22/7.0);

  printf("%20.10f\n", 22/7.0);

  printf("%020.10f\n", 22/7.0);

  printf("%+.10f\n", 22/7.0);

  printf("%.10f%%\n", 22/7.0);

  printf("%e\n", 22/7.0);

  printf("%x\n", 31567);

  printf("%.4s\n", "Good morning");

  printf("%10.4s\n", "Good morning");

  return 0;
}