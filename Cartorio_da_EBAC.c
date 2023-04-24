#include <stdio.h> //bliblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço na memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //início da função registrar /função responsável por cadastrar os usuários no sistema
{
	//início criação de variável/string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char arquivo[40];
	//fim criação de variável/string
	
	
	printf("Digite o CPF a ser cadastrado:");  //coletando informação do usuário
	scanf("%s",cpf);  //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //criar o arquivo no banco de dados
	file=fopen(arquivo, "w"); //criar o arquivo com o nome e o "w" é escrever
	fprintf(file,"CPF:"); //adicionando na tela a informação
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file=fopen(arquivo,"a"); //abrir o arquivo e "a" de atualizar
	fprintf(file,"\n"); //adicionando nova linha
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s",nome); //salva na string
	file=fopen(arquivo,"a"); //abrir o arquivo e "a" de atualizar
	fprintf(file,"Nome:"); //adicionando na tela a informação
	fprintf(file,nome); //salva o valor da variável
	fprintf(file,"\n"); //adicionando nova linha
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome); //salva na string
	file=fopen(arquivo,"a"); ///abrir o arquivo e "a" de atualizar
	fprintf(file,"Sobrenome:"); //adicionando na tela a informação
	fprintf(file, sobrenome); //salva o valor da variável
	fprintf(file,"\n"); //adicionando nova linha
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo); //salva na string
	file=fopen(arquivo,"a"); //abrir o arquivo e "a" de atualizar
	fprintf(file,"Cargo:"); //adicionando na tela a informação
	fprintf(file,cargo); //salva o valor da variável
	fclose(file);//fecha o arquivo
		
	system("pause"); //pausa aguardando usuário
} //fim da função registrar 

int consulta() //início da função consultar
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	char cpf[40]; //variáveis
	char conteudo[200]; // armazena na variável conteudo
	
	printf("Digite o CPF a ser consultado:"); //pergunta ao usuário
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file; 
	file=fopen(cpf, "r"); // abre o arquivo para ler (read)
	
	if(file==NULL) //caso seja nulo 
	{
		printf("Não foi possível abrir o arquivo, não localizado! \n"); //mensagem ao usuário
	} 
			
	while(fgets(conteudo,200, file)!= NULL) //buscando conteúdo dentro do arquivo
	{
		printf("%s",conteudo); //mostrar conteúdo do arquivo escolhido
		printf("\n\n"); //nova linha
	}
	
	fclose(file);	//fecha o arquivo
	system("pause"); //pausa aguardando usuário
} //fim da função consultar

int deletar() //início da função deletar
{
	char cpf[40]; //variáveis
	
	printf("Digite o CPF do usuário a ser deletado:"); //pergunta ao usuário
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file; 
	file = fopen(cpf,"r"); // abre o arquivo para ler (read)
	
	if(file!=NULL) //caso seja diferente de nulo 
	{
		fclose(file); //fecha o arquivo
		remove(cpf); //deletar do arquivo
		printf("O usuário foi deletado! \n"); //mensagem ao usuário
		system("pause"); //pausa aguardando usuário
	}
	else
	{
		printf("O usuário não se encontra no sistema! \n"); //mensagem ao usuário
		system("pause"); //pausa aguardando usuário
	}
	
} //fim da função deletar

	int main() //início do menu principal
		{
				int opcao=0; //Definindo variáveis
				int laco=1;
				
				for(laco=1;laco=1;)
				{
			
					system("cls"); // responsável por limpar a tela 
								
					setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
								
					printf("### Cartório da EBAC ###\n\n"); //Inicio do Menu
					printf("Escolha a opção desejada do menu:\n\n");
					printf("\t1-Registrar Nomes\n");
					printf("\t2-Consultar Nomes\n");
					printf("\t3-Deletar Nomes\n\n");
					printf("Opção: "); // Fim do Menu 
			
					scanf("%d", &opcao); //armazenando a escolha do usuário
				
					system("cls");	//responsável por limpar a tela	
			
					switch(opcao) //início da seleção
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
						printf("Essa opção não está disponível!\n"); //mensagem ao usuário
						system("pause"); //pausa aguardando usuário
						break;
					} //fim da seleção
										
				}//fim do menu principal
				
		}
