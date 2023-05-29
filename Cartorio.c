#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int salvar() //Fun��o para salvar nomes no Bando de Dados
{
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o das vari�veis
	
	printf("Digite o CPF: "); //coletando informa��es de CPF do usu�rio
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo,cpf); //Respons�vel por copiar os valores das string (cpf para arquivo)
	
	FILE *file; //Comando para criar um arquivo (file), chamando fun��o na biblioteca chamada FILE
	file = fopen(arquivo,"w"); //Abre o file arquivo, "w" significa escrever
	fprintf(file,"CPF:"); //adiciona o "CPF:" no inicio para facilitar a leitura na hora de consultar
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,cpf); //Salva o valor da varialvel "cpf" no arquivo
	fclose(file);
	
	file = fopen(arquivo,"a"); //Abre o arquivo que ja foi criado, "a" significa atualziar um arquivo que j� existe
	fprintf(file,";"); //Escreve dentro do arquivo o ";" para separar, facilitando a leitura na hora de conslutar
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome: "); //coletando informa��es de Nome do usu�rio
	scanf("%s", nome);

	file = fopen(arquivo,"a"); //Abre o arquivo que ja foi criado, "a" significa atualziar um arquivo que j� existe
	fprintf(file,"Nome:"); //adiciona o "Nome:" no inicio para facilitar a leitura na hora de consultar
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome); //Salva o valor da varialvel "nome" no arquivo
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,";"); //Escreve dentro do arquivo o ";" para separar, facilitando a leitura na hora de conslutar
	fclose(file);
	
	printf("Digite o sobrenome: "); //coletando informa��es de Sobrenome do usu�rio
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,"Sobrenome:"); //adiciona o "Sobrenome:" no inicio para facilitar a leitura na hora de consultar
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome); //Salva o valor da varialvel "sobrenome" no arquivo
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,";"); //Escreve dentro do arquivo o ";" para separar, facilitando a leitura na hora de conslutar
	fclose(file);
	
	printf("Digite o cargo: "); //coletando informa��es de Cargo do usu�rio
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,"Cargo:"); //adiciona o "Cargo:" no inicio para facilitar a leitura na hora de consultar
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo); //Salva o valor da varialvel "cargo" no arquivo
	fclose(file);

}

int consultar() //Fun��o para consultar nomes no Bando de Dados
{
	setlocale(LC_ALL, "Portuguese"); //Escolha da linguagem
	
	//inicio da cria��o de vari�veis/strings
	char cpf[40];
	char conteudo[200];
	//final da cria��o das vari�veis
	
	printf("Digite o CPF para consulta: ");
	scanf("%s",cpf); //pega os dados de CPF para realizar a consulta
	
	FILE *file;
	file = fopen(cpf,"r"); //abre o arquivo em modo "r" para read, ler o valor no arquivo "file"
	
	if(file== NULL) //comando para caso o usu�rio digite um valor que n�o existe no banco de dados
	{
		printf("\n\t##########Usu�rio n�o localizado.##########\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //comando para repetir a busca dos dados no arquivo at� nao tem mais nada "NULL"
	{
		printf("\nDados do usu�rio abaixo: \n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
		
}

int deletar() //Fun��o para deletar nomes no Bando de Dados
{
	char cpf[40];
	
	printf("Digite o CPF que deseja apagar: ");
	scanf("%s", cpf); //pede o dado de CPF para realizar o delete
	
	if (remove(cpf) == 0) //caso o CPF exista e a exclus�o seja com sucesso retorna resposta de confirma��o
	{
		printf("\nUsu�rio apagado\n\n");
		system("pause");
	}
	
	else //se o CPF n�o existe retorna pedidno para tentar novamente
	{
	FILE *file;
	file = fopen(cpf, "r");
	
		if(file == NULL)
		{
				printf("\nUsu�rio n�o existe, tente novamente !\n\n");
		system("pause");
		}
	}
		
}


int main()
{
	int opcao=0; //Definindo a vari�lvel
	int repete=1; //Defini��o da vari�vel do repete para for
	
	for(repete=1;repete=1;) //Inicio do for para repeti��o das op��es
	{
	
		system("cls"); //Limpeza da tela
		
		setlocale(LC_ALL, "Portuguese"); //Escolha da linguagem
	
		printf("################### Cart�rio do Luiz Felipe ###################\n\n");
		printf("Fa�a as suas escolhas:\n\n");
		printf("\t1 - Salvar Nomes:\n");
		printf("\t2 - Consultar Nomes:\n");
		printf("\t3 - Apagar Nomes:\n\n\n");
		
		printf("Digite a op��o desejada:");
		scanf("%d", &opcao); //Coletando a escolha da usu�rio
		
		system("cls"); //Limpeza da tela
		
		switch(opcao) //Inicio do switch para as op��es
		{
			case 1:
			salvar(); //chamada de fun��o "salavar"
			break;
			
			case 2:
			consultar(); //chamada de fun��o "consultar"
			break;
			
			case 3:
			deletar(); //chamada de fun��o "deletar"
			break;
			
			default:
			printf("\n\n\tOp��o n�o est� disponivel !!\n\n"); //caso n�o exista a op��o retorna um erro de op��o n�o disponivel
			system("pause");
			break;		
		} // Fim do swtch
		
	} // Fim do For
	
	printf("\n\n\t\t ########################Software do Angeluiz########################");
}
