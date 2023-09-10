/*
TASK 1. Conway's cellular automaton
*/

#include <stdio.h>

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    int a[100][100] = {0};
    int b[100][100] = {0};
    int zhiv = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int h;
            scanf("%d", &h);
            if (h == 1) {
                zhiv++;
            }
            a[i][j] = h;
            b[i][j] = h;
        }
    }
    int period = 1;
    while (period <= 1000) {
        int perexod = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                int nakop1 = a[(i + N - 1) % N][j] +
                             a[(i + N - 1) % N][(j + M + 1) % M] +
                             a[i][(j + M + 1) % M] +
                             a[(i + N + 1) % N][(j + M + 1) % M] +
                             a[(i + N + 1) % N][j] +
                             a[(i + N + 1) % N][(j + M - 1) % M] +
                             a[i][(j + M - 1) % M] +
                             a[(i + N - 1) % N][(j + M - 1) % M];
                if (a[i][j] == 0 && nakop1 == 3) {
                    b[i][j] = 1;
                    zhiv++;
                    perexod++;
                } else if (a[i][j] == 1 && nakop1 != 2 && nakop1 != 3) {
                    b[i][j] = 0;
                    zhiv--;
                    perexod++;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                a[i][j] = b[i][j];
            }
        }
        if (period == 1 || period == 10 || period == 100 || period == 1000) {
            printf("Step %d: alives %d\n", period, zhiv);
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    printf("%c", a[i][j] ? 'x' : ' ');
                }
                printf("\n");
            }
            if (period == 1000) {
                printf("End life step 1000");
            }
        }
        if (perexod == 0 || zhiv == 0) {
            printf("End life step %d\n", period);
            break;
        }
        period++;
    }
    return 0;
}
