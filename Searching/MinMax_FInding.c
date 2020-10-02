#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

void MinMax(int *arr, int l, int h, int *max, int *min)
{
    int max1, min1;
    if (l == h) { // case I - only one item
        *max = *min = arr[0];
    }

    else if (l == h - 1) { // case II - when there are two elements
        if (arr[l] > arr[h])
        {
            *max = arr[l];
            *min = arr[h];
        }

        else {
            *max = arr[h];
            *min = arr[l];
        }
    }

    else { // case - III
        int mid = (l + h) / 2; // Divide
        MinMax(arr, l, mid, max , min); // conquer
        MinMax(arr, mid+1, h, &max1 , &min1); //conquer

        if(*max < max1) *max = max1; //combine
        if(*min > min1) *min = min1;  //combine
    }
}




int main(int argc, char const *argv[])
{
    int arr[SIZE], n;
    clock_t start, end;
    double total_time = 0.00;
    int min, max;

    printf("Enter number of elements : ");
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }

    MinMax(arr, 0, n-1, &max, &min);
    
    printf("Min element :  %d\nMax element : %d\n", min, max);


    return 0;
}
