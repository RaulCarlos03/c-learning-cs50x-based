#include <cs50.h>
#include <stdio.h>

int linear_search(int values[], int n, int target);

int main(void) {
    int list[] = {4, 8, 15, 16, 23, 42, 7, 9, 31, 50};
    int list_lng = sizeof(list) / sizeof(list[0]);
    int number = get_int("Number: " );

    int result = linear_search(list, list_lng, number);
    if(result == -1) {
        printf("Not found\n");
    }
    else {
        printf("Found at index %i\n", result);
    }
}

int linear_search(int values[], int n, int target) {
    for(int i = 0; i < n; i++) {
        if(values[i] == target) {
            return i;
        }
    }
    return -1;
}
