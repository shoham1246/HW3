#ifndef COMMON_H
#define COMMON_H

#include <stddef.h>  /* size_t type */
#include <stdio.h>   /* printf etc. */
#include <stdlib.h>  /* malloc etc. */
#include <stdbool.h> /* bool type */

enum result { SUCCESS = 0, FAIL };
typedef void * elem_t;

typedef struct stack {
	int max_size;
	int num_of_elements;
	void* head_elem; //pointer to the top element
	elem_t* elements; // Array to store the elements
} *Stack;

Stack stack_create(int max_size); //complete alone??

int stack_destroy(Stack stack);
int stack_push(Stack stack, void * elem_t);
void stack_pop(Stack stack);
void * stack_peek(Stack stack);

int stack_size(Stack stack);
bool stack_is_empty(Stack stack);
int stack_capacity(Stack stack);
void stack_print(Stack stack);




#endif /* COMMON_H */

