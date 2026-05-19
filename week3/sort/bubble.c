#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int values[], int n);
void print_array(int values[], int n);

int main(void) {
    int list[] = {42, 5, 91, 16, 8, 23, 2, 56, 38, 12, 72};
    int list_lng = sizeof(list) / sizeof(list[0]);

    printf("Before: ");
    print_array(list, list_lng);
    bubble_sort(list, list_lng);
    printf("After:  ");
    print_array(list, list_lng);
}

void bubble_sort(int values[], int n) {
    bool swapped = true;
    int aux = 0;

    while(swapped) {
        swapped = false;
        for(int i = 0; i < n - 1; i++) {
            if(values[i] > values[i + 1]) {
                aux = values[i];
                values[i] = values[i + 1];
                values[i + 1] = aux;
                swapped = true;
            }
        }
    }
}

void print_array(int values[], int n) {
    for(int i = 0; i < n; i++) {
        if(i > 0) {
            printf(" ");
        }
        printf("%i", values[i]);
    }
    printf("\n");
}
