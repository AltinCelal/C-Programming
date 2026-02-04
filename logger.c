#include <stdio.h>
#include "logger.h"

// SADECE BU DOSYAYA ÖZEL
static int log_count = 0;
int value = 15;
void log_message(const char *msg)
{
    log_count++;
    printf("[%d] %s\n", log_count, msg);
}
