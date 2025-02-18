#include<stdio.h>
#define max 100
struct Date{
	int day;
	int month;
	int year;
};

struct Student{
	char studentId[10];
	int numberOfClassroom;
	char nameStudent[25];
	struct Date dateStudent;
	int intgender; // 1 nam 0 nu
	char gender[5];
	char phoneNumberStudent[11];
	char email[30];
};

struct Classroom{
	char classroomId[10]; // id lop
	char classroomName[30]; // ten lop
	char majoy[30]; // nganh hoc
	int  numberOfStudent; // so luong sv ton tai trong lop do
	char status[15]; // dang hoc, da ket thuc
	struct Student studentlist[100]; // cac mang sinh vien
};

struct Teacher{
	char teacherId[10];
	char teacherName[25];
	struct Date dateTeacher;
	char gender[5];
	char phoneNumberTeacher[11];
	char email[30];
	struct Classroom *classrooms;
};

