#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void decrypt(const char* encrypted_text, char* decrypted_text) {
    int key = encrypted_text[strlen(encrypted_text) - 1] - '0';

    for (int i = 0; i < strlen(encrypted_text) - 1; i++) {
        char ch = encrypted_text[i];
        if (ch == ' ') {
            decrypted_text[i] = ch;
        } else {
            ch -= key;
            decrypted_text[i] = ch;
        }
    }

    decrypted_text[strlen(encrypted_text) - 1] = '\0';
}

int main() {
    char encrypted_text[] = "Ymnx nx f nruqjrjsyfynts knqj ytyfq 8<596<89=68=9<=78<69>=88785 ynrj35";
    char decrypted_text[10000];

    printf("Encrypted Text: %s\n", encrypted_text);

    decrypt(encrypted_text, decrypted_text);
    printf("Decrypted Text: %s\n", decrypted_text);

    return 0;
}
