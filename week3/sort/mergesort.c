#include <cs50.h>
#include <stdio.h>

void merge_sort(int values[], int n);
void merge(int left[], int mid, int right[], int n_mid, int values[]);
void print_array(int values[], int n);

int main(void) {
    int list[] = {42, 5, 91, 16, 8, 23, 2, 56, 38, 12, 72};
    int list_lng = sizeof(list) / sizeof(list[0]);

    printf("Before: ");
    print_array(list, list_lng);
    merge_sort(list, list_lng);
    printf("After:  ");
    print_array(list, list_lng);
}

void merge_sort(int values[], int n) {
    if(n <= 1) {
        return;
    }

    int mid = n / 2;
    int n_mid = n - mid;
    int left[mid];
    int right[n - mid];

    for(int i = 0; i < mid; i++) {
        left[i] = values[i];
    }

    for(int j = 0; j < n - mid; j++) {
        right[j] = values[mid + j];
    }

    merge_sort(left, mid);
    merge_sort(right, n - mid);

    merge(left, mid, right, n_mid, values);
}

void merge(int left[], int mid, int right[], int n_mid, int values[]) {
    int i = 0;
    int j = 0;
    int k = 0;

    while(i < mid && j < n_mid) {
        if(left[i] <= right[j]) {
            values[k] = left[i];
            i++;
        }
        else if(left[i] > right[j]) {
            values[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < mid) {
        values[k] = left[i];
        i++;
        k++;
    }

    while(j < n_mid) {
        values[k] = right[j];
        j++;
        k++;
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
