#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Decode_Cipher(char* input_file_name, char* output_file_name){
    FILE *input_file, *output_file;
    char message[800];
    
    input_file = fopen(strcat(input_file_name, ".txt"), "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    
    output_file = fopen(strcat(output_file_name, ".txt"), "w");
    if (output_file == NULL) {
        printf("Error creating output file.\n");
        exit(1);
    }

    int i = 0;
    while((message[i] = fgetc(input_file)) != EOF) i++;

    int key = atoi(&message[i-2]);

    i = 0;
    while(message[i] != '\0'){
        if(message[i] == 32){
            fputc(' ', output_file);
            i++;
            continue;
        }
        else if(message[i] == '\n'){
            fputc('\n', output_file);
            i++;
            continue;
        }
        message[i] -= key;
        if(message[i]>=33 && message[i]<=126) fputc(message[i], output_file);
        i++;
    }
    
    fclose(input_file);
    fclose(output_file);
    
    printf("Decryption complete.\n");
}

int main(){
    char inputfilename[] = "EncryptedResult", outputfilename[] = "DecryptedResult";
    Decode_Cipher(inputfilename, outputfilename);
    return 0;
}
