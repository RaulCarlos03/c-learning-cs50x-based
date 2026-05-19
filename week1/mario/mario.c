#include <cs50.h>
#include <stdio.h>

void left(int n);
int get_in_range_int(void);

int main(void) {
    int n = get_in_range_int();
    left(n);
}

int get_in_range_int(void) {
    int n;
    do {
        n = get_int("Set the pyramid length (between 1 - 8 units):" );
    } while(n < 1 || n > 8);
    return(n);
}

void left(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        for(int k = 0; k < i + 1; k++) {
            printf("#");
        }
        printf("  ");
        for(int l = n + 1; l < n + i + 2; l++) {
            printf("#");
        }
        printf("\n");
    }
}

