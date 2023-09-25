# PyBoy
Projeto de programação
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Funcionario {
    char nome[50];
} Funcionario;

typedef struct Entrega {
    Funcionario *funcionario;
    char endereco[100];
} Entrega;

Funcionario *funcionarios[100];
Entrega *entregas[100];

int numFuncionarios = 0;
int numEntregas = 0;

void printLine() {
    for (int i = 0; i < 50; i++) printf("#");
    printf("\n");
}

void printMenu(char *title, char *options[], int numOptions) {
    printLine();
    printf("# %s\n", title);
    printLine();
    for (int i = 0; i < numOptions; i++) {
        printf("# %d. %s\n", i + 1, options[i]);
    }
    printLine();
}

void adicionarFuncionario() {
    Funcionario *f = malloc(sizeof(Funcionario));
    printf("Digite o nome do funcionário: ");
    scanf("%s", f->nome);
    funcionarios[numFuncionarios++] = f;
}

void listarFuncionarios() {
    for (int i = 0; i < numFuncionarios; i++) {
        printf("%s\n", funcionarios[i]->nome);
    }
}

void demitirFuncionario() {
    char nome[50];
    printf("Digite o nome do funcionário a ser demitido: ");
    scanf("%s", nome);
    for (int i = 0; i < numFuncionarios; i++) {
        if (strcmp(funcionarios[i]->nome, nome) == 0) {
            free(funcionarios[i]);
            for (int j = i; j < numFuncionarios - 1; j++) {
                funcionarios[j] = funcionarios[j + 1];
            }
            numFuncionarios--;
            break;
        }
    }
}

void adicionarEntrega() {
    Entrega *e = malloc(sizeof(Entrega));
    char nome[50];
    printf("Digite o nome do funcionário para a entrega: ");
    scanf("%s", nome);
    for (int i = 0; i < numFuncionarios; i++) {
        if (strcmp(funcionarios[i]->nome, nome) == 0) {
            e->funcionario = funcionarios[i];
            break;
        }
    }
    printf("Digite o endereço da entrega: ");
    scanf("%s", e->endereco);
    entregas[numEntregas++] = e;
}

void listarEntregas() {
    for (int i = 0; i < numEntregas; i++) {
        printf("Funcionário: %s, Endereço: %s\n", entregas[i]->funcionario->nome, entregas[i]->endereco);
    }
}

void concluirEntrega() {
    char endereco[100];
    printf("Digite o endereço da entrega concluída: ");
    scanf("%s", endereco);
    for (int i = 0; i < numEntregas; i++) {
        if (strcmp(entregas[i]->endereco, endereco) == 0) {
            free(entregas[i]);
            for (int j = i; j < numEntregas - 1; j++) {
                entregas[j] = entregas[j + 1];
            }
            numEntregas--;
            break;
        }
    }
}

void enviarMensagem() {
    char nome[50];
    printf("Digite o nome do funcionário para enviar uma mensagem: ");
    scanf("%s", nome);
    for (int i = 0; i < numFuncionarios; i++) {
        if (strcmp(funcionarios[i]->nome, nome) == 0) {
            char mensagem[100];
            printf("Digite a mensagem: ");
            scanf("%s", mensagem);
            printf("Mensagem para %s: %s\n", nome, mensagem);
            break;
        }
    }
}

int main() {
    
char *menuPrincipal[] = {"Funcionários", "Entregas", "Comunicação", "Sair"};
char *menuFuncionarios[] = {"Adicionar Funcionário", "Listar Funcionários", "Demitir Funcionário", "Voltar"};
char *menuEntregas[] = {"Adicionar Entrega", "Listar Entregas", "Concluir Entrega", "Voltar"};

while (1) {

printMenu("Menu Principal", menuPrincipal, 4);

int opcao;
scanf("%d", &opcao);

switch (opcao) {

case 1:
printMenu("Menu Funcionários", menuFuncionarios, 4);
scanf("%d", &opcao);
switch (opcao) {
case 1:
adicionarFuncionario();
break;
case 2:
listarFuncionarios();
break;
case 3:
demitirFuncionario();
break;
case 4:
break;
}
break;

case 2:
printMenu("Menu Entregas", menuEntregas, 4);
scanf("%d", &opcao);
switch (opcao) {
case 1:
adicionarEntrega();
break;
case 2:
listarEntregas();
break;
case 3:
concluirEntrega();
break;
case 4:
break;
}
break;

case 3:
enviarMensagem();
break;

case 4:
return 0;

}
}
}
