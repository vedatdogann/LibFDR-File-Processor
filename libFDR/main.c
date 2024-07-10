#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fields.h"
#include "dllist.h"
#include "jrb.h"
#include "jval.h"
#include "ctype.h"

int main() {
    IS is;
    Dllist text_list, temp_node, node_to_delete, cursor;
    char *command, *token;
    int count;

    is = new_inputstruct("giris.dat");  
    if (is == NULL) {
        perror("Dosya açılamadı");
        exit(EXIT_FAILURE);
    }

    text_list = new_dllist();
    cursor = NULL;

    while (get_line(is) >= 0) {
        command = strtok(is->text1, " \t\n");
        if (command == NULL) continue;

        if (strcmp(command, "yaz:") == 0) {
            if (cursor == NULL) {  // İlk yazma işlemi ya da liste boşsa
                cursor = dll_last(text_list); 
            }

            while ((token = strtok(NULL, " \t\n")) != NULL) {
                count = atoi(token);
                token = strtok(NULL, " \t\n");

                for (int i = 0; i < count; i++) {
                    char *new_char = (char *)malloc(sizeof(char) * 2);
                    new_char[0] = (strcmp(token, "\\b") == 0) ? ' ' : (strcmp(token, "\\n") == 0) ? '\n' : token[0];
                    new_char[1] = '\0';

                    if (cursor == NULL) {
                        dll_append(text_list, new_jval_s(new_char));
                        cursor = dll_last(text_list);
                    } else {
                        dll_insert_b(dll_next(cursor), new_jval_s(new_char));
                        cursor = dll_next(cursor);
                    }
                }
            }
        } else if (strcmp(command, "sil:") == 0) {
            while ((token = strtok(NULL, " \t\n")) != NULL) {
                count = atoi(token);
                token = strtok(NULL, " \t\n");
                Dllist back_traversal = cursor ? cursor : dll_last(text_list);

                while (back_traversal != NULL && count > 0) {
                    char *current_char = jval_s(back_traversal->val);
                    if (current_char[0] == token[0]) {
                        node_to_delete = back_traversal;
                        back_traversal = dll_prev(back_traversal);
                        dll_delete_node(node_to_delete);
                        count--;
                    } else {
                        back_traversal = dll_prev(back_traversal);
                    }
                }
                cursor = back_traversal;
            }
        }
         else if (strcmp(command, "sonagit:") == 0) {
            cursor = dll_last(text_list);  // Cursor'ı listenin sonuna taşı
        }
        else if (strcmp(command, "dur:") == 0) {
            FILE *out_file = fopen("sonuc.dat", "w");  // Çıktı dosyasını aç
            if (out_file == NULL) {
                perror("Çıktı dosyası açılamadı");
                exit(EXIT_FAILURE);
            }
            dll_traverse(temp_node, text_list) {
                fprintf(out_file, "%s", jval_s(temp_node->val));  // Dosyaya yaz
            }
            fclose(out_file);  // Dosyayı kapat

            dll_traverse(temp_node, text_list) {
                free(jval_s(temp_node->val));  // Ayrılan belleği serbest bırak
            }
            free_dllist(text_list);
            jettison_inputstruct(is);
            exit(EXIT_SUCCESS);  // Programdan çık
        }
    }

    dll_traverse(temp_node, text_list) {
        printf("%s", jval_s(temp_node->val));
    }
    printf("\n");

    dll_traverse(temp_node, text_list) {
        free(jval_s(temp_node->val));
    }
    free_dllist(text_list);
    jettison_inputstruct(is);

    return EXIT_SUCCESS;
}
