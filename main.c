#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "table.h"

int main(int argc, char const *argv[])
{
    if(argc < 2) {
        printf("Please enter filename.\n");
        return 1;
    } else {
        const char * filename = argv[1];
        
        table* table[10];
        unsigned current_size = 0;
        FILE* out;
        FILE* in; 

        int re, im;
        char data[5] = {
            'y', 'a', ' ', 'p', 'o'
        };
        
        unsigned num;
        int command;
        while (command != 5) {
            printf("0 - print table, 1 - straight table, "
            "2 - reversed table, 3 - random table"
            ", 4 - load table, 5 - exit\n"
            );
            scanf("%d", &command);
            switch (command) {
                case 0:
                    for (size_t i = 0; i < current_size; i++) {
                        printf("%d + %d * i\t%s\n", table[i]->key->re,
                            table[i]->key->im, table[i]->data
                        );
                    }
                    break;
                case 1:
                    re = 0;
                    im = 1;
                    out = fopen(filename, "w");
                    for (int i = 0; i < 10; i++) {
                        table[current_size++] = table_add_string(
                            data,
                            re,
                            im
                        );
                        re++;
                        im++;
                        table_export_string_to_txt(table[i], out);
                    }
                    fclose(out);
                    break;
                case 2:
                    re = 9;
                    im = 10;
                    out = fopen(filename, "w");
                    for (int i = 0; i < 10; i++) {
                        table[current_size++] = table_add_string(
                            data,
                            re,
                            im);
                        re--;
                        im--;
                        table_export_string_to_txt(table[i], out);
                    }
                    fclose(out);
                    break;
                case 3:
                    out = fopen(filename, "w");
                    for (int i = 0; i < 10; i++) {
                        srand(i);
                        re = rand() % 125;
                        im = rand() % 100;
                        table[current_size++] = table_add_string(
                            data,
                            re,
                            im);
                        table_export_string_to_txt(table[i], out);
                    }
                    fclose(out);
                    break;
                case 4:
                    in = fopen(filename, "r");
                    for (size_t i = 0; i < 10; i++) {
                        table[i] = table_import_string_from_txt(table[i], in);
                    }
                    fclose(in);
                    break;
            }
        }
    }
    return 0;
}
