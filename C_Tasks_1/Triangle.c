#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Triangle {
    int a;
    int b;
    int c;
} Triangle;


bool isValid(Triangle *T) {
    // a side cannot be bigger or equal to sum of other two sides
    // checking A                  checking B              checking C
   return (T->b + T->c > T->a) && (T->a + T->c > T->b) && (T->a + T->b > T->c);
}

bool isScalene(Triangle *T){
    // each side is of different length
    // AB AC BC
    return (T->a != T->b) && (T->a != T->c) && (T->b != T->c);
}

bool isIsosceles(Triangle* T){
    // if any two sides are equal
    // AB AC BC
    return (T->a == T->b) || (T->a == T->c) || (T->b == T->c);
}

bool isEquilateral(Triangle* T){
    // if all sides are equal
    // AB BC
    return (T->a == T->b) && (T->b == T->c);
}

int main(int argc, char** argv) {
    Triangle T;
    printf("Enter the first value= ");
    scanf("%d",&T.a);
    printf("Enter the second value= ");
    scanf("%d",&T.b);
    printf("Enter the third value= ");
    scanf("%d",&T.c);
    if (isValid(&T)) {
        printf("Valid\n");
        if (isScalene(&T))
            printf("SACALENE: a:%d b:%d c:%d\n", T.a, T.b, T.c);
        else if (isIsosceles(&T))
            printf("ISOSCELES: a:%d b:%d c:%d\n", T.a, T.b, T.c);
        else if (isEquilateral(&T))
            printf("EQUILATERAL: a:%d b:%d c:%d\n", T.a, T.b, T.c);
        else
            printf("SOME WEIRD KIND OF TRIANGLE THIS IS! \033[32mBEGONE THOT!!!\033[0m");
    } else {
        printf("\033[33mInvalid\033[0m");
    }
    
    return 0;
}

