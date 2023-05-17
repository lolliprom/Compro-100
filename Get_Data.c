#include <stdio.h>
#include <math.h>
#include<string.h>
#include <stdlib.h>
int Ciphertxt[1000][4];
int Row_Code[250][4];
//int OBFMatrix2
int i;

int main(){
    FILE *file;
    file = fopen("Ciphereiei.txt","r");
    int word2_count=0,row2_count=0,pos=0;

    if(file == NULL){
        printf("Error in opening!");
        return 1;
    }

    printf("Cipher: ");
    while(!feof(file)){
        if((pos+1)%5 != 0){
            for(i=0; i<4; i++){
                fscanf(file,"%d ",&Ciphertxt[row2_count][i]);
                printf("%d ",Ciphertxt[row2_count][i]);
                word2_count++;
                pos++;
            }
        }else{
            for(i=0; i<4; i++){
            	fscanf(file,"%1d",&Row_Code[row2_count][i]);
            	printf("%d",Row_Code[row2_count][i]);
            }
			row2_count++;
			pos++;
            printf(" ");	  
        }
    }
    printf("\n");
    //printf("\n%d",Row_Code[row2_count-1][0]);
    fclose(file);
    return 0;
}