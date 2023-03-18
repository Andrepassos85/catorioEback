#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h>// Biblioteca responsável por cuidar das string's

int registro()//Função responsável por cadastrar os usuários no sistema
{
	// Início de criação das variáveis/string's
	setlocale(LC_ALL, "portuguese"); // Definindo a linguagem
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final de criação das variáveis/string's
	
	printf("Didite o CPF a ser cadastrado: ");//Coletando informações do usuário(a)
	scanf("%s",cpf);//%s refere-se a strings
	
	strcpy(arquivo,cpf);//Responsável por copiar os valores das string's
	
	FILE *file;//Cria o arquivo na pasta do programa
	file = fopen(arquivo,"w");//Cria o arquivo na pasta do programa, "w" significa escrever
	fprintf(file,cpf);//Salvo o  valor da variavel
	fclose(file);// Fecha o arquivo
	
	file = fopen(arquivo,"a");//Abre o arquivo na pasta do programa
	fprintf(file,",");// Salva o valor na variavel e adiciona vígula para separação dos valores escritos na tela 
	fclose(file);// Fecha o arquivo
	
	
	printf("Digite o nome a ser cadastrado: ");//Coleta o nome do usuário(a)
	scanf("%s",nome);//salva a variável nome 
	
	file = fopen(arquivo,"a");//Abre o arquivo na pasta do programa
	fprintf(file,nome);//Escreve ao usuário as informações 
	fclose(file);// Fecha o arquivo
	
	file = fopen(arquivo,"a");//Abre o arquivo nas psta do programa
	fprintf(file,",");//Salva o valor na variável e adiciona vírgula para separação dos valores escritos na tela
	fclose(file);//Fecha o arquivo
	
	printf("Digite o sobrenomea ser cadastrado: ");// Coleta o sobrenome do usuário(a)
	scanf("%s",sobrenome);//salva ao sobrenome na variável
	
	file = fopen(arquivo,"a");//Abre  oarquivo na psta do programa
	fprintf(file,sobrenome);//Salva o valor na variável e adiciona vírgula para separação dos valores escritos na tela
	fclose(file);//Fecha o arquivo
	
	file = fopen(arquivo,"a");//Abre  oarquivo na psta do programa
	fprintf(file,",");//Salva o valor na variável e adiciona vírgula para separação dos valores escritos na tela
	fclose(file);//Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");// Coleta o cargo do usuário(a)
	scanf("%s",cargo);//salva a variável cargo
	
	file= fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");//Adicina uma pasa entre os menus para o usuário(a) fazer a leitura 
		
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); // Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");//Coleta o cpf do usuário
	scanf("%s",cpf);//Salva o cpf na variável
	
	FILE *file;//Cria o arquivo na pasta do programa
	file = fopen(cpf,"r");//Abre o arquivo cpf e lê os dados da variavel comando"r"
	
	if(file == NULL)//Responsável por verificar se a informação está no sistema
	{
		printf("\nNão foi possível abrir o Arquivo, Arquivo NÂO localizado ou inexistente!.\n\n");//Aviso para o usuário(a) sobre a inexistência dos arquivos
	}
	
	while(fgets(conteudo, 200, file) != NULL)//Função "enquanto" que coleta os dados cadastrados do usuário(a)
	{
		printf("\nEssas são as informações do usuário: ");//Informa os dados cadastrados do usuário(a)
		printf("%s", conteudo);//informações do usuário 
		printf("\n\n");// Adiciona 2(duas) linhas de espaço na tela da impressão
	}
	
	system("pause");//Pausa no sistema para o usuária ler as informações
	



}
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");//Coleta o cpf do usuário(a) 
	scanf("%s",cpf);//Salva o dado coletado
	
	remove(cpf);//Remove os dados selecionados do sistema
	
	FILE *file;//Cria o arquivo na pasta do programa
	file = fopen(cpf,"r");//Abre o arquivo cpf e lê os dados da variavel comando"r"
	
	if(file==NULL)//Função par arquivo inexistente
	{
		printf("O usuário não se enconta no sistema! .\n");//Infoma ainexistência do arquivo no programa
		system("pause");//Pausa no programa para ler as informações na tela
	}
}
int main()
{
	int opcao=0; // Definindo ás variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");//Responsável por limpar a tela do programa
		
		setlocale(LC_ALL, "portuguese"); // Definindo a linguagem

		printf("#### Cartório da EBAC ####\n"); // Início do menu
		printf(" \nSelecione a opção desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - sair do sistema\n");
		printf("Opção: ");// Fim do menu
	
		scanf("%d", &opcao); //	Armazenando a escolha do usuário
	
		system("cls");
		
		switch(opcao)//Início das funções do menu
		{
			case 1://Início da seleção
			registro();//chamada as funções
			break;//Termina a função
			
			case 2://Início da seleção
			consulta();//chamada as funções
			break;//Termina a função
			
			case 3://Início da seleção
			deletar();//chamada as funções
			break;//Termina a função
			
			case 4:
			printf("Obrigado por utilizar o sistema!!");	
			return 0;
			break;
			
			
			default:// Fim da seleção
			printf("Essa opção não está disponivel\n");//Avisa o usuário(a) sobre a inexistênci dos dados
			system("pause");//Pausa a tela para ler as informações
			break;//Termina a função
		} 
    }		
}

