#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) {
    //Comprobaciones de validez del argumento de linea:
    if(argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int argv_length = strlen(argv[1]);

    for(int i = 0; i < argv_length; i++) {
        if(!isdigit(argv[1][i])) {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int clave = atoi(argv[1]);

    string plaintext = get_string("plaintext:  " );
    int texto_lng = strlen(plaintext);

    for(int i = 0; i < texto_lng; i++) {
        if(isupper(plaintext[i])) {
            plaintext[i] = (plaintext[i] - 'A' + clave) % 26 + 'A';
        }
        else if(islower(plaintext[i])) {
            plaintext[i] = (plaintext[i] - 'a' + clave) % 26 + 'a';
        }
    }
    printf("ciphertext: %s\n", plaintext);
}
