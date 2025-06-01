// this is the entry point of the project
// [>_]
#include <stdio.h>
#include "password.h"

int main(){
	printf("Simple Password Manager \n");
	int choice;
	while(1) {
		printf("\n1. Add Password \n2. List Passwords \n3. Update Passwords \n4. Delete Passwords \n5. Exit\nChoice: ");
		scanf("%d", &choice);
		getchar();

		switch(choice) {
			case 1: add_password();break;
			case 2: read_password();break;
			case 3: update_password();break;
			case 4: delete_password();break;
			case 5: return 0;
			default: printf("Invalid Choice\n");
		}
	}
}
