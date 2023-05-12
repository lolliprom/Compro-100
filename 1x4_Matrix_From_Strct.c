#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int setofnumbers[8][4]={{8,1,8,9},{5,5,0,9},{6,3,3,1},{5,4,5,4},{8,0,4,3},{8,9,9,0},{1,9,7,2},{0,7,3,4}};
int Generator_Matrix[4][4],arr1[1][4],Mutiplied_Matrix[5][5];
struct Ascii{
    int num[10];
};


/*int (*p)[4][4];
p = &Generator_Matrix;*/

void generate_matrix(int (*x)[4][4]){
    srand(time(NULL));

    for (int i=0;i<4;i++){
        int r = rand()%8;
        for (int j=0;j<4;j++){
            (*x)[i][j] = setofnumbers[r][j];
        }
    }
}

void MultiplyMatrix()
{
    int m = 1;
    int n = 4;
    int o = 4;
    int p = 4;
    int sum=0,i,j,k;

	for(i=0; i<m; i++)
		for(j=0; j<p; j++)
			Mutiplied_Matrix[i][j]=0;
			
	for(i=0; i<m; i++)
	{
		for(j=0; j<p; j++)
		{
			sum=0;
			for(k=0;k<n;k++)
			{
				sum = sum+arr1[i][k]*Generator_Matrix[k][j];
			}
			Mutiplied_Matrix[i][j]=sum;
		}
	}

    printf("\nThe Result is:");
	for(i=0;i<m;i++)
	{
		printf("\n");
		for(j=0;j<p;j++){
		
			printf("%d\t",Mutiplied_Matrix[i][j]);
		}
	}
}



void Struct_array(){
    struct Ascii x;
    int i;
    for(i=0; i<=10 ; i++)
    {
        x.num[i] = i;
    }
}



int main()
{
    int i;
    int (*p)[4][4];
    p = &Generator_Matrix;
   
    Struct_array();
        for(i=0;i<=3;i++)
        {
            printf("%d:",i);
            scanf("%d",&arr1[0][i]);
        }
        for (int j=0;j<4;j++)
        {
             printf("%d",arr1[0][j]);
        }
            printf("\n\n");

    generate_matrix(p);
        for (int i=0;i<4;i++){
            for (int j=0;j<4;j++){
                printf("%d",Generator_Matrix[i][j]);
            }
            printf("\n");
            }

    MultiplyMatrix();
}
