#ifndef TABLE_H_
#define TABLE_H_

#include <stdio.h>

typedef struct complex {
    int re;
    int im;
} complex;

typedef struct table {
    complex* key;
    char data[5];
} table;

table* table_add_string(char *data, int re, int im);
void table_export_string_to_txt(table* string, FILE* out);
void table_delete_string(table *string);
table* table_import_string_from_txt(table* string, FILE* in);
//table* table_search_string_bin(table* tab[], complex* key);
int comp_long(complex* key);
table *quick_sort(table *sorted[]);

#endif