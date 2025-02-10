#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funtion.h"
#define max 1000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int countStudent = 1; 
	struct Student studentList[max];
	int t=1;
	while(t){
		int choice1 = inputChoice(0,9);
		switch(choice1){
			case 1:{
				studentManagement( studentList, &countStudent);
				break;
			}
			case 2:{
				printf("%d",countStudent);
				break;
			}
			case 3:{
				break;
			}
			case 0:{
				t--;
				break;
			}
		}
	}
	return 0;
}
