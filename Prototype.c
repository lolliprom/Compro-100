#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define Size_of_Arrays 10000
int menu;
char filename[100];

struct ASCII //character and it's ASCII value.
	{
		char character[Size_of_Arrays];
		int ascno[Size_of_Arrays];
	};
int OBFMatrix[Size_of_Arrays][4] ;
int setofnumbers[8][4]={{8,1,8,9},{5,5,0,9},{6,3,3,1},{5,4,5,4},{8,0,4,3},{8,9,9,0},{1,9,7,2},{0,7,3,4}};
int Generator_Matrix[4][4];
int Row_Pos_Matrix[4];
int Mutiplied_Matrix[1][4];
int arr[1][4];
int i,j,k,l=0,swap,final_count=0;

int Create_Menu(){

    int action, check;
  do{
    printf("==============================================================\n");
    printf("=             Welcome to KODTUENG CRYTOGRAPHY                =\n");
    printf("==============================================================\n");
    printf("Choose what you want to do:\n");
    printf("1.Encrypt\n2.Deccrypt\n");
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("Type 1 or 2:");
    check = scanf("%d",&action);
    while (getchar() != '\n');
    if(check != 1) printf("Invalid input. Please enter an integer.\n\n");
    else return action;
    
  }while(check != 1);
}


float Ciphertxt[Size_of_Arrays][4];
int Row_Code[Size_of_Arrays][4];
int FBFMatrix[4][4];
float Inverse[4][4];
int adjoint[4][4];
int detSum;
float Mutiplied_Matrix2[1][4]; //already had in Matrix_encode
float arr2[1][4]; //already had in Matrix_encode
int Result_Matrix[Size_of_Arrays][4];
int i,j,k,FBF_count=0;

int FindTextfile(){
    FILE *fptr;
    char *message;

    printf("Enter the name of file that stores data for encrypt/decrypt: ");
    scanf("%s", filename);

    strcat(filename, ".txt");

    return 0;
}

void encrypt_recursive(FILE* file, int key, char* encrypted_text, int index) {
    char ch = fgetc(file);
    if (ch == EOF) {
        char key_str[2];
        sprintf(key_str, "%d", key);
        encrypted_text[index] = key_str[0];
        encrypted_text[index + 1] = '\0';
        fclose(file);
        return;
    }

    if (ch == ' ') {
        encrypted_text[index] = ch;
    } else {
        ch += key;
        encrypted_text[index] = ch;
    }
    
    encrypt_recursive(file, key, encrypted_text, index + 1);
}

void encrypt(const char* input_filename, char* encrypted_text) {
    printf("\nOpening file...\n");
    FILE* file = fopen(input_filename, "r");
    while (file == NULL) {
        file = fopen(input_filename, "r");
    }
    printf("Open file complete.\n");

    srand(time(NULL));
    int key = rand() % 9 + 1;
    encrypt_recursive(file, key, encrypted_text, 0);
}

void decrypt(const char* encrypted_text, char* decrypted_text) {
    int key = encrypted_text[strlen(encrypted_text) - 1] - '0';

    for (int i = 0; i < strlen(encrypted_text) - 1; i++) {
        char ch = encrypted_text[i];
        if (ch == ' ') {
            decrypted_text[i] = ch;
        } else {
            ch -= key;
            decrypted_text[i] = ch;
        }
    }

    decrypted_text[strlen(encrypted_text) - 1] = '\0';
}

void MultiplyMatrix(int (*a)[1][4]) {
    int m = 1;
    int n = 4;
    int o = 4;
    int p = 4;
    int sum=0,i,j,h;

    for(i=0; i<4; i++){
        //printf("%d ",(*a)[0][i]);

    }
    //printf("\n");
	for(i=0; i<m; i++)
		for(j=0; j<p; j++)
			Mutiplied_Matrix[i][j]=0;
			
	for(i=0; i<m; i++)
	{
		for(j=0; j<p; j++)
		{
			sum=0;
			for(h=0;h<n;h++)
			{
				sum = sum+((*a)[i][h])*Generator_Matrix[h][j];
			}
			Mutiplied_Matrix[i][j]=sum;

		}
	}
    //printf("\n");
}

int Char_to_ASCII(char *OBF, int size) {
    char a;
    int i,j,b,count=0;
    struct ASCII x;
	
    for(i=0; i<size; i++) {
        a = *OBF;
        x.character[i] = a;
		
        b = *OBF;
        x.ascno[i] =  b;
		
        if(i%4==0 && i!=0) {
            count++;
        }
        OBF++;
    }
	
    return count;
}

