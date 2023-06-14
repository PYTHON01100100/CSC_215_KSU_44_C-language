#include <stdio.h>

int main(){
  int a = 1, b = 10, c = 0;

  printf("a=%d b=%d c=%d\n", a, b, c);

  printf("%c++ + %d = %d\n", 'a', b, a++ + b);

  printf("++%c + %d = %d\n", 'a', b, ++a + b);
  
  printf("%d && %d = %d\n", a, c, a && c);

  printf("%d || %d = %d\n", a, c, a || c);

  printf("%d & %d = %d\n", a, 2, a & 2);

  printf("%d | %d = %d\n", a, 0, a | 0);

  printf("%d << %d = %d\n", a, 2, a << 2);

  printf("%d >> %d = %d\n", a, 1, a >> 1);

  return 0;
}