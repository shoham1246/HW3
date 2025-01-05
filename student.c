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

/**
 * @brief Application's main entry point
 * @param argc Number of arguments
 * @param argv Pointer to arguments
 * @return Non-zero value in case of an error
 */


//USER FUNCTIONS
Student* student_clone(const Student* student){


	Student* student_copy = (Student*)malloc(sizeof(Student));


	if(student_copy == NULL){
		return NULL;
	}

	student_copy->name = (char*)malloc(strlen(student->name) + 1); // +1 for \0
    if (student_copy->name == NULL) {
        free(student_copy); 
        return NULL;
    }

	strcpy(student_copy->name, student->name);
	student_copy->age = student->age;
	student_copy->id = student->id;

	return student_copy;

}


void student_destroy(Student* student){

	free(student->name); //because it was allocated seperately
	free(student);
}


void student_print(Student* student){

	printf("student name: ");


	i=0;
	while(*(student->name +i)!='\0'){

		printf("%c",*(student->name +i));
		i++;
	}

	printf(", age: %d, id: %d\n", student->age, student->id);


}



int main(int argc, char **argv) {

	printf("Hello World\n");
	return 0;
}