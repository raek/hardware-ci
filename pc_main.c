#include <stdio.h>
#include "simple_io.h"
#include "test.h"

int main(int argc, char **argv)
{
    TEST_runTests();
    return 0;
}

void IO_printLine(const char *line)
{
    puts(line);
}
