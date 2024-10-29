#ifndef LOGIN_H
#define LOGIN_H

/**
 * @def MAX_USERNAME_LENGTH
 * @brief A quantidade máxima de caracteres que o nome de usuário pode ter.
 */
#define MAX_USERNAME_LENGTH 20 

/**
 * @def MAX_PASSWORD_LENGTH
 * @brief A quantidade máxima de caracteres que a senha pode ter.
 */
#define MAX_PASSWORD_LENGTH 20

/**
 * @def MAX_PASSWORD_ATTEMPTS
 * @brief A quantidade máxima de vezes em que o usuário pode falhar ao tentar realizar um login no sistema.
 */
#define MAX_PASSWORD_ATTEMPTS 3

/**
 * @brief Tenta autenticar o usuário com as credenciais fornecidas.
 *
 * Solicita ao usuário as informações necessárias para realizar um login no sistema de gerenciamento
 * de produtos, sendo um nome de usuário e uma senha.
 * 
 * @param username O nome de usuário fornecido para autenticação.
 * @param password A senha fornecida para autenticação.
 * 
 * @return Retorna 1 se a autenticação for bem-sucedida; caso contrário, retorna um código de erro.
 */
int Login_AuthenticateUser(char* username, char* password);

/**
 * @brief Exibe o painel de login e tenta autenticar o usuário.
 *
 * Mostra a interface de login, onde o usuário pode inserir suas credenciais. Após a entrada, chama a 
 * função de autenticação para verificar o acesso.
 */
void LOGIN_ShowPanel();

#endif
