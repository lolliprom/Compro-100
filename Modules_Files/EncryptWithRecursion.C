#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void EncryptFile(FILE *input_file, FILE *output_file, int key) {
    char ch = fgetc(input_file);
    
    if (ch == EOF) {
        fprintf(output_file, "\n\n%d", key);
        return;
    }
    
    if (ch == 32) {
        fprintf(output_file, " ");
    } else {
        ch = ch + key;
        fputc(ch, output_file);
    }
    
    EncryptFile(input_file, output_file, key);
}

void Encode_Cipher(const char *input_file_name, const char *output_file_name) {
    srand(time(NULL));
    FILE *input_file, *output_file;
    int key = rand() % 14 + 1;
    
    char *input_file_name_copy = strdup(input_file_name);
    char *output_file_name_copy = strdup(output_file_name);
    
    input_file = fopen(strcat(input_file_name_copy, ".txt"), "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    
    output_file = fopen(strcat(output_file_name_copy, ".txt"), "w");
    if (output_file == NULL) {
        printf("Error creating output file.\n");
        exit(1);
    }
    
    EncryptFile(input_file, output_file, key);
    
    fclose(input_file);
    fclose(output_file);
    
    printf("Encryption complete.\n");
    
    free(input_file_name_copy);
    free(output_file_name_copy);
}

int main() {
    const char *inputfilename = "Sample";
    const char *outputfilename = "EncryptedResult";
    
    Encode_Cipher(inputfilename, outputfilename);
    
    return 0;
}
