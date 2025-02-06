#include <stdio.h> //biblioteca de comunicacao com o usuário
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacao de texto por regiao
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() // Função responsável por cadastrar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");
	// Criaçaõ das variaveis/string abaixo
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s por ser uma string // 
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo, w = write
	fprintf(file,cpf); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a"); // o "a" é para atualizar as informações do arquivo
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //Abrir o arquivo para adicionar o nome ou outra informação
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo,"a"); 
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o cargo da pessoa a ser cadastrada: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); // Esse "a" é para atualizar o arquivo, pois ele já existe, e não cria um novo
	fprintf(file, cargo);
	fclose(file);

	printf("\nO usuário foi cadastrado com sucesso \n"); //Mensagem de confirmação do processo
		
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	char *token;
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) //Para resultados inexistentes 
	{
		
		printf("Não foi localizado o arquivo. \n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL) //Para resultados existentes
	{
		
		printf("\nEssas são as informações do usuário: \n");
		
		token = strtok(conteudo, ",");
		printf("CPF: %s\n", token);  // Variavel utilizada para dividir a string em linhas, o "," é onde a linha será quebrada
		
		token = strtok(NULL, ",");
		printf("Nome: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("Sobrenome: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("Cargo: %s\n", token);
		
	}
	
	printf("\n");
	
	system("pause");
	fclose(file); // Fechar arquivo
	
}


int deletar()  // Função para deletar os usuários
{
	setlocale(LC_ALL, "Portuguese"); //Adicionar os carcacteres da lingua portuguesa
	
	char cpf[40];
	
	printf("Qual o CPF do usuário que deseja deletar? \n");
	scanf("%s",cpf); //%s por ser uma string
	
	
	FILE *file;
	file = fopen(cpf, "r"); //abrir o arquivo e "r" para ler o arquivo
	
	if(file == NULL) //Se o valor informado for igual a inexistente
	{
		
		printf("O usuário não se encontra na base de dados\n");
		system("pause");
	}
		
	else  //senão
	
	{
	fclose(file); //Vai ser necessário fechar o arquivo, para que ele seja deletado
	remove(cpf); //Com o arquivo fechado, ele poderá ser deletado
	printf("O usuário com o CPF acima foi deletado \n");
	system("pause");
	}
	
	
	
}

int main()
{
	int opcao=0;//Definindo Variáveis
	int laco=1;
	
	char senhadigitada[]="a";
	int comparacao;
	printf("### Cartório da EBAC ### \n\n");
	printf("Login de administrador! \n\n Digite a sua senha: \n");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
	system("cls");	
	for(laco=1;laco=1;)
	{
	
			system("cls"); //cls serve para limpar a tela
			setlocale(LC_ALL, "Portuguese"); //Foi definida a linguagem em português
		
			printf("\n### Cartório da EBAC ### \n\n");
	//Início do menu	
			printf("Escolha a opção desejada do menu: \n\n");
			printf("\t1 - Registrar Nomes \n");
			printf("\t2 - Consultar Nomes\n");
			printf("\t3 - Deletar Nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("\tEscolha a Opção Desejada: "); //Fim do Menu
		
			scanf("%d",& opcao); //Armazenando a escolha do usuário
		
			system("cls"); //Limpando a tela anterior 
			
			switch(opcao)
			{
				case 1:
					registro(); //Chama a função registro
					break;
				case 2:
					consulta();	//Chama a função de consulta
					break;
				case 3:
					deletar(); //Chama a função de deletar
					break;	
				case 4:
					printf("Obrigado por utilizar o sistema\n");
					return 0;	
					break;	
				default:
					printf("Você selecionou uma opção inválida, por favor, tente novamente\n"); //Caso selecione uma opção inválida
					system("pause"); // Esperar a resposta do usuário
					break;
					//Fim da seleção
		
	
	
				}
		
				
							
			}
		
	

			
		}
		else
			printf("Senha Incorreta");
		
	}

		
		
	
		



