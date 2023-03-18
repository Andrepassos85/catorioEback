#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h>// Biblioteca respons�vel por cuidar das string's

int registro()//Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	// In�cio de cria��o das vari�veis/string's
	setlocale(LC_ALL, "portuguese"); // Definindo a linguagem
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final de cria��o das vari�veis/string's
	
	printf("Didite o CPF a ser cadastrado: ");//Coletando informa��es do usu�rio(a)
	scanf("%s",cpf);//%s refere-se a strings
	
	strcpy(arquivo,cpf);//Respons�vel por copiar os valores das string's
	
	FILE *file;//Cria o arquivo na pasta do programa
	file = fopen(arquivo,"w");//Cria o arquivo na pasta do programa, "w" significa escrever
	fprintf(file,cpf);//Salvo o  valor da variavel
	fclose(file);// Fecha o arquivo
	
	file = fopen(arquivo,"a");//Abre o arquivo na pasta do programa
	fprintf(file,",");// Salva o valor na variavel e adiciona v�gula para separa��o dos valores escritos na tela 
	fclose(file);// Fecha o arquivo
	
	
	printf("Digite o nome a ser cadastrado: ");//Coleta o nome do usu�rio(a)
	scanf("%s",nome);//salva a vari�vel nome 
	
	file = fopen(arquivo,"a");//Abre o arquivo na pasta do programa
	fprintf(file,nome);//Escreve ao usu�rio as informa��es 
	fclose(file);// Fecha o arquivo
	
	file = fopen(arquivo,"a");//Abre o arquivo nas psta do programa
	fprintf(file,",");//Salva o valor na vari�vel e adiciona v�rgula para separa��o dos valores escritos na tela
	fclose(file);//Fecha o arquivo
	
	printf("Digite o sobrenomea ser cadastrado: ");// Coleta o sobrenome do usu�rio(a)
	scanf("%s",sobrenome);//salva ao sobrenome na vari�vel
	
	file = fopen(arquivo,"a");//Abre  oarquivo na psta do programa
	fprintf(file,sobrenome);//Salva o valor na vari�vel e adiciona v�rgula para separa��o dos valores escritos na tela
	fclose(file);//Fecha o arquivo
	
	file = fopen(arquivo,"a");//Abre  oarquivo na psta do programa
	fprintf(file,",");//Salva o valor na vari�vel e adiciona v�rgula para separa��o dos valores escritos na tela
	fclose(file);//Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");// Coleta o cargo do usu�rio(a)
	scanf("%s",cargo);//salva a vari�vel cargo
	
	file= fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");//Adicina uma pasa entre os menus para o usu�rio(a) fazer a leitura 
		
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); // Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");//Coleta o cpf do usu�rio
	scanf("%s",cpf);//Salva o cpf na vari�vel
	
	FILE *file;//Cria o arquivo na pasta do programa
	file = fopen(cpf,"r");//Abre o arquivo cpf e l� os dados da variavel comando"r"
	
	if(file == NULL)//Respons�vel por verificar se a informa��o est� no sistema
	{
		printf("\nN�o foi poss�vel abrir o Arquivo, Arquivo N�O localizado ou inexistente!.\n\n");//Aviso para o usu�rio(a) sobre a inexist�ncia dos arquivos
	}
	
	while(fgets(conteudo, 200, file) != NULL)//Fun��o "enquanto" que coleta os dados cadastrados do usu�rio(a)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");//Informa os dados cadastrados do usu�rio(a)
		printf("%s", conteudo);//informa��es do usu�rio 
		printf("\n\n");// Adiciona 2(duas) linhas de espa�o na tela da impress�o
	}
	
	system("pause");//Pausa no sistema para o usu�ria ler as informa��es
	



}
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");//Coleta o cpf do usu�rio(a) 
	scanf("%s",cpf);//Salva o dado coletado
	
	remove(cpf);//Remove os dados selecionados do sistema
	
	FILE *file;//Cria o arquivo na pasta do programa
	file = fopen(cpf,"r");//Abre o arquivo cpf e l� os dados da variavel comando"r"
	
	if(file==NULL)//Fun��o par arquivo inexistente
	{
		printf("O usu�rio n�o se enconta no sistema! .\n");//Infoma ainexist�ncia do arquivo no programa
		system("pause");//Pausa no programa para ler as informa��es na tela
	}
}
int main()
{
	int opcao=0; // Definindo �s vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");//Respons�vel por limpar a tela do programa
		
		setlocale(LC_ALL, "portuguese"); // Definindo a linguagem

		printf("#### Cart�rio da EBAC ####\n"); // In�cio do menu
		printf(" \nSelecione a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - sair do sistema\n");
		printf("Op��o: ");// Fim do menu
	
		scanf("%d", &opcao); //	Armazenando a escolha do usu�rio
	
		system("cls");
		
		switch(opcao)//In�cio das fun��es do menu
		{
			case 1://In�cio da sele��o
			registro();//chamada as fun��es
			break;//Termina a fun��o
			
			case 2://In�cio da sele��o
			consulta();//chamada as fun��es
			break;//Termina a fun��o
			
			case 3://In�cio da sele��o
			deletar();//chamada as fun��es
			break;//Termina a fun��o
			
			case 4:
			printf("Obrigado por utilizar o sistema!!");	
			return 0;
			break;
			
			
			default:// Fim da sele��o
			printf("Essa op��o n�o est� disponivel\n");//Avisa o usu�rio(a) sobre a inexist�nci dos dados
			system("pause");//Pausa a tela para ler as informa��es
			break;//Termina a fun��o
		} 
    }		
}

