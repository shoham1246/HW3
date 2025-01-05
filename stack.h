#ifndef STACK_H
#define STACK_H

#include <stddef.h>  /* size_t type */
#include <stdio.h>   /* printf etc. */
#include <stdlib.h>  /* malloc etc. */
#include <stdbool.h> /* bool type */

enum result { SUCCESS = 0, FAIL };
typedef void* elem_t;
typedef elem_t (*clone_t)(elem_t e);
typedef void (*destroy_t)(elem_t e);
typedef void (*print_t)(elem_t e);

typedef struct stack {
	int max_size;
	int num_of_elements;
	elem_t* head_elem; //pointer to the top element
	elem_t* elements; // Array to store the elements
	clone_t clone;    // Function to clone elements
    destroy_t destroy; // Function to destroy elements
    print_t print;    // Function to print elements

} *Stack;

Stack stack_create(int max_size, clone_t clone, destroy_t destroy, print_t print); 

int stack_destroy(Stack stack);
int stack_push(Stack stack, elem_t* elem_t);
void stack_pop(Stack stack);
elem_t* stack_peek(Stack stack);

int stack_size(Stack stack);
bool stack_is_empty(Stack stack);
int stack_capacity(Stack stack);
void stack_print(Stack stack);




#endif /* STACK_H */

