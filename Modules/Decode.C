#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Decode_Cipher(char* input_file_name, char* output_file_name){
    FILE *input_file, *output_file;
    char ch;
    int key = 10;
    
    input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    
    output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error creating output file.\n");
        exit(1);
    }

    // for (i = 0; str[i] != '\0'; i++);
    // num = atoi(&str[i-2]);
    
    while ((ch = fgetc(input_file)) != EOF) {
        if(ch == 32){
            fputc(" ", output_file);
            continue;
        }
        ch = ch - key;
        fputc(ch, output_file);
    }
    
    fclose(input_file);
    fclose(output_file);
    
    printf("Decryption complete.\n");
}

int main(){
    
}