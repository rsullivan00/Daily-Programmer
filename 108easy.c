#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 10

int main(void){
	char input[MAXLEN];
	scanf("%s", input);
	
	int len = strlen(input);
	printf("%c.", input[0]);
	int i;
	for(i = 1; i < len; i++){
		printf("%c", input[i]);
	}
	printf(" x 10^%d\n", len-1);
	return 0;
}
