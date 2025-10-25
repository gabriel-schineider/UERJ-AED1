# include <stdio.h>
# include <stdbool.h>

typedef struct Aluno
{
		int ID;
		char nome[4]; // WHY THE NUMBER '4'??? WELL... IT IS BECAUSE OF THE NULL TERMINATOR '\0'. IT IS VERY IMPORTANT TO REMEMBER, SINCE FUNCTIONS AS printf("%s", vetooooor)
		float CR;
		bool ativo;
} Aluno;
	

int main (void)
{
	
	// I can assign value by value:
	/*
	Aluno a1;
	a1.ID = 124869;
	a1.nome[0] = 'B'; a1.nome[1] = 'I'; a1.nome[2] = 'A';
	a1.CR = 8.9;
	a1.ativo = 1;
	*/
	
	// Or, if I know the elements order, I can just code:
	Aluno a1 = {124869, "BIA", 8.9, true};
	
	Aluno a2;
	a2 = a1;
	a2.ID = 146293;
	*a2.nome = 'L';
	a2.nome[1] = 'U';
	
	
	printf("%d %d \n%s %s \n%f %f \n%d %d \n", a1.ID, a2.ID, a1.nome, a2.nome, a1.CR, a2.CR, a1.ativo, a2.ativo);
	
	return 0;
}
