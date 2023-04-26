#include <math.h>
#include <stdio.h>

int main() {
    int a=1;
    int b=2;
    int c=3;
    int re1,re2,re3,re4;
    printf("::::: Powers Table :::::\n");
    printf("Number\tSquare\tCube\t4th power\n");
    // calculates the power
    re1=pow(a,1);re2=pow(a,2);re3=pow(a,3);re4=pow(a,4);
    printf("%d    \t%d    \t%d    \t%d    \n",re1,re2,re3,re4);
    re1=pow(b,1);re2=pow(b,2);re3=pow(b,3);re4=pow(b,4);
    printf("%d    \t%d    \t%d    \t%d    \n",re1,re2,re3,re4);
    re1=pow(c,1);re2=pow(c,2);re3=pow(c,3);re4=pow(c,4);
    printf("%d    \t%d    \t%d    \t%d    \n",re1,re2,re3,re4);
    // calculates the power
    printf("============================================================\n");
    printf("%d    \t%d    \t%d    \t%d    \n",re1,re2,re3,re4);
    printf("%d    \t%d    \t%d    \t%d    \n",re1,re2,re3,re4);
    printf("%d    \t%d    \t%d    \t%d    \n",re1,re2,re3,re4);

    return 0;
}