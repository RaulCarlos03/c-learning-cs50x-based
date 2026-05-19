#include <cs50.h>
#include <stdio.h>

void selection_sort(int values[], int n);
void print_array(int values[], int n);

int main(void) {
    int list[] = {42, 5, 91, 16, 8, 23, 2, 56, 38, 12, 72};
    int list_lng = sizeof(list) / sizeof(list[0]);

    printf("Before: ");
    print_array(list, list_lng);
    selection_sort(list, list_lng);
    printf("After:  ");
    print_array(list, list_lng);
}

void selection_sort(int values[], int n) {
    int aux = 0;
    int min_idx = 0;

    for(int i = 0; i < n - 1; i++) {
        min_idx = i;
        for(int j = i + 1; j < n; j++) {
            if(values[j] < values[min_idx]) {
                min_idx = j;
            }
        }
        aux = values[i];
        values[i] = values[min_idx];
        values[min_idx] = aux;
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
