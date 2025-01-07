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
#include <string.h>
#include "student.h"
#include "common.h"

/**
 * @brief Application's main entry point
 * @param argc Number of arguments
 * @param argv Pointer to arguments
 * @return Non-zero value in case of an error
 */



//USER FUNCTIONS
void* student_clone(const void* student){


	Student student_copy = (Student)malloc(sizeof(student)); //casting to known type student


	if(student_copy == NULL){
		return NULL;
	}

	Student temp = (Student)student;
	student_copy->name = (char*)malloc(strlen(temp->name) + 1); // +1 for \0
    if (student_copy->name == NULL) {
        free(student_copy); 
        return NULL;
    }

	strcpy(student_copy->name, temp->name);
	student_copy->age = temp->age;
	student_copy->id = temp->id;

	return (void *)student_copy; //reversed casting

}


void student_destroy(void* student){
	if(student== NULL){
		return;
	}
	Student temp = (Student)student;
	free(temp->name); //because it was allocated seperately
	free(temp);
}


void student_print(void* student){

	printf("student name: ");

	Student temp = (Student)student;
	int i=0;
	while(*(temp->name +i)!='\0'){

		printf("%c",*(temp->name +i));
		i++;
	}

	printf(", age: %d, id: %d\n", temp->age, temp->id);


}


