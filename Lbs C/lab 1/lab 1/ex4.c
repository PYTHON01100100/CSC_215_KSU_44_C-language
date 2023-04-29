#include <stdio.h>

int main(){
  char letter = 'b';
  printf("%c\n", letter);
  printf("%d\n", letter);
  printf("%c\t%d\n", letter, letter);

  printf("%c\t%c\n", letter, letter+15);
  /* letter+15 is the character that comes in the 15th place after 'b' in the ASCII table */

  return 0;
}