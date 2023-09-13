/*
TASK 1. Flip the array
*/

#include <stdio.h> 
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int *a = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]); 
    }
    
    for (int j = N - 1; j >= 0; j--) {
        printf("%d\n", a[j] * a[j]);
    }
    
    free(a);
    
    return 0;
}

/*
TASK 2. Crossing
*/

#include <stdio.h>
#include <stdlib.h>

int check(int array[], int value, int length) {
    for (int i = 0; i < length; i++) {
        if (value == array[i]) {
            return 1; 
        }
    }
    
    return 0;
}

int main() {
    int N;
    scanf("%d", &N); 
 
    int *a = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    
    int M; 
    scanf("%d", &M);
    
    int *b = malloc(M * sizeof(int));
    for (int j = 0; j < M; j++) {
        scanf("%d", &b[j]);
    }
    
    int *z = malloc(N * sizeof(int));
    int count = 0;
    
    for (int k = 0; k < N; k++) {
        if (check(b, a[k], M) && !check(z, a[k], count)) {
            z[count] = a[k];
            count++;
        }
    }
    
    printf("%d\n", count);
    for (int f = 0; f < count; f++) {
        printf("%d\n", z[f]);
    }
    
    free(a);
    free(b);
    free(z);
    
    return 0;
}

/*
TASK 3. The nearest element
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int check(int arr[], int num, int len) {
    for (int i = 0; i < len; i++) {
        if (abs(num) == abs(arr[i])) {
            return i;
        }
    }

    return 100000; 
}

int main() {
    int N;
    scanf("%d", &N);

    int* a = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    int ku;
    scanf("%d", &ku);

    for (int j = 0; j < N; j++) {
        int k = check(a, ku + j, N);
        int l = check(a, ku - j, N);

        if ((k != 100000 || l != 100000) && (k <= l)) {
            printf("%d", k + 1);
            return 0;
        }
        else if ((k != 100000 || l != 100000) && (k >= l)) {
            printf("%d", l + 1);
            return 0;
        }
    }

    free(a);

    return 0;
}

/*
TASK 4. Local minima in the ring
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int *arr = malloc((N + 2) * sizeof(int));
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]); 
    }

    arr[0] = arr[N];
    arr[N + 1] = arr[1];
    
    int count = 0;
    
    for (int j = 1; j <= N; j++) {
        if (arr[j - 1] > arr[j] && arr[j] < arr[j + 1]) {
            count++;
        }
    }
    
    printf("%d", count);
    
    free(arr);
    
    return 0;
}

/*
TASK 5. Difference with arithmetic mean
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    
    float *a = malloc(N * sizeof(float));
    for (int i = 0; i < N; i++) {
        scanf("%f", &a[i]);
    }
    
    float sum = 0.0;
    for (int j = 0; j < N; j++) {
        sum += a[j]; 
    }
    
    float average = sum / N;
    for (int k = 0; k < N; k++) {
        printf("%.2f\n", a[k] - average);
    }
    
    free(a);
    
    return 0;
}

/*
TASK 6. Shift to the right
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    scanf("%d\n%d", &N, &M);

    float *a = malloc(N * sizeof(float));
    for (int i = 0; i < N; i++) {
        scanf("%f", &a[i]);
    }

    float *b = malloc(N * sizeof(float));
    for (int j = 0; j < N; j++) {
        int index = (j + M) % N;
        b[index] = a[j];
    }

    for (int k = 0; k < N; k++) {
        printf("%.2f\n", b[k]);
    }

    free(a);
    free(b);

    return 0;
}

/*
TASK 7. Stack with support for highs and lows
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100001

int main() {

    int command;
    scanf("%d", &command);

    int stack[MAX_SIZE] = {0};
    int maxPrefix[MAX_SIZE] = {0};
    int minPrefix[MAX_SIZE] = {0};
    
    int index = 0;
    
    while (command != 5) {
        if (command == 0) {
            int value;
            scanf("%d", &value);
            
            if (index == MAX_SIZE) {
                printf("Overflow");
            }
            else {
                stack[index] = value;
            
                if (index == 0) {
                    maxPrefix[index] = value;
                    minPrefix[index] = value;
                }
                else {
                    maxPrefix[index] = (value > maxPrefix[index-1]) ? value : maxPrefix[index-1];
                    minPrefix[index] = (value < minPrefix[index-1]) ? value : minPrefix[index-1];
                }
            
                index++;
            }
        
        }
        else if (command == 1) {
            if (index == 0) {
                printf("Underflow\n");
            }
            else {
                index--;
            }
        }
        else if (command == 2) {
            if (index == 0) {
                printf("Stack is empty\n");
            }
            else {
                printf("%d\n", stack[index-1]);
            }
        }
        else if (command == 3) {
            if (index == 0) {
                printf("Stack is empty\n");
            }
            else {
                printf("%d\n", maxPrefix[index-1]);
            }
        }
        else if (command == 4) {
            if (index == 0) {
                printf("Stack is empty\n");
            }
            else {
                printf("%d\n", minPrefix[index-1]);
            }
        }
    
        scanf("%d", &command);
    }
    
    return 0;
}