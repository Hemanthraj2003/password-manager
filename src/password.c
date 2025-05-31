#include <stdio.h>
#include "password.h" // includes the code from the password.h

void add_password(){
	passwordEntry entry;

	printf("Enter Service Name: ");
	fgets(entry.services, MAX_LEN, stdin);  // (where to store, size(where to store), stdin (or other input methods))


	printf("Enter username: ");
	fgets(entry.username, MAX_LEN, stdin);

	printf("Enter password: ");
	fgets(entry.password, MAX_LEN, stdin);



	// currently just printing the values
	printf("\n[Saved Password Successfully]\n");
	printf("Service: %s", entry.services);
	printf("Username: %s", entry.username);
	printf("Password: %s", entry.password);
}

