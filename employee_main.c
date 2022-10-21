// Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c
// gcc employeeMain.c employeeTable.c employeeTwo.c
#include <stdlib.h>
#include <string.h>

#include "employee.h"

int main(void) {
    // defined in employeeSearchOne.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char* nameToFind);

    // search by phone and salary
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char* phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);
    // defined in employeeTable.c
    extern Employee EmployeeTable[];    //extern: define somewhere else, don't allocate
    extern const int EmployeeTableEntries;
    PtrToEmployee matchPtr;  // Declaration
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);
    // Example not found
    if (matchPtr != NULL)
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");
    // Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");

    // example
    // match found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "213-555-1212");
    if (matchPtr != NULL)
        printf("Employee phone number 213-555-1212 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee phone number 213-555-1212 is NOT found in the record\n");
    // match not found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "123-456-7890");
    if (matchPtr != NULL)
        printf("Employee phone number 123-456-7890 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee phone number 123-456-7890 is NOT found in the record\n");

    // match found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 7.80);
    if (matchPtr != NULL)
        printf("Employee salary 7.80 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee salary 7.80 is NOT found in the record\n");
    // match not found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 3.50);
    if (matchPtr != NULL)
        printf("Employee salary 3.50 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee salary 3.50 is NOT found in the record\n");
    return EXIT_SUCCESS;
}