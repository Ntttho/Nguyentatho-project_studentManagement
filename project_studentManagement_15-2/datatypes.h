#include<stdio.h>
struct Date{
	int day;
	int month;
	int year;
};

struct Student{
	char studentId[10];
	char classroomId[10]; // mac dinh la null
	char nameStudent[25];
	struct Date dateStudent;
	int intgender; // 1 nam 0 nu
	char gender[5];
	char phoneNumberStudent[11];
	char email[30];
};

struct Classroom{
	char classroomId[10];
	char classroomName[30];
	char majoy[30];
	int  numberOfStudent;
	char status[15]; // dang hoc, da ket thuc
	struct Student studentlist[];
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

