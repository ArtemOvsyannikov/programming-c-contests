/*
TASK 1. A tour of the rooftops
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int N = 0;
	scanf("%d", &N);
	int a[10000];
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	for (;;) {
		int b = 0;
		scanf("%d", &b);
		if(b == -1){
			return 0;
		}
		int o = b-1;
		int l = 0;
		int maxka1 = a[o];
		while (o > 0) {
			o--;
			if (a[o] >= maxka1) {
				maxka1 = a[o];
				l++;
			}
		}
		int p = b-1;
		int r = 0;
		int maxka2 = a[p];
		while (p < N) {
			p++;
			if (a[p] >= maxka2) {
				maxka2 = a[p];
				r++;
			}
		}
		printf("%d %d\n", l, r);
	}
	free(a);
}

/*
TASK 2. The sum of the numbers
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int max = 9, min = 101;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x > max) max = x;
        if (x < min) min = x;
    }
    int sum_max = max / 10 + max % 10;
    int sum_min = min / 10 + min % 10;
    printf("%d %d\n", sum_max, sum_min);
    if (sum_max == sum_min) printf("Yes\n");
    else printf("No\n");
    return 0;
}

/*
TASK 3. Arithmetic mean
*/

#include <stdio.h>

int main() {
    int N, i, sum = 0;
    double mean;
    scanf("%d", &N);
    int arr[N], new_arr[N];
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    mean = (double)sum / N;
    int j = 0, k = N - 1;
    for (i = 0; i < N; i++) {
        if (arr[i] >= mean) {
            new_arr[j++] = arr[i];
        } else {
            new_arr[k--] = arr[i];
        }
    }
    for (i = 0; i < N; i++) {
        printf("%d\n", new_arr[i]);
    }
    return 0;
}

/*
TASK 4. Array of digit totals
*/

#include <stdio.h>

int main() {
    int N, i;
    scanf("%d", &N);
    int arr[N];
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = N - 1; i >= 0; i--) {
        int sum = 0, temp = arr[i];
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        printf("%d\n", sum);
    }
    return 0;
}

/*
TASK 5. Multiples of 3 and 6
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, i, b, t, nn, summ, flag1;
    scanf("%d", &N);
    int a[N];
    for (i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    while (scanf("%d", &b) && b != -1) {
        t = abs(a[b - 1]);
        if (t % 3 == 0) {
            printf("Yes ");
        } else {
            printf("No ");
        }
        if (t % 6 == 0) {
            printf("Yes\n");
        } else {
            summ = 0;
            flag1 = 0;
            while (t != 0) {
                nn = t % 10;
                if (nn % 2 == 0) {
                    flag1 = 1;
                }
                summ += nn;
                t /= 10;
            }
            if (flag1 && summ % 3 == 0) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}

/*
TASK 6. The most popular
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, i, max_count = -1;
    scanf("%d", &N);
    int *a = (int*)malloc(N * sizeof(int));
    for (i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    int sortedMass[2001] = { 0 };
    for (i = 0; i < N; i++) {
        sortedMass[a[i] + 1000]++;
        if (sortedMass[a[i] + 1000] > max_count) {
            max_count = sortedMass[a[i] + 1000];
        }
    }
    for (i = 0; i < N; i++) {
        if (sortedMass[a[i] + 1000] == max_count) {
            printf("%d", a[i]);
            break;
        }
    }
    free(a);
    return 0;
}

/*
TASK 7. Correct placement of parentheses
*/

#include <stdio.h>

int main() {
    int ch, count = 0;
    while ((ch = getchar()) != '\n') {
        if (ch == '(') {
            count++;
        } else if (ch == ')' && --count < 0) {
            break;
        }
    }
    printf(count == 0 ? "Yes\n" : "No\n");
    return 0;
}

/*
TASK 8. Correct placement of brackets
*/

#include <stdio.h>
#include <stdbool.h>

#define SIZE 1003

int main() {
    char arr[SIZE], stack[SIZE];
    int top = -1;
    bool valid = true;
    scanf("%s", arr);
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] == '(' || arr[i] == '[' || arr[i] == '{') {
            stack[++top] = arr[i];
        } else if (arr[i] == ')') {
            if (top == -1 || stack[top--] != '(') {
                valid = false;
                break;
            }
        } else if (arr[i] == ']') {
            if (top == -1 || stack[top--] != '[') {
                valid = false;
                break;
            }
        } else if (arr[i] == '}') {
            if (top == -1 || stack[top--] != '{') {
                valid = false;
                break;
            }
        }
    }
    if (valid && top == -1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
