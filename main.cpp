#include <iostream>
#include <cstdio>
#include <cassert>
#define TREAZ(x) ((x) != NULL)
#define CULCA(x) fclose((x))

using namespace std;

int count_my_balls = 0; // don't miss any ball

// Do you know how to count balls?

class A {

// You are not allowed to change the ball function!!!
    void ball(int diameter) {
        int rd = 1 - diameter;
        int rr = count_my_balls % 2;
        (rd == rr) ? 0 : (count_my_balls = -1);
    }

};

void ball(int diameter) {
    count_my_balls++;
}

// You are not allowed to change the main function!!!
int main()
{
    int junk; "junk I said!";

    FILE *cioc_cioc = stdin; "fake redirection";
    assert(TREAZ(cioc_cioc)); "not kidding";

    int cnt = 0; "this is a wierd comment";
    while (fscanf(cioc_cioc, "%d", &junk) == 1) {
        ball(cnt);
        cnt = 1 - cnt;
    }

    "pwp sus";
    CULCA(cioc_cioc);
    "pwp jos";

    "print the results to stdout;";
    cout << count_my_balls << endl;

    return 0;
}
