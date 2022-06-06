Uma empresa prestadora de serviços armazena informações sobre os serviços prestados. Sabe-se que essa empresa realiza, no máximo, três serviços diariamente. É de interesse da direção dessa empresa manter um histórico mensal (30 dias) sobre os serviços prestados.

Estruturas
A empresa realiza quatro tipos de serviços:

Pintura;
Jardinagem;
Faxina;
Reforma em geral.
Cada um dos quatro tipos de serviços deve ser cadastrado pelo usuário usando uma estrutura com código do serviço:inteiro e descrição:literal[20]. Utilize um vetor de quatro posições capaz de armazenar as informações de cada um dos quatro tipos de serviços.

Além disso, cada serviço desenvolvido deve ser cadastrado usando uma estrutura com as seguintes informações: código do serviço:inteiro, número do serviço:inteiro, valor do serviço:real, e código do cliente:inteiro.

Matriz de serviços
Utilize uma matriz capaz de armazenar em cada posição todas as informações referentes a um serviço prestado. Cada linha representa um dia do mês e cada coluna representa um serviço realizado (máximo 3). Dessa maneira, considere a matriz com dimensão 30 x 3.

Dica: Lembre-se que a matriz deve começar na posição [0][0], porém o primeiro dia do mês será 1.

Inicialização
Inicialize, antes do usuário inserir entradas, cada informação (código de serviço, número de serviço, valor de serviço e código do cliente) de cada posição da matriz de serviços com o valor 0 (zero). Inicialize, também, cada informação de cada posição do vetor de tipos de serviços, sendo que o código do serviço deve ser inicializado com 0 (zero) e a descrição do serviço deve ser inicializada com "" (vazio).

Dica: Utilize a função strcpy do cabeçalho string.h da biblioteca padrão da linguagem C para inicializar a descrição do serviço com vazio.

Menu de opções
Cadastrar um dos quatro tipos de serviços
Cadastrar um serviço prestado em um determinado dia
Mostrar todos os serviços prestados em um determinado dia
Mostrar todos os serviços prestados dentro de um intervalo de valor
Mostrar o relatório geral (separado por dia), que exibe, inclusive, a descrição do tipo do serviço
Finalizar o programa
Atenção: Não printe o menu de opções em seu programa!

Receba uma opção:inteiro do usuário e caso a opção informada não exista, mostre a mensagem de erro a seguir e volte ao menu principal:

printf("Opcao invalida\n");
Informações Importantes
Para a opção 1

Deve-se cadastrar um dos quatro tipos de serviços oferecidos pela empresa.

Receba o código:inteiro do tipo de serviço e verifique se o cadastro de tipos de serviço está lotado, mostre a seguinte mensagem e volte ao menu principal em caso afirmativo:

printf("Cadastro de tipos de servicos lotado\n");
Em caso negativo, verifique se o código do tipo de cadastro já foi utilizado por outro tipo de serviço, mostre a seguinte mensagem e volte ao menu principal em caso afirmativo:

printf("Ja existe tipo de servico cadastrado com esse codigo\n");
Caso contrário receba também a descrição:literal[20] do tipo de serviço, armazene o código e a descrição no vetor de tipos de serviços, exiba a mensagem a seguir e volte ao menu principal:

printf("Tipo de servico cadastrado com sucesso\n");
Dica: Use o trecho de código abaixo para receber a descrição do usuário:

scanf(" %[^\n]", /* VARIÁVEL */);


Para a opção 2

Receba o dia:inteiro que deseja cadastrar o serviço prestado.

Verifique se o usuário esta tentando cadastrar mais de três serviços prestados em um mesmo dia, mostre a seguinte mensagem e volte ao menu principal apenas em caso afirmativo:

printf("Todos os servicos prestados neste dia ja foram cadastrados\n");
Caso contrário, receba um código do serviço e verifique se ele existe no vetor de tipos de serviços, mostre a seguinte mensagem e volte ao menu principal apenas em caso negativo:

printf("Codigo de servico invalido\n");
Em caso afirmativo, receba também o número do serviço, o valor do serviço e o código do cliente, nesta ordem, registre os quatro itens na matriz, exiba a mensagem a seguir e volte ao menu principal:

printf("Servico cadastrado com sucesso\n");


Para a opção 3

Receba o dia:inteiro que deseja consultar e mostre os respectivos serviços prestados.

Para cada serviço (que não está vazio) prestado no dia mostre a seguinte linha: (mude o nome das variáveis se necessário)

printf("%d %d %.2f\n", cod_servico, num_serv, valor_serv);
Se não houver serviços prestados naquele dia mostre a mensagem a seguir e volte ao menu principal:

printf("Nenhum servico foi prestado neste dia\n");


Para a opção 4

Receba o valor:real de serviço mínimo e o valor:real de serviço máximo e mostre todos os serviços prestados ao longo dos dias que estiverem neste intervalo fechado.

Para cada serviço que conter o valor no intervalo, mostre a seguinte linha: (mude o nome das variáveis se necessário)

printf("%d %d %.2f\n", cod_serv, num_serv, valor_serv);
Caso não haja serviços prestados com valores no intervalo definido, mostre a seguinte mensagem e volte ao menu principal:

printf("Nenhum servico prestado esta entre os valores citados\n");


Para a opção 5

Mostre os serviços prestados ao longo de todos os dias, inclusive com a descrição do tipo de serviço.

Para cada serviço prestado, mostre a seguinte linha: (mude o nome das variáveis se necessário)

printf("Dia: %d | %d | %d | %.2f | %d | %s", dia_atual, cod_serv, num_serv, valor_serv, cod_cliente, descricao);
Caso ainda não haja nenhum serviço prestado cadastrado na matriz, mostre a seguinte mensagem e volte ao menu principal:

printf("Nenhum servico prestado foi cadastrado\n");


Para a opção 6

Mostre a seguinte mensagem e finalize o programa:

printf("Fim de execucao\n");