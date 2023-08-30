#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 struct Funcionario
{
  
char nome[50];
   
char telefone[15];
 
};

 
struct Entrega
{
  
char endereco[100];
   
struct Funcionario *funcionario;
 
};

 
void
adicionarFuncionario (struct Funcionario *funcionarios, int *numFuncionarios)
{
  
printf ("Digite o nome do funcionario: ");
  
scanf ("%s", funcionarios[*numFuncionarios].nome);
  
printf ("Digite o telefone do funcionario: ");
  
scanf ("%s", funcionarios[*numFuncionarios].telefone);
  
(*numFuncionarios)++;
  
printf ("Funcionario adicionado com sucesso!\n");

} 
 
void

listarFuncionarios (struct Funcionario *funcionarios, int numFuncionarios)
{
  
printf ("Lista de Funcionarios:\n");
  
for (int i = 0; i < numFuncionarios; i++)
    {
      
printf ("Nome: %s, Telefone: %s\n", funcionarios[i].nome,
	       funcionarios[i].telefone);

} 
} 
 
void

adicionarEntrega (struct Entrega *entregas, int *numEntregas,
		  struct Funcionario *funcionarios, int numFuncionarios)
{
  
printf ("Digite o endereco da entrega: ");
  
scanf ("%s", entregas[*numEntregas].endereco);
  
 
listarFuncionarios (funcionarios, numFuncionarios);
  
 
char nomeFuncionario[50];
  
printf ("Digite o nome do funcionario para a entrega: ");
  
scanf ("%s", nomeFuncionario);
  
 
int funcionarioEncontrado = 0;
  
for (int i = 0; i < numFuncionarios; i++)
    {
      
if (strcmp (funcionarios[i].nome, nomeFuncionario) == 0)
	{
	  
entregas[*numEntregas].funcionario = &funcionarios[i];
	  
funcionarioEncontrado = 1;
	  
break;
	
}
    
}
  
 
if (funcionarioEncontrado)
    {
      
(*numEntregas)++;
      
printf ("Entrega adicionada com sucesso!\n");
    
}
  else
    {
      
printf ("Funcionario nao encontrado.\n");
    
}

}


 
void
listarEntregas (struct Entrega *entregas, int numEntregas)
{
  
printf ("Lista de Entregas:\n");
  
for (int i = 0; i < numEntregas; i++)
    {
      
printf ("Endereco: %s, Funcionario: %s\n", entregas[i].endereco,
	       entregas[i].funcionario->nome);

} 
} 
 
void

entrarContatoFuncionario (struct Funcionario *funcionarios,
			  int numFuncionarios)
{
  
char nomeFuncionario[50];
  
printf ("Digite o nome do funcionario para entrar em contato: ");
  
scanf ("%s", nomeFuncionario);
  
 
int funcionarioEncontrado = 0;
  
for (int i = 0; i < numFuncionarios; i++)
    {
      
if (strcmp (funcionarios[i].nome, nomeFuncionario) == 0)
	{
	  
printf ("Digite a mensagem para o funcionario %s: ",
		   funcionarios[i].nome);
	  
char mensagem[200];
	  
scanf (" %[^\n]", mensagem);
	  
printf ("Mensagem enviada para o funcionario %s: %s\n",
		   funcionarios[i].nome, mensagem);
	  
funcionarioEncontrado = 1;
	  
break;
	
}
    
}
  
 
if (!funcionarioEncontrado)
    {
      
printf ("Funcionario nao encontrado.\n");
    
}

}


 
int
main ()
{
  
struct Funcionario funcionarios[100];
  
struct Entrega entregas[100];
  
int numFuncionarios = 0;
  
int numEntregas = 0;
  
 
int escolhaPrincipal;
  
  do
    {
      
printf ("\nMenu Principal:\n");
      
printf ("1. Funcionarios\n");
      
printf ("2. Entregas\n");
      
printf ("3. Comunicacoes\n");
      
printf ("0. Sair\n");
      
printf ("Escolha uma opcao: ");
      
scanf ("%d", &escolhaPrincipal);
      
 
switch (escolhaPrincipal)
	{
	
case 1:
	  
int escolhaFuncionarios;
	  
	  do
	    {
	      
printf ("\nMenu Funcionarios:\n");
	      
printf ("1. Adicionar funcionario\n");
	      
printf ("2. Listar funcionarios\n");
	      
printf ("3. Voltar\n");
	      
printf ("Escolha uma opcao: ");
	      
scanf ("%d", &escolhaFuncionarios);
	      
 
switch (escolhaFuncionarios)
		{
		
case 1:
		  
adicionarFuncionario (funcionarios, &numFuncionarios);
		  
break;
		
case 2:
		  
listarFuncionarios (funcionarios, numFuncionarios);
		  
break;
		
case 3:
		  
break;
		
default:
		  
printf ("Opcao invalida.\n");
		  
break;
		
}
	    
}
	  while (escolhaFuncionarios != 3);
	  
break;
	
case 2:
	  
int escolhaEntregas;
	  
	  do
	    {
	      
printf ("\nMenu Entregas:\n");
	      
printf ("1. Adicionar entrega\n");
	      
printf ("2. Listar entregas\n");
	      
printf ("3. Voltar\n");
	      
printf ("Escolha uma opcao: ");
	      
scanf ("%d", &escolhaEntregas);
	      
 
switch (escolhaEntregas)
		{
		
case 1:
		  
adicionarEntrega (entregas, &numEntregas, funcionarios,
				     numFuncionarios);
		  
break;
		
case 2:
		  
listarEntregas (entregas, numEntregas);
		  
break;
		
case 3:
		  
break;
		
default:
		  
printf ("Opcao invalida.\n");
		  
break;
		
}
	    
}
	  while (escolhaEntregas != 3);
	  
break;
	
case 3:
	  
int escolhaComunicacoes;
	  
	  do
	    {
	      
printf ("\nMenu Comunicacoes:\n");
	      
printf ("1. Entrar em contato com funcionario\n");
	      
printf ("2. Voltar\n");
	      
printf ("Escolha uma opcao: ");
	      
scanf ("%d", &escolhaComunicacoes);
	      
 
switch (escolhaComunicacoes)
		{
		
case 1:
		  
entrarContatoFuncionario (funcionarios, numFuncionarios);
		  
break;
		
case 2:
		  
break;
		
default:
		  
printf ("Opcao invalida.\n");
		  
break;
		
}
	    
}
	  while (escolhaComunicacoes != 2);
	  
break;
	
case 0:
	  
printf ("Saindo do programa...\n");
	  
break;
	
default:
	  
printf ("Opcao invalida.\n");
	  
break;
	
}
    
}
  while (escolhaPrincipal != 0);
  
 
return 0;

}


