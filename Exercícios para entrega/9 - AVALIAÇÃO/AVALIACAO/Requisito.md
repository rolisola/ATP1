Uma revista de gastronomia irá realizar a avaliação de estabelecimentos em uma dada cidade. Ela está contratando você para desenvolver seu sistema de avaliação e análise. Segue abaixo as especificações que você deve seguir para desenvolver o sistema solicitado.

Inicialmente, é necessário entender as entidades envolvidas no processo, as quais são descritas abaixo.
Estabelecimento: um estabelecimento é identificado por nome, localização e contato (todos strings, sem formatos específicos, cada qual com 50 caracteres).
Restaurante: um restaurante é um estabelecimento que tem como características o tipo de comida (brasileira, italiana, francesa, mexicana, outros) (fazer validação [1-5]) e o tipo de serviço (à la carte, self-service) (fazer validação [1-2]).
Fast-Food: um fast-food é um estabelecimento que tem como características o tipo de comida (pizzaria, sanduicheria, temakeria, cafeteria, creperia, diversos [1-6]) (fazer validação) e se faz entrega a domicilio (sim [s]/não [n]).
Buteco: um buteco é um estabelecimento sem características adicionais.
Avaliação: uma avaliação é composta por um estabelecimento, tipo de estabelecimento (restaurante, fast-food, buteco) (fazer validação [1-3]), sendo o mesmo classificado por número de estrelas (1, 2, 3, 4, 5) (fazer validação [1-5]). Para facilitar, supõe-se que é possível cadastrar no máximo 10 avaliações (fazer validação).
A fim de agilizar as buscas/contagens (vide funcionalidades), existirão duas matrizes que atuarão como índices, como abaixo descrito:
Uma matriz que armazenará, para cada tipo de estabelecimento (restaurante, fast-food e buteco), as posições que os mesmos se encontram no vetor de avaliações. Assim, existe uma matriz 3X11 que armazena para cada tipo de estabelecimento (linhas), as posições que os mesmos ocupam no referido vetor de avaliações (colunas). A primeiro coluna (coluna=0) armazena a quantidade de elementos cadastrados em um dado tipo de estabelecimento (em outras palavras, quantas colunas de uma dada linha foram preenchidas). As 10 restantes os códigos das posições onde se encontram um dado tipo de estabelecimento no vetor de avaliações.
Uma matriz que armazenará, para cada uma das possíveis estrelas (1, 2, 3, 4, 5), as posições dos estabelecimentos cadastrados que apresentam uma dada classificação no vetor de avaliações. Assim, existe uma matriz 5X11 que armazena para cada uma das possíveis estrelas (linhas), as posições, no referido vetor de avaliações, dos estabelecimentos que receberam uma determinada classificação (colunas). A primeiro coluna (coluna=0) armazena a quantidade de estabelecimentos cadastrados em um dada estrela (em outras palavras, quantas colunas de uma dada linha foram preenchidas). As 10 restantes os códigos das posições onde se encontram os estabelecimentos avaliados com a respectiva estrela no vetor de avaliações.
O seu sistema disponibiliza as seguintes funcionalidades:
Cadastra avaliação (opção 1): cadastra uma avaliação. Para tanto, informa-se qual o tipo de estabelecimento, os dados do estabelecimento, assim como a avaliação em si (estrelas). Os índices, representados pelas matrizes, devem ser atualizados a cada novo cadastro.
Lista o número de estabelecimentos por tipo de estabelecimento (contagem) (opção 2): lista, para cada tipo de estabelecimento, o número de estabelecimentos cadastrados. Para tanto, é necessário utilizar os índices existentes (não necessariamente os dois).
Lista o número de estabelecimentos de um dado tipo por estrelas (contagem) (opção 3): o usuário informa o tipo de estabelecimento desejado e uma listagem com o número de estabelecimentos do tipo solicitado e classificado em cada uma das possíveis estrelas é apresentado. Para tanto, é necessário utilizar os índices existentes (não necessariamente os dois).
Lista o número de estabelecimentos por estrelas (contagem) (opção 4): lista, para cada uma das possíveis estrelas, o número de estabelecimentos cadastrados. Para tanto é necessário utilizar os índices existentes (não necessariamente os dois).
Sair (opção 5): encerra o programa.
Observações:

Para especificar os tipos de dados é necessário utilizar struct, union e enum.
Na especificação dos tipos de dados, não use inteiros para estrelas, tipo de estabelecimento, tipo de comida e tipo de serviço.
Para cada opção implementar uma ou mais funções.
O main apenas gerencia o menu e as chamadas e os retornos das funções.
IMPORTANTE: lembre-se que os códigos serão comparados em termo de similaridade e será checado se o mesmo contempla as especificações recomendadas.
Em relação as saídas, printar:

Quando houver problema em relação ao intervalo de entrada considerado. Por exemplo, tipo de estabelecimento só pode ser 1, 2 ou 3. Valores fora desse intervalo são entradas invalidas:
printf("Entrada invalida\n");
Quando uma avaliação for cadastrada com sucesso:
printf("Avaliacao realizada com sucesso\n");
Quando o usuário tentar cadastrar mais de 10 avaliações:
printf("Vetor cheio\n");
Em relação as análises (contagens), tem-se dois padrões de impressão:
///Padrão 1

printf("Restaurantes: %d\n", /* Variavel*/);
printf("Fast-Food: %d\n", /* Variavel*/);
printf("Butecos: %d\n", /* Variavel*/);
//Padrão 2

printf("Estrelas: 1: %d\n", /* Variavel*/);
printf("Estrelas: 2: %d\n", /* Variavel*/);
printf("Estrelas: 3: %d\n", /* Variavel*/);
printf("Estrelas: 4: %d\n", /* Variavel*/);
printf("Estrelas: 5: %d\n", /* Variavel*/);
Quando for dado o comando de encerramento:

printf("Encerrando...");