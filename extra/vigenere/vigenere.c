#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) {
    if(argc != 2) {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }

    int clave_lng = strlen(argv[1]);

    for(int i = 0; i < clave_lng; i++) {
        if(!isalpha(argv[1][i])) {
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }
    }

    string clave = argv[1];

    string plaintext = get_string("plaintext:  " );
    int text_lng = strlen(plaintext);
    int shift = 0;
    int k = 0;

    for(int j = 0; j < text_lng; j++) {
        if(isupper(plaintext[j])) {
            shift = (toupper(clave[k % clave_lng]) - 'A') % 26;
            plaintext[j] = (plaintext[j] - 'A' + shift) % 26 + 'A';
            k++;
        }
        if(islower(plaintext[j])) {
            shift = (toupper(clave[k % clave_lng]) - 'A') % 26;
            plaintext[j] = (plaintext[j] - 'a' + shift) % 26 + 'a';
            k++;
        }
    }
    printf("ciphertext: %s\n", plaintext);
}
