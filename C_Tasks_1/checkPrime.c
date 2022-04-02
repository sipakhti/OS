#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void checkPrimeNumber();
bool isPrime(int);

void checkPrimeNumber(){
    int number;
    printf("Enter the number= ");
    scanf("%d", &number);
    if (isPrime(number))
        printf("PRIME\n");
    else
        printf("NOT PRIME\n");
    return;
}

bool isPrime(int number){
    if (number < 2) return false;
    for (int i = 2; i <= number/2; i++)
        if (number % i == 0) return false;
    return true;
}

int main(int argc, char** argv){
    checkPrimeNumber();
    return 0;
}