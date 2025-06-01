#include <stdio.h>
#include <string.h>
#include "password.h" // includes the code from the password.h


// adds password in to password.txt file
void add_password(){
	passwordEntry entry;

	printf("Enter Service Name: ");
	fgets(entry.services, MAX_LEN, stdin);  // (where to store, size(where to store), stdin (or other input methods))
	entry.services[strcspn(entry.services, "\n")] = 0; // https://www.geeksforgeeks.org/strcspn-in-c/
	// strcspan = string complementry span...
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
		printf("\n[Saved Password Successfully]\n");
        	printf("Service: %s", entry.services);
       		printf("Username: %s", entry.username);
	        printf("Password: %s\n", entry.password);

	} else {
		perror("Error Opening file");
	}

}


// list all the passwords that are been saved in the password.txt file
void read_password() {
    FILE *file = fopen(FILE_NAME, "r");  // Open in read mode
    if (!file) {
        perror("Error opening file");
        return;
    }

    passwordEntry entry;

    printf("\n[Saved Credentials]\n");
    printf("-------------------------\n");

    // Keep reading sets of 3 strings (space-separated)
    while (fscanf(file, "%s %s %s", entry.services, entry.username, entry.password) == 3) {
        printf("Service:  %s\n", entry.services);
        printf("Username: %s\n", entry.username);
        printf("Password: %s\n", entry.password);
        printf("-------------------------\n");
    }

    fclose(file);
}

// function to update the existing password
void update_password(){
	FILE *file = fopen(FILE_NAME,"r"); // reading the password.txt file to edit it later
	FILE *temp = fopen("temp.txt", "w");

	if(!file || !temp){
		perror("Error opening either 'password.txt' or 'temp.txt'");
		return;
	}

	char target_service[MAX_LEN]; // variable to store the search parameter
	
	// taking input from the user for the search term
	printf("Enter the service name for which you want to update the password: ");
	fgets(target_service, MAX_LEN, stdin);

	//cleaning for \n using strcspn
	target_service[strcspn(target_service, "\n")] = 0;

	passwordEntry entry;
	int updated = 0; // update flag to signal the update status

	while(fscanf(file, "%s %s %s", entry.services, entry.username, entry.password) == 3){
		// using string compare to check if the search term and the service name from the filematch
		if(strcmp(entry.services,target_service ) == 0 ){  
			printf("Updating entry for: \n%s", entry.services);
			int flag = 0;
			printf("\nDo u want to change the UserName - '%s'\n(Yes=1, No=0) : ", entry.username);
			scanf("%d", &flag);
			// this line clean up for fgets to read chars from the input buffer...
			getchar();
			if(flag){
				printf("Enter New Username: ");
				fgets(entry.username, MAX_LEN, stdin);
				entry.username[(strcspn(entry.username, "\n"))]=0;
				flag = 0;
			}

			printf("\nDo u want to change the Password  - '%s'\n(Yes=1, No=0) : ", entry.password);
			scanf("%d", &flag);
			getchar();
			if(flag){
				printf("Enter the new password: \n");
				fgets(entry.password, MAX_LEN, stdin);
				entry.password[strcspn(entry.password, "\n")] = 0;
			}
			updated = 1;
			printf("Successfully Updated!!!\n");
		}		
		fprintf(temp,"%s   %s   %s\n", entry.services, entry.username, entry.password );

	}


	// cleaning up opened files
	fclose(file);
	fclose(temp);
	
	// we are mimicing the updation by wrinting into a new file and renaming it
	// so original file is remove.
	
	remove(FILE_NAME);

	// we are renaming the temp.txt to FILE_NAME
	rename("temp.txt", FILE_NAME);

	if(updated == 0) {
		printf("Did not find any matching service for the searched service - '%s'\n", target_service);
	}
}


// function to implement delete function that deletes the passwords from the password.txt
void delete_password(){
	FILE *file = fopen(FILE_NAME,"r" );
	FILE *temp = fopen("temp.txt", "w");

	// checking if the files are properly opened
	if(!file || !temp){
		perror("\nUnable to open password.txt or temp.txt\n");
		return;
	}

	// creating object and nessary variables
	passwordEntry entry;
	char target_service[MAX_LEN]; // use to store the search term
	int deleted = 0;
	
	printf("Enter the service name of which u want to delete: ");
	fgets(target_service, MAX_LEN, stdin);
	target_service[strcspn(target_service, "\n")] = 0;


	while(fscanf(file, "%s %s %s", entry.services, entry.username, entry.password)== 3){
		if(strcmp(target_service, entry.services) == 0) {
			deleted = 1;
			continue;
		}

		fprintf(temp, "%s   %s   %s\n", entry.services, entry.username, entry.password);
	}

	// file clean ups
	fclose(file);
	fclose(temp);

	// removeing the outdated file
	remove(FILE_NAME);
	// renameing the new temp file to FILE_NAME
	rename("temp.txt", FILE_NAME);

	if(deleted){
		printf("\nDeleted %s service successfully\n", target_service);
	} else {
		printf("\n%s named service Not Found!!\n", target_service);
	}
}
