/*
TASK 1. Leap year
*/

#include <stdio.h>

int main() {
    int year;
    scanf("%d", &year);

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

/*
TASK 2. Lucky ticket
*/

#include <stdio.h>

int main() {
    int number;
    scanf("%d", &number);

    int left_sum = number / 100000 + (number / 10000) % 10 + (number / 1000) % 10;
    int right_sum = (number / 100) % 10 + (number / 10) % 10 + number % 10;

    if (left_sum == right_sum) {
        printf("Happy\n");
    } else {
        printf("Unhappy\n");
    }

    return 0;
}

/*
TASK 3. Palindrome
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int digit1 = n / 100000;
    int digit2 = (n / 10000) % 10;
    int digit3 = (n / 1000) % 10;
    int digit4 = (n / 100) % 10;
    int digit5 = (n / 10) % 10;
    int digit6 = n % 10;

    if(digit1 == digit6 && digit2 == digit5 && digit3 == digit4) {
        printf("Palindrome\n");
    } else {
        printf("Non palindrome\n");
    }

    return 0;
}

/*
TASK 4. Odd numbers
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k = 0;
    scanf("%d", &n);

    n = abs(n);

    for (int i = 100000; i > 0; i /= 10) {
        if (((n / i) % 10) % 2 != 0) {
            k++;
        }
    }

    printf("%d", k);

    return 0;
}

/*
TASK 5. Pizza
*/

#include <stdio.h>
#include <math.h>

int main() {
    int s, r;
    scanf("%d%d", &s, &r);

    double  circleArea = (int)(3.14 * r * r * 100) / 100.0,
            squareArea = (int)(s * s * 100) / 100.0,
            squareDiagonal = (int)(s * sqrt(2.0) * 100) / 100.0;

    printf("%.2lf %.2lf\n", squareArea, circleArea);

    if (squareArea > circleArea) {
        printf("Square is bigger\n");
    } else if (squareArea == circleArea) {
        printf("Equal\n");
    } else {
        printf("Circle is bigger\n");
    }

    if (squareDiagonal <= 2 * r) {
        printf("Square in circle\n");
    } else if (2 * r <= s) {
        printf("Circle in square\n");
    } else {
        printf("Impossible\n");
    }

    return 0;
}

/*
TASK 6. Triangle
*/

#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double s, p;
    scanf("%lf%lf%lf", &a, &b, &c);

    if ((a < b + c) && (b < a + c) && (c < a + b)) {
        p = (a + b + c) / 2.0;
        s = sqrt(p * (p - a) * (p - b) * (p - c));

        printf("%.2lf", s);
    } else {
        printf("0");
    }

    return 0;
}

/*
TASK 7. Days of the week
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    switch (n) {
        case 1:
            printf("Monday");
            break;
        case 2:
            printf("Tuesday");
            break;
        case 3:
            printf("Wednesday");
            break;
        case 4:
            printf("Thursday");
            break;
        case 5:
            printf("Friday");
            break;
        case 6:
            printf("Saturday");
            break;
        case 7:
            printf("Sunday");
            break;
        default:
            printf("Wrong day number");
    }

    return 0;
}


/*
TASK 8. Call cost
*/

#include <stdio.h>

int main() {
    int n;
    double t, p, c;
    scanf("%lf%lf%d", &t, &p, &n);

    c = t * p;

    if ((n == 6 || n == 7) && t >= 10) {
        c *= 0.8;
    }

    printf("%.2lf", c);

    return 0;
}

/*
TASK 9. Health damage
*/

#include <stdio.h>

int main() {
    double h, d, n;
    scanf("%lf%lf", &h, &d);

    n = h * 100 - d * 100;

    if (n < 10) {
        printf("0");
    } else {
        printf("%.2lf", n / 100);
    }

    return 0;
}

/*
TASK 10. Calculator
*/

#include <stdio.h>

int main() {
    double n, m;
    char op;
    scanf("%lf%c%lf", &n, &op, &m);

    if (op == '-') {
        m = -m;
    }

    printf("%.2f", n + m);

    return 0;
}

