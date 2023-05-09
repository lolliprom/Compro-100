#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct ASCII
	{
		char character[100];
		int ascno[100];
	};

	
void Char_to_ASCII();

int main(){
	Char_to_ASCII();
	
}
	
		
void Char_to_ASCII(){
	
	char a,input[100];
	int i,b;
	struct ASCII x;
	
	printf("Type something eiei: ");
	scanf("%[^\n]",input);
	
	for(i=0; i<strlen(input); i++)
	{
		a = input[i];
		x.character[i] = a;
		
		b = input[i];
		x.ascno[i] =  b;
	}
	
	printf("ASCII -> ");
	for(i=0; i<strlen(input); i++)
	{
		printf("%c:",x.character[i]);
		printf("%d ",x.ascno[i]);
	}
	
}
