#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void encrypt_recursive(FILE* file, int key, char* encrypted_text, int index) {
    char ch = fgetc(file);
    if (ch == EOF) {
        char key_str[2];
        sprintf(key_str, "%d", key);
        encrypted_text[index] = key_str[0];
        encrypted_text[index + 1] = '\0';
        fclose(file);
        return;
    }

    if (ch == ' ') {
        encrypted_text[index] = ch;
    } else {
        ch += key;
        encrypted_text[index] = ch;
    }
    
    encrypt_recursive(file, key, encrypted_text, index + 1);
}

void encrypt(const char* input_filename, char* encrypted_text) {
    printf("Opening file...\n");
    FILE* file = fopen(input_filename, "r");
    while (file == NULL) {
        file = fopen(input_filename, "r");
    }
    printf("Open file complete.\n");

    srand(time(NULL));
    int key = rand() % 9 + 1;
    encrypt_recursive(file, key, encrypted_text, 0);
}

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
