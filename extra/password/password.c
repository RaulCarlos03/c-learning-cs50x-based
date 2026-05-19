#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

string robustez(string password);

int main(void) {
    string password = get_string("Password: ");
    string robust = robustez(password);
    printf("%s\n", robust);
}

string robustez(string password) {
    bool has_upper = false;
    bool has_lower = false ;
    bool has_digit = false;
    bool has_symbol = false;
    int flags_sum = 0;
    int password_lng = strlen(password);

    for(int i = 0; i < password_lng; i++) {
        if(isdigit(password[i])) {
            has_digit = true;
        }
        else if(isupper(password[i])) {
            has_upper = true;
        }
        else if(islower(password[i])) {
            has_lower = true;
        }
        else {
            has_symbol = true;
        }
    }
    flags_sum = has_digit + has_upper + has_lower + has_symbol;
    if(password_lng > 7 && flags_sum == 4) {
        return "Strong";
    }
    if(password_lng > 5 && flags_sum >= 3) {
        return "Medium";
    }
    return "Weak";
}
