

#include <stddef.h>
#include <stdio.h>

typedef struct {
    long number;
    char *name;
    char *phone;
    double salary;  // make everything 8 bytes
} Employee, *PtrToEmployee;
typedef const Employee *PtrToConstEmployee;