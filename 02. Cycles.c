/*
TASK 1. Multiples of 3
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int arraySize = 0;
    scanf("%d", &arraySize); 
    int* numbers = (int*)malloc(arraySize * sizeof(int)); 
    for (int i = 0; i < arraySize; i++) {
        scanf("%d", &numbers[i]);
    }
    for (int j = 0; j < arraySize; j++) {
        if (numbers[j] % 3 == 0) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    free(numbers); 
    return 0;
}

/*
TASK 2. Simple numbers
*/

#include <stdio.h>
#include <math.h>

int main() {
    int N, count = 0;
    scanf("%d", &N);
    for (int i = 2; i <= N; i++) {
        int isPrime = 1;
        for (int j = 2; j <= ceil(sqrt(i)); j++) {
            if (i % j == 0 && i != j) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) count++;
    }
    printf("%d", count);
    return 0;
}

/*
TASK 3. Triangle
*/

#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    for (int i = N; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

/*
TASK 4. Maximum number digit
*/

#include <stdio.h>

int main() {
    int N, maxDigit = 0;
    scanf("%d", &N);
    while (N > 0) {
        int digit = N % 10;
        if (digit > maxDigit) {
            maxDigit = digit;
        }
        N /= 10;
    }
    printf("%d", maxDigit);
    return 0;
}

/*
TASK 5. The inverted number
*/

#include <stdio.h>

int main() {
    int N, M, reversedN = 0;
    scanf("%d%d", &N, &M);
    while (N % 10 == 0) N /= 10;
    while (M % 10 == 0) M /= 10;
    while (N > 0) {
        reversedN = reversedN * 10 + N % 10;
        N /= 10;
    }
    printf(reversedN == M ? "Yes" : "No");
    return 0;
}

/*
TASK 6. Chocolate
*/

#include <stdio.h>

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while (1) {
        int a;
        scanf("%d", &a);
        if (a < 0) {
            printf("You are full\n");
            break;
        }
        if (a % m == 0 && n - a / m >= 0) n -= a / m;
        else if (a % n == 0 && m - a / n >= 0) m -= a / n;
        if (n <= 0 || m <= 0) {
            printf("Chocolate is over\n");
            break;
        } else printf("%d %d\n", n, m);
    }
    return 0;
}

/*
TASK 7. Pythagoras' triplets
*/

#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 3; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int k = sqrt(i * i + j * j);
            if (k <= n && i * i + j * j == k * k) {
                printf("%d %d %d\n", i, j, k);
            }
        }
    }
    return 0;
}

/*
TASK 8. Multiples of 6
*/

#include <stdio.h>

int main() {
    int n, sum = 0, even_flag = 0;
    while (scanf("%d", &n) == 1 && n != -1) {
        if (n % 2 == 0) {
            even_flag = 1;
        }
        sum += n;
        if (sum % 3 == 0 && even_flag) {
            printf("Stop\n");
            break;
        } else {
            printf("No\n");
        }
    }
    return 0;
}

/*
TASK 9. Calculator
*/

#include <stdio.h>

int main() {
    int n, res, operand;
    char operator;
    scanf("%d", &n);
    res = n;
    while (scanf(" %c", &operator) == 1 && operator != '=') {
        scanf("%d", &operand);
        switch (operator) {
            case '+':
                res += operand;
                break;
            case '-':
                res -= operand;
                break;
            case '*':
                res *= operand;
                break;
            case '/':
                res /= operand;
                break;
            case '%':
                res %= operand;
                break;
        }
    }
    printf("%d\n", res);
    return 0;
}

/*
TASK 10. Rectangle
*/

#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a > 0 && b > 0 && c > 0 && (a == b || a == c || b == c)) {
        printf("Yes");
    } else {
        printf("No");
    }
    return 0;
}


