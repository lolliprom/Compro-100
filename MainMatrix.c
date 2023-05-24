#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define Size_of_Arrays 300
struct ASCII //character and it's ASCII value.
	{
		char character[200];
		int ascno[200];
	};
int OBFMatrix[Size_of_Arrays][4] ;
int setofnumbers[8][4]={{8,1,8,9},{5,5,0,9},{6,3,3,1},{5,4,5,4},{8,0,4,3},{8,9,9,0},{1,9,7,2},{0,7,3,4}};
int Generator_Matrix[4][4];
int Row_Pos_Matrix[4];
int Mutiplied_Matrix[1][4];
int arr[1][4];
int i,j,k,l=0,swap,final_count=0;

void MultiplyMatrix(int (*a)[1][4])
{
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
    printf("\n");

}

int Char_to_ASCII(char *OBF, int size)
{
	char a;
	int i,j,b,count=0;
	struct ASCII x;
	
	for(i=0; i<size; i++)
	{
		a = *OBF;
		x.character[i] = a;
		
		b = *OBF;
		x.ascno[i] =  b;
		
		if(i%4==0 && i!=0)
		{
			count++;
		}
		OBF++;
	}
	
	//printf("ASCII -> ");
	/*for(i=0; i<size; i++)
	{
		printf("%c:",x.character[i]);
		printf("%d ",x.ascno[i]);
	}
	printf("\n");*/
	return count;
}

void ASCII_to_Matrix(int rowsize, int size)
{
	int i,j,a,k=0;
	struct ASCII x;
	
	for(i=0; i<=rowsize; i++)
	{
		for(j=0; j<=3; j++)
		{	
			a = 0 ;
			OBFMatrix[i][j] = a;

		}
	}
	for(i=0;i<=rowsize; i++)
	{
	
		for(j=0;j<=3; j++)
		{
			if(k<=size)
			{
				a = x.ascno[k];
				OBFMatrix[i][j] = a;
				k++;
			}
			else
			{
				break;
			}
			
		}
	}
	
	/*for(i=0;i<=rowsize; i++)
	{
	
		for(j=0;j<=3; j++)
		{
			printf("Array[%d][%d] = %d\n",i,j,OBFMatrix[i][j]);
		}
	}*/
}

void generate_matrix(int (*x)[4][4]){
    srand(time(NULL));

    for (int i=0;i<4;i++){
        int r = rand()%8;
        for (int j=0;j<4;j++){
            (*x)[i][j] = setofnumbers[r][j];
        }
    }
}

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

void Find_Row_Pos(int matrix[4][4]){
    int i,j,k;

    for(i=0;i<=3;i++){
        for(j=0;j<=7;j++){
            if(matrix[i][0]==setofnumbers[j][0] && matrix[i][1]==setofnumbers[j][1] && matrix[i][2]==setofnumbers[j][2] && matrix[i][3]==setofnumbers[j][3]){
                Row_Pos_Matrix[i] = j;
            }
        }
    }
}

int main(){
	//store information in structure and 2d array
    char Cipher1[Size_of_Arrays];
	int count_row;
	printf("type something:");
	scanf("%[^\n]",Cipher1);
	
	count_row = Char_to_ASCII(&Cipher1[0],strlen(Cipher1));
	ASCII_to_Matrix(count_row,strlen(Cipher1));


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
            Determinant = det4x4(Generator_Matrix);

            //printf("\n4x4 Matrix is:\n");
            /*for (int i=0;i<4;i++){
                for (int j=0;j<4;j++){
                printf("%d",Generator_Matrix[i][j]);
            }
            printf("\n");
            }
        printf("Determinant is %d",Determinant);*/
        }

        //find row position of matrix
        Find_Row_Pos(Generator_Matrix);
        //printf("\nRow position:\n");
        /*for(i=0;i<=3;i++){
            printf("%d:%d\n",i,Row_Pos_Matrix[i]);
        }*/
        //create array 1x4 for multiplying

        int (*ary)[1][4];
        ary = &arr;

        for(j=0; j<=3; j++){
            arr[0][j] = OBFMatrix[k][j];
        }

        MultiplyMatrix(ary);
        //printf("Cipher for array is :");
        for(j=0; j<=3; j++){
            //printf("%d ",Mutiplied_Matrix[0][j]);
            final[l] = Mutiplied_Matrix[0][j];
            final_count++;
            position[l] = Row_Pos_Matrix[j];
            l++;
        }
        //printf("%d%d%d%d\n",Row_Pos_Matrix[0],Row_Pos_Matrix[1],Row_Pos_Matrix[2],Row_Pos_Matrix[3]);

    }

    //print result
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
    return 0;
}
		
