#include <math.h>
#include <stdio.h>
void display();
int main(){
    display();
    display();
    return 0;
}
void display(){
    static int c=0;
    printf("%d ", c);
    c +=5;
    // the first round will be 0 then 5 like we see
}
