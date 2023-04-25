#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int m = n * (n + 1) / 2;

    int sum = 0;
    for (int i = 0; i <= n; ++i)
        sum += i;

    printf("Suma primelor %d numere este %d = %d\n", n, m, sum);
}