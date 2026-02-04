#include <stdio.h>
#include "math_utils.h"
#include "logger.h"

int main(void)
{
    extern int value;
    int result = add(-10, 20);
    printf("Result = %d\n", result);

    log_message("Program started");
    log_message("Calculation done");

    printf("\nvalue:%d\n",value);
    return 0;
}
