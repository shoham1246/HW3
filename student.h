#ifndef STUDENT_H
#define STUDENT_H

#include <stddef.h>  /* size_t type */
#include <stdio.h>   /* printf etc. */
#include <stdlib.h>  /* malloc etc. */
#include <stdbool.h> /* bool type */

enum result { SUCCESS = 0, FAIL };
typedef void * elem_t;

typedef struct student {
	char *name;
	int age;
	int id;
};


Student* student_clone(const Student* student);
//const Student* because the function will not change
//the original object.


void student_destroy(Student* student);

void student_print(Student* student);


#endif /* STUDENT_H */
