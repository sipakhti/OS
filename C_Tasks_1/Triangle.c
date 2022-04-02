#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Triangle {
    int a;
    int b;
    int c;
} Triangle;


bool isValid(Triangle *T) {
   return (T->a + T->b > T->c) && (T->a + T->c > T->b) && (T->b + T->c > T->a);
}

bool isScalene(Triangle *T){
    return (T->a != T->b) && (T->a != T->c) && (T->b != T->c);
}

bool isIsosceles(Triangle* T){
    return (T->a == T->b) || (T->a == T->c) || (T->b == T->c);
}

bool isEquilateral(Triangle* T){
    return (T->a == T->b) && (T->b == T->c);
}

int main(int argc, char** argv) {
    Triangle T;
    printf("Enter the first value=");
    scanf("%d",&T.a);
    printf("Enter the second value=");
    scanf("%d",&T.b);
    printf("Enter the third value=");
    scanf("%d",&T.c);
    if (isValid(&T)) {
        printf("Valid\n");
        if (isScalene(&T))
            printf("SACALENE\n");
        else if (isIsosceles(&T))
            printf("ISOSCELES\n");
        else if (isEquilateral(&T))
            printf("EQUILATERAL\n");
        else
            printf("SOME WEIRD KIND OF TRIANGLE THIS IS! \033[32mBEGONE THOT!!!\033[0m");
    } else {
        printf("\033[33mInvalid\033[0m");
    }
    
    return 0;
}

