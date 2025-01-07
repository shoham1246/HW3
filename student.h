#ifndef STUDENT_H
#define STUDENT_H

#include <stddef.h>  /* size_t type */
#include <stdio.h>   /* printf etc. */
#include <stdlib.h>  /* malloc etc. */
#include <stdbool.h> /* bool type */
#include "common.h"

//enum result { SUCCESS = 0, FAIL };
//typedef void * elem_t;

typedef struct student {
    char *name;
    int age;
    int id;
} *Student;

void* student_clone(const void* student);
//const Student* because the function will not change
//the original object.


void student_destroy(void* student);

void student_print(void* student);


#endif /* STUDENT_H */
