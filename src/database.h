#ifndef DATABASE_H
#define DATABASE_H

#define DATABASE_FILE_PATH "users.bin"

#include "user.h"

#include <stdio.h>
#include <stdbool.h>

void DATABASE_CreateFile();

void DATABASE_WriteUser(char username[USER_MAX_USERNAME_LENGTH], char password[USER_MAX_PASSWORD_LENGTH], bool admin);

void DATABASE_RemoveUser(int id);

#endif