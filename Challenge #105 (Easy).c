#include <stdio.h>
#include <string.h>

void alphabetize(char * string);

int main(void){
	FILE *fp1, *fp2;
	if((fp1 = fopen("scrambled.txt", "r")) == NULL){
		printf("Scrambled.txt could not open.\n");
		return 0;
	}
	printf("Scrambled.txt has opened.\n");
	if((fp2 = fopen("dictionary.txt", "r")) == NULL){
		printf("Dictionary.txt could not open.\n");
		return 0;
	}
	printf("Dictionary.txt has opened.\n\n");

	char word1[20], word2[20];
	while(fscanf(fp1, "%s", word1) != EOF){
		printf("Scanning for next word.\n\n");
		printf("%s :\t", word1);
		printf("Do we have a word printed?");
		alphabetize(word1);
		while(fscanf(fp2, "%s", word2) != EOF){
			alphabetize(word2);
			if(strcmp(word1,word2) == 0)
				printf("%s\t",word2);
		}
		printf("\n");
	}
	printf("Closing files...\n\n");
	fclose(fp1);
	fclose(fp2);
	return 0;
}

void alphabetize(char * string){
	int i = 0;
	int len, j;
	len = strlen(string);
	char tempWord[20];
	char temp;
	while(i<len){
		temp = string[i];
		for(j=i+1;j<len;j++){
			if(string[j]<temp)
				temp = string[j];
		}
		tempWord[i] = temp;
	}
	strcpy(string, tempWord);
	return;
}
