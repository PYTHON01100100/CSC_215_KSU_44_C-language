#include <math.h>
#include <stdio.h>

int main() {
    int x[4]={12,20,39,43}, *y;
    y=x;
    printf("1) %d \n",*y+1);
    printf("2) %d \n",*(y+1));
    y+=2;
    printf("3) %d \n",*y);
    *y=38;
    printf("4) %d \n",*y);
    printf("5) %d \n",*y-1);
    printf("6) %d \n",*y++);
    printf("7) %d \n",*y);
    printf("8) %d \n",y[0]);
    printf("9) %d \n",x[2]>y[0]);
    printf("10) %d \n",y-x);
    return 0;
}