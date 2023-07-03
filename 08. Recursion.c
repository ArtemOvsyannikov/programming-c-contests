/*
TASK 1. Cross
*/

#include <stdio.h>
#include <math.h>

void printFractal(char ** arr, int n, int x, int y, int size) {
    if (n == 0) {
        arr[x][y] = '*';
        return;
    }
    printFractal(arr, n-1, x,y, size/3);
    printFractal(arr, n-1, x+size/3,y, size/3);
    printFractal(arr, n-1, x-size/3,y, size/3);
    printFractal(arr, n-1, x,y+size/3, size/3);
    printFractal(arr, n-1, x,y-size/3, size/3);
}

int main() {
    int n;
    scanf("%d", &n);
    int size = pow(3,n);
    char** arr = (char**) calloc(size, sizeof(char*));
    for (int i = 0; i < size; i++) {
        arr[i] = (char*) calloc(size, sizeof(char));
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr[i][j] = ' ';
        }
    }
    printFractal(arr, n, size/2, size/2, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}