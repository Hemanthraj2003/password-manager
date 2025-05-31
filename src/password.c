#include <stdio.h>
#include <string.h>
#include "password.h" // includes the code from the password.h

void add_password(){
	passwordEntry entry;

	printf("Enter Service Name: ");
	fgets(entry.services, MAX_LEN, stdin);  // (where to store, size(where to store), stdin (or other input methods))
	entry.services[strcspn(entry.services, "\n")] = 0; // https://www.geeksforgeeks.org/strcspn-in-c/

	printf("Enter username: ");
	fgets(entry.username, MAX_LEN, stdin);
	entry.username[strcspn(entry.username, "\n")] = 0;

	printf("Enter password: ");
	fgets(entry.password, MAX_LEN, stdin);
	entry.password[strcspn(entry.password, "\n")] = 0;

	FILE *file = fopen(FILE_NAME, "a"); //docs on fopen: https://www.geeksforgeeks.org/c-fopen-function-with-examples/

	if(file){
		fprintf(file, "%s %s %s\n",entry.services, entry.username, entry.password);
		fclose(file);
		printf("Saved\n");
	} else {
		perror("Error Opening file");
	}

	// currently just printing the values
	printf("\n[Saved Password Successfully]\n");
	printf("Service: %s", entry.services);
	printf("Username: %s", entry.username);
	printf("Password: %s", entry.password);
}

