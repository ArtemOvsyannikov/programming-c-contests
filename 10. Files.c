/*
TASK 1. Ball
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 101

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");
    char buffer1[BUFFER_SIZE];
    int size1 = 0, size2 = 0;
    while (fgets(buffer1, BUFFER_SIZE, input_file) != NULL) {
        size1++;
        size2 = strlen(buffer1);
    }
    rewind(input_file);
    char** lines_array = (char**) malloc(size1 * sizeof(char*));
    int total_coins = 0;
    for (int i = 0; i < size1; i++) {
        fgets(buffer1, BUFFER_SIZE, input_file);
        for (int j = 0; j < size2; j++) {
            if (buffer1[j] == '*') {
                total_coins++;
            }
        }
        lines_array[i] = (char*) malloc((size2+1) * sizeof(char));
        strcpy(lines_array[i], buffer1);
    }
    int x = 1, y = 1;
    int flag = 2;
    int coins = 0;
    while(1) {
        if (flag == 1) {
            while(1) {
                if (lines_array[x][y] == '#') {
                    flag = 5;
                    break;
                } else if (lines_array[x][y] == '/') {
                    flag = 2;
                    y++;
                    break;
                } else if (lines_array[x][y] == '\\') {
                    flag = 4;
                    y--;
                    break;
                } else if (lines_array[x][y] == '*') {
                    coins++;
                }
                x--;
            }
        } else if (flag == 2) {
            while(1) {
                if (lines_array[x][y] == '#') {
                    flag = 5;
                    break;
                } else if (lines_array[x][y] == '/') {
                    flag = 1;
                    x--;
                    break;
                } else if (lines_array[x][y] == '\\') {
                    flag = 3;
                    x++;
                    break;
                } else if (x == size1-2 && y == size2-3) {
                    flag = 0;
                    break;
                } else if (lines_array[x][y] == '*') {
                    coins++;
                }
                y++;
            }
        } else if (flag == 3) {
            while(1) {
                if (lines_array[x][y] == '#') {
                    flag = 5;
                    break;
                } else if (lines_array[x][y] == '/') {
                    y--;
                    flag = 4;
                    break;
                } else if (lines_array[x][y] == '\\') {
                    y++;
                    flag = 2;
                    break;
                } else if (x == size1-2 && y == size2-3) {
                    flag = 0;
                    break;
                } else if (lines_array[x][y] == '*') {
                    coins++;
                }
                x++;
            }
        } else {
            while(1) {
                if (lines_array[x][y] == '#') {
                    flag = 5;
                    break;
                } else if (lines_array[x][y] == '/') {
                    flag = 3;
                    x++;
                    break;
                } else if (lines_array[x][y] == '\\') {
                    flag = 1;
                    x--;
                    break;
                } else if (lines_array[x][y] == '*') {
                    coins++;
                }
                y--;
            }
        }

        if (flag == 0) {
            fprintf(output_file, "yes\n");
            if (coins == total_coins) {
                fprintf(output_file, "yes");
            } else {
                fprintf(output_file, "no");
            }
            break;
        }

        if (flag == 5) {
            fprintf(output_file, "no");
            break;
        }
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}
