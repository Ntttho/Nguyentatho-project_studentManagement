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
	printf("[7] check inputdata to student\n"); // if n == 0		X // kiem tra du lieu sinh vien
	printf("[8] file'student manipulation \n");//			X // luu thong tin sinh vien vao file bin
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
void addNewStudent(struct Student *studentList2, int *numberOfStudent2, int check ){
	// check o day dung de tai su dung cho ham fixinforstudent!!!
	printf("====ENTER INFORMATION OF STUDENT====\n");
	int n = *numberOfStudent2;
	if(check != 0){
		printf("id of student: |%30s",""); scanf("%s",studentList2[n].studentId);
	}
	printf("classroomId of student: |%21s",""); scanf("%s",studentList2[n].classroomId);
	printf("name of student: |%28s",""); fflush(stdin); gets(studentList2[n].nameStudent);
	printf("age of student (date month year) : |%10s",""); scanf("%d %d %d",&studentList2[n].dateStudent.day, &studentList2[n].dateStudent.month, &studentList2[n].dateStudent.year);
	printf("gender (/1:boy/0:girl/): |%20s",""); scanf("%d",&studentList2[n].intgender); // --> lay ra nam hoac nu 1:nam 0:nu
	if(studentList2[n].intgender == 1){
		strcpy(studentList2[n].gender, "boy");
	}else if(studentList2[n].intgender == 0){
		strcpy(studentList2[n].gender,"girl");
	}else{
		strcpy(studentList2[n].gender,"non");		
	}
	printf("phonenumber of student: |%21s",""); scanf("%s",studentList2[n].phoneNumberStudent);
	printf("email of student: |%27s",""); scanf("%s",studentList2[n].email);
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
do dai thong tin nhap vao phai hop le V
id != gmail != phone  V
cac thong tin sinh vien khong duoc de trong V
du lieu nao khong hop le thi cho nhap lai ngay tuc thoi V
*/
void checkDataStudent(struct Student *studentList7, int numberOfStudent7){
	int i, n = numberOfStudent7;
	int check1 = 1;// cac bien check kiem tra du lieu co hop le khong
	for(i = 0; i < n; i++){ //kiem tra du lieu tung sinh vien
		printf("check student: |%s|\n",studentList7[i].nameStudent);
		// kiem tra do dai cua id sinh vien
		while(strlen(studentList7[i].studentId) > 10 || strlen(studentList7[i].studentId) == 0){
			printf("[erron] id of |%2s| > 10 charater!\n");
			printf("re-enter id that:"); scanf("%s",studentList7[i].studentId);
		}
		// kiem tra do dai cua ten sinh vien
		int check2 = 1;
		while(check2){
			if(strlen(studentList7[i].nameStudent) > 25 || strlen(studentList7[i].nameStudent) == 0){ // do dai = 0 hoac >25 thi se loi Erron
				printf("[Erron] lenght student's name!\n");
				printf("Re-enter student'name: "); fflush(stdin); gets(studentList7[i].nameStudent);
			}else{
				check2--;
			}
		}
		//kiem tra ngay sinh sinh vien
		int check3 = 1;
		while(check3){
			int check3_1 = 0, check3_2 = 0;
			if(studentList7[i].dateStudent.day <= 0 || studentList7[i].dateStudent.day > 31){
				printf("[Erron] day!\n");
				printf("Re-enter day of birth: "); scanf("%d", &studentList7[i].dateStudent.day);
			}
			if(studentList7[i].dateStudent.month <= 0 || studentList7[i].dateStudent.month > 12){
				printf("[Erron] month!\n");
				printf("Re-enter month of birth: "); scanf("%d",&studentList7[i].dateStudent.month);
			}
			if(studentList7[i].dateStudent.year < 1900 || studentList7[i].dateStudent.year > 2025){
				printf("[Erron year!\n]");
				printf("Re-enter year of birth: "); scanf("%d",&studentList7[i].dateStudent.year);
			}
			if(!(studentList7[i].dateStudent.day <= 0 || studentList7[i].dateStudent.day > 31 || studentList7[i].dateStudent.month <= 0 || studentList7[i].dateStudent.month > 12 ||studentList7[i].dateStudent.year < 1900 || studentList7[i].dateStudent.year > 2025)){
				check3--;
			}
		}
		// kiem tra gioi tinh cua sinh vien
		while(studentList7[i].gender == "non" || studentList7[i].gender == 0){ // 
			printf("[Erron] gender of student!\n");
			printf("Re-enter that (1-boy/0-girl): "); scanf("%d",&studentList7[i].intgender);
			if(studentList7[i].intgender == 1){
				strcpy(studentList7[i].gender,"boy");
			}else if(studentList7[i].intgender){
				strcpy(studentList7[n].gender,"girl");
			} else {
				strcpy(studentList7[n].gender,"non");
			}
		}
		// kiem tra id mail phonenumber co trung nhau hay bo trong hay khong!/// va sua lai
		int check1 = 1;
		while(check1){
			if( !strcmp(studentList7[i].studentId, studentList7[i].phoneNumberStudent) || !strcmp(studentList7[i].studentId, studentList7[i].email) || !strcmp(studentList7[i].email, studentList7[i].phoneNumberStudent)){
				printf("[Erron] duplicate!\n");
				printf("+=============+==========+\n");
				printf("|Id of student|%-10s|\n",studentList7[i].studentId);
				printf("+=============+==========+\n");
				printf("Re-enter email of student: "); scanf("%s",studentList7[i].email);
				printf("Re-enter phonenumber of student: "); scanf("%s",studentList7[i].phoneNumberStudent);
			}
			if(studentList7[i].email == 0 || studentList7[i].phoneNumberStudent == 0 ){
				printf("[Erron] unoccupile\n ");
			}else {
				check1--;
			}
		}
		// kiem tra classroom id co bo trong hay khong
		while(strlen(studentList7[i].classroomId) > 10 || strlen(studentList7[i].classroomId) == 0){
			printf("[Erron] unoccupile!\n");
			printf("Re-enter classroom'id: "); scanf("%s",studentList7[i].classroomId);
		}
		i++;
	}
	resetCmd();
};
/*
thao tac voi file
du lieu sinh vien duoc ghi vao file V
du lieu sinh vien lay tu file V
*/
void actionWithFile(struct Student *studentList8, int numberOfStudent8){
	printf("========action with file binary========\n");
	printf("[1] save infor to file binary\n");
	printf("[2] take infor from file binary\n");
	printf("========================================\n");
	int choice4 = inputChoice(1,2);
	switch(choice4){
		case 1:{
			int i;
			int n = numberOfStudent8;
			FILE *f1 = fopen("student.bin","wb");
			if(f1 == NULL){
				printf("[Erron] create file\n");
				break;
			}
			fwrite(&n, sizeof(int), 1, f1); // ghi vao so luong sinh vien truoc
			fwrite(studentList8, sizeof(struct Student), n, f1);
			fclose(f1);
			printf("Write to file success\n");
			break;
		}
		case 2:{
			int i;
			int n = numberOfStudent8;
			FILE *f2 = fopen("student.bin","rb");
			if(f2 == NULL){
				printf("[Erron] create file\n");
				break;
			}
			fread(&n, sizeof(int), 1, f2); // doc so luong sinh vien truoc
			fread(studentList8, sizeof(struct Student), n, f2); // doc tat ca cac sinh vien
			printf("\n\n student: %s\n", studentList8[0].gender);
			fclose(f2);
			printf("Read from file success\n");
			break;
			break;
		}
	}
	
	
	
	resetCmd();
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
				checkDataStudent(students, *numberOfStudent);
				break;
			}
			case 8:{
				system("cls");
				actionWithFile(students, *numberOfStudent);
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
		if(strcmp(idCheck, classroomList3[i].classroomId)){
			printf("==========Id here==========\n");
			printf("+==========+==============================+==============================+=====+===============+\n"); 
			printf("|%-10s|%-30s|%-30s|%-5s|%-15s|\n","classid","class name","majoy","size","status");
			printf("+==========+==============================+==============================+=====+===============+\n"); 
			printf("|%-10s|%-30s|%-30s|%-5d|%-15s|\n",classroomList3[i].classroomId,classroomList3[i].classroomName, classroomList3[i].majoy, classroomList3[i].numberOfStudent,classroomList3[i].status);
			printf("+==========+==============================+==============================+=====+===============+\n"); 
			int choiceStatus;
			printf("=============fix==============\n");
			printf("%-30s|","fix classroom'name:"); fflush(stdin); gets(classroomList3[i].classroomName);
			printf("%-30s|","fix classroom'majoy:");gets(classroomList3[i].majoy);
			printf("%-30s|","fix classroom'status(1-active/2-finished):"); scanf("%d",&choiceStatus);
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


 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
