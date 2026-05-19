#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) {
    if(argc != 2) {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    int clave_lng = strlen(argv[1]);
    if(clave_lng != 26) {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for(int i = 0; i < 26; i++) {
        if(!isalpha(argv[1][i])) {
            printf("Key must only have letters.\n");
            return 1;
        }
    }
    for(int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (toupper(argv[1][i]) == toupper(argv[1][j])) {
                printf("Each letter must be only one time.\n");
                return 1;
            }
        }
    }

    string plaintext = get_string("plaintext:  " );
    int texto_lng = strlen(plaintext);

    for(int i = 0; i < texto_lng; i++) {
        if(isupper(plaintext[i])) {
            plaintext[i] = toupper(argv[1][toupper(plaintext[i]) - 'A']);
        }
        else if(islower(plaintext[i])) {
            plaintext[i] = tolower(argv[1][toupper(plaintext[i]) - 'A']);
        }
    }
     printf("ciphertext: %s\n", plaintext);
}
