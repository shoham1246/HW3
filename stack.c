/* Welcome to Mamat, 044101
 *
 * Use this project as a template for other C/C++ projects.
 * To copy this project, right-click on the project name "hello-world"
 * in the "project explorer" tab (left), then "copy" and finally "paste".
 *
 * To compile the project use "gcc" within the terminal.
 * To debug the project use "gdb" within the terminal.
 *
 * The red vertical line (right) represents the code width limit (80 chars).
 * Make sure not to cross it. */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/**
 * @brief Application's main entry point
 * @param argc Number of arguments
 * @param argv Pointer to arguments
 * @return Non-zero value in case of an error
 */

//probably not needed cause declared in header: typedef void * elem_t;
//USER FUNCTIONS
typedef void (*print_t)(elem_t e); //function that gets element pointer and print.
typedef void (*destroy_t)(elem_t e); //func that removes element
typedef elem_t (*clone_t)(elem_t e); //func that duplicates element


Stack stack_create(int max_size, clone_t clone, destroy_t destroy, print_t print){
    Stack result = malloc(sizeof(struct stack));
	if (result==NULL) {
		return NULL;
	}
	//initialize fields
	result->max_size = max_size;
	result->num_of_elements = 0;
	result->head_elem = NULL;
	result->clone = clone;
	result->destroy = destroy;
	result->print = print;
	result->elements = malloc(sizeof(elem_t) * max_size);
	/*
		Stack strucure:
		-we have an array of elements[max_size]
		-the start of the array is the bottom of the stack
	*/
	//question - need to insert 0 to all array? for stack_pop..

	if (result->elements == NULL) {
        free(result);
        return NULL;
    }
	return result;
}

int stack_destroy(Stack stack) {
	if (stack==NULL) {
		return 0;
	}
	free(stack);
	return 1;
}

<<<<<<< HEAD
int stack_push(Stack stack, elem_t* elem) {
	if (stack==NULL) {
		return 0;
	}
	elem_t added_elem = (stack->clone)(elem); //need to check success??
	if(added_elem == NULL) {
        return FAIL; // Cloning failed
    }
	stack->elements[stack->num_of_elements] = added_elem;

	stack->head_elem = &(stack->elements[stack->num_of_elements]);
	//head elem points to the last element in the array
	stack->num_of_elements++;
}
=======
int stack_push(Stack stack, void * elem_t) {
	if (stack==NULL) {
		return 0;
	}
	elem_t added_elem = clone_t(elem_t); //need to check success??
	stack->elements[stack->num_of_elements] = added_elem;
	stack->num_of_elements++;
	stack->head_elem = added_elem;
>>>>>>> ee655a294723732a823ba93ab688a713c7609609
	return 1;
}

void stack_pop(Stack stack) {
<<<<<<< HEAD
	elem_t* deleted_elem = stack->head_elem;
=======
>>>>>>> ee655a294723732a823ba93ab688a713c7609609
	stack->elements[stack->num_of_elements] = 0; //set to 0? what to do?
	stack->num_of_elements--;
	stack->head_elem = stack->elements[stack->num_of_elements] ;
	(stack->destroy)(deleted_elem);
}

<<<<<<< HEAD
elem_t * stack_peek(Stack stack) {
=======
//void * stack_peek(Stack stack) {
>>>>>>> ee655a294723732a823ba93ab688a713c7609609
	elem_t* head_elem = stack->head_elem;
	return head_elem; //if fail - head_elem==NULL - it returns NULL
}

int stack_size(Stack stack){
	int stack_size = stack->num_of_elements;
	return stack_size;
}

bool stack_is_empty(Stack stack){
	if(stack->num_of_elements == 0){
		return TRUE;
	}else{
		return FALSE;
	}
}

int stack_capacity(Stack stack){
	int capacity = stack->max_size - stack->num_of_elements;
	return capacity;
}


void stack_print(Stack stack){

	int num_of_elements = stack->num_of_elements;

	/*
		we print from the top element to the bottom,
		the top is at the end of the array, which is why
		the loop is from end to start of the array
	*/
	for(int i = num_of_elements -1 ; i>=0 ; i--){
		print_t(stack->elements[i]);
	}
}



int main(int argc, char **argv) {

	printf("Hello World\n");
	return 0;
}
