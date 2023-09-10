/*
TASK 1. Odd indices to the end
*/

#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 10000

int main() {
    char input[MAX_LENGTH + 1];
    char evenChars[MAX_LENGTH / 2 + 1], oddChars[MAX_LENGTH / 2 + 1];
    int evenCount = 0, oddCount = 0;
    scanf("%s", input);
    for (int i = 0; i < strlen(input); i++) {
        if (i % 2 == 0) {
            evenChars[evenCount++] = input[i];
        } else {
            oddChars[oddCount++] = input[i];
        }
    }
    evenChars[evenCount] = '\0';
    oddChars[oddCount] = '\0';
    printf("%s%s\n", evenChars, oddChars);
    return 0;
}

/*
TASK 2. Numbers to the end
*/

#include <stdio.h>
#define SIZE 10001

int main() {
    char str[SIZE] = {0};
    fgets(str, SIZE, stdin);
    for (int i = 0; i < SIZE-1; i++){
        if (str[i] == '\0' || str[i] == '\n') break;
        int x = (int)str[i] - '0';
        if (x < 0 || x > 9) {
            printf("%c", str[i]);
        }
    }
    for (int i = 0; i < SIZE-1; i++){
        if (str[i] == '\0' || str[i] == '\n') break;
        int y = (int)str[i] - '0';
        if (0 <= y  &&  y <= 9) {
            printf("%c", str[i]);
        }
    }
    return 0;
}

/*
TASK 3. Palindrome
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[10001];
    fgets(input, 10001, stdin);
    int leftIndex = 0;
    int rightIndex = strlen(input) - 1;
    while (leftIndex < rightIndex) {
        if (!isalnum(input[leftIndex])) {
            leftIndex++;
        } else if (!isalnum(input[rightIndex])) {
            rightIndex--;
        } else if (tolower(input[leftIndex]) != tolower(input[rightIndex])) {
            printf("no\n");
            return 0;
        } else {
            leftIndex++;
            rightIndex--;
        }
    }
    printf("yes\n");
    return 0;
}

/*
TASK 4. Who won
*/

#include <stdio.h>
#include <string.h>

int main() {
    char firstTeam[101], secondTeam[101];
    int firstTeamScore, secondTeamScore, firstHalfScore, secondHalfScore;
    int firstHalfWinner = 0, secondHalfWinner = 0, gameWinner = 0;

    scanf("%100[^-] - %100[^ ] %d:%d (%d:%d)", firstTeam, secondTeam, &firstTeamScore, &secondTeamScore, &firstHalfScore, &secondHalfScore);

    if (firstHalfScore > secondHalfScore) {
        firstHalfWinner = 1;
    } else if (firstHalfScore < secondHalfScore) {
        firstHalfWinner = 2;
    }

    if (firstTeamScore - firstHalfScore > secondTeamScore - secondHalfScore) {
        secondHalfWinner = 1;
    } else if (firstTeamScore - firstHalfScore < secondTeamScore - secondHalfScore) {
        secondHalfWinner = 2;
    }

    if (firstTeamScore > secondTeamScore) {
        gameWinner = 1;
    } else if (firstTeamScore < secondTeamScore) {
        gameWinner = 2;
    }

    if (firstHalfWinner == secondHalfWinner && secondHalfWinner == gameWinner) {
        if (firstHalfWinner == 0) {
            printf("draw\n");
        } else if (firstHalfWinner == 1) {
            printf("%s\n", firstTeam);
        } else {
            printf("%s\n", secondTeam);
        }
    } else {
        if (firstHalfWinner == 0) {
            printf("draw\n");
        } else if (firstHalfWinner == 1) {
            printf("%s\n", firstTeam);
        } else {
            printf("%s\n", secondTeam);
        }
        if (secondHalfWinner == 0) printf("draw\n");
        else if (secondHalfWinner == 1) printf("%s\n", firstTeam);
        else printf("%s\n", secondTeam);
        if (gameWinner == 0) printf("draw\n");
        else if (gameWinner == 1) printf("%s\n", firstTeam);
        else printf("%s\n", secondTeam);
    }
    return 0;
}

/*
TASK 5. Calculator
*/

#include <stdio.h>

int main() {
    int sum = 0, num;
    char op;
    scanf("%d", &sum);
    while (scanf("%c%d", &op, &num) == 2) {
        if (op == '+') sum += num;
        else sum -= num;
    }
    printf("%d\n", sum);
    return 0;
}
