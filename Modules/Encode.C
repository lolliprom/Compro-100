#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void Encode_Cipher(char *input_file_name,char *output_file_name){
    srand(time(NULL));
    FILE *input_file, *output_file;
    char ch;
    int key = rand() % 14 + 1;
    
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
    
    while ((ch = fgetc(input_file)) != EOF) {
        if(ch == 32){
            fprintf(output_file," ");
            continue;
        }
        ch = ch + key;
        fputc(ch, output_file);
    }
    fprintf(output_file,"\n\n%d",key);
    
    fclose(input_file);
    fclose(output_file);
    
    printf("Encryption complete.\n");
}

int main(){
    char inputfilename[10] = "Sample", outputfilename[20] = "EncryptedResult";
    Encode_Cipher(inputfilename,outputfilename);
}