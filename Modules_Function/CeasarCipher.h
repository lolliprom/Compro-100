#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include <stdio.h>

void encrypt_recursive(FILE* file, int key, char* encrypted_text, int index);
void encrypt(const char* input_filename, char* encrypted_text);
void decrypt(const char* encrypted_text, char* decrypted_text);

#endif