void ASCII_to_Matrix(int rowsize, int size) {
    int i,j,a,k=0;
    struct ASCII x;
	
    for(i=0; i<=rowsize; i++) {
        for(j=0; j<=3; j++) {	
            a = 0 ;
            OBFMatrix[i][j] = a;
        }
    }
    for(i=0; i<=rowsize; i++) {
        for(j=0; j<=3; j++) {
            if(k<=size) {
                a = x.ascno[k];
                OBFMatrix[i][j] = a;
                k++;
            } else {
                break;
            }
        }
    }
}

void generate_matrix(int (*x)[4][4]){
    for (int i=0;i<4;i++) {
        int r = rand()%8;
        for (int j=0;j<4;j++) {
            (*x)[i][j] = setofnumbers[r][j];
        }
    }
}

int det3x3_ForEncode(int matrix[4][4], int i, int j) {
    int submatrix[3][3];
    int k, l, row, col;
    for (k = 0, row = 0; k < 4; k++) {
        if (k == i) continue;
        for (l = 0, col = 0; l < 4; l++) {
            if (l == j) continue;
            submatrix[row][col] = matrix[k][l];
            col++;
        }
        row++;
    }
    return submatrix[0][0]*((submatrix[1][1]*submatrix[2][2])-(submatrix[2][1]*submatrix[1][2]))-submatrix[0][1]*(submatrix[1][0]*submatrix[2][2]-submatrix[2][0]*submatrix[1][2])+submatrix[0][2]*(submatrix[1][0]*submatrix[2][1]-submatrix[2][0]*submatrix[1][1]);
}

int det4x4_ForEncode(int matrix[4][4]) {
    int det=0;
    int j;
    for (j=0;j<4;j++) {
        det += matrix[0][j]*(j%2==0 ? 1:-1)*det3x3_ForEncode(matrix,0,j);
    }
    return det;
}

void Find_Row_Pos(int matrix[4][4]) {
    int i,j,k;

    for(i=0;i<=3;i++) {
        for(j=0;j<=7;j++) {
            if(matrix[i][0]==setofnumbers[j][0] && matrix[i][1]==setofnumbers[j][1] && matrix[i][2]==setofnumbers[j][2] && matrix[i][3]==setofnumbers[j][3]) {
                Row_Pos_Matrix[i] = j;
            }
        }
    }
}

void Create_FBFMatrix() {
    for(j=0; j<=3; j++) {
        for(i=0; i<=3; i++) {
            FBFMatrix[j][i] = setofnumbers[Row_Code[FBF_count][j]][i];
        }
    }
    FBF_count++;
}

void MultiplyMatrix2(float (*a)[1][4]) {
    int m = 1;
    int n = 4;
    int o = 4;
    int p = 4;
    int h;
    float sum = 0;

    for(i=0; i<m; i++)
        for(j=0; j<p; j++)
            Mutiplied_Matrix2[i][j]=0;

    for(i=0; i<m; i++) {
        for(j=0; j<p; j++) {
            sum=0;
            for(h=0;h<n;h++) {
                sum = sum+((*a)[i][h])*Inverse[h][j];
            }
            Mutiplied_Matrix2[i][j]=sum;
        }
    }
}


int det3x3(int matrix[4][4], int i, int j)

{
    int submatrix[3][3];
    int k, l, row, col;
    for (k = 0, row = 0; k < 4; k++)
    {
        if (k == i) continue;
        for (l = 0, col = 0; l < 4; l++)
        {
            if (l == j) continue;
            submatrix[row][col] = matrix[k][l];
            col++;
        }
        row++;
    }
    return submatrix[0][0]*((submatrix[1][1]*submatrix[2][2])-(submatrix[2][1]*submatrix[1][2]))-submatrix[0][1]*(submatrix[1][0]*submatrix[2][2]-submatrix[2][0]*submatrix[1][2])+submatrix[0][2]*(submatrix[1][0]*submatrix[2][1]-submatrix[2][0]*submatrix[1][1]);
}

void adjointcal(int matrix[4][4])
{
    int i,j;
    int cofactor=0;
    int matrixBeforetranspose[4][4];
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            cofactor= ((i+j)%2==0 ? 1:-1)*det3x3(matrix,i,j);
            matrixBeforetranspose[i][j]= cofactor;
        }
    }

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            adjoint[i][j]=matrixBeforetranspose[j][i];
        }
    }
}

