#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 10

int main(void){
	char input[MAXLEN];
	scanf("%s", input);
	int i=0;
	while(input[i] != '\0'){
		if(input[i] < 48 || input[i] > 57){
			printf("False.\n");
			return 0;
		}
		i++;
	}
	printf("True.\n");
	return 0;
}
