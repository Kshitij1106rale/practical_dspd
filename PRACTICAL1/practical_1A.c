/*AIM: Write a program to accept 'n' numbers into an array and then calculate the sum of numbers present in odd positions and even positions respectively. */


#include <stdio.h>

int main() {
    int n;

    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

   
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum_even_pos = 0; 
    int sum_odd_pos = 0;  

   
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            sum_even_pos += arr[i];
        else
            sum_odd_pos += arr[i];
    }

    
    printf("Sum of numbers at even positions: %d\n", sum_even_pos);
    printf("Sum of numbers at odd positions: %d\n", sum_odd_pos);

    return 0;
}

/*
output:
Enter the number of elements: 6
Enter 6 elements:
10 20 30 40 50 60
Sum of numbers at even positions: 90
Sum of numbers at odd positions: 120
*/