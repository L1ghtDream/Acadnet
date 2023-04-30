#include <stdio.h>
#include <assert.h>

#define true 1
#define false 0

#define IIF(cond) IIF_ ## cond
#define IIF_0(t, f) f
#define IIF_1(t, f) t

#define MULTIPLY(a, b) ((a) * (b))

#define ADD(a, b) ((a) + (b))


int main(void) {
    printf("Your mission, should you choose to accept it, is to test and make sure these macros work!\n");

    printf("Expected result 1, actual result: %d\n", IIF(0)(0, 1));
    printf("Expected result 0, actual result: %d\n", IIF(1)(0, 1));
    printf("Expected result 0, actual result: %d\n", MULTIPLY(1, 0));
    printf("Expected result 1, actual result: %d\n", MULTIPLY(1, 1));
    printf("Expected result 36, actual result: %d\n", MULTIPLY(6, 6));
    printf("Expected result 3, actual result: %d\n", MULTIPLY(1, 1 + 2));
    printf("Expected result 3, actual result: %d\n", MULTIPLY(1 + 2, 1));
    printf("Expected result 3, actual result: %d\n", MULTIPLY(1 + 2, 1 + 0));
    printf("Expected result 18, actual result: %d\n", MULTIPLY(1 + 2, 6 + 0));
    printf("Expected result 18, actual result: %d\n", MULTIPLY(1 + 2, 1 + 2) + MULTIPLY(1 + 2, 1 + 2));

    printf("Expected result 81, actual result: %d\n", MULTIPLY(1 + 2, 1 + 2) * MULTIPLY(1 + 2, 1 + 2));

    printf("Expected result 792, actual result: %d\n", MULTIPLY(6 + 2, 1 + 2) * MULTIPLY(9 + 2, 1 + 2));

    printf("Expected result 57, actual result: %d\n", ADD(MULTIPLY(6 + 2, 1 + 2), MULTIPLY(9 + 2, 1 + 2)));

    printf("Expected result -57, actual result: %d\n", -ADD(MULTIPLY(6 + 2, 1 + 2), MULTIPLY(9 + 2, 1 + 2)));

    assert(1 == IIF(0)(0, 1));
    assert(0 == IIF(1)(0, 1));
    assert(0 == MULTIPLY(1, 0));
    assert(0 == MULTIPLY(0, 1));
    assert(1 == MULTIPLY(1, 1));
    assert(36 == MULTIPLY(6, 6));
    assert(3 == MULTIPLY(1, 1 + 2));
    assert(3 == MULTIPLY(1 + 2, 1));
    assert(3 == MULTIPLY(1 + 2, 1 + 0));
    assert(18 == MULTIPLY(1 + 2, 6 + 0));
    assert(18 == MULTIPLY(1 + 2, 1 + 2) + MULTIPLY(1 + 2, 1 + 2));
    assert(81 == MULTIPLY(1 + 2, 1 + 2) * MULTIPLY(1 + 2, 1 + 2));
    assert(792 == MULTIPLY(6 + 2, 1 + 2) * MULTIPLY(9 + 2, 1 + 2));
    assert(57 == ADD(MULTIPLY(6 + 2, 1 + 2), MULTIPLY(9 + 2, 1 + 2)));
    assert(-57 == -ADD(MULTIPLY(6 + 2, 1 + 2), MULTIPLY(9 + 2, 1 + 2)));

    return 0;
}
