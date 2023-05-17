#include <stdio.h>
#include <math.h>
#include<string.h>
#include <stdlib.h>
int Ciphertxt[1000][4];
int Row_Code[250][4];
int setofnumbers[8][4]={{8,1,8,9},{5,5,0,9},{6,3,3,1},{5,4,5,4},{8,0,4,3},{8,9,9,0},{1,9,7,2},{0,7,3,4}};
int FBFMatrix[4][4];
int Mutiplied_Matrix[4][4];
int arr2[1][4];
int i,j,FBF_count=0;

void Create_FBFMatrix(){
    printf("FBFMatrix %d:\n",FBF_count+1);
    for(j=0; j<=3; j++){
        for(i=0; i<=3; i++){
            FBFMatrix[j][i] = setofnumbers[Row_Code[FBF_count][j]][i];
            printf("%d",FBFMatrix[j][i]);
        }
        printf("\n");
    }
    FBF_count++;
}

void MultiplyMatrix2(int (*a)[1][4])
{
    int m = 1;
    int n = 4;
    int o = 4;
    int p = 4;
    int sum=0,i,j,h;

    for(i=0; i<4; i++){
        printf("%d ",(*a)[0][i]);

    }
    printf("\n");
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
				sum = sum+((*a)[i][h])*FBFMatrix[h][j];
			}
			Mutiplied_Matrix[i][j]=sum;
		}
	}
    printf("\n");

}

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

    Create_FBFMatrix();
    int (*ary2)[1][4];
    ary2 = &arr2;

    for(j=0; j<=3; j++){
        arr2[0][j] = Ciphertxt[0][j];
    }
    void MultiplyMatrix2(ary2);

    fclose(file);
    return 0;
}