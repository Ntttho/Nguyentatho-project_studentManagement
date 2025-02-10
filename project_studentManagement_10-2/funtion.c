#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "datatypes.h"

void startProgram(){
	printf("***Student Management System Using C***\n\n");
	printf("%6s===================================\n","");
	printf("%6s[1] Admin\n","");
	printf("%6s[2] Student\n","");
	printf("%6s[3] Teacher\n","");
	printf("%6s[0] Exit the program\n","");
	printf("%6s===================================\n","");
}; // bat dau chuong trinh
void menuStudentManagement(){
	printf("***Menu Student Management***\n\n");
	printf("=========================================\n");
	printf("[1] show list student\n");
	printf("[2] add new student\n");
	printf("[3] change student\n");
	printf("[4] delete student\n");
	printf("[5] search student follow name\n");
	printf("[6] soft student follow name\n");
	printf("[7] check inputdata to student\n");
	printf("[8] save information of student to file\n");
	printf("==========================================\n");
};
int inputChoice(int a, int b){
	printf("input (from %d to %d): ",a,b);
	int n; scanf("%d",&n);
	return n;
};
void showListStudent(struct Student studentList[], int numberOfStudent1){
	int i, n;
	n = numberOfStudent1;
	if(n != 0 ){
		printf("|==========|=========================|==============================|===============|==========|\n");
		printf("|%4sID%4s|%10sNAME%11s|%13sEMAIL%12s|%5sPHONE%5s|NO. COURSE|\n"
				,"","","","","","","","");
		printf("|==========|=========================|==============================|===============|==========|\n");
		for(i = 0; i < n; i++){
			printf("|%-10s|%-25s|%-30s|%-15s|%-10s|\n",
					studentList[i].studentId,studentList[i].nameStudent,studentList[i].email,studentList[i].phoneNumberStudent,studentList[i].classroomId);
			printf("|==========|=========================|==============================|===============|==========|\n");
		}
	} else printf("chua co sinh vien nao!\n");
};

void addNewSudent(struct Student *studentList2, int *numberOfStudent2){
	printf("====ENTER INFORMATION OF STUDENT====\n");
	int n = *numberOfStudent2;
	printf("id of student: "); scanf("%s",studentList2[n].studentId);
	printf("classroomId of student: "); scanf("%s",studentList2[n].classroomId);
	printf("name of student: "); fflush(stdin); gets(studentList2[n].nameStudent);
	printf("age of student (date month year) : "); scanf("%d %d %d",&studentList2[n].ageStudent.day, &studentList2[n].ageStudent.month, &studentList2[n].ageStudent.year);
	printf("gender (/1:boy/0:girl/): "); scanf("%d",&studentList2[n].intgender); // --> lay ra nam hoac nu 1:nam 0:nu
	if(studentList2[n].intgender == 1){
		strcpy(studentList2[n].gender, "boy");
	}else if(studentList2[n].intgender == 0){
		strcpy(studentList2[n].gender,"girl");
	}
	printf("phonenumber of student: "); scanf("%s",studentList2[n].phoneNumberStudent);
	printf("email of student: "); scanf("%s",studentList2[n].email);
	*numberOfStudent2 += 1;
	printf("======successfully entering information of student=====\n");
};



void studentManagement(struct Student *students, int *numberOfStudent){
	int t2=1;
	while(t2){
		int choice2 = inputChoice(0,8);
		switch(choice2){
			case 1:{
				showListStudent( students, *numberOfStudent);
				break;
			}
			case 2:{
				addNewSudent( students, &*numberOfStudent);
				break;
			}
			case 3:{
				break;
			}
			case 0:{
				t2--;
				break;
			}
		}
	}
};
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
