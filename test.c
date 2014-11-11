#include <stdio.h>
#include "test.h"
#include "simple_io.h"

static int testPerfect(int i, int expected, int n);
static int isPerfect(int n);

void TEST_runTests(void)
{
    IO_printLine("1..6");
    testPerfect(1, 0, 1);
    testPerfect(2, 0, 5);
    testPerfect(3, 1, 6);
    testPerfect(4, 0, 27);
    testPerfect(5, 1, 28);
    testPerfect(6, 0, 495);
    testPerfect(7, 1, 496);
}

static int testPerfect(int i, int expected, int n)
{
    char line[200];
    if (isPerfect(n) == expected) {
        snprintf(line, 200, "ok %d - isPerfect(%d) == %d", i, n, expected);
    } else {
        snprintf(line, 200, "not ok %d - isPerfect(%d) == %d", i, n, expected);
    }
    IO_printLine(line);
}

static int isPerfect(int n)
{
    int i;
    int s;
    s = 0;
    for (i = 1; i < n; i++) {
        if ((n % i) == 0) {
            s += i;
        }
    }
    return s == n;
}
