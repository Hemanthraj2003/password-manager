# this file is used to create build file, this is also called a recipe file

# variable
CC = gcc
CFLAG = -Wall -Wextra -g
SRC = src/main.c src/password.c
OUT = password-manager


# build logic here
# the below code is a rule header
# if out is outdated the indented command is exceuted
$(OUT): $(SRC)
	$(CC) $(CFLAG) $(SRC) -o $(OUT)


#clean rule
clean:
	rm -f $(OUT)
