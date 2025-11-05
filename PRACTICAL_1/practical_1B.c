#include <stdio.h>

int main() {
    int io, search, start = 0, found = 0, mid = 0, n;
    int arr[50];

    printf("Enter the range of the array: ");
    scanf("%d", &n);

    printf("Enter the sorted elements of the array:\n");
    for (io = 0; io < n; io++) {
        scanf("%d", &arr[io]);
    }

    printf("Enter the element whose location you need to find (in the array): ");
    scanf("%d", &search);

    int high = n - 1;

    while (start <= high) {
        mid = (start + high) / 2;
        printf("Start = %d, End = %d\n", start, high);
        printf("Midpoint value = %d\n", arr[mid]);

        if (search == arr[mid]) {
            printf("The element %d is present at index %d\n", search, mid);
            found = 1;
            break;
        } else if (search < arr[mid]) {
            high = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    if (!found) {
        printf("The element %d is not present in the array.\n", search);
    }

    return 0;
}

