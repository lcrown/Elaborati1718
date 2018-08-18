#ifndef TEXT_H
#define TEXT_H

struct text;

struct text *read_text(char *file);
void print_text(struct text *T);
void remove_char(struct text *T, char c);
void single_line(struct text *T);

#endif
