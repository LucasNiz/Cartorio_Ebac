#include <stdio.h> //biblioteca de comunicacao com o usu�rio
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacao de texto por regiao
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");
	// Cria�a� das variaveis/string abaixo
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s por ser uma string // 
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo, w = write
	fprintf(file,cpf); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a"); // o "a" � para atualizar as informa��es do arquivo
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //Abrir o arquivo para adicionar o nome ou outra informa��o
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
	
	file = fopen(arquivo, "a"); // Esse "a" � para atualizar o arquivo, pois ele j� existe, e n�o cria um novo
	fprintf(file, cargo);
	fclose(file);

	printf("\nO usu�rio foi cadastrado com sucesso \n"); //Mensagem de confirma��o do processo
		
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
		
		printf("N�o foi localizado o arquivo. \n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL) //Para resultados existentes
	{
		
		printf("\nEssas s�o as informa��es do usu�rio: \n");
		
		token = strtok(conteudo, ",");
		printf("CPF: %s\n", token);  // Variavel utilizada para dividir a string em linhas, o "," � onde a linha ser� quebrada
		
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


int deletar()  // Fun��o para deletar os usu�rios
{
	setlocale(LC_ALL, "Portuguese"); //Adicionar os carcacteres da lingua portuguesa
	
	char cpf[40];
	
	printf("Qual o CPF do usu�rio que deseja deletar? \n");
	scanf("%s",cpf); //%s por ser uma string
	
	
	FILE *file;
	file = fopen(cpf, "r"); //abrir o arquivo e "r" para ler o arquivo
	
	if(file == NULL) //Se o valor informado for igual a inexistente
	{
		
		printf("O usu�rio n�o se encontra na base de dados\n");
		system("pause");
	}
		
	else  //sen�o
	
	{
	fclose(file); //Vai ser necess�rio fechar o arquivo, para que ele seja deletado
	remove(cpf); //Com o arquivo fechado, ele poder� ser deletado
	printf("O usu�rio com o CPF acima foi deletado \n");
	system("pause");
	}
	
	
	
}

int main()
{
	int opcao=0;//Definindo Vari�veis
	int laco=1;
	
	char senhadigitada[]="a";
	int comparacao;
	printf("### Cart�rio da EBAC ### \n\n");
	printf("Login de administrador! \n\n Digite a sua senha: \n");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
	system("cls");	
	for(laco=1;laco=1;)
	{
	
			system("cls"); //cls serve para limpar a tela
			setlocale(LC_ALL, "Portuguese"); //Foi definida a linguagem em portugu�s
		
			printf("\n### Cart�rio da EBAC ### \n\n");
	//In�cio do menu	
			printf("Escolha a op��o desejada do menu: \n\n");
			printf("\t1 - Registrar Nomes \n");
			printf("\t2 - Consultar Nomes\n");
			printf("\t3 - Deletar Nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("\tEscolha a Op��o Desejada: "); //Fim do Menu
		
			scanf("%d",& opcao); //Armazenando a escolha do usu�rio
		
			system("cls"); //Limpando a tela anterior 
			
			switch(opcao)
			{
				case 1:
					registro(); //Chama a fun��o registro
					break;
				case 2:
					consulta();	//Chama a fun��o de consulta
					break;
				case 3:
					deletar(); //Chama a fun��o de deletar
					break;	
				case 4:
					printf("Obrigado por utilizar o sistema\n");
					return 0;	
					break;	
				default:
					printf("Voc� selecionou uma op��o inv�lida, por favor, tente novamente\n"); //Caso selecione uma op��o inv�lida
					system("pause"); // Esperar a resposta do usu�rio
					break;
					//Fim da sele��o
		
	
	
				}
		
				
							
			}
		
	

			
		}
		else
			printf("Senha Incorreta");
		
	}

		
		
	
		



