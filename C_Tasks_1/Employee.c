#include <stdlib.h>
#include <stdio.h>



// create an employee linked list to dynamically create memory
// add a while loop that keeps on taking input for employees
// clears screens at every new employee
// blank name will end in termination of input loop
typedef struct Employee {
    int id, age;
    double salary;
    char* name;
} Employee;

int getSize(char* str){
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
    Employee *employees = (Employee*) malloc(sizeof(Employee) * numberOfEmp);
    for (size_t i = 0; i < numberOfEmp; i++)
    {
        employees[i].name = (char*) calloc(sizeof(char), 100);
        
        printf("Enter the name of the employee: ");
        // getline(employees[i].name, 100, stdin);
        fflush(stdin);
        fgets(employees[i].name, 100, stdin);
        // char* temp = fgets(employees[i].name, 100, stdin);
        // printf("%s\n", temp);
        // free(temp);
        // scanf("%s[^\n]s",employees[i].name);
        // printf("sizeof name: %d", getSize(employees[i].name));
        // employees[i].name = (char*) realloc(employees[i].name, sizeof(char) * getSize(employees[i].name));
        printf("Enter the employee age: ");
        scanf("%d", &employees[i].age);
        printf("Enter the employee salary: ");
        scanf("%lf", &employees[i].salary);
        employees[i].id = i+1;
    }

    for (size_t i = 0; i < numberOfEmp; i++)
    {
        printf("ID: %d NAME: %s AGE: %d SALARY: %lf\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
    }

    for (size_t i = 0; i < numberOfEmp; i++)
    {
        free(employees[i].name);
    }
    free(employees);
    
    return 0;    
}