#include<stdio.h>

int a[100][100], b[100][100], c[100][100];

int i, j, k, m, n, p;

int main()
{
    scanf("%d%d%d", &n, &m, &p);

    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < m; ++i) {
        for(j = 0; j < p; ++j) {
            scanf("%d", &b[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < p; j++) {
            for (k = 0; k < m; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < p; ++j) {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
}