Uma pizzaria será informatizada e surgiu a necessidade de um controle eficaz do sistema de entrega em domicilio. Dessa maneira, serão utilizadas as informações a seguir:

Endereço (rua, número, bairro)
Pessoa (telefone, nome, endereço [tipo 1])
Cliente (pessoa [tipo 2])
Motoqueiro (pessoa [tipo 2], cod)
Pizza (cod_pizza, nome, preco)
Pedido (codpedido, telefonecliente, codpizza, codmotoqueiro, situação)
OBS 1: telefone, telefone_cliente = String de tamanho máximo 15

OBS 2: codpedido, codpizza, cod_motoqueiro, situação, número = Tipo INT

OBS 3: nome, rua, bairro = String de tamanho máximo 50

OBS 4: preco = Tipo FLOAT

Para simplificar, será considerado que:
Podem existir até 5 clientes cadastrados;
Podem existir até 3 pizzas cadastradas;
Podem existir até 6 pedidos;
Podem existir até 2 motoqueiros
O cliente é identificado pelo número de telefone;
O campo situação do pedido refere-se as fases pelas quais o pedido passa até chegar a residência do cliente (1: em preparo, 2: a caminho, 3: entregue).
Faça um programa que:
Contenha uma função que realize o cadastro dos clientes. Não pode haver mais que um cliente com o mesmo telefone;
Contenha uma função que realize o cadastro dos motoqueiros. Não pode haver mais que um motoqueiro com o mesmo código;
Contenha uma função que realize o cadastro das pizzas. Não pode haver mais que uma pizza com o mesmo código;
Contenha uma função que realize o cadastro dos pedidos, supondo-se que o cliente e a pizza envolvidos no pedido já tenham sido cadastrados. Quando o pedido é cadastrado, o campo situação recebe o valor 1 e o campo código do motoqueiro o valor 0; O código do pedido é gerado incrementalmente a partir de 0.
Contenha uma função que realize o despacho da pizza, definindo o campo situação para 2 e atribuindo o código do motoqueiro, supondo-se que o motoqueiro envolvido no pedido já tenha sido cadastrado;
Contenha uma função que faça o recebimento da pizza, alterando o campo situação para 3;
Contenha uma função que liste os pedidos por situação. O usuário informa a situação que tem interesse em pesquisar. A lista deve ser printada em ordem de código do pedido;
Contenha uma função que liste os pedidos de um cliente. O usuário informa o telefone do cliente que tem interesse em pesquisar;
Contenha uma função que liste os pedidos de um motoqueiro. O usuário informa o código do motoqueiro que tem interesse em pesquisar;
Informações importantes para o funcionamento:
O Fluxo dos dados podem ser expressos graficamente da seguinte maneira: https://drive.google.com/file/d/17tUxWeu6QBEdNp-skDWFFkFPBA1Lxyw8/view?usp=sharing

Menu de opções:
O Fluxo de funcionamento do programa será dado através dos comandos desse menu:

Cadastra Cliente
Cadastra Motoqueiro
Cadastra Pizza
Cadastra Pedido
Despacha Pizza
Recebe Pizza
Pedidos por Situação
Pedidos por Cliente
Motoqueiros Entregas
Sair
OBS: O menu não deve ser printado, sendo como base apenas para os comandos do fluxo do sistema.

Controle de fluxo:
Para ter o controle dos dados que estão sendo armazenados e do fluxo de informações digitadas, deve-se printar as mensagens autoexplicativas para os seguintes fluxos quando necessário:

1. Cadastra Cliente:
printf("Cliente ja cadastrado\n");
printf("Cliente cadastrado com sucesso\n");
printf("Numero maximo de clientes cadastrados\n");
2. Cadastra Motoqueiro
printf("Motoqueiro ja cadastrado\n");
printf("Motoqueiro cadastrado com sucesso\n");
printf("Numero maximo de motoqueiros cadastrados\n");
3. Cadastra Pizza
printf("Pizza ja cadastrada\n");
printf("Pizza cadastrada com sucesso\n");
printf("Numero maximo de pizzas cadastrados\n");
4. Cadastra Pedido
printf("Pedido cadastrado\n");
printf("Numero maximo de pedidos realizados\n");
Dentro deste menu terá a leitura do telefone e código da pizza, desta forma, caso não haja ou código da pizza ou telefone do cliente cadastrado deve-se apresentar as mensagens de erros desta maneira:

printf("Cliente nao encontrado\n");
printf("Pizza nao cadastrada\n");
5. Despacha Pizza
printf("Pedido nao encontrado\n");
printf("Despachando pedido\n");
printf("Pedido ja despachado\n");
printf("Pedido ja entregue\n");
Dentro deste menu terá a leitura do código do motoqueiro, desta forma, caso o código não esteja cadastrado deve-se apresentar as mensagens de erros desta maneira:

printf("Motoqueiro nao encontrado\n");
6. Recebe Pizza
printf("Pedido entregue\n");
printf("Pedido nao encontrado\n");
printf("Entrega ja realizada\n");
7. Pedidos por Situação
Código da situação inválida:

printf("Opcao invalida\n");
Situação vazia:

printf("Sem itens nessa situacao\n");
Os pedidos devem ser printados da seguinte maneira:

printf("Pedido: %d\n", /*Código do pedido*/);
printf("Cliente: %s\n", /*Telefone do cliente*/);
printf("Pizza: %d\n", /*Código da pizza*/);
printf("Motoq: %d\n", /*Código do motorista*/);
OBS: Trocar os campos entre os /* e */pelo seu código que gere o que está entre eles

8. Pedidos por Cliente
Telefone do cliente inválido:

printf("Cliente nao encontrado\n");
Cliente sem pedido:

printf("Cliente sem pedidos\n");
Os pedidos devem ser printados da seguinte maneira:

printf("Pedido: %d\n", /*Código do pedido*/);
printf("Situacao: %d\n", /*Código da situação*/);
printf("Pizza: %d\n", /*Código da pizza*/);
printf("Motoq: %d\n", /*Código do motorista*/);
OBS: Trocar os campos entre os /* e */ pelo seu código que gere o que está entre eles

9. Motoqueiros Entregas
Código do motoqueiro inválido:

printf("Motoqueiro nao encontrado\n");
Motoqueiro sem pedido:

printf("Motoqueiro sem pedidos\n");
printf("Pedido: %d\n", /*Código do pedido*/);
printf("Situacao: %d\n", /*Código da situação*/);
OBS: Trocar os campos entre os /* e */ pelo seu código que gere o que está entre eles

0. Sair
printf("Encerrando sistema");
Mensagens do menu de opções:
printf("Opcao invalida\n");
Dicas importantes:
Scanfs de string devem serem feitos da seguinte maneira:
scanf(" %[^\n]", /*VARIAVEL*/);
Scanfs de char ou int devem serem feitos das seguintes maneiras:
scanf(" %d", /*VARIAVEL*/);
scanf(" %c", /*VARIAVEL*/);
TODAS as mensagens de erro devem ser dadas assim que forem identificadas e deve-se voltar ao menu de opções. Ex: Telefone Digitada já existe, portanto, a mensagem referente ao erro é printada e volta-se ao menu de opções, sem digitar o nome, rua, etc.

Deve-se printar apenas as mensagens especificadas acima (erros, cadastros ou os prints nos modelos necessários)

Erros diversos como string sendo inseridos em int ou char, não devem ser considerados.