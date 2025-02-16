#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funtion.h"
#define max 1000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	struct Student studentList[max];
	int countStudent = 0; 
	struct Classroom classrooms[max];
	int countClass = 1;
	struct Teacher teachers[max];
	int countTeacher = 0;
	int t=1;
	readFile(studentList, &countStudent);
	while(t){
		startProgram();
		int choice1 = inputChoice(0,9);
		switch(choice1){
			case 1:{
				system("cls");
				studentManagement( studentList, &countStudent);
				break;
			}
			case 2:{
				system("cls");
				teacherManagement(teachers, &countTeacher);
				break;
			}
			case 3:{
				system("cls");
				classManagement(classrooms, &countClass, &countStudent, studentList);
				break;
			}
			case 0:{
				system("cls");
				printf(" ======THANK YOU======\n");
				printf("******See You Soon******\n\n");
				t--;
				break;
			}
			default:
				break;
		}
	}
	return 0;
}
