#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "table.h"

table* table_add_string(char* data, int re, int im) {
    table* rec = (table*) (malloc(sizeof(table)));
    complex* key = (complex*) (malloc(sizeof(complex)));
    key->re = re;
    key->im = im;
    rec->key = key;
    strcpy(rec->data, data);
    return rec;
}

void table_export_string_to_txt(table* string, FILE* out) {
    fprintf(out, "%d + %d * i\t", string->key->re, string->key->im);
    fprintf(out, "%s\n", string->data);
    printf("exported\n");
}

void table_delete_string(table* string) {
    free(string->key);
    free(string);
}

table *table_import_string_from_txt(table *string, FILE *in) {
    fscanf(in, "%d + %d * i \t %s", &(string->key->re), &(string->key->im), string->data);
    return string;
}

/*table *table_search_string_bin(table *tab[], complex *key) {
    size_t size;
    for (int i = 0; tab[i]; i++) {
        size = i;
    }

    table* searching;
    while(searching == NULL) {
        int left = 0;
        int right = size;
        int mid = (left + (right - left)) / 2;
        if (tab[mid]->key == key) {
            return tab[mid];
        } else if ((size > 1) && (!(size % 2))) {
            table* table_left[mid];
            table* table_right[mid];
            for (int i = 0; i < mid; i++) {
                table_left[i] = tab[i];
            }
            for (int i = mid; i < size; i++) {
                table_right[i] = tab[i];
            }

        } else if ((size > 1) && ((size % 2))) {
            table *table_left[mid];
            table *table_right[mid - 1];
            for (int i = 0; i < mid; i++) {
                table_left[i] = tab[i];
            }
            for (int i = mid; i < size; i++) {
                table_right[i] = tab[i];
            }
        } else if (size == 1) {
            if (tab[0]->key == key) {
                searching = tab[0];
            }
        }
    }
} */

int comp_long(complex* key) {
    return(sqrt(key->im * key->im + key->re * key->re));
}

table* quick_sort(table* sorted[]) {
    size_t size;
    for (int i = 0; sorted[i]; i++) {
        size = i;
    }
    int less_size = 0;
    int greater_size = 0;
    table *less[less_size];
    table *grater[greater_size];
    complex *key = (complex*) malloc(sizeof(complex));
    key->re = sorted[size]->key->re;
    key->im = sorted[size]->key->im;
    for(int i = 0; i < size; i++) {
        if (comp_long(sorted[i]->key) < comp_long(key)) {
            less[less_size] = (table*) (realloc(less, less_size + 1));
            less[less_size]->data = sorted[i]->data;
            
        }
    }
}