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
	char classroomName[23];
	struct Student studentlist[];
};
