#include <cs50.h>
#include <stdio.h>

int binary_search(int values[], int n, int target);

int main(void) {
    int list[] = {2, 5, 8, 12, 16, 23, 38, 42, 56, 72, 91};
    int list_lng = sizeof(list) / sizeof(list[0]);
    int number = get_int("Number: " );

    int result = binary_search(list, list_lng, number);
    if(result == -1) {
        printf("Not found\n");
    }
    else {
        printf("Found at index %i\n", result);
    }
}

int binary_search(int values[], int n, int target) {
    int low = 0;
    int high = n - 1;


    while(low <= high) {
        int mid = (low + high) / 2;
        if(values[mid] == target) {
            return mid;
        }
        else if(values[mid] < target) {
            low = mid + 1;
        }
        else if(values[mid] > target) {
            high = mid - 1;
        }
    }
    return -1;
}
