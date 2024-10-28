#ifndef LOGIN_H
#define LOGIN_H

/**
 * Tenta autenticar o usuário.
 */
int LOGIN_AuthenticateUser(char* username, char* password);

/**
 * Exibe o painel de login e tenta autenticar o usuário.
 */
void LOGIN_ShowPanel();

#endif
