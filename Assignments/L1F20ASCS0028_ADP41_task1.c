/**
 * @file L1F20ASCS0028_ADP41_task1.c    
 * @author Umer Mehmood Khan Rana
 * @brief task1 for ADP41 Operating Systems
 * @version 1.0
 * @date 2022-04-04
 * 
 * @copyright sipakhti (c) 2022
 * 
 * @limitations max size of the employee array is 100
 *              no support for names with spaces
 *              
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
#define FILE_NAME "task1.txt"
#define CLEAR_SCREEN "\e[1;1H\e[2J"

int getSize(char* str){
    if (str == NULL) return 0;
    int i = 0;
    while (1)
    {
        if (str[i] == '\0') return i;
        i++;
    }
    
}


typedef struct Employee {
    char* id;
    char* name;
    char gender;
    char* jobPosition;
    int exp;
    double salary;
} Employee;

void printStd(Employee*);
void fprintStd(Employee*, FILE*);
void readData(Employee*, int*);
void addRecord(Employee*,int*);
void searchByID(char[], Employee*, int);
// void searchByName(char[], Employee*, int);
// void searchByGender(char[], Employee*, int);
// void searchByPosition(char[], Employee*, int);
// void searchByExp(int, Employee*, int);
// void searchBySalary(double, Employee*, int);
void deleteRecord(char[], Employee*, int);
// void sortByID(Employee*, int);
// void sortByName(Employee*, int);

void showAllRecords(Employee*, int);
void showBelowBasicPay(Employee*, int, double);

/**
 * @brief prints the employee details using printf
 * 
 * @param employee 
 */
void printStd(Employee* employee){
    printf("%s %s %c %s %d %lf\n", employee->id, employee->name, employee->gender, employee->jobPosition, employee->exp, employee->salary);
}

/**
 * @brief adds the employee data to the fileStream using fprintf
 * 
 * @param employee 
 * @param file fileStream to which the data is written
 */
void fprintStd(Employee* employee, FILE* file){
    fprintf(file, "%s %s %c %s %d %lf\n", employee->id, employee->name, employee->gender, employee->jobPosition, employee->exp, employee->salary);
}

/**
 * @brief reads data from the file
 * 
 * @param employees 
 * @param count record count. pass as reference
 */
void readData(Employee *employees,int *count){
    // open file
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        fprintf(stderr, "\nCANNOT OPEN %s",FILE_NAME);
        exit(1);
    }
    // lopp until end of file
    while (!feof(file)) {
        // initialize employee string fields
        employees[*count].id = (char*) calloc(sizeof(char), MAX_SIZE);
        employees[*count].name = (char*) calloc(sizeof(char), MAX_SIZE);
        employees[*count].jobPosition = (char*) calloc(sizeof(char), MAX_SIZE);
        // read row from file
        fscanf(file, "%s %s %c %s %d %lf", employees[*count].id, employees[*count].name, &employees[*count].gender, employees[*count].jobPosition, &employees[*count].exp, &employees[*count].salary);
        // shrink  arrays to save space.
        employees[*count].id = (char*) realloc(employees[*count].id, sizeof(char) * getSize(employees[*count].id));
        employees[*count].name = (char*) realloc(employees[*count].name, sizeof(char) * getSize(employees[*count].id));
        employees[*count].jobPosition = (char*) realloc(employees[*count].jobPosition, sizeof(char) * getSize(employees[*count].jobPosition));
        // realloc will always work because i am shrinking the array.
        // checking against NULL to make sure that no invalid data is read.
        // workaround for a bug in the fprintf() function. that adds a newline character to the end of the string the row.
        if (employees[*count].id == NULL) continue; 
        (*count)++;
        // the employee array is not dynamic. imposing limit is necessary. it outputs to stderr.
        if (*count == MAX_SIZE) {
            fprintf(stderr, "\nMAX_SIZE REACHED");
            break;
        }
    }

    fclose(file);
}

/**
 * @brief prints all records to stdout using printf
 * 
 * @param employees 
 * @param count 
 */
void showAllRecord(Employee employees[],int count){
    printf(CLEAR_SCREEN); // clear screen
    printf("SHOWING ALL RECORDS(%d)\n", count); // print header
    // loop through all employees and prints each record to the screen.
    for (size_t i = 0; i < count; i++)
        printStd(&employees[i]);
    
    getchar();
    return;
}

