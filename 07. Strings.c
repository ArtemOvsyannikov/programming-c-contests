/*
TASK 1. Count the number of words in the line
*/

#include <stdio.h>
#define SIZE 100010

int main() {
    char str[SIZE] = {0};
    fgets(str, SIZE, stdin);
    int c = 0;
    for (int i = 0; str[i+1] != '\0'; i++){
        if (str[i] != ' ' && (str[i+1] == ' ' || str[i+1] == '\n' || str[i+1] == '\0'))
            c++;
    }
    printf("%d", c);
    return 0;
}

/*
TASK 2. Reverse the odd words
*/

#include <stdio.h>
#define SIZE 100002

int main() {
    char str[SIZE] = {0};
    fgets(str, SIZE, stdin);
    int pos = 0;
    for (int i = SIZE-1; i > -1; i--) str[i+1] = str[i];
    str[0] = ' ';
    int i = 1;
    while (str[i] != '\n' && str[i] != '\0') {
        if (str[i] == ' ') {
            printf("%c", str[i]);
            i++;
            continue;
        }
        if (str[i-1] == ' ') {
            pos++;
            if (pos % 2 == 0) {
                while (str[i] != ' ' && str[i] != '\n' && str[i] != '\0') {
                    printf("%c", str[i]);
                    i++;
                }
                continue;
            }
            int nach = i;
            while(str[i+1] != ' ' && str[i+1] != '\n' && str[i+1] != '\0') i++;
            int kon = i;
            for(int g = kon; g > nach-1; g--)
                printf("%c", str[g]);
            i++;
            continue;
        }
    }
    return 0;
}

/*
TASK 3. Delete repetitions
*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[100000] = "";
    fgets(str, sizeof(str), stdin);
    char last = str[0];
    printf("%c", last);
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != last && str[i] != ' ' && str[i] != '\n' && str[i] != '\0') {
            last = str[i];
            printf("%c", last);
        }
    }
    return 0;
}

/*
TASK 4. Sequence compression
*/

#include <stdio.h>
#define SIZE 100010

int main() {
    char str[SIZE] = {0};
    fgets(str, SIZE, stdin);
    int c = 1;
    printf("%c", str[0]);
    for (int i = 1; str[i] != '\n' && str[i] != '\0'; i++) {
        if (str[i] != str[i-1]) {
            if (c > 1) {
                printf("(%d)", c);
                c = 1;
            }
            printf("%c", str[i]);
        } else {
            c++;
        }
    }
    if (c > 1) {
        printf("(%d)", c);
    }
    return 0;
}

/*
TASK 5. Count unique and universal symbols
*/

#include <stdio.h>
#define SIZE 100010

int main() {
    char str[SIZE] = {0};
    fgets(str, SIZE, stdin);
    int c = 0;
    for (int i = 0; i < SIZE-1; i++){
        if (str[i+1] == '\0') break;
        if (str[i] != ' ' && (str[i+1] == ' ' || str[i+1] == '\n' || str[i+1] == '\0'))
            c++;
    }
    int chitaem[260] = {0};
    int j = 0;
    while(1) {
        if (str[j] == '\n' || str[j] == '\0') break;
        if (str[j] != ' ') {
            int nach = j;
            while (str[j + 1] != ' ' && str[j + 1] != '\n' && str[j + 1] != '\0') j++;
            int kon = j;
            char prikol[260] = {0};
            for(int g = nach; g<=kon; g++){
                int aa = (int)str[g];
                prikol[aa]++;
            }
            for(int h = 0; h < 256; h++){
                if (prikol[h] != 0) chitaem[h]++;
            }
        }
        j++;
        continue;
    }
    printf("Universal:");
    int c1 = 0;
    for(int h = 0; h < 256; h++){
        if (chitaem[h] == c) {
            c1++;
            char q = h;
            printf(" %c",q);
        }
    }
    if (!c1) printf(" no");
    printf("\n");
    printf("Unique:");
    int c2 = 0;
    for(int h = 0; h < 256; h++){
        if (chitaem[h] == 1) {
            c2++;
            char q = h;
            printf(" %c",q);
        }
    }
    if (!c2) printf(" no");
    return 0;
}
