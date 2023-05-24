#include <math.h>
#include <stdio.h>

int main() {

    char ch, *str = "Hello World";
    while((ch= *str++ ) != '\0')
    printf("%c", ch);
    puts("\n------------------------");
    int *p, arr[] = {10,33,15,22,14};
    for(p=arr; p<arr+5; p+=2)
    printf("%d ", *p);
    puts("\n------------------------");
    char n=0, *s, *e, str2[] = "siht hsinif ot ekil I";
    while(str2[++n]);
    for(s=str2, e=str2+n-1; e>s ;e--,s++ ){
        str2[n] = *e;
        *e = *s;
        *s = str2[n];
        }
        str2[n] = '\0';
        



    return 0;
}