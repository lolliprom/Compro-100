#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define Size_of_Arrays 100
struct ASCII //character and it's ASCII value.
	{
		char character[100];
		int ascno[100];
	};

int Char_to_ASCII(char *p, int size);
void ASCII_to_Matrix(int rowsize, int size);
int OBFMatrix[Size_of_Arrays][4] ;

int main(){
	char Cipher1[Size_of_Arrays];
	int count_row;
	printf("type something:");
	scanf("%[^\n]",Cipher1);
	
	count_row = Char_to_ASCII(&Cipher1[0],strlen(Cipher1));
	ASCII_to_Matrix(count_row,strlen(Cipher1));

}
		
int Char_to_ASCII(char *p, int size)
{
	char a;
	int i,b,count=0;
	struct ASCII x;
	
	for(i=0; i<size; i++)
	{
		a = *p;
		x.character[i] = a;
		
		b = *p;
		x.ascno[i] =  b;
		
		if(i%4==0 && i!=0)
		{
			count++;
		}
		p++;
	}
	
	printf("ASCII -> ");
	for(i=0; i<size; i++)
	{
		printf("%c:",x.character[i]);
		printf("%d ",x.ascno[i]);
	}
	printf("\n");
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
	
	for(i=0;i<=rowsize; i++)
	{
	
		for(j=0;j<=3; j++)
		{
			printf("Array[%d][%d] = %d\n",i,j,OBFMatrix[i][j]);
		}
	}
}



