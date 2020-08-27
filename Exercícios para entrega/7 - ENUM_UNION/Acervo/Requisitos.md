Suponha que você trabalha na biblioteca de uma universidade e é responsável pelo cadastro do acervo bibliográfico. Existem três tipos de obras que devem ser catalogadas:

livros;
teses;
periódicos.
(1) Os livros catalogados devem conter as seguintes informações: autor :literal[30], título:literal[30], ano:inteiro (yyyy), editora:literal[30] e cidade:literal[30].

(2) Já as teses precisam ser indexadas pelas seguintes informações: título:literal[30], autor:literal[30], mês:inteiro (mm), ano:inteiro (yyyy), universidade:literal[30], programa de pós-graduação:literal[30], modalidade:enum e orientador:literal[30]. A modalidade pode ser mestrado (valor: 1) ou doutorado (valor: 2).

(3) Os periódicos devem conter as informações a seguir: título:literal[30], volume:inteiro, mês:inteiro (mm), ano:inteiro (yyyy), editora:literal[30], cidade:literal[30] e número de páginas:inteiro.

Faça um programa para realizar o cadastramento e consulta das fichas catalográficas, considerando a categoria a qual uma obra pertence. Para o cadastro do acervo haverá um único array de struct (de tamanho máximo [5]) que conterá o tipo da obra e suas respectivas informações.

Menu de opções
Cadastrar um dos três tipos de obras
Consultar um dos três tipos de obras
Finalizar o programa
Atenção: Não printe o menu de opções em seu programa!

Você deve utilizar enumerações, structs e uniões para implementar o programa. Implemente as interfaces adequadas para ler os dados e guardar as informações corretamente. O programa deve ser implementado modularmente, usando funções com passagens de parâmetros.

Informações Importantes
Para a opção 1

Caso o usuário tente cadastrar mais de 5 obras, printe a seguinte mensagem de erro e volte ao menu principal:

printf("Limite de cadastros excedido!\n");
Caso contrário, receba do usuário a opção que ele deseja cadastrar

Cadastrar Livro
Cadastrar Tese
Cadastrar Periódico
Atenção: Não printe este submenu em seu programa!

Após isso, receba do usuário cada informação respectiva da obra escolhida. As informações devem ser recebidas na ordem em que foram apresentadas.

Por fim, printe uma das mensagens respectiva à obra escolhida pelo usuário e volte ao menu principal:

printf("-----Livro Cadastrado!-----\n");
printf("-----Tese Cadastrada!-----\n");
printf("-----Periodico Cadastrado!-----\n");
Para a opção 2 Receba do usuário a opção que ele deseja consultar

Consultar Livro
Consultar Tese
Consultar Periódico
Atenção: Não printe este submenu em seu programa!

Consulte todos os livros de um determinado tipo de obra com as informações na ordem em que foram apresentadas e volte ao menu principal:

Para a consulta de livros:

printf("Autor: %s\n", autor);
printf("Titulo: %s\n", titulo);
printf("Ano: %d\n", ano);
printf("Editora: %s\n", editora);
printf("Cidade: %s\n", cidade);
printf("-----------------\n");;
Para a consulta de Teses

printf("Autor: %s\n", autor);
printf("Titulo: %s\n", titulo);
printf("Mes: %d\n", mes);
printf("Ano: %d\n", ano);
printf("Universidade: %s\n", universidade);
printf("Programa: %s\n", programa);
printf("Orientador: %s\n", orientador);
printf("Graduacao: %d\n", tipo);
printf("-----------------\n");
Para a consulta de Periódicos:

printf("Titulo: %s\n", titulo);
printf("Volume: %d\n", volume);
printf("Mes: %d\n", mes);
printf("Ano: %d\n", ano);
printf("Editora: %s\n", editora);
printf("Cidade: %s\n", cidade);
printf("Numero de paginas: %d\n", num_pag);
printf("-----------------\n");
Para a opção 3 Mostre a seguinte mensagem e finalize o programa:

printf("Fim de execucao\n");
Informações Adicionais
Para a leitura de entradas do tipo string use:

scanf(" %[^\n]", /* VARIÁVEL */);
Outros dados leia sempre com um espaço antes do %

Não use fflush, setbuf, ou outros métodos de limpar o buffer.