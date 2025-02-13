#include "datatypes.h"
void resetCmd();


void startProgram();
void menuStudent();

int inputchoice(int a, int b);
// ======================quan ly sinh vien==========================
void studentManagement(struct Student *students, int *numberOfStudent); // goc
void showListStudent(struct Student studentList1[], int begin ,int numberOfStudent1); // show danh sach sinh vien
void addNewSudent(struct Student *studentList2, int *numberOfStudent2, int check); // them moi sinh vien
void fixInforStudent(struct Student *studentList3, int numberOfStudent3); // chiinh ssua thong tin sinh vien thong qua id
void deleteStudent(struct Student *studentList4, int *numberOfStudent4); // xoa sinh vien 
void searchStudent(struct Student *studentList5, int numberOfStudent5); // tim kiem va in thong tin theo ten cua sinh vien
void sortStudent1(struct Student *studentList6, int numberOfStudent6); // sap xep sinh vien theo ten loai1 : an-far-b
void sortStudent2(struct Student *studentList6, int numberOfStudent6);// sap xep sinh vien theo ten loai 2 : do dai ten
void checkDataStudent(struct Student *studentList7, int numberOfStudent7);//  kiem tra du lieu cua sinh vien
void actionWithFile(struct Student *studentList8, int numberOfStudent8); // ghi va doc file 
// ==========================quan ly sinh vien========================

// ==========================quan ly lop hoc==========================
void menuClassManagement();
void classManagement(struct Classroom *classrooms, int *numberOfClass,int *numberOfStudent);
void showListClassroom(struct Classroom *classroomList1 ,int numberOfClass1);
void addNewClassroom(struct Classroom *classroomList2, int *numberOfClass2);
void fixInforClassroom(struct Classroom *classroomList3, int numberOfClass3);
void deleteClassroom(struct Classroom *classroomList4, int *numberOfClass4);
// ===========================quan ly lop hoc=========================






