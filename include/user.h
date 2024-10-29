#ifndef USER_H
#define USER_H

#define USER_MAX_USERNAME_LENGTH 20
#define USER_MAX_PASSWORD_LENGTH 20

#include <stdbool.h>

typedef struct User {
    char name[USER_MAX_USERNAME_LENGTH];

    char password[USER_MAX_PASSWORD_LENGTH];

    int id;

    bool admin;
} User;

#endif
