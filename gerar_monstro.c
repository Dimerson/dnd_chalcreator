#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct talentos{						//Nome dos talentos
	char nome[18];
	struct talentos* prox;
} Tal;

typedef struct monstros{						//Nome dos Monstros/Animais
	char nome [25];
	char tp[5];
	short int dv[3];							//Dado de Vida
	short int ini;								//Iniciativa
	float des;									//Deslocamento
	short int CA;
	float alc;									//Alcance
	short int res[3];							//Testes de Resistencia (Fort, Ref, Von)
	short int hab[6];							//Habilidades (For, Des, Con, Int, Sab, Car)
	Tal* lista;									//Lista de talentos
	short int desafio;
	
} Mon;

Tal* cria_tal (char NOME[])
{
	Tal* novo = malloc(sizeof(Tal));
	novo->prox = NULL;
	stcrpy(novo->nome, NOME);
	
	return novo;
}


Mon* cria_mon (char NOME[], char TP[], short int DV[3], short int DADOS[3], float OUTRO[2], int RES[3], int HAB[6], Tal* LISTA)
{
	Mon* novo = malloc(sizeof(Mon));
	strcpy(novo->nome, NOME);
	strcpy(novo->tp, TP);
	novo->dv = DV;
	novo->ini = DADOS[0];
	novo->CA = DADOS[1];
	novo->desafio = DADOS[2];
	novo->des = OUTRO[0];
	novo->alc = OUTRO[1];
	novo->res = RES;
	novo->hab = HAB;
	tal = LISTA;
	
	return novo;
}

Tal* aloca_tal(Tal* atual, char str[])
{
	if (atual == NULL)
		return cria_tal(str);
	
	return aloca_tal(atual->prox, str);
}

void menu()
{
	printf("1 - Adicionar Monstro\n");
	printf("2 - Remover Monstro\n");
	printf("\n");
}

Mon* add_monstro(Mon* list)
{
	short int dados[3];
	char* nomes[2][];
	float aux[2];
	short int dv[3];
	int res[3];
	int hab[6];
	Tal* lista = NULL;
	
	char* str[] = "nada";
	
	printf("Nome do monstro: ");
	gets(nomes[0]);
	printf("Tipo: ");
	gets(nomes[1]);
	printf("Dados de Vida: ");
	scanf("%hi %hi %hi", &dv[0], &dv[1], &dv[2]);
	printf("Iniciativa: ");
	scanf("%hi", &dados[0]);
	printf("Deslocamento: ");
	scanf("%f", aux[0]);
	printf("CA: ");
	scanf("%hi", dados[1]);
	printf("Alcance: ");
	scanf("%f", &aux[1]);
	printf("Testes de Resistencia: ");
	scanf("%hi %hi %hi", res[0], res[1], res[2]);
	printf("Habilidades: ");
	scanf("%hi %hi %hi %hi %hi %hi %hi", hab[0], hab[1], hab[2], hab[3], hab[4], hab[5]);
	printf("Talentos (digite 0 pra sair): ");
	
	while(strcmp(str, "0") != 0)
	{
		scanf("%s", str);
		if (strcmp(str, "0") != 0)
			lista = aloca_tal(lista, str);
	}
	
	printf("Desafio: ");
	scanf("%hi", &dados[2]);
	
	return cria_mon(nomes[0], nomes[1], dv, dados, aux, hab, str);
}


void imprime_talento(Tal* atual)
{
	if atual == NULL
		return atual;
	
	printf("- %s\n", atual->nome);
	imprime_talento(atual->prox);
}


void imprime_lista(Mon no)
{
	printf("Nome: %s\nTipo: %s\nIniciativa: %hi\n", no->nome, no->tp, no->ini);
	printf("Deslocamento: %.1f\nCA: &hi\nAlcance: &.1f\n", no->des, no->CA, no->alc);
	printf("Fort: %hi, Ref: %hi, Von: %hi\n", no->res[0], no->res[1], no->res[2])
	printf("For: &hi, Des: &hi, Con: %hi, Int: %hi, Sab: &hi, Car: &hi\n", no->hab[0], no->hab[1], no->hab[2], no->hab[3], no->hab[4], no->hab[5]);
	printf("Talentos: \n");
	imprime_talento(Mon->lista);
	printf("Desafio: &hi\n\n", no->desafio);
}


int main()
{
	Mon Monster;
	
	int escolha = 1;
	
	while(escolha != 0)
	{
		void menu();
		
		switch(escolha)
		{
			case 1:
				Monster = add_mostro(Monster);
				break;
			
			case 2:
				break;
		}
		
		printf("\n\n");
		printf("\n\n");
		
		imprime_lista(Monster);
		
		printf("\n\n");
	}
	
	return 0;
}
