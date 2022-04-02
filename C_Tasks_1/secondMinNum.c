#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main(int argc, char** args){
    int min, minNext;
    printf("Enter the Array elements(Enter -99 to stop input): ");
    int input = -99;
    min = INT_MAX;
    minNext = INT_MAX;
    do
    {
        scanf("%d", &input); // takes user input
        if (input != -99) // input does not equal to SIGTERM
        {
            if (input < min) // input less than min
            {
                minNext = min; // replace the second minimun value with min
                min = input; // replace the min value with input
            }
            else if (input < minNext) // input only less than second minimun
            {
                minNext = input; // replace the second minimum value
            }
        }
        
    } while (input != -99);

    printf("OUTPUT: %d\n", minNext);
    return 0;
    
}