#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    printf(1, "the following line will test exit(0) %d\n", add());
    exit(0);
}