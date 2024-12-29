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


//USER FUNCTIONS
typedef void (*print_t)(elem_t e); //function that gets element pointer and print.


Stack stack_create(int max_size) {
    Stack result = malloc(sizeof(struct stack));
	if (result==NULL) {
		return NULL;
	}
	//need fields?

	//initialize fields
	result->max_size = max_size;
	result->num_of_elements = 0;
	result->head_elem = NULL;
	result->elements = malloc(sizeof(elem_t) * max_size); 

	/*
		Stack strucure:
		-we have an array of elements[max_size]
		-the start of the array is the bottom of the stack
	*/

	if (result->elements == NULL) {
        free(result);
        return NULL;
    }


	return result;
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
