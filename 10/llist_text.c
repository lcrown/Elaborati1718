/****************************
LINKED LISTS
******************************/
#include "text.h"
#include <stdlib.h>

struct line {
	char c;
	struct line * next;
};

struct text {
	struct line * line;
	struct text * next;
};

static struct line *get_head(struct text *T) {
	struct line *L = T->line;
	return L;
}

static struct line *get_tail(struct text *T) {
	struct line *L = T->line;
	while (L->next) {
			L = L->next;
	}
	return L;
}

struct line *find_prev(struct line *curr, struct line *prev) {
    while (prev->next != curr) {
        prev = prev->next;
    }
    return prev;
}

void remove_char(struct text *T, char c) {
	struct line *head, *tail, *curr, *prev, *tmp;

	while (T != NULL) {
		curr = T->line;
		while (curr != NULL) {
            head = get_head(T);
            tail = get_tail(T);
			if (curr->c == c) {
				/* assign pointer to tmp. (node to be deleted) */
				tmp = curr;
                if (curr == head)
                    T->line = curr->next;
                else if (curr == tail) {
                    prev = find_prev(curr,head);
                    prev->next = NULL;
                }
                else {
                    prev = find_prev(curr,head);
                    prev->next = curr->next;
                }
			}
			curr = curr->next;
			free(tmp);
		}
		T = T->next;
	}
}



void single_line(struct text *T) {
	struct line *curr, *tmp, *head, *tail, *prev;

    while (T != NULL) {
        curr = T->line;
        while (curr != NULL) {
            head = get_head(T);
            tail = get_tail(T);
            if (curr->c == ' ' || curr->c == '\n') {
                tmp = curr;
                if (curr == head)
                    T->line = curr->next;
                else if (curr == tail) {
                    prev = find_prev(curr,head);
                    prev->next = NULL;
                }
                else {
                    prev = find_prev(curr,head);
                    prev->next = curr->next;
                }
            }
            curr = curr->next;
            free(tmp);
        }
    T = T->next;
    }
}
