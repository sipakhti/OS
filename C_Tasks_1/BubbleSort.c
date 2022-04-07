#include <stdlib.h>
#include <stdio.h>


int populateArray(int*, int*, int);
void bubbleSort(int*, int);
void printNumbers(int*, int);

int main(int argv, char** argc){

    const int SIZE = 20;
    int* numbers = (int*) calloc(sizeof(int), SIZE);
    int* sortedNumbers = (int*) calloc(sizeof(int), SIZE);
    int actualSize = populateArray(numbers, sortedNumbers, SIZE);
    bubbleSort(sortedNumbers, actualSize);
    printf("The entered sequence is: ");
    printNumbers(numbers, actualSize);
    printf("Updated sequence is: ");
    printNumbers(sortedNumbers, actualSize);
    free(numbers);
    free(sortedNumbers);
    return 0;
}

int populateArray(int* primary, int* secondary, int size){
    printf("ENTER 20 VALUES. ENTER -99 stop input.\n");
    for (int i = 0; i < size; i++)
    {
        printf("Enter value for index(%d): ",i);
        scanf("%d",&primary[i]);
        if (primary[i] == -99) return i;
        secondary[i] = primary[i];
    }
    
}

void bubbleSort(int* numbers, int size) {
    int temp;
    for (int i = 1; i <= size; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            if (numbers[j] > numbers[j+1]){
                temp = numbers[j+1];
                numbers[j+1] = numbers[j];
                numbers[j] = temp;
            }
        }
        
    }
    
}

void printNumbers(int* numbers, int size){
    for (size_t i = 0; i < size; i++)
        printf("%d ", numbers[i]);
    printf("\n");
    return;
}