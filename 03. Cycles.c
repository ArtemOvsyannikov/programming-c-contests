/*
TASK 1. Multiples of 3
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int array_size = 0;
    scanf("%d", &array_size);

    int* numbers = (int*)malloc(array_size * sizeof(int));

    for (int i = 0; i < array_size; i++) {
        scanf("%d", &numbers[i]);
    }

    for (int j = 0; j < array_size; j++) {
        if (numbers[j] % 3 == 0) {
            printf("Yes\n");
        } else {
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
    int N;
    scanf("%d", &N);

    int count = 0;

    for (int i = 2; i <= N; i++) {
        int is_prime = 1;

        for (int j = 2; j <= ceil(sqrt(i)); j++) {
            if (i % j == 0 && i != j) {
                is_prime = 0;
                break;
            }
        }

        if (is_prime) {
            count++;
        }
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
    int N;
    scanf("%d", &N);

    int max_digit = 0;

    while (N > 0) {
        int digit = N % 10;

        if (digit > max_digit) {
            max_digit = digit;
        }

        N /= 10;
    }

    printf("%d", max_digit);

    return 0;
}

/*
TASK 5. The inverted number
*/

#include <stdio.h>

int main() {
    int N, M;
    scanf("%d%d", &N, &M);

    while (N % 10 == 0) {
        N /= 10;
    }
    while (M % 10 == 0) {
        M /= 10;
    }

    int reversed_N = 0;
    while (N > 0) {
        reversed_N = reversed_N * 10 + N % 10;
        N /= 10;
    }

    if (reversed_N == M) {
        printf("Yes");
    } else {
        printf("No");
    }

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

        if (a % m == 0 && n - a / m >= 0) {
            n -= a / m;
        } else if (a % n == 0 && m - a / n >= 0) {
            m -= a / n;
        }

        if (n <= 0 || m <= 0) {
            printf("Chocolate is over\n");
            break;
        } else {
            printf("%d %d\n", n, m);
        }
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
    int sum = 0, even_flag = 0;

    int n;
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
    int res;
    scanf("%d", &res);

    char operator;
    while (scanf(" %c", &operator) == 1 && operator != '=') {
        int operand;
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
