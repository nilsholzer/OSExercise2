#include "print.h"
#include <stdio.h>

void print_line(int64_t number, char *string)
{
    printf("%" PRId64 " %s\n", number, string);
}
