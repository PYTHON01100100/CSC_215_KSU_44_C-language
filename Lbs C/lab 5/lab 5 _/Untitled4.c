#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, i, j, flag, sum = 0, count = 0;
    float avg;
    int *arr;
    
    printf("Enter the number of values: ");
    scanf("%d", &n);
    
    arr = (int *)malloc(n * sizeof(int)); // dynamically allocate memory for array
    
    printf("Enter the values: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf("Unique values: ");
    for(i = 0; i < n; i++)
    {
        flag = 0;
        for(j = 0; j < i; j++)
        {
            if(arr[i] == arr[j])
            {
                flag = 1; // duplicate found
                break;
            }
        }
        for(j = i+1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                flag = 1; // duplicate found
                break;
            }
        }
        if(flag == 0) // unique value found
        {
            printf("%d ", arr[i]);
            sum += arr[i];
            count++;
        }
    }
    
    avg = (float)sum / (float)count; // calculate average
    printf("\nAverage: %.2f", avg);
    
    free(arr); // free the dynamically allocated memory
    
    return 0;
}