#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
float Ciphertxt[1000][4];
int Row_Code[250][4];
int setofnumbers[8][4]={{8,1,8,9},{5,5,0,9},{6,3,3,1},{5,4,5,4},{8,0,4,3},{8,9,9,0},{1,9,7,2},{0,7,3,4}};
int FBFMatrix[4][4];
float Inverse[4][4];
int adjoint[4][4];
int detSum;
float Mutiplied_Matrix2[1][4]; //already had in Matrix_encode
float arr2[1][4];//already had in Matrix_encode
int Result_Matrix[1000][4];
int i,j,k,FBF_count=0;

void Create_FBFMatrix(){
    //printf("FBFMatrix %d:\n",FBF_count+1);
    for(j=0; j<=3; j++){
        for(i=0; i<=3; i++){
            FBFMatrix[j][i] = setofnumbers[Row_Code[FBF_count][j]][i];
            //printf("%d",FBFMatrix[j][i]);
        }
       // printf("\n");
    }
    FBF_count++;
}

void MultiplyMatrix2(float (*a)[1][4])
{
    int m = 1;
    int n = 4;
    int o = 4;
    int p = 4;
    int h;
    float sum = 0;

    /*for(i=0; i<4; i++){
        printf("%d ",(*a)[0][i]);

    }*/
    printf("\n");
	for(i=0; i<m; i++)
		for(j=0; j<p; j++)
			Mutiplied_Matrix2[i][j]=0;
			
	for(i=0; i<m; i++)
	{
		for(j=0; j<p; j++)
		{
			sum=0;
			for(h=0;h<n;h++)
			{
				sum = sum+((*a)[i][h])*Inverse[h][j]; //check variable type for operation ด้วย
			}
			Mutiplied_Matrix2[i][j]=sum;
            //printf("%f ",Mutiplied_Matrix2[i][j]); //check multiplication
		}
	}
   // printf("\n");

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
    /*printf("\nSub-matrix is :");
    for (i = 0; i < 3; i++) {
       for (j = 0; j < 3; j++) {
           printf("%d ", submatrix[i][j]);
       }
       printf("\n");
    }*/
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
    /*printf("\nNew-matrix before transpose is :\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", newmatrix[i][j]);
        }
        printf("\n");
    }*/
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            adjoint[i][j]=matrixBeforetranspose[j][i];
        }
    }
    /*printf("\nAdjoint matrix is:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", adjoint[i][j]);
        }
        printf("\n");
    }*/
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
            //printf("%d\n",detSum);
            Inverse[row][column]= (float)adjoint[row][column]/(float)detSum;
            //printf("\nadjoint: %d det: %d",adjoint[row][column],detSum);
        }
    }
    /*printf("\nInverse matrix is:\n");
    for (row = 0; row < 4; row++)
    {
        for (column = 0; column < 4; column++)
        {
            printf("%10f ", Inverse[row][column]);
        }
        printf("\n");
    }*/
}

int main(){
    FILE *file;
    file = fopen("Ciphereiei.txt","r");
    int word2_count=0,row2_count=0,position=0;
    //float *decode = malloc(sizeof(float)*word2_count);

    if(file == NULL){
        printf("Error in opening!");
        return 1;
    }

    printf("Cipher: ");
    while(!feof(file)){
        if((position+1)%5 != 0){
            for(i=0; i<4; i++){
                fscanf(file,"%f ",&Ciphertxt[row2_count][i]);
                printf("%f ",Ciphertxt[row2_count][i]);
                word2_count++;
                position++;
            }
        }else{
            for(i=0; i<4; i++){
            	fscanf(file,"%1d",&Row_Code[row2_count][i]);
            	printf("%d",Row_Code[row2_count][i]);
            }
			row2_count++;
			position++;
            printf(" ");	  
        }
    }
    printf("\n");

    float (*ary2)[1][4];
    ary2 = &arr2;
    int x = row2_count;
    int Result_Matrix[1000][4];


    for(k=0; k<=row2_count-1; k++){
        detSum =0;
        Create_FBFMatrix();
        //printf("1 by 4 Matrix is:");
        for(j=0; j<=3; j++){
            arr2[0][j] = Ciphertxt[k][j];
            //printf("%f ", arr2[0][j]);
        }
        //printf("\n");

        det4x4(FBFMatrix);
        //printf("Determinant of the matrix is %d",detSum);
        adjointcal(FBFMatrix);
        inverseCal(adjoint);
        //printf("ResultMatrix: ");
        MultiplyMatrix2(ary2);
        for(i=0; i<=3; i++){
            Result_Matrix[k][i] = (int)round(Mutiplied_Matrix2[0][i]);
        }
    }

    printf("Check decodematrix: \n");
    for(j=0; j<=row2_count-1; j++){
        for(i=0; i<=3; i++){
            printf("%d ",Result_Matrix[j][i]);
        }
        printf("\n");
    }

    fclose(file);
    //free(decode);
    return 0;
}