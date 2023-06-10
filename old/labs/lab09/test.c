#include <stdio.h>
#include "functions.h"

int main(){
  int count, i;
  char* str = "The white cat invited the red cat to a caterpillar lunch";
  printf("%s\n\n", str_replace("cat", "tiger", str));
  char** carr = explode(" ", str, &count);
  for (i=0; i < count; i++)
    printf("%s\n", carr[i]);
  printf("\n%s\n", implode("|", carr, count));
  return 0;
}