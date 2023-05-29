#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int salvar() //Função para salvar nomes no Bando de Dados
{
	//inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação das variáveis
	
	printf("Digite o CPF: "); //coletando informações de CPF do usuário
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo,cpf); //Responsável por copiar os valores das string (cpf para arquivo)
	
	FILE *file; //Comando para criar um arquivo (file), chamando função na biblioteca chamada FILE
	file = fopen(arquivo,"w"); //Abre o file arquivo, "w" significa escrever
	fprintf(file,"CPF:"); //adiciona o "CPF:" no inicio para facilitar a leitura na hora de consultar
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,cpf); //Salva o valor da varialvel "cpf" no arquivo
	fclose(file);
	
	file = fopen(arquivo,"a"); //Abre o arquivo que ja foi criado, "a" significa atualziar um arquivo que já existe
	fprintf(file,";"); //Escreve dentro do arquivo o ";" para separar, facilitando a leitura na hora de conslutar
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome: "); //coletando informações de Nome do usuário
	scanf("%s", nome);

	file = fopen(arquivo,"a"); //Abre o arquivo que ja foi criado, "a" significa atualziar um arquivo que já existe
	fprintf(file,"Nome:"); //adiciona o "Nome:" no inicio para facilitar a leitura na hora de consultar
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome); //Salva o valor da varialvel "nome" no arquivo
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,";"); //Escreve dentro do arquivo o ";" para separar, facilitando a leitura na hora de conslutar
	fclose(file);
	
	printf("Digite o sobrenome: "); //coletando informações de Sobrenome do usuário
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
	
	printf("Digite o cargo: "); //coletando informações de Cargo do usuário
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,"Cargo:"); //adiciona o "Cargo:" no inicio para facilitar a leitura na hora de consultar
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo); //Salva o valor da varialvel "cargo" no arquivo
	fclose(file);

}

int consultar() //Função para consultar nomes no Bando de Dados
{
	setlocale(LC_ALL, "Portuguese"); //Escolha da linguagem
	
	//inicio da criação de variáveis/strings
	char cpf[40];
	char conteudo[200];
	//final da criação das variáveis
	
	printf("Digite o CPF para consulta: ");
	scanf("%s",cpf); //pega os dados de CPF para realizar a consulta
	
	FILE *file;
	file = fopen(cpf,"r"); //abre o arquivo em modo "r" para read, ler o valor no arquivo "file"
	
	if(file== NULL) //comando para caso o usuário digite um valor que não existe no banco de dados
	{
		printf("\n\t##########Usuário não localizado.##########\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //comando para repetir a busca dos dados no arquivo até nao tem mais nada "NULL"
	{
		printf("\nDados do usuário abaixo: \n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
		
}

int deletar() //Função para deletar nomes no Bando de Dados
{
	char cpf[40];
	
	printf("Digite o CPF que deseja apagar: ");
	scanf("%s", cpf); //pede o dado de CPF para realizar o delete
	
	if (remove(cpf) == 0) //caso o CPF exista e a exclusão seja com sucesso retorna resposta de confirmação
	{
		printf("\nUsuário apagado\n\n");
		system("pause");
	}
	
	else //se o CPF não existe retorna pedidno para tentar novamente
	{
	FILE *file;
	file = fopen(cpf, "r");
	
		if(file == NULL)
		{
				printf("\nUsuário não existe, tente novamente !\n\n");
		system("pause");
		}
	}
		
}


int main()
{
	int opcao=0; //Definindo a variálvel
	int repete=1; //Definição da variável do repete para for
	
	for(repete=1;repete=1;) //Inicio do for para repetição das opções
	{
	
		system("cls"); //Limpeza da tela
		
		setlocale(LC_ALL, "Portuguese"); //Escolha da linguagem
	
		printf("################### Cartório do Luiz Felipe ###################\n\n");
		printf("Faça as suas escolhas:\n\n");
		printf("\t1 - Salvar Nomes:\n");
		printf("\t2 - Consultar Nomes:\n");
		printf("\t3 - Apagar Nomes:\n");
		printf("\t4 - Sair do sistema\n\n\n");
		
		printf("Digite a opção desejada:");
		scanf("%d", &opcao); //Coletando a escolha da usuário
		
		system("cls"); //Limpeza da tela
		
		switch(opcao) //Inicio do switch para as opções
		{
			case 1:
			salvar(); //chamada de função "salavar"
			break;
			
			case 2:
			consultar(); //chamada de função "consultar"
			break;
			
			case 3:
			deletar(); //chamada de função "deletar"
			break;
			
			case 4:
			printf("\n\n\tObrigado por utilizar o sistema!\n");
			printf("\tSistema criado por Luiz Felipe Rangel\n\n\n");
			printf("\t#####Pressione qualquer tecla para fechar#####\n\n");
			return 0;
			break;
			
			default:
			printf("\n\n\tOpção não está disponivel !!\n\n"); //caso não exista a opção retorna um erro de opção não disponivel
			system("pause");
			break;		
		} // Fim do swtch
		
	} // Fim do For

}
