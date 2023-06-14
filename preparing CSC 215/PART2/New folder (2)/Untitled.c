#include <stdio.h>
#include <math.h>
void foo(int*);
int main()
{
char str1[] = "Hello";
char str2[] = "Hello";
if(str1 == str2)
 printf("Equal");
else
 printf("\nUnequal");
}
void foo(int *p)
{
int j = 2;
p = &j;
printf("%d ", *p);
}
