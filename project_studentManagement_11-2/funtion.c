#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "datatypes.h"

void resetCmd() { // xoa bo dem nho nhap enter xoa man hinh cmd
    // In thông báo
    printf("+++ 'enter' to come back: ");

    while (getchar() != '\n');
    	getchar();  
    system("cls");
}

void startProgram(){
	printf("***Student Management System Using C***\n\n");
	printf("%6s===================================\n","");
	printf("%6s[1] Student_management\n","");
	printf("%6s[2] Student\n","");
	printf("%6s[3] Teacher\n","");
	printf("%6s[0] Exit the program\n","");
	printf("%6s===================================\n","");
}; // bat dau chuong trinh

void menuStudentManagement(){
	printf("***Menu Student Management***\n\n");
	printf("=========================================\n");
	printf("[1] show list student\n"); // if n == 0					V
	printf("[2] add new student\n"); // none						V
	printf("[3] fix infor student\n"); // if n == 0					V
	printf("[4] delete student\n"); // if n == 0					V
	printf("[5] search student follow name\n"); // if n == 0 		V
	printf("[6] soft student follow name\n"); // none				V
	printf("[7] check inputdata to student\n"); // if n == 0		X
	printf("[8] save information of student to file\n");//			X
	printf("==========================================\n");
};

int inputChoice(int a, int b){
	printf("input (from %d to %d): ",a,b);
	int n; scanf("%d",&n);
	return n;
};

void showListStudent(struct Student studentList[], int begin ,int numberOfStudent1){
	int i, n; // gia tri begin dung de show tu begin den numberOfStudent1 // (begin tai su dung cac yeu cau khong chi la show ca list student)
	n = numberOfStudent1;
	if(n != 0 ){
		printf("|==========|=========================|==============================|===============|==========|\n");
		printf("|%4sID%4s|%10sNAME%11s|%13sEMAIL%12s|%5sPHONE%5s|NO. COURSE|\n"
				,"","","","","","","","");
		printf("|==========|=========================|==============================|===============|==========|\n");
		for(i = begin; i < n; i++){
			printf("|%-10s|%-25s|%-30s|%-15s|%-10s|\n",
					studentList[i].studentId,studentList[i].nameStudent,studentList[i].email,studentList[i].phoneNumberStudent,studentList[i].classroomId);
			printf("|==========|=========================|==============================|===============|==========|\n");
		}
	} else printf("chua co sinh vien nao!\n");
	resetCmd();
};

void addNewStudent(struct Student *studentList2, int *numberOfStudent2, int check ){
	// check o day dung de tai su dung cho ham fixinforstudent!!!
	printf("====ENTER INFORMATION OF STUDENT====\n");
	int n = *numberOfStudent2;
	if(check != 0){
		printf("id of student: "); scanf("%s",studentList2[n].studentId);
	}
	printf("classroomId of student: "); scanf("%s",studentList2[n].classroomId);
	printf("name of student: "); fflush(stdin); gets(studentList2[n].nameStudent);
	printf("age of student (date month year) : "); scanf("%d %d %d",&studentList2[n].dateStudent.day, &studentList2[n].dateStudent.month, &studentList2[n].dateStudent.year);
	printf("gender (/1:boy/0:girl/): "); scanf("%d",&studentList2[n].intgender); // --> lay ra nam hoac nu 1:nam 0:nu
	if(studentList2[n].intgender == 1){
		strcpy(studentList2[n].gender, "boy");
	}else if(studentList2[n].intgender == 0){
		strcpy(studentList2[n].gender,"girl");
	}
	printf("phonenumber of student: "); scanf("%s",studentList2[n].phoneNumberStudent);
	printf("email of student: "); scanf("%s",studentList2[n].email);
	if(check != 0){
		*numberOfStudent2 += 1;
	}
	printf("======successfully entering information of student=====\n");
	resetCmd();
	
};

void fixInforStudent(struct Student *studentList3, int numberOfStudent3){
	int check = 0;
	int i; int n = numberOfStudent3;
	if(numberOfStudent3 != 0){
		char checkId[10]; printf("enter Id to check: "); scanf("%s",checkId);
		for(i = 0; i < n; i++){
			if(!strcmp(studentList3[i].studentId, checkId)){
				printf("=====student you find here!=====\n");
				showListStudent(studentList3, i, i+1);
				addNewStudent(studentList3, &i, 0);
				check = 1;
				printf("fix infor of student success!\n");
				break;	
			}
		}
		if(check == 0 ){ // sau vong lap neu khong tim thay id sv thi se in thong bao khong tim thay
			printf("don't have id of student here!...\n");
		}
	} else printf("no student here!...\n");
	resetCmd();
};

void deleteStudent(struct Student *studentList4, int *numberOfStudent4){
	if(*numberOfStudent4 !=0){
		*numberOfStudent4 = *numberOfStudent4 - 1;
		int check = 0;
		int i, j, n = *numberOfStudent4;
		char checkId[10]; printf("enter Id to check: "); scanf("%s",checkId);
		for(i = 0; i < n; i++){
			if(!strcmp(studentList4[i].studentId, checkId)){
				for( j = i ; j < n; j++){
					studentList4[j] = studentList4[j + 1]; 
					check = 1;
					printf("delete student success!\n");
					break;
				}
				break;
			}
		}
		if(check == 0){ //sau vong lap neu khong tim thay thi se thong bao khong co id o day
			printf("don't have id of student here!...\n");
		}
	} else printf("no student here!...\n");
	resetCmd();
};

void sortStudent1(struct Student *studentList6, int numberOfStudent6){ // sap xep theo anfarB
	int i, j, n = numberOfStudent6;
	for(i = 1; i < n; i++){
		j = i - 1;
		struct Student key = studentList6[i];
		while( j >= 0 && strcmp(studentList6[j].nameStudent, key.nameStudent) > 0){ // so sanh ky tu dau tien cua ten
			studentList6[j + 1] = studentList6[j];
			j = j - 1;
		}
		studentList6[j + 1] = key;
	}
	printf("successful sort student by their name!\n");
	resetCmd();
}
void sortStudent2(struct Student *studentList6, int numberOfStudent6){ // sap xep theo do dai cua ten sv
	int i, j, n = numberOfStudent6;
	for(i = 1; i < n; i++){
		j = i - 1;
		struct Student key = studentList6[i];
		while( j >= 0 && studentList6[j].nameStudent > key.nameStudent ){ // so sanh ky tu dau tien cua ten
			studentList6[j + 1] = studentList6[j];
			j = j - 1;
		}
		studentList6[j + 1] = key;
	}
	printf("successful sort student by their name!\n");
	resetCmd();
}

void searchStudent(struct Student *studentList5, int numberOfStudent5){
	int i, n = numberOfStudent5;
	int serial = 1; 
	if( n != 0){
		char name[25]; printf("enter name of student that you want search: "); fflush(stdin); gets(name);
		for(i =0 ; i< n; i++){
			if(strcmp( studentList5[i].nameStudent, name) == 0){
				printf("student: %s\n", studentList5[i].nameStudent);
				printf("++===================================================++\n");
				printf("|| %-12s | %-35s||\n","ClassId",studentList5[i].classroomId);
				printf("|| %-12s | %-35s||\n","StudentId",studentList5[i].studentId);
				printf("|| %-12s | %2d/2%d/4%d%27s||\n","birthday",studentList5[i].dateStudent.day,studentList5[i].dateStudent.month,studentList5[i].dateStudent.year,"");
				printf("|| %-12s | %-35s||\n","Gender",studentList5[i].gender);
				printf("|| %-12s | %-35s||\n","phonenumber",studentList5[i].phoneNumberStudent);
				printf("|| %-12s | %-35s||\n","",studentList5[i].email);
				printf("++===================================================++\n");
				serial+=1;
			}
		}
		if(serial == 1){
			printf("don't find here!\n");
		}
	} else printf("no student here!...\n");
};

void studentManagement(struct Student *students, int *numberOfStudent){
	int t2=1;
	while(t2){
		menuStudentManagement();
		int choice2 = inputChoice(0,8);
		switch(choice2){
			case 1:{
				system("cls");
				showListStudent( students, 0 ,*numberOfStudent);
				break;
			}
			case 2:{
				system("cls");
				addNewStudent( students, &*numberOfStudent, 1);
				break;
			}
			case 3:{
				system("cls");
				fixInforStudent(students, *numberOfStudent);
				break;
			}
			case 4:{
				system("cls");
				deleteStudent(students, &*numberOfStudent);
				break;
			}
			case 5:{
				system("cls");
				searchStudent(students, *numberOfStudent);
				break;
			}
			case 6:{
				system("cls");
				printf("========sort with name of student========\n");
				printf("[1] anFarB\n");
				printf("[2] lenght of student\n");
				int choice3 = inputChoice(1,2);
				switch(choice3){
					case 1:{
						sortStudent1(students, *numberOfStudent);
						break;
					}
					case 2:{
						sortStudent2(students, *numberOfStudent);
						break;
					}
				}
				break;
			}
			case 7:{
				system("cls");
				break;
			}
			case 0:{
				system("cls");
				t2--;
				break;
			}
		}
	}
};
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
