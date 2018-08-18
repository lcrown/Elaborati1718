/****************************
LINKED LISTS
******************************/
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "text.h"

struct line {
  char c;
  struct line *next;
};

struct text {
  struct line *line;
  struct text *next;
};


static void tail_insert_line(struct text **head, struct text **tail, struct line *L) {
	struct text *tmp = (struct text *)malloc(sizeof(struct text));
	
	tmp->line = L;
	tmp->next = NULL;	

	if(*head == NULL) 
		*head = tmp;
	else 
		(*tail)->next = tmp;
	*tail = tmp;
}

static void tail_insert_char(struct line **head, struct line **tail, char c) {
	struct line *tmp = (struct line *)malloc(sizeof(struct line));

	tmp->c    = c;
	tmp->next = NULL;

	if(*head == NULL)
		*head = tmp;
	else
		(*tail)->next = tmp;
	*tail = tmp;
}

static void print_line(struct line *L) {
	while(L != NULL) {
		printf("%c",L->c);
		L = L->next;
	}
	printf("\n");
}


static struct line *read_line(FILE *in) {
	struct line *L_head = NULL, *L_tail = NULL;
	char c;
	
	while((c = fgetc(in)) != EOF && c != '\n') 
		tail_insert_char(&L_head,&L_tail,c);	
	
	return L_head;
}


struct text *read_text(char *file) {
	FILE *in = fopen(file,"r");
	struct text *T_head = NULL, *T_tail = NULL;
	struct line *line;

	if(in != NULL) {
		do {
			line = read_line(in);
			if(!feof(in))
				tail_insert_line(&T_head,&T_tail,line);
		} while(!feof(in));
		fclose(in);
	}
	return T_head;
}

void print_text(struct text *T) {
	while(T != NULL) {
		print_line(T->line);
		T = T->next;
	}
}

