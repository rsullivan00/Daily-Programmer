#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char *word;
	int count;
	struct node *next;
	struct node *prev;
};

int addWord(char *word, struct node *root);
void printList(struct node *root);

int main(void){
	printf("Starting main.");
	FILE *fp;
	if((fp = fopen("106words.txt", "r")) == NULL){
		printf("File could not open.\n");
		return 0;
	}
	printf("File opened.");
	
	struct node *root;
	
	char temp[99];
	while(fscanf(fp, "%s", temp) != EOF){
		addWord(temp, root);
	}
	
	printList(root);
	return 0;
}

int addWord(char *word, struct node *root){
	struct node *p = root;
	struct node *q = root;
	while(1){
		if(p == NULL){
			//Empty list.
			if( q == NULL){
				struct node *new = (struct node *)malloc(sizeof(struct node));
				new->count = 1;
				new->word = word;
				new->next = NULL;
				new->prev = NULL;
				root = new;
				return 1;
			}
			//Goes at the end of the list.
			struct node *new = (struct node *)malloc(sizeof(struct node));
			new->count = 1;
			new->word = word;
			new->next = NULL;
			new->prev = q;
			q->next = new;
		}
		
		//If word matches, increase count.
		if(strcmp(p->word, word) == 0){
			p->count++;
			return 1;
		}
		
		//If word belongs before the current node, add it in that position.
		if(strcmp(p->word, word) > 0){
			struct node *new = (struct node *)malloc(sizeof(struct node));
			new->count = 1;
			new->word = word;
			new->next = p;
			new->prev = q;
			if(q == NULL)
				root = new;
			else
				q->next = new;
			p->prev = new;
			return 1;
		}
		q = p;
		p = p->next;
	}
	return -1;
}


void printList(struct node *root){
	struct node *p;
	while(p != NULL){
		printf("%s:\t %d times.\n", p->word, &p->count);
		p = p->next;
	}
	return;
}
