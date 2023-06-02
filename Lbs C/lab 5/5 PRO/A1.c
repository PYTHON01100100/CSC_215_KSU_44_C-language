#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("please enter No of int to sum: ");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        printf("enter the No #%d :",(i+1));
        scanf("%d",&arr[i]);
    }
    /**/
    int tot=0;
    for(int i=0;i<n;i++){
    printf("%d + ",arr[i]);
    tot+=arr[i];
}

printf("=%d",tot);
float avg=(double) tot/n;
printf("\n the avg: %.2f",avg);
return 0;
}