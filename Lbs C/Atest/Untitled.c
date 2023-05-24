#include <math.h>
#include <stdio.h>
void funct1(void); void funct2(void);
int globvar =10;
int main(){
    int numbers[5]={0, 1, 2, 3, 4};
    int* ptr=numbers;
    printf("0)%d\t",*ptr);
    printf("%d\n",numbers[0]);
    ++*ptr; 
    printf("0)%d\t",*ptr);
    printf("%d\n",numbers[0]);
    *++ptr; //1
    printf("1)%d\t",*ptr);
    printf("%d\n",numbers[1]);
    ++*ptr; 
    printf("1)%d\t",*ptr);
    printf("%d\n",numbers[1]);
    *ptr++;//2
    printf("2)%d\t",*ptr);
    printf("%d\n",numbers[2]);
    *ptr++; //3
    printf("3)%d\t",*ptr);
    printf("%d\n",numbers[3]);
return 0;
}