void det4x4(int matrix[4][4])
{
    int det=0;
    int j;
    for (j=0; j<4; j++)
    {
        detSum += matrix[0][j]*(j%2==0 ? 1:-1)*det3x3(matrix,0,j);
    }
    //return det;
}

void inverseCal(int adjoint[4][4])

{
    int row,column,det;
    //det=det4x4(matrix);
    for (row=0; row<4; row++)
    {
        for(column=0; column<4; column++)
        {
            Inverse[row][column]= (float)adjoint[row][column]/(float)detSum;
        }
    }
}


int main() {
    int condition = 0,process = 0;
    char encrypted_text[Size_of_Arrays];
    char decrypted_text[Size_of_Arrays];
    
    while(condition == 0){
        process = Create_Menu();
        if(process == 1){
            FindTextfile();
            encrypt(filename, encrypted_text);

            int count_row;
            
            count_row = Char_to_ASCII(&encrypted_text[0],strlen(encrypted_text));
            ASCII_to_Matrix(count_row,strlen(encrypted_text));

            srand(time(NULL));
            int Determinant;
            int (*p)[4][4];
            int *final = malloc(sizeof(int)*Size_of_Arrays);
            int *position = malloc(sizeof(int)*(4*count_row));

            for(k=0; k<=count_row; k++){
                //random 4x4 matrix
                //check det of 4x4 matrix ,if det is 0 random again!
                Determinant = 0;

                while(Determinant == 0){
                    p = &Generator_Matrix;
                    generate_matrix(p);
                    Determinant = det4x4_ForEncode(Generator_Matrix);
                }
                Find_Row_Pos(Generator_Matrix);

                int (*ary)[1][4];
                ary = &arr;

                for(j=0; j<=3; j++){
                    arr[0][j] = OBFMatrix[k][j];
                }

                MultiplyMatrix(ary);
                for(j=0; j<=3; j++){
                    final[l] = Mutiplied_Matrix[0][j];
                    final_count++;
                    position[l] = Row_Pos_Matrix[j];
                    l++;
                }
                
            }

            printf("Cipher text is :");
            int pos=0;
            for(i=0;i<=final_count-1;i++){
                printf("%d ",final[i]);
                if(((i+1)%4) == 0){
                    for(j=0;j<=3;j++){
                    printf("%d",position[pos]);
                    pos++;
                    }
                    printf(" ");
                }
            }

            free(final);
            free(position);
        }
    
        else if(process == 2){
            FindTextfile();
            FILE *file;
            file = fopen(filename,"r");
            int word2_count=0,row2_count=0,position=0;

            if(file == NULL){
                printf("Error in opening!");
                return 1;
            }

            while(!feof(file)){
                if((position+1)%5 != 0){
                    for(i=0; i<4; i++){
                        fscanf(file,"%f ",&Ciphertxt[row2_count][i]);
                        word2_count++;
                        position++;
                    }
                }else{
                    for(i=0; i<4; i++){
                        fscanf(file,"%1d",&Row_Code[row2_count][i]);
                    }
                    row2_count++;
                    position++;
                }
            }

            float (*ary2)[1][4];
            ary2 = &arr2;
            int x = row2_count;


            for(k=0; k<=row2_count-1; k++){
                detSum =0;
                Create_FBFMatrix();
                for(j=0; j<=3; j++){
                    arr2[0][j] = Ciphertxt[k][j];
                }

                det4x4(FBFMatrix);
                adjointcal(FBFMatrix);
                inverseCal(adjoint);
                MultiplyMatrix2(ary2);
                for(i=0; i<=3; i++){
                    Result_Matrix[k][i] = (int)round(Mutiplied_Matrix2[0][i]);
                }
            }

            k = 0;
            char ascToword[4001];
            for (j=0; j<=row2_count-1; j++)
            {
                for (i=0; i<=3; i++)
                {
                        ascToword[k] = (char)Result_Matrix[j][i];
                        k++;
                }
            }
        
            printf("\n");
            fclose(file);
            decrypt(ascToword, decrypted_text);
            printf("Plainttext is (Decrypted Text): %s\n", decrypted_text);

            break;     
        }

        else{
            printf("Please enter 1 or 2!\n\n");
        }
    }
    return 0;
}
