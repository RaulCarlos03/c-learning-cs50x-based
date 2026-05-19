#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int conversion_a_numero(char letra, char cuadrado[5][5]);
char conversion_a_letra(int fila, int columna, char cuadrado[5][5]);
void transponer(int digitos[], int n, int resultado[]);

int main(int argc, string argv[]) {
    if(argc != 2) {
        printf("Usage: ./polibio key\n");
        return 1;
    }

    int cuadrado_lng = strlen(argv[1]);

    if(cuadrado_lng != 25) {
        printf("Key must contain 25 characters.\n");
        return 1;
    }

    for(int i = 0; i < 25; i++) {
        if(!isalpha(argv[1][i]) || toupper(argv[1][i]) == 'J') {
            printf("Key must only have letters and cannot contain J.\n");
            return 1;
        }
    }

    for(int i = 0; i < 25; i++) {
        for (int j = i + 1; j < 25; j++) {
            if (toupper(argv[1][i]) == toupper(argv[1][j])) {
                printf("Each letter must be only one time.\n");
                return 1;
            }
        }
    }

    char cuadrado[5][5];

    for (int fila = 0; fila < 5; fila++) {
        for (int columna = 0; columna < 5; columna++) {
            cuadrado[fila][columna] = toupper(argv[1][fila * 5 + columna]);
        }
    }

    string plaintext = get_string("plaintext:  " );
    int texto_lng = strlen(plaintext);

    int digitos[texto_lng * 2];
    int j = 0;

    int posiciones_espacios[texto_lng];
    int letras_vistas = 0;
    int k = 0;

    int resultado[texto_lng * 2];
    char ciphertext[texto_lng];
    int m = 0;
    int p = 0;

    for(int i = 0; i < texto_lng; i++) {
        if(isalpha(plaintext[i])) {
        char letra_buscada = toupper(plaintext[i]);

            if (letra_buscada == 'J') {
                letra_buscada = 'I';
            }

            int clave = conversion_a_numero(letra_buscada, cuadrado);
            int fil = clave / 10;
            int col = clave % 10;

            digitos[j++] = fil;
            digitos[j++] = col;
            letras_vistas++;
        }

        if(isspace(plaintext[i])) {
            posiciones_espacios[k++] = letras_vistas;
        }
    }

    //Prueba de bugs 1:
    printf("DEBUG digitos: ");
    for (int x = 0; x < j; x++) printf("%i", digitos[x]);
    printf("\n");

    transponer(digitos, j, resultado);

    //pruebe de bugs 2:
    printf("DEBUG resultado: ");
    for (int x = 0; x < j; x++) printf("%i", resultado[x]);
    printf("\n");

    for(int l = 0; l < j; l += 2) {
        ciphertext[m++] = conversion_a_letra(resultado[l], resultado[l + 1], cuadrado);
    }

    printf("ciphertext: ");

    for(int i = 0; i < m; i++) {
        if(p < k && posiciones_espacios[p] == i) {
            printf(" ");
            p++;
        }
        printf("%c", ciphertext[i]);
    }
    printf("\n");
}

int conversion_a_numero(char letra, char cuadrado[5][5]) {
    int fil = 0;
    int col = 0;
    int num = 0;

    for(int fila = 0; fila < 5; fila++) {
        for(int columna = 0; columna < 5; columna++) {
            fil = fila + 1;
            col = columna + 1;

            if(cuadrado[fila][columna] == letra) {
                num = (fil * 10) + col;
            }
        }
    }
    return num;
}

void transponer(int digitos[], int n, int resultado[]) {
    int mid = n / 2;
    int left[mid];
    int right[n - mid];

    for(int i = 0; i < mid; i++) {
        left[i] = digitos[i];
    }

    for(int j = 0; j < n - mid; j++) {
        right[j] = digitos[mid + j];
    }

    for(int k = 0; k < n; k++) {
        if(k % 2 == 0) {
            resultado[k] = left[k / 2];
        }
        else {
            resultado[k] = right[k / 2];
        }
    }
}

char conversion_a_letra(int fila, int columna, char cuadrado[5][5]) {
    return cuadrado[fila - 1][columna - 1];
}

