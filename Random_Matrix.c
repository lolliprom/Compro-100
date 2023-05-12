#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int setofnumbers[8][4]={{8,1,8,9},{5,5,0,9},{6,3,3,1},{5,4,5,4},{8,0,4,3},{8,9,9,0},{1,9,7,2},{0,7,3,4}};
int Generator_Matrix[4][4];
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

int main()
{
    int (*p)[4][4];
    p = &Generator_Matrix;

    generate_matrix(p);

    for (int i=0;i<4;i++){
            for (int j=0;j<4;j++){
                printf("%d",Generator_Matrix[i][j]);
            }
            printf("\n");

            }

    return 0;
}
