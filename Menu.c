#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int Create_Menu(){
    int action;
    printf("Welcome to KODTUENG CRYTOGRAPHY, choose what you want to do:\n");
    printf("1.Encode\n2.Decode\n");
    printf("Choose what you want to do (in number):");
    scanf("%d",&action);
    return action;
}