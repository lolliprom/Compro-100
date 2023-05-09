#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define Size_of_Arrays 100
struct ASCII //character and it's ASCII value.
	{
		char character[100];
		int ascno[100];
	};
char Cipher1[Size_of_Arrays];

void Char_to_ASCII(char *p, int size);

int main(){
	printf("type something:");
	scanf("%[^\n]",Cipher1);
	
	Char_to_ASCII(&Cipher1,strlen(Cipher1));
	
}
	
		
void Char_to_ASCII(char *p, int size){
	
	char a;
	int i,b;
	struct ASCII x;
	
	for(i=0; i<size; i++)
	{
		a = *p;
		x.character[i] = a;
		
		b = *p;
		x.ascno[i] =  b;

		p++;
	}
	
	printf("ASCII -> ");
	for(i=0; i<size; i++)
	{
		printf("%c:",x.character[i]);
		printf("%d ",x.ascno[i]);
	}
	
}
