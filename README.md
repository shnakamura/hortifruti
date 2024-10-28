# HortiFruti Rodrigues

HortiFruti Rodrigues é uma aplicação de linha de comando que permite aos usuários gerenciar o inventário de café, vender café, acompanhar o saldo de vendas e realizar diversas outras operações. Este README fornece uma visão geral da aplicação e instruções para configurá-la e executá-la em sua máquina local.

## Features

- **Adicione um produto**: Adiciona um novo produto ao estoque, com valor e quantidade.
- **Venda de produto**: Vende uma produto do estoque, especificando pelo ID e quantidade e atualiza e acompanha o saldo de vendas.
- **Demonstrativo de Estoque**: Exibe o inventário atual, incluindo ID do café, nome, preço e quantidade.
- **Demonstrativo de Vendas**: Exibe o saldo total acumulado das vendas.
- **Remova um produto**: Remova um produto do inventário especificando seu ID. Atualiza o inventário de acordo.

## Pre Requerimentos

Para rodar o HortiFruti Rodrigues em sua maquina, você vai precisar instalar os seguites programas:
 
- C compiler (e.g., GCC)
- Standard C libraries

## Getting Started

1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/your-username/sadias-coffee-shop.git
   ```

2. Navigate to the project directory:

   ```bash
   cd sadias-coffee-shop
   ```

3. Compile the code using the C compiler:

   ```bash
   gcc -o coffee_shop main.c login.c menu.c splash.c features.c utils.c
   ```

4. Run the application:

   ```bash
   ./coffee_shop
   ```

## Usage

Upon running the application, you will be presented with a login panel. Use the following credentials to log in as an admin:

- Username: admin
- Password: admin

After successful login, the main menu will be displayed, offering various options for managing the coffee inventory and performing operations.

Choose an option by entering the corresponding number and following the prompts to add coffee, sell coffee, view inventory, check sales balance, or remove coffee from the inventory.

## Contributing

Contributions to Sadia's Coffee Shop are welcome! If you have any suggestions, improvements, or bug fixes, please submit a pull request. Before submitting a pull request, ensure that your code adheres to the existing code style and that all tests pass successfully.

## License

This project is licensed under the [MIT License](LICENSE). Feel free to modify and distribute it according to your needs.

## Acknowledgments

- The Sadia's Coffee Shop project was developed as a learning exercise and does not represent a real-world coffee shop application.
- The code structure and organization were inspired by best practices and modular design principles.

## Contact

If you have any questions or suggestions regarding Sadia's Coffee Shop, please feel free to contact me at [your-email@example.com](mailto:sadia.ahmed05@northsouth.edu).
