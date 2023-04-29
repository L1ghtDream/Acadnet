#include <iostream>

using namespace std;

// IMPORTANT: Singurele linii care pot fi schimbate sunt cele care incep
// cu #define.
#define SIGNBITONLY(x)	((x) >> (sizeof((x)) * 8 - 1))
#define ABS(x)		(((x) + SIGNBITONLY(x)) ^ SIGNBITONLY(x))
#define MINMAXOP(x, y, OP) ((x + y OP ABS(x - y)) / 2)
#define MIN(x, y)	MINMAXOP(x, y, -)
#define MAX(x, y)	MINMAXOP(x, y, +)

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << MIN(a, MIN(b, c)) << ' ' << MAX(MAX(a, b), c) << '\n';
    return 0;
}
