#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int CreatTextFile(){
    FILE *fptr;
    char filename[100];
    char *message;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    printf("Enter the message to be written to the file: ");
    message = (char*) malloc(1000 * sizeof(char));
    scanf(" %[^\n]", message);

    fptr = fopen(strcat(filename, ".txt"), "w");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(fptr, "%s", message);
    fclose(fptr);
    printf("File written successfully.\n");

    free(message);

    return 0;
}

int main(){
    CreatTextFile();
}
