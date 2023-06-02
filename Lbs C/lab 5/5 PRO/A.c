#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, flag;
    int *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int*) malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
        flag = 0;
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                printf("%d is not a unique value.\n Please enter a unique value: ", arr[i]);
                scanf("%d", &arr[i]);
                flag = 1;
                break;
            }
        }
        if (flag) i--;
    }

    printf("Unique values entered are: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    int sum = 0, count = 0;
    double avg;
    for (i = 0; i < n; i++) {
        flag = 0;
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            sum += arr[i];
            count++;
        }
    }
    avg = (double) sum / count;
    printf("\nAverage of unique values entered is: %.2lf", avg);

    free(arr);
    return 0;
}