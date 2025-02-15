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

void menuTeacher(){
	printf("%7s========Menu Teacher Management========\n","");
	printf("%7s[1] Show list teacher\n","");
	printf("%7s[2] Add new teacher\n","");
	printf("%7s[3] Fix infor of teacher\n","");
	printf("%7s[4] Delete teacher\n","");
	printf("%7s[5] Search infor teacher\n","");
	printf("%7s[6] add new class to teacher\n","");
	printf("%7s[7] check teacher'inputdata\n","");
	printf("%7s[8] action with file\n","");
	printf("%7s[0] Come Back\n","");
	printf("%7s=======================================\n","");
};


void startProgram(){ 
	printf("***Student Management System Using C***\n\n");
	printf("%6s===================================\n","");
	printf("%6s[1] Student_management\n","");
	printf("%6s[2] Teacher_management\n","");
	printf("%6s[3] Class_management\n","");
	printf("%6s[0] Exit the program\n","");
	printf("%6s===================================\n","");
}; // bat dau chuong trinh

void menuStudentManagement(){
	printf("***Menu Student Management***\n\n"); // tieu de menu quan ly sinh vien V
	printf("=========================================\n");
	printf("[1] show list student\n"); // if n == 0					V // show danh sach sinh vien
	printf("[2] add new student\n"); // none						V // them moi sinh vien
	printf("[3] fix infor student\n"); // if n == 0					V // chinh sua thong tin sinh vien
	printf("[4] delete student\n"); // if n == 0					V // xoa sinh vien
	printf("[5] search student follow name\n"); // if n == 0 		V // tim kiem xem thong tin sinh vien
	printf("[6] soft student follow name\n"); // none				V // sap xep sinh vien theo do dai ten hoac theo anfarB
	printf("[7] check inputdata to student\n"); // if n == 0		V // kiem tra du lieu sinh vien
	printf("[8] save data to file'student \n");//					X // luu thong tin sinh vien vao file bin
	printf("[0] come back\n");
	printf("==========================================\n");
};

void menuClassManagement(){
	printf("***Menu Class Management***\n\n");
	printf("%6s====================================\n","");
	printf("%6s[1] show List classroom\n","");
	printf("%6s[2] add new classroom\n","");
	printf("%6s[3] fix classroom'infor\n","");
	printf("%6s[4] delete classroom\n","");
	printf("%6s[5] show full infor of classroom\n","");
	printf("%6s[6] detele student of classroom\n","");
	printf("%6s[7] sort list classroom\n","");
	printf("%6s[8] check data of Classroom\n","");
	printf("%6s[9] file'classroom manipulation\n","");
	printf("%6s====================================\n","");
}

