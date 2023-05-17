#include <stdio.h>
#include <math.h>
float Inverse[4][4];
int adjoint[4][4];
int detSum;
int decodeMatrix[1][4];//ข้อมูลหลังdecode ประเภทข้อมูลเป็น int
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
    printf("\nAdjoint matrix is:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", adjoint[i][j]);
        }
        printf("\n");
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
            //printf("%d\n",detSum);
            Inverse[row][column]= (float)adjoint[row][column]/(float)detSum;
            //printf("\nadjoint: %d det: %d",adjoint[row][column],detSum);
        }
    }
    printf("\nInverse matrix is:\n");
    for (row = 0; row < 4; row++)
    {
        for (column = 0; column < 4; column++)
        {
            printf("%10f ", Inverse[row][column]);
        }
        printf("\n");
    }
}

int main()
{
    float cipherMatrix[1][4]= {1145,2281,1473,1738}; //ถ้าทำต่อเอาเมทริกซ์ข้อมูลมาใส่ตรงนี้
    float resultMatrix[1][4];//ข้อมูลหลังdecode ประเภทข้อมูลเป็น float
    int matrix[4][4]= {{1,9,7,2},{5,4,5,4},{5,5,0,9},{0,7,3,4}};
    int i,j;
    /*printf("\nEnter the matrix->");
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                scanf("%d",&matrix[i][j]);
            }
        }*/
    det4x4(matrix);
    printf("Determinant of the matrix is %d",detSum);
    adjointcal(matrix);
    inverseCal(adjoint);//Inverseของmatrix ที่เราเอามาคูณ matrix ข้อมูล
    resultMatrix[0][0]=(cipherMatrix[0][0]*Inverse[0][0])+(cipherMatrix[0][1]*Inverse[1][0])+(cipherMatrix[0][2]*Inverse[2][0])+(cipherMatrix[0][3]*Inverse[3][0]);
    resultMatrix[0][1]=(cipherMatrix[0][0]*Inverse[0][1])+(cipherMatrix[0][1]*Inverse[1][1])+(cipherMatrix[0][2]*Inverse[2][1])+(cipherMatrix[0][3]*Inverse[3][1]);
    resultMatrix[0][2]=(cipherMatrix[0][0]*Inverse[0][2])+(cipherMatrix[0][1]*Inverse[1][2])+(cipherMatrix[0][2]*Inverse[2][2])+(cipherMatrix[0][3]*Inverse[3][2]);
    resultMatrix[0][3]=(cipherMatrix[0][0]*Inverse[0][3])+(cipherMatrix[0][1]*Inverse[1][3])+(cipherMatrix[0][2]*Inverse[2][3])+(cipherMatrix[0][3]*Inverse[3][3]);
    printf("\nResult Matrix is :\n");
    for (i=0,j = 0; j < 4; j++)
    {
        printf("%f ", resultMatrix[i][j]);
        printf(" ");
    }
    for (i=0,j = 0; j < 4; j++)//ใช้ปัดเศษให้ข้อมูลที่เป็นfloat กลายเป็น int
    {
        decodeMatrix[i][j]=(int)round(resultMatrix[i][j]);
        printf(" ");
    }
    printf("\nDecode matrix : ");
    for (i=0,j = 0; j < 4; j++)
    {
        printf("%d ", decodeMatrix[i][j]);
        printf(" ");
    };
}