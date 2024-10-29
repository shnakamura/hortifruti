#ifndef MAIN_H
#define MAIN_H

/**
 * @brief Função principal do programa.
 *
 * Ponto de entrada do programa, responsável por gerenciar o fluxo de execução até o encerramento do mesmo.
 * 
 * @return Retorna 0 se o programa encerrar com sucesso; caso contrário, retorna um código de erro.
 */
int main(void);

/**
 * @brief Inicializa a execução do programa e configura os recursos necessários.
 *
 * Realiza as operações iniciais necessárias para o funcionamento do programa, incluindo a alocação de 
 * recursos e a leitura de dados.
 */
void MAIN_Initialize();

/**
 * @brief Finaliza a execução do programa e desativa os recursos necessários.
 *
 * Realiza as operações necessárias para encerrar o programa de forma segura, sendo a liberação de recursos 
 * alocados e a gravação de dados.
 */
void MAIN_Exit();

#endif
