/*
	Acadnet 2017 - Etapa Judeteana
	Problema A
*/

#include <stdio.h>
#include <limits.h>
#include <vector>

using namespace std;

int compute_min(const vector<int> &v)
{
    int min = INT_MAX, i;

    for(i = 0; i < v.size(); i++)
        if (min > v[i])
            min = v[i];

    return min;
}

int count_3min(const vector<int> &v, int min)
{
    int cnt = 0, i;

    for(i = 0; i < v.size(); i++)
        if (3 * min > v[i])
            cnt++;

    return cnt;
}

int main()
{
    vector<int> v;
    int min, n, i, cnt;

    scanf("%d", &n);
    v.resize(n, 0);

    for (i = 0; i < n; i++)
        scanf("%d", &v[i]);

    min = compute_min(v);
    printf("%d ", min);
    cnt = count_3min(v, min);
    printf("%d\n", cnt);

    return 0;
}
