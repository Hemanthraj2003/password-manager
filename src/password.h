#ifndef PASSWORD_H //used to prevent multiple includes
#define PASSWORD_H
#define MAX_LEN 50
#define FILE_NAME "password.txt"

// structure definition to hold the password info
typedef struct {
	char services[MAX_LEN];
	char username[MAX_LEN];
	char password[MAX_LEN];
} passwordEntry;


// function prototype to accept / read / update and delete  the passwords (CRUD)
void add_password(); 
void read_password();
void update_password();
void delete_password();
// actual code for this is implemented in the included .c file


#endif

