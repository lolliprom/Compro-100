#include "CeasarCipher.h"

int main() {
    char input_filename[] = "Sample.txt";
    char encrypted_text[10000];
    char decrypted_text[10000];

    encrypt(input_filename, encrypted_text);
    printf("Encrypted Text: %s\n", encrypted_text);

    decrypt(encrypted_text, decrypted_text);
    printf("Decrypted Text: %s\n", decrypted_text);

    return 0;
}