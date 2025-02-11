#include "datatypes.h"
void resetCmd();


void startProgram();
void menuStudent();

int inputchoice(int a, int b);
void studentManagement(struct Student *students, int *numberOfStudent);
void showListStudent(struct Student studentList1[], int begin ,int numberOfStudent1);
void addNewSudent(struct Student *studentList2, int *numberOfStudent2, int check);
void fixInforStudent(struct Student *studentList3, int numberOfStudent3);
void deleteStudent(struct Student *studentList4, int *numberOfStudent4);
void searchStudent(struct Student *studentList5, int numberOfStudent5);
void sortStudent1(struct Student *studentList6, int numberOfStudent6);
void sortStudent2(struct Student *studentList6, int numberOfStudent6); 