/**
 * @brief searches for a record by ID and prints it to stdout using printf
 * 
 * @param ID 
 * @param employees 
 * @param count 
 */
void searchByID(char ID[], Employee employees[],int count){
    printf(CLEAR_SCREEN); // clear screen
    printf("\nSearching for ID: %s\n", ID); // print header
    // loop through all employees and prints matching records to the screen.
    for (size_t i = 0; i < count; i++) 
        if (strcmp(ID, employees[i].id) == 0)
            printStd(&employees[i]);  
    getchar();  
    return;
}

/**
 * @brief prints all the employees below the basic pay to stdout using printf
 * 
 * @param employees 
 * @param count 
 * @param basicPay 
 */
void showBelowBasicPay(Employee employees[],int count, double basicPay){
    printf(CLEAR_SCREEN);
    printf("\nShowing employees below basic pay of %lf\n", basicPay);
    for (size_t i = 0; i < count; i++)
        if (employees[i].salary < basicPay)
            printStd(&employees[i]);
    getchar();
    return;
}

/**
 * @brief adds a new record to the the employee array
 * 
 * @param employees 
 * @param count 
 */
void addRecord(Employee *employees, int *count){
    printf(CLEAR_SCREEN);
    employees[*count].id = (char*) calloc(sizeof(char), MAX_SIZE);
    employees[*count].name = (char*) calloc(sizeof(char), MAX_SIZE);
    employees[*count].jobPosition = (char*) calloc(sizeof(char), MAX_SIZE);
    printf("Enter the employee ID: ");
    scanf("%s", employees[*count].id);
    printf("Enter the employee name: ");
    scanf("%s", employees[*count].name);
    printf("Enter the employee gender: ");
    scanf(" %c", &employees[*count].gender);
    printf("Enter the employee job position: ");
    scanf("%s", employees[*count].jobPosition);
    printf("Enter the employee experience: ");
    scanf("%d", &employees[*count].exp);
    printf("Enter the employee salary: ");
    scanf("%lf", &employees[*count].salary);
    (*count)++;
}

/**
 * @brief saves the data to the file. overwrites the file. instead of appending
 * 
 * @param employees 
 * @param count 
 */
void save(Employee employees[],int count){
    printf(CLEAR_SCREEN);
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        fprintf(stderr, "\nCANNOT OPEN %s",FILE_NAME);
        exit(1);
    }
    printf("SAVING DATA\n");
    for (size_t i = 0; i < count; i++)
        fprintStd(&employees[i], file);
    
    fclose(file);
    return;
}

/**
 * @brief deletes a record from the employee array by ID
 * 
 * @param ID 
 * @param employees 
 * @param count 
 */
void deleteRecord(char ID[], Employee employees[], int count){
    printf(CLEAR_SCREEN);
    printf("\nDeleting record with ID: %s\n", ID);
    for (size_t i = 0; i < count; i++)
        if (strcmp(ID, employees[i].id) == 0) {
            for (size_t j = i; j < count - 1; j++)
                employees[j] = employees[j + 1];
            count--;
            break;
        }
    return;
}

int main(){

    int count = 0;
    Employee *employees = (Employee*) calloc(sizeof(Employee), MAX_SIZE);
    readData(employees, &count);

    int choice = 0;
    while (1)
    {
        printf(CLEAR_SCREEN);
        printf("==================== MENU =================== \n");
        printf("1. Add a record \n");
        printf("2. Delete a record \n");
        printf("3. Search a record by ID \n");
        printf("4. Show all records \n");
        printf("5. Show employees having pay less then basic pay (20000) \n");
        printf("6. Save and exit \n");
        printf("==================== MENU =================== \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addRecord(employees, &count);
            break;
        case 2:
            printf("Enter the ID of the record to be deleted: ");
            char ID[MAX_SIZE];
            scanf("%s", ID);
            deleteRecord(ID, employees, count);
            break;        
        case 3:
            printf("Enter the employee ID: ");
            ID[MAX_SIZE];
            scanf("%s", ID);
            searchByID(ID, employees, count);
            break;
        case 4:
            showAllRecord(employees, count);
            break;
        case 5:
            showBelowBasicPay(employees, count, 20000);
            break;
        case 6:
            save(employees, count);
            free(employees);
            return 0;
        default:
            printf("Invalid choice. Please try again\n");
            break;
        }
        printf("\nPress enter to continue\n");
        getchar();
    }
    
    return 0;

}
