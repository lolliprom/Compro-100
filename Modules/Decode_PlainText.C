#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

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

void Encode_Cipher(char *filename_input,char *filename_output){
    int key = 0;
    while()
}

void Decode_Cipher(){

}

int main(){

}