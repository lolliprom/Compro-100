#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Matrix_filler(int inputi);
int i=0,j=0;

int main(){

    int input1[100][4],input[400];
   

    Matrix_filler(input1);

    printf("Type some int:");
    scanf("%[^\n]",input);

}

void Matrix_filler(int inputi)
{
     int swap;
    for(i=0; i<=100; i++);
     for(j=0; j<=4; j++)
        {
            swap = 0;
            inputi[i][j] = swap;
        }
}

