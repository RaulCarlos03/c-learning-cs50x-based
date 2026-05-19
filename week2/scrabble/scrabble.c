#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int puntuar(string palabra, int valores[]);

int main(void) {
    int valores[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    string palabra1 = get_string("Player 1: " );
    string palabra2 = get_string("Player 2: " );
    int puntos1 = puntuar(palabra1, valores);
    int puntos2 = puntuar(palabra2, valores);

    if(puntos1 > puntos2) {
        printf("Player 1 wins!\n" );
    }
    else if(puntos1 < puntos2) {
        printf("Player 2 wins!\n" );
    }
    else {
        printf("Tie!\n" );
    }
}

int puntuar(string palabra, int valores[]) {
    int total = 0;
    for(int i = 0; i < strlen(palabra); i++) {
        char letra = palabra[i];
        if(isalpha(letra)) {
            total = total + valores[toupper(letra) - 'A'];
        }
    }
    return total;
}
