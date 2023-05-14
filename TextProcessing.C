#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

int Show_Menu(){
    int num;
    printf("\n");
    printf("===== MENU ===== \n");
    printf(" 1)CreatTextFile \n");
    printf(" 2)SortWithASCII \n");
    printf(" 0)Exit \n");
    printf(" \n");
    printf("Select...");
    scanf("%d",&num);
    if((num < 0)||(num > 5)){
        return -1;
    }
    return num;
}

int CreatTextFile(){
    FILE *fptr;
    char filename[50];
    char *message;

    printf("Enter the name of the file: ");
    scanf("%s", filename);
  
    printf("Enter the message to be written to the file: ");
    // scanf("%[^\n]", message);
    int len = 0;
    while((c = getchar()) != '\n' && c != EOF) {
       len++;
    }
    message = (char*) malloc(len+1)
  
    fptr = fopen(strcat(filename, ".txt"), "w");
  
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
  
    fprintf(fptr, "%s", message);
    fclose(fptr);
    printf("File written successfully.\n");

    return 0;
}

void Read_File(char* file_name, char words[][MAX_WORD_LENGTH], int* num_words) {
    FILE* File_Pointer;
    char word[MAX_WORD_LENGTH];
    int i = 0, j = 0;
    File_Pointer = fopen(file_name, "r");
    if (File_Pointer == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    while (1) {
        char ch = fgetc(File_Pointer);
        if (ch == EOF) {
            break;
        } else if (ch == ' ' || ch == '\t' || ch == '\n') {
            if (j > 0) {
                word[j] = '\0';
                strcpy(words[i], word);
                i++;
                j = 0;
                if (i >= MAX_WORDS) {
                    printf("Error: too many words in file.\n");
                    exit(1);
                }
            }
        } else {
            word[j] = ch;
            j++;
            if (j >= MAX_WORD_LENGTH) {
                printf("Error: word too long.\n");
                exit(1);
            }
        }
    }
    if (j > 0) {
        word[j] = '\0';
        strcpy(words[i], word);
        i++;
    }
    *num_words = i;
    fclose(File_Pointer);
}

void Encode_Cipher(char *input_file_name,char *output_file_name){
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
    
    while ((ch = fgetc(input_file)) != EOF) {
        ch = ch + key;
        fputc(ch, output_file);
    }
    
    fclose(input_file);
    fclose(output_file);
    
    printf("Encryption complete.\n");
}

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
    
    while ((ch = fgetc(input_file)) != EOF) {
        ch = ch - key;
        fputc(ch, output_file);
    }
    
    fclose(input_file);
    fclose(output_file);
    
    printf("Decryption complete.\n");
}

int main(){
    CreatTextFile();

    return 0;
}