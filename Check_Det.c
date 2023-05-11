#include <stdio.h>

int det3x3(int matrix[4][4], int i, int j)
{
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

int det4x4(int matrix[4][4])
{
    int det=0;
    int j;
    for (j=0;j<4;j++)
    {
        det += matrix[0][j]*(j%2==0 ? 1:-1)*det3x3(matrix,0,j);
    }
    return det;
}
int main()
{
    int matrix[4][4];
    int i,j;
    printf("\nEnter the matrix->");
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                scanf("%d",&matrix[i][j]);
            }
        }
    printf("Determinant of the matrix is %d",det4x4(matrix));
}