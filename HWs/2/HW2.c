#include <stdio.h>
int main() {
int x=1 , y=7,z=0; double i=1.5,j=-0.7; char a='m';
int re=0;
printf("Result(1): %f \n",x * y - z / i);
re= (3 * (2*x+1)/ x);
printf("Result(2): %d \n",re);
re= (x&&y|z);
printf("Result(3): %d \n",re);
re= 0;
printf("Result(4): %f \n",(double)(x/i*y));
re= (double)(a/y+(int)i/x);
printf("Result(5): %d \n",re);
re= (i>j&j>x||!z);
printf("Result(6): %d \n",re);
re= (x+y--+z++);
printf("Result(7): %d \n",re);
re= 0;
printf("Result(8): %.2f \n",--x>z++?y--:i*j);
re= (a?y-x:x-y);
printf("Result(9): %d \n",re);
re= (x=5?(y=z):(z=y));
printf("Result(10): %d \n",re);
//hw2 done
   return 0;
}