int inputChoice(int a, int b){
	printf("input (from %d to %d): ",a,b);
	int n; scanf("%d",&n);
	return n;
};
// hien thi danh sach sinh vien V
void showListStudent(struct Student studentList[], int begin ,int numberOfStudent1){
	int i, n; // gia tri begin dung de show tu begin den numberOfStudent1 // (begin tai su dung cac yeu cau khong chi la show ca list student)
	n = numberOfStudent1;
	if(n != 0 ){
		// in thong tin sinh vien ra duoi dang bang V
		printf("|==========|=========================|==============================|===============|==========|\n");
		printf("|%4sID%4s|%10sNAME%11s|%13sEMAIL%12s|%5sPHONE%5s|NO. COURSE|\n"
				,"","","","","","","","");
		printf("|==========|=========================|==============================|===============|==========|\n");
		for(i = begin; i < n; i++){
			printf("|%-10s|%-25s|%-30s|%-15s|%-10s|\n",
					studentList[i].studentId,studentList[i].nameStudent,studentList[i].email,studentList[i].phoneNumberStudent,studentList[i].classroomId);
			printf("|==========|=========================|==============================|===============|==========|\n");
		}
	} else printf("chua co sinh vien nao!\n"); // neu sinh vien khong ton tai hien thong bao ra man hinh V
	resetCmd();
};
/*
yeu cau nhap lan luot thong tin cua sinh vien V
sau khi them thanh con in thong bao ra man hinh V
*/
/*
do dai thong tin nhap vao phai hop le V
id != gmail != phone  V
cac thong tin sinh vien khong duoc de trong V
du lieu nao khong hop le thi cho nhap lai ngay tuc thoi V
*/
void addNewStudent(struct Student *studentList2, int *numberOfStudent2, int check ){
	// check o day dung de tai su dung cho ham fixinforstudent!!!
	int i, checkc;
	printf("====ENTER INFORMATION OF STUDENT====\n");
	int n = *numberOfStudent2;
	//id

	if(check != 0){
		checkc=1;
		while(checkc){
			printf("id of student: |%30s",""); scanf("%s",studentList2[n].studentId);
			if(strlen(studentList2[n].studentId) > 10){
				checkc=1;
			}else {
				for( i = 0; i <= n; i++){
					if(i!=n && strcmp(studentList2[n].studentId, studentList2[i].studentId) == 0){
						checkc = 1;
						break;
					} else {
						checkc = 0;
					}
				}
			}
			// kiem tra 
			if(checkc == 1){
				printf("erron enter id!\n");
			}
		}
	}
		
	// id lop (khong duoc dai qua)
	checkc = 1;
	while(checkc){
		printf("classroomId of student: |%21s",""); scanf("%s",studentList2[n].classroomId);
		if( strlen(studentList2[n].classroomId) > 10){
			checkc = 1;
			printf("erron enter class'id!\n");
		}else checkc = 0;
	}
	
	// name (khong duoc dai qua)
	checkc = 1;
	while(checkc){
		printf("name of student: |%28s",""); fflush(stdin); gets(studentList2[n].nameStudent);
		if( strlen(studentList2[n].nameStudent) > 25){
			checkc = 1;
			printf("erron enter student'name!\n");
		}else checkc = 0;
	}
	//tuoi (khong duoc trong) V
	checkc = 1;
	while(checkc){
		printf("age of student (date month year) : |%10s",""); scanf("%d %d %d",&studentList2[n].dateStudent.day, &studentList2[n].dateStudent.month, &studentList2[n].dateStudent.year);
		if(studentList2[n].dateStudent.day > 31 || studentList2[n].dateStudent.day < 1 || studentList2[n].dateStudent.month > 12 || studentList2[n].dateStudent.month < 1 || studentList2[n].dateStudent.year < 1950 ||studentList2[n].dateStudent.year > 2025){       
			checkc = 1;
			printf("erron birthday!\n");
		}else {
			checkc = 0;
		}
	}
	// gioi tinh(khong duoc trong) V
	checkc = 1;
	while(checkc){
		printf("gender (/1:boy/0:girl/): |%20s",""); scanf("%d",&studentList2[n].intgender); // --> lay ra nam hoac nu 1:nam 0:nu
		if(studentList2[n].intgender == 1){
			strcpy(studentList2[n].gender, "boy");
		}else if(studentList2[n].intgender == 0){
			strcpy(studentList2[n].gender,"girl");
		}else{
			strcpy(studentList2[n].gender,"non");
		}
		if(strcmp(studentList2[n].gender,"non") == 0){
			printf("erron gender neutral!\n");
		}else {
			checkc = 0;
		}
	}
	//phone ko duoc trung va trong
	checkc = 1;
	while(checkc){
		printf("phonenumber of student: |%21s",""); scanf("%s",studentList2[n].phoneNumberStudent);
		if(strlen(studentList2[n].phoneNumberStudent) > 10){
			checkc = 1;
		}else {
			for(i = 0; i<= n; i++){
				if(i!=n && !strcmp(studentList2[i].phoneNumberStudent, studentList2[n].phoneNumberStudent)){
					checkc=1;
					
					break;
				}else{
					checkc=0;
				}
			}
		}
		if(checkc == 1){
			printf("erron enter phone!\n");
		}
		
	}
	//gmail ko duoc trung trong
	checkc = 1;
	while(checkc){
		printf("email of student: |%27s",""); scanf("%s",studentList2[n].email);
		if( strlen(studentList2[n].email) > 30 ){
			checkc = 1;
		}else {
			for(i = 0; i<= n; i++){
				if(i!=n && !strcmp(studentList2[i].email,studentList2[n].email)){
					checkc = 1;
					break;
				}else {
					checkc = 0;
				}
			}
		}
		if(checkc == 1){
			printf("erron enter email!\n");
		}
	}
	
	
	
	if(check != 0){
		*numberOfStudent2 += 1;
	}
	printf("======successfully entering information of student=====\n");
	resetCmd();	
};
/*
yeu cau nhap sinh vien muon sua V
neu id sinh vien khong ton tai thong bao ra man hinh V
neu id sv toon tai thi hien thi va nhap thong tin moi V
sau khi sua thong tin xong thi thong bao ra man hinh V
*/
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
/*
yeu cau nhap id sv muon xoa V
neu sinh vien khong ton tai hien thi thong bao ra man hinh V
neu id sv ton tai thi hien thi xac nhan xoa (dong y va khong) V
sau khi xoa sinh vien thanh con thi hien thi thong bao ra man hinh V
*/
void deleteStudent(struct Student *studentList4, int *numberOfStudent4){
	if(*numberOfStudent4 !=0){
		int check = 0;
		int i, j, n = *numberOfStudent4;
		char checkId[10]; printf("enter Id to check: "); scanf("%s",checkId);
		for(i = 0; i < n; i++){
			if(!strcmp(studentList4[i].studentId, checkId)){
				for( j = i ; j < n; j++){
					int checkk; 
					printf("|===delete student===|");
					printf("|%-20s|\n","[1] confirm");
					printf("|%-20s|\n","[2] not confirm");
					printf("|====================|\n");
					checkk = inputChoice(1,2);
					
					switch(checkk){
					case 1:
						*numberOfStudent4 = *numberOfStudent4 - 1;
						studentList4[j] = studentList4[j + 1]; 
						check = 1;
						printf("delete student success!\n");
						break;
					case 2:
						printf("you don't confirm that delete student\n");
						check = 1;
						break;
					
					}
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
/*
yeu cau chon thu tu sap xep danh sach thong qua menu con V
<sap xep theo do dai sinh vien hoac theo anfarb>
sau khi sap xep thanh cong thi in thong bao ra man hinh V
*/
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
/*
yeu cau nhap ten sinh vien V
neu khong tim thay hien ra thong bao ra man hinh V
neu tim thay thi hien thi danh sach sinh vien duoi dang bang V
*/

void searchStudent(struct Student *studentList5, int numberOfStudent5){
	int i, n = numberOfStudent5;
	int serial = 1; 
	if( n != 0){
		char name[25]; printf("enter name of student that you want searching: "); fflush(stdin); gets(name);
		for(i =0 ; i< n; i++){
			if(strcmp( studentList5[i].nameStudent, name) == 0){
				printf("student: %s\n", studentList5[i].nameStudent);
				printf("++===================================================++\n");
				printf("|| %-12s | %-35s||\n","ClassId",studentList5[i].classroomId);
				printf("|| %-12s | %-35s||\n","StudentId",studentList5[i].studentId);
				printf("|| %-12s | %2d/2%d/4%d%27s||\n","birthday",studentList5[i].dateStudent.day,studentList5[i].dateStudent.month,studentList5[i].dateStudent.year,"");
				printf("|| %-12s | %-35s||\n","Gender",studentList5[i].gender);
				printf("|| %-12s | %-35s||\n","phonenumber",studentList5[i].phoneNumberStudent);
				printf("|| %-12s | %-35s||\n","email",studentList5[i].email);
				printf("++===================================================++\n");
				serial+=1;
			}
		}
		if(serial == 1){
			printf("don't find here!\n");
		}
	} else printf("no student here!...\n");
};


/*
thao tac voi file
du lieu sinh vien duoc ghi vao file V
du lieu sinh vien lay tu file V
*/
void actionWithFile(struct Student *studentList8, int *numberOfStudent8){
			int i;
			int n = *numberOfStudent8;
			FILE *f1 = fopen("student.bin","wb");
			if(f1 == NULL){
				printf("[Erron] create file\n");
				return;
			}
			fwrite(&*numberOfStudent8, sizeof(int), 1, f1); // ghi vao so luong sinh vien truoc
			fwrite(studentList8, sizeof(struct Student), n, f1);
			fclose(f1);
			printf("Write to file success\n");
	resetCmd();
};
void readFile(struct Student *data, int *numberOfStudent9){
	int i;
	int n = 0;
	FILE *f = fopen("student.bin","rb");
	if(f == NULL){
		printf("erron creaete file\n");
		return;
	}
	fread(&n, sizeof(int), 1 ,f);
	fread(data, sizeof(struct Student), n, f);
	fclose(f);
	*numberOfStudent9 += n;
	printf("Read file successful!\n");
};

//======================================================================================//======================================================================================
// quan ly sinh vien
/*
hien thi danh sach sinh vien duoi dang bang V
canh chinh hang canh le ro rang V
moi lua chon se co 1 man hinh rieng V
trong man hinh cua moi lua chon se co lua chon de quay lai menu <reserCmd()> V
*/

void studentManagement(struct Student *students, int *numberOfStudent){
	readFile(students, &*numberOfStudent);
	int t2=1;
	while(t2){
		menuStudentManagement();
		int choice2 = inputChoice(0,8); // yeu cau nhap lua chon cho menu quan ly sinh vien V
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
			case 8:{
				system("cls");
				actionWithFile(students, &*numberOfStudent);
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
//======================================================================================//======================================================================================
void showListClassroom(struct Classroom *classroomList1, int numberOfClass1){
	classroomList1[0].numberOfStudent = 0;
	if(numberOfClass1 != 0){
		int i;
		printf("===Show List Classroom===+\n");
		printf("+==========+==============================+==============================+=====+===============+\n"); 
		printf("|%-10s|%-30s|%-30s|%-5s|%-15s|\n","classid","class name","majoy","size","status");
		for(i = 0; i < numberOfClass1; i++){
			printf("+==========+==============================+==============================+=====+===============+\n"); 
			printf("|%-10s|%-30s|%-30s|%-5d|%-15s|\n",classroomList1[i].classroomId,classroomList1[i].classroomName, classroomList1[i].majoy, classroomList1[i].numberOfStudent,classroomList1[i].status);
		}
		printf("+==========+==============================+==============================+=====+===============+\n"); 
	}else {
		printf("no Classroom here!\n");
	}
	resetCmd();
};

void addNewClassroom(struct Classroom *classroomList2, int *numberOfClass2){
	int choiceStatus;
	printf("=====Add New Classroom====\n");
	printf("%-30s","Enter classroom'id: |"); scanf("%s",classroomList2[*numberOfClass2].classroomId);
	printf("%-30s |","Enter Classroom'name:");  fflush(stdin); gets(classroomList2[*numberOfClass2].classroomName);
	printf("%-30s |","Enter classroom'majoy:"); gets(classroomList2[*numberOfClass2].majoy);
	classroomList2[*numberOfClass2].numberOfStudent = 0;
	printf("%-30s |","status(1-active/2-finished):"); scanf("%d",&choiceStatus);
	if(choiceStatus == 1){
		strcpy(classroomList2[*numberOfClass2].status, "active");
	}
	else if(choiceStatus == 2){
		strcpy(classroomList2[*numberOfClass2].status, "finished");
	}
	*numberOfClass2 +=1;
	resetCmd();
};

void fixInforClassroom(struct Classroom *classroomList3, int numberOfClass3){
	char idCheck[10]; int i; int check4 = 0;
	printf("%30s","Enter classroom'id you want fix: |"); scanf("%s",idCheck);
	for(i = 0; i < numberOfClass3; i++){
		if(!strcmp(idCheck, classroomList3[i].classroomId)){
			printf("==========Id here==========\n");
			printf("+==========+==============================+==============================+=====+===============+\n"); 
			printf("|%-10s|%-30s|%-30s|%-5s|%-15s|\n","classid","class name","majoy","size","status");
			printf("+==========+==============================+==============================+=====+===============+\n"); 
			printf("|%-10s|%-30s|%-30s|%-5d|%-15s|\n",classroomList3[i].classroomId,classroomList3[i].classroomName, classroomList3[i].majoy, classroomList3[i].numberOfStudent,classroomList3[i].status);
			printf("+==========+==============================+==============================+=====+===============+\n"); 
			int choiceStatus;
			printf("=============fix==============\n");
			printf("%-30s|","fix classroom'name:",""); fflush(stdin); gets(classroomList3[i].classroomName);
			printf("%-30s|","fix classroom'majoy:","");gets(classroomList3[i].majoy);
			printf("%-30s|","fix classroom'status(1-active/2-finished):",""); scanf("%d",&choiceStatus);
			if(choiceStatus == 1){
				strcpy(classroomList3[i].status,"active");
			}else if(choiceStatus == 2){
				strcpy(classroomList3[i].status,"finished");
			}
			check4 = 1;
		}
	}
	if(check4 == 0){
		printf("don't id here!\n"); // khong tim thay id 
	}else{
		printf("successfully fix that\n"); // sua thanh cong
	}
	resetCmd();
};

void deleteClassroom(struct Classroom *classroomList4, int *numberOfClass4){
	char idCheck[10];
	int i, j, check5 = 0 , n = *numberOfClass4;
	printf("Enter classroom id to delete: "); scanf("%s",idCheck);
	for(i = 0; i < n; i++){
		printf("hello");
		if(!strcmp(idCheck, classroomList4[i].classroomId)){
			printf("=========id here=========\n");
			int choiceYN;
			// xac thuc xoa hay la khong
			printf("do you want delete that? (1-yes/0-no):  |"); scanf("%d",&choiceYN);
			if(choiceYN == 0){
				// neu khong thi khong xoa (khong lam gi ca)
				check5 = 2;
				break;
			} else{
				for(j = i; j < n; j++){
					classroomList4[j] = classroomList4[j+1];
				}
				*numberOfClass4 = *numberOfClass4 - 1;
				check5 = 1;
				break;
			}
		}
	}
	if(check5 == 0){
		printf("==========don't id here!=========\n");
	}else if(check5 == 1){
		printf("======successfully delete classroom!======\n");
	}else if(check5 == 2){
		printf("======not delete classroom!======\n");
	}
};
void showFullInforClassroom(struct Classroom *classroomList5, int *numberOfclass5){
	char idCheck[10];
	printf("Enter classroom'id: "); scanf("%s",idCheck);
	
};

//======================================================================================//======================================================================================


// quan ly lop hoc
void classManagement(struct Classroom *classrooms, int *numberOfClass, int *numerOfStudent){
	int t3 = 1;
	while(t3){
		menuClassManagement();
		int choice5 = inputChoice(0,9);
		switch(choice5){
			case 1:{
				system("cls");
				showListClassroom(classrooms, *numberOfClass);
				break;
			}
			case 2:{
				system("cls");
				addNewClassroom(classrooms, &*numberOfClass);
				break;
			}
			case 3:{
				system("cls");
				fixInforClassroom(classrooms, *numberOfClass);
				break;
			}
			case 4:{
				system("cls");
				deleteClassroom(classrooms, &*numberOfClass);
				break;
			}
			case 5:{
				system("cls");
				break;
			}
			case 0:{
				system("cls");
				t3--;
				break;
			}
		}
	}
};

//======================================================================================//======================================================================================

void showListTeacher(struct Teacher *teachers1, int countTeacher1){
	int i , n = countTeacher1;
	if(countTeacher1 == 0){
		printf("no teacher here!\n");
	}else {
		printf("+==========+=========================+===========+==============================+\n");
		printf("|%-10s|%-25s|%-11s|%-30s|\n","id","name of teacher","phone","email");
		printf("+==========+=========================+===========+==============================+\n");
		for(i = 0; i< n; i++){
			printf("|%-10s|%-25s|%-11s|%-30s|\n",teachers1[i].teacherId,teachers1[i].teacherName,teachers1[i].phoneNumberTeacher,teachers1[i].email);
			printf("+==========+=========================+===========+==============================+\n");
		}
	}
	resetCmd();
};
void addNewTeacher(struct Teacher *teachers2, int *countTeacher2){
	int i = *countTeacher2;
	int gender;
	printf("=====Add New Teacher=====\n");
	printf("%-30s|","teacher'id:"); scanf("%s",teachers2[i].teacherId);
	printf("%-30s|","teacher'name:"); fflush(stdin); gets(teachers2[i].teacherName);
	printf("%-30s|","birthday:"); scanf("%d%d%d",&teachers2[i].dateTeacher.day,&teachers2[i].dateTeacher.month, &teachers2[i].dateTeacher.year);
	printf("%-30s|","gender (1-boy/2-girl):"); scanf("%d",&gender);
	if(gender == 1){
		strcpy(teachers2[i].gender,"boy");
	}else if(gender == 2){
		strcpy(teachers2[i].gender,"girl");
	}
	printf("%-30s|","teacher'phonenumber"); scanf("%s",teachers2[i].phoneNumberTeacher);
	printf("%-30s|","teacher'email"); scanf("%s",teachers2[i].email);
	printf("====successfully enter information of teacher====\n");
	*countTeacher2 +=1;
	resetCmd();
};

void fixInforTeacher(struct Teacher *teachers3, int countTeacher3){
	int gender;
	int i, n = countTeacher3;
	int check7 = 0;
	char idCheck[10]; printf("Enter id to check teacher: "); scanf("%s",idCheck);
	for(i = 0; i < n; i++){
		if(!strcmp(idCheck, teachers3[i].teacherId)){
			printf("teacher here!\n");
			printf("+==================================================+\n");
			printf("|teacher'id: %38s|\n",teachers3[i].teacherId);
			printf("|teacher'name: %36s|\n",teachers3[i].teacherName);
			printf("|teacher'birthdays: /%18s%3d/%3d/%4d|\n","",teachers3[i].dateTeacher.day,teachers3[i].dateTeacher.month,teachers3[i].dateTeacher.year);
			printf("|teacher'gender: %34s|\n",teachers3[i].gender);
			printf("|teacher'phonenumber: %29s|\n",teachers3[i].phoneNumberTeacher);
			printf("|teacher'email: %35s|\n",teachers3[i].email);
			printf("+==================================================+\n\n");
			printf("|enter teacher'id: %19s|",""); scanf("%s",teachers3[i].teacherId);
			printf("|enter teacher'name: %17s|",""); fflush(stdin); gets(teachers3[i].teacherName);
			printf("|enter teacher'birthdays:  %11s|",""); scanf("%d%d%d",&teachers3[i].dateTeacher.day,&teachers3[i].dateTeacher.month, &teachers3[i].dateTeacher.year);
			printf("|enter teacher'gender(1-boy/2-girl):  |");scanf("%d",&gender);
			if(gender==1){
				strcpy(teachers3[i].gender,"boy");
			}else if(gender==2){
				strcpy(teachers3[i].gender,"girl");
			}
			printf("|enter teacher'phonenumber: %10s|",""); scanf("%s",teachers3[i].phoneNumberTeacher);
			printf("|enter teacher'email: %16s|","");	scanf("%s",teachers3[i].email);
			printf("\n\n=====fix successfull=======\n");
			check7 = 1;
			break;
		}
	}
	if(check7 == 0){
		printf("no teacher'id here\n");
	}
	resetCmd();
};

//===================quan ly giao vien==============================
void teacherManagement(struct Teacher *teachers, int *countTeacher){
	int t5 = 1;
	while(t5){
		menuTeacher();
		int choice6 = inputChoice(0,9);
		switch(choice6){
			case 1:{
				system("cls");
				showListTeacher(teachers, *countTeacher);
				break;
			}
			case 2:{
				system("cls");
				addNewTeacher(teachers, &*countTeacher);
				break;
			}
			case 3:{
				system("cls");
				fixInforTeacher(teachers, *countTeacher);
				break;
			}
			case 0:{
				system("cls"); 
				t5--;
				break;
			} 
		}
	}
};

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
