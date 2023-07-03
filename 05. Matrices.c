/*
TASK 1. Transpose the matrix
*/

#include <stdio.h>

int main() {
	int N = 0, M = 0;
	scanf("%d%d", &N, &M);
	int a[100][100];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf("%d", &a[j][i]);
		}
	}
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}

/*
TASK 2. Swap columns in the matrix
*/

#include <stdio.h>

int main() {
    int N, M, i, j, sum, max_sum = -1000000, max_index, min_sum = 1000000, min_index, tmp;
    scanf("%d%d", &N, &M);
    int a[N][M];
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < M; i++) {
        sum = 0;
        for (j = 0; j < N; j++) {
            sum += a[j][i];
        }
        if (sum > max_sum) {
            max_sum = sum;
            max_index = i;
        }
        if (sum < min_sum) {
            min_sum = sum;
            min_index = i;
        }
        printf("%d ", sum);
    }
    printf("\n");
    for (i = 0; i < N; i++) {
        tmp = a[i][max_index];
        a[i][max_index] = a[i][min_index];
        a[i][min_index] = tmp;
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/*
TASK 3. Swap matrix rows
*/

#include <stdio.h>

int main() {
    int N, i, j, k, target_index, tmp;
    scanf("%d", &N);
    int a[N][N];
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (a[i][j] == 0) {
                target_index = j;
                break;
            }
        }
        if (target_index == i) continue;
        for (k = 0; k < N; k++) {
            tmp = a[i][k];
            a[i][k] = a[target_index][k];
            a[target_index][k] = tmp;
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/*
TASK 4. The amount in the rectangle
*/

#include <stdio.h>

int main() {
	int N = 0, M = 0;
	scanf("%d%d", &N, &M);
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	int a[100][100] = { 0 };
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	int sum = 0;
	for (int i = x1-1; i < x2; ++i) {
		for (int j = y1-1; j < y2; ++j) {
			sum += a[i][j];
		}
	}
	printf("%d\n", sum);
	return 0;
}

/*
TASK 5. Count the local lows
*/

#include <stdio.h>

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    int a[100][100] = {0};
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    int co = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (a[i][j] < a[(i + N - 1) % N][j] &&
                a[i][j] < a[(i + N - 1) % N][(j + M + 1) % M] &&
                a[i][j] < a[i][(j + M + 1) % M] &&
                a[i][j] < a[(i + N + 1) % N][(j + M + 1) % M] &&
                a[i][j] < a[(i + N + 1) % N][j] &&
                a[i][j] < a[(i + N + 1) % N][(j + M - 1) % M] &&
                a[i][j] < a[i][(j + M - 1) % M] &&
                a[i][j] < a[(i + N - 1) % N][(j + M - 1) % M]) {
                printf("%d %d\n", i + 1, j + 1);
                co++;
            }
        }
    }
    printf("%d\n", co);
    return 0;
}
