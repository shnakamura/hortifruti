#ifndef USER_H
#define USER_H

#define USER_MAX_USERNAME_LENGTH 20
#define USER_MAX_PASSWORD_LENGTH 20

typedef struct User {
    char name[USER_MAX_USERNAME_LENGTH];

    char password[USER_MAX_PASSWORD_LENGTH];

    int id;

    int admin;
} User;

#endif
