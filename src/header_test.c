#include <unistd.h>

#include "header_test.h"

void hello_func(int port)
{
    printf("Header worked! \n");
    printf("Port: %d", port);
}
