#include <stdio.h>
#include <stdlib.h>

#pragma disableWarnings

int main(int argc, char** args) {
    printf("NUMBER OF ARGS: %d\n%s\n", argc, args[0]);
    if (argc == 3) {
        int a, b;
        a = atoi(args[1]);
        b = atoi(args[2]);
        printf("%d x %d = %d\n", a, b, a*b);
    }
    return 0;
}