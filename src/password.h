#ifndef PASSWORD_H //used to prevent multiple includes
#define PASSWORD_H
#define MAX_LEN 50

// structure definition to hold the password info
typedef struct {
	char services[MAX_LEN];
	char username[MAX_LEN];
	char password[MAX_LEN];
} passwordEntry;


// function prototype to accept the passwords
void add_password(); // actual code for this is implemented in the included .c file

#endif

