#include <cs50.h>
#include <stdio.h>

void merge(int aa[], int n_a, int bb[], int n_b, int res[]);
void print_array(int res[], int n);

int main(void) {
    int a[] = {2, 7, 12, 19, 25};
    int b[] = {3, 5, 14, 18, 22, 30};
    int a_lng = sizeof(a) / sizeof(a[0]);
    int b_lng = sizeof(b) / sizeof(b[0]);
    int result[a_lng + b_lng];
    int res_lng = sizeof(result) / sizeof(result[0]);

    merge(a, a_lng, b, b_lng, result);
    print_array(result, res_lng);
}

void merge(int aa[], int n_a, int bb[], int n_b, int res[]) {
    int i = 0;
    int j = 0;
    int k = 0;

    while(i < n_a && j < n_b) {
        if(aa[i] <= bb[j]) {
            res[k] = aa[i];
            i++;
        }
        else if(aa[i] > bb[j]) {
            res[k] = bb[j];
            j++;
        }
        k++;
    }

    while(i < n_a) {
        res[k] = aa[i];
        i++;
        k++;
    }

    while(j < n_b) {
        res[k] = bb[j];
        j++;
        k++;
    }
}

void print_array(int res[], int n) {
    for(int i = 0; i < n; i++) {
        if(i > 0) {
            printf(" ");
        }
        printf("%i", res[i]);
    }
    printf("\n");
}
