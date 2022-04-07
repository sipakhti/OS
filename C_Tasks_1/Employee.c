#include <stdlib.h>
#include <stdio.h>


// TODO:
// create an employee linked list to dynamically create memory
// add a while loop that keeps on taking input for employees
// clears screens at every new employee
// blank name will end in termination of input loop

typedef struct Employee {
    int id, age;
    double salary;
    char* name;
} Employee;

int getSize(char* str, ...){
    if (str == NULL) return 0;
    int i = 0;
    while (1)
    {
        if (str[i] == '\0') return i;
        i++;
    }
    
}

int main()
{
    int numberOfEmp;
    printf("Enter the number of employees: ");
    scanf("%d", &numberOfEmp);
    Employee *employees = (Employee*) calloc(sizeof(Employee), numberOfEmp);
    // input loop
    for (size_t i = 0; i < numberOfEmp; i++)
    {
        employees[i].name = (char*) calloc(sizeof(char), 100);
        
        printf("Enter the name of the employee: ");
        // getline(employees[i].name, 100, stdin);
        fflush(stdin);
        // fgets(employees[i].name, 100, stdin);
        // char* temp = fgets(employees[i].name, 100, stdin);
        // printf("%s\n", temp);
        // free(temp);
        scanf("%[^\n]",employees[i].name);
        // printf("sizeof name: %d", getSize(employees[i].name));
        // employees[i].name = (char*) realloc(employees[i].name, sizeof(char) * getSize(employees[i].name));
        printf("Enter the employee age: ");
        scanf("%d", &employees[i].age);
        printf("Enter the employee salary: ");
        scanf("%lf", &employees[i].salary);
        employees[i].id = i+1;
    }

    // output loop
    for (size_t i = 0; i < numberOfEmp; i++)
    {
        printf("ID: %d NAME: %s AGE: %d SALARY: %lf\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
    }

    // deallocate the char* in employee struct
    for (size_t i = 0; i < numberOfEmp; i++)
    {
        free(employees[i].name);
    }
    free(employees);
    
    return 0;    
}