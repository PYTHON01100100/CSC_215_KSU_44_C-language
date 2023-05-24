#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[10];
    int i, j, n, count = 0, sum = 0;
    printf("Enter the number of elements you want to enter: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                printf("Duplicate value found, please try again.\n");
                return 0;
            }
        }
        sum += arr[i];
        count++;
        printf("%d ", arr[i]);
    }
    printf("\nAverage of unique values: %.2f", (float)sum/count);
    return 0;
}