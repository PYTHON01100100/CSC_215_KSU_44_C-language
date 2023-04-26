#include <stdio.h>
int main() {
    unsigned char flag=89;
    printf("Lights= %d\n",flag & 1);
    printf("Curtains = %d\n",flag >> 1 & 1);
    printf("TV = %d\n",flag >> 2&1);
    printf("AC = %d\n",flag >> 3 & 15);
    printf("Alarm = %d\n",flag >>7 & 1);
    printf("============================\n");
    // Turn TV on
    // flag=flag|4
    flag |=4;
    printf("TV = %d\n",flag >> 2&1);
    printf("============================\n");
    //AC -> 12
    flag &=~(15<<3);
    flag |=12<<3;
    printf("Lights= %d\n",flag & 1);
    printf("Curtains = %d\n",flag >> 1 & 1);
    printf("TV = %d\n",flag >> 2&1);
    printf("AC = %d\n",flag >> 3 & 15);
    printf("Alarm = %d\n",flag >>7 & 1);


 return 0;
}