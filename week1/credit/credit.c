#include <cs50.h>
#include <stdio.h>

int get_head(long n);
int suma_dobles(long n);
int suma_simples(long n);

int main(void) {
    int suma = 0;
    int cont = 0;
    long n = get_long("Number:" );
    int head_2 = get_head(n);
    int head_1 = head_2 / 10;
    long temp = n;

    while(temp > 0) {
        temp = temp / 10;
        cont++;
    }
    if(cont < 13 || cont > 16) {
        printf("INVALID\n");
    }
    else {
        suma = suma_simples(n);
        if(suma % 10 == 0) {
            if(head_1 == 4 && (cont == 13 || cont == 16)) {
                printf("VISA\n");
            }
            else if((head_2 == 51 || head_2 == 52 || head_2 == 53 ||head_2 == 54 ||head_2 == 55) && cont == 16) {
                printf("MASTERCARD\n");
            }
            else if((head_2 == 34 || head_2 == 37) && cont == 15) {
                printf("AMEX\n");
            }
            else {
                printf("INVALID\n");
            }
        }
        else {
            printf("INVALID\n");
        }
    }
}

int get_head(long n) {
    long temp = n;

    while(temp >= 100) {
        temp = temp / 10;
    }
    return(temp);
}

int suma_dobles(long n) {
    int sum = 0;
    int digit = 0;
    long temp = n;
    int i = 0;

    while(temp > 0) {
        digit = temp % 10;
        if(i % 2 != 0) {
            digit = digit * 2;
            if(digit > 9) {
                sum = sum + (digit % 10) + (digit / 10);
            }
            else {
                sum = sum + digit;
            }
        }
        temp = temp / 10;
        i++;
    }
    return sum;
}

int suma_simples(long n) {
    int sum = suma_dobles(n);
    int digit = 0;
    int i = 0;
    long temp = n;

    while(temp > 0) {
        digit = temp % 10;
        if(i % 2 == 0) {
            sum = sum + digit;
        }
        temp = temp / 10;
        i++;
    }
    return sum;
}
