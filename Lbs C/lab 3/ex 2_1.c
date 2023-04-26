#include <stdio.h>
#include <math.h>


int main() {
    double sum=0;
    for(int i=1;i<=100;i++){
        double t1 =pow(-1,i+1);
        double t2 =pow(i,2);
        double t3 =pow(i+5,2);
        sum +=t1*t2/t3;
    }
    printf("the sum of first 1000 is %f \n",sum);
    puts("=======================================================================================");
    sum=0;
    double sum2=0;
        for(int i=1;fabs(sum)<0.5;i++){
            sum2=sum;
        double t1 =pow(-1,i+1);
        double t2 =pow(i,2);
        double t3 =pow(i+5,2);
        sum +=t1*t2/t3;
    }
        printf("the sum of first 1000 is %f \n",sum);

    return 0;
}
