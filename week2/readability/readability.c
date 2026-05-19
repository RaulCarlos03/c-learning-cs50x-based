#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void) {
    string texto = get_string("Text: " );
    int espacios = 0;
    int letras = 0;
    int palabras = 0;
    int frases = 0;

    int lng = strlen(texto);
    for(int i = 0; i < lng; i++) {
        if(isalpha(texto[i])) {
            letras++;
        }
        if(texto[i] == ' ') {
            espacios++;
        }
        if(texto[i] == '.' || texto[i] == '!' || texto[i] == '?') {
            frases++;
        }
    }

    palabras = espacios + 1;
    float L = (float) letras / palabras * 100;
    float S = (float) frases / palabras * 100;
    int indice = round(0.0588 * L - 0.296 * S - 15.8);

    if(indice < 1) {
        printf("Before Grade 1\n" );
    }
    else if(indice >= 16) {
        printf("Grade 16+\n" );
    }
    else {
        printf("Grade %i\n", indice);
    }
}
