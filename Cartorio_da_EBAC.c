#include <stdio.h> //bliblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o na mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //in�cio da fun��o registrar /fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio cria��o de vari�vel/string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char arquivo[40];
	//fim cria��o de vari�vel/string
	
	
	printf("Digite o CPF a ser cadastrado:");  //coletando informa��o do usu�rio
	scanf("%s",cpf);  //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //criar o arquivo no banco de dados
	file=fopen(arquivo, "w"); //criar o arquivo com o nome e o "w" � escrever
	fprintf(file,"CPF:"); //adicionando na tela a informa��o
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file=fopen(arquivo,"a"); //abrir o arquivo e "a" de atualizar
	fprintf(file,"\n"); //adicionando nova linha
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s",nome); //salva na string
	file=fopen(arquivo,"a"); //abrir o arquivo e "a" de atualizar
	fprintf(file,"Nome:"); //adicionando na tela a informa��o
	fprintf(file,nome); //salva o valor da vari�vel
	fprintf(file,"\n"); //adicionando nova linha
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome); //salva na string
	file=fopen(arquivo,"a"); ///abrir o arquivo e "a" de atualizar
	fprintf(file,"Sobrenome:"); //adicionando na tela a informa��o
	fprintf(file, sobrenome); //salva o valor da vari�vel
	fprintf(file,"\n"); //adicionando nova linha
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo); //salva na string
	file=fopen(arquivo,"a"); //abrir o arquivo e "a" de atualizar
	fprintf(file,"Cargo:"); //adicionando na tela a informa��o
	fprintf(file,cargo); //salva o valor da vari�vel
	fclose(file);//fecha o arquivo
		
	system("pause"); //pausa aguardando usu�rio
} //fim da fun��o registrar 

int consulta() //in�cio da fun��o consultar
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	char cpf[40]; //vari�veis
	char conteudo[200]; // armazena na vari�vel conteudo
	
	printf("Digite o CPF a ser consultado:"); //pergunta ao usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file; 
	file=fopen(cpf, "r"); // abre o arquivo para ler (read)
	
	if(file==NULL) //caso seja nulo 
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado! \n"); //mensagem ao usu�rio
	} 
			
	while(fgets(conteudo,200, file)!= NULL) //buscando conte�do dentro do arquivo
	{
		printf("%s",conteudo); //mostrar conte�do do arquivo escolhido
		printf("\n\n"); //nova linha
	}
	
	fclose(file);	//fecha o arquivo
	system("pause"); //pausa aguardando usu�rio
} //fim da fun��o consultar

int deletar() //in�cio da fun��o deletar
{
	char cpf[40]; //vari�veis
	
	printf("Digite o CPF do usu�rio a ser deletado:"); //pergunta ao usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file; 
	file = fopen(cpf,"r"); // abre o arquivo para ler (read)
	
	if(file!=NULL) //caso seja diferente de nulo 
	{
		fclose(file); //fecha o arquivo
		remove(cpf); //deletar do arquivo
		printf("O usu�rio foi deletado! \n"); //mensagem ao usu�rio
		system("pause"); //pausa aguardando usu�rio
	}
	else
	{
		printf("O usu�rio n�o se encontra no sistema! \n"); //mensagem ao usu�rio
		system("pause"); //pausa aguardando usu�rio
	}
	
} //fim da fun��o deletar

	int main() //in�cio do menu principal
		{
				int opcao=0; //Definindo vari�veis
				int laco=1;
				
				for(laco=1;laco=1;)
				{
			
					system("cls"); // respons�vel por limpar a tela 
								
					setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
								
					printf("### Cart�rio da EBAC ###\n\n"); //Inicio do Menu
					printf("Escolha a op��o desejada do menu:\n\n");
					printf("\t1-Registrar Nomes\n");
					printf("\t2-Consultar Nomes\n");
					printf("\t3-Deletar Nomes\n\n");
					printf("Op��o: "); // Fim do Menu 
			
					scanf("%d", &opcao); //armazenando a escolha do usu�rio
				
					system("cls");	//respons�vel por limpar a tela	
			
					switch(opcao) //in�cio da sele��o
					{
						case 1:
						registro();
						break;
						
						case 2:
						consulta();
						break;
						
						case 3:
						deletar();
						break;
						
						default:
						printf("Essa op��o n�o est� dispon�vel!\n"); //mensagem ao usu�rio
						system("pause"); //pausa aguardando usu�rio
						break;
					} //fim da sele��o
										
				}//fim do menu principal
				
		}
