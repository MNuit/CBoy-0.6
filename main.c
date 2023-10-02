#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
} Funcionario;

typedef struct {
    char cpf[12];
    char nome[50];
    char endereco[100];
} Cliente;

typedef struct {
    int idFuncionario;
    char cpfCliente[12];
    int concluida;
} Entrega;

typedef struct {
    char remetente[50];
    char destinatario[50];
    char mensagem[500];
} Mensagem;

void adicionarFuncionario(Funcionario funcionarios[], int *numFuncionarios) {
    printf("Digite o nome do funcionário: ");
    scanf("%s", funcionarios[*numFuncionarios].nome);
    funcionarios[(*numFuncionarios)++].id = *numFuncionarios;
    printf("Funcionário adicionado com sucesso.\n");
}

void listarFuncionarios(Funcionario funcionarios[], int numFuncionarios) {
    printf("Lista de Funcionários:\n");
    for (int i = 0; i < numFuncionarios; i++) {
        printf("ID: %d, Nome: %s\n", funcionarios[i].id, funcionarios[i].nome);
    }
}

void adicionarCliente(Cliente clientes[], int *numClientes) {
    printf("Digite o nome do cliente: ");
    scanf("%s", clientes[*numClientes].nome);
    printf("Digite o CPF do cliente: ");
    scanf("%s", clientes[*numClientes].cpf);
    printf("Digite o endereço do cliente: ");
    getchar();
    fgets(clientes[*numClientes].endereco, sizeof(clientes[*numClientes].endereco), stdin);
    clientes[*numClientes].endereco[strcspn(clientes[*numClientes].endereco, "\n")] = '\0';
    printf("Cliente adicionado com sucesso.\n");
    (*numClientes)++;
}

void listarClientes(Cliente clientes[], int numClientes) {
    printf("Lista de Clientes:\n");
    for (int i = 0; i < numClientes; i++) {
        printf("CPF: %s, Nome: %s, Endereço: %s\n", clientes[i].cpf, clientes[i].nome, clientes[i].endereco);
    }
}

void adicionarEntrega(Entrega entregas[], int *numEntregas, Funcionario funcionarios[], int numFuncionarios, Cliente clientes[], int numClientes) {
    printf("Digite o CPF do cliente: ");
    scanf("%s", entregas[*numEntregas].cpfCliente);

    int idFuncionario;
    int encontrado = 0;

    for (int i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].cpf, entregas[*numEntregas].cpfCliente) == 0) {
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Cliente não encontrado.\n");
        return;
    }

    printf("Digite o ID do funcionário responsável: ");
    scanf("%d", &idFuncionario);

    encontrado = 0;
    for (int i = 0; i < numFuncionarios; i++) {
        if (funcionarios[i].id == idFuncionario) {
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Funcionário não encontrado.\n");
        return;
    }

    entregas[(*numEntregas)++].idFuncionario = idFuncionario;
    entregas[*numEntregas - 1].concluida = 0;
    printf("Entrega adicionada com sucesso.\n");
}

void listarEntregas(Entrega entregas[], int numEntregas, Funcionario funcionarios[], int numFuncionarios, Cliente clientes[], int numClientes) {
    printf("Entregas em Andamento:\n");
    for (int i = 0; i < numEntregas; i++) {
        printf("ID Funcionário: %d, CPF Cliente: %s, Concluída: %s\n",
               entregas[i].idFuncionario, entregas[i].cpfCliente,
               entregas[i].concluida ? "Sim" : "Não");

        char nomeFuncionario[50];
        char nomeCliente[50];

        for (int j = 0; j < numFuncionarios; j++) {
            if (funcionarios[j].id == entregas[i].idFuncionario) {
                strcpy(nomeFuncionario, funcionarios[j].nome);
                break;
            }
        }

        for (int j = 0; j < numClientes; j++) {
            if (strcmp(clientes[j].cpf, entregas[i].cpfCliente) == 0) {
                strcpy(nomeCliente, clientes[j].nome);
                break;
            }
        }

        printf("Nome Funcionário: %s, Nome Cliente: %s\n", nomeFuncionario, nomeCliente);
    }
}

void enviarMensagem(Mensagem mensagens[], int *numMensagens, Funcionario funcionarios[], int numFuncionarios, Cliente clientes[], int numClientes) {
    Mensagem novaMensagem;
    int opcaoDestinatario;
    int encontrado = 1;

    printf("Escolha o destinatário:\n");
    printf("1. Funcionário (usando ID)\n");
    printf("2. Cliente (usando CPF)\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcaoDestinatario);

    switch (opcaoDestinatario) {
        case 1:
            printf("Digite o ID do funcionário destinatário: ");
            scanf("%d", &novaMensagem.destinatario);

            for (int i = 0; i < numFuncionarios; i++) {
                if (funcionarios[i].id == novaMensagem.destinatario) {
                    encontrado = 1;
                    break;
                }
            }
            break;

        case 2:
            printf("Digite o CPF do cliente destinatário: ");
            scanf("%s", novaMensagem.destinatario);

            for (int i = 0; i < numClientes; i++) {
                if (strcmp(clientes[i].cpf, novaMensagem.destinatario) == 0) {
                    encontrado = 1;
                    break;
                }
            }
            break;

        default:
            printf("Opção inválida.\n");
            return;
    }

    if (!encontrado) {
        printf("Destinatário não encontrado.\n");
        return;
    }

    printf("Digite a mensagem: ");
    getchar();
    fgets(novaMensagem.mensagem, sizeof(novaMensagem.mensagem), stdin);
    novaMensagem.mensagem[strcspn(novaMensagem.mensagem, "\n")] = '\0';
    strcpy(novaMensagem.remetente, "Remetente Padrão");
    mensagens[(*numMensagens)++] = novaMensagem;
    printf("Mensagem enviada com sucesso.\n");
}

void listarMensagens(Mensagem mensagens[], int numMensagens) {
    printf("Lista de Mensagens:\n");
    for (int i = 0; i < numMensagens; i++) {
        printf("Remetente: %s, Destinatário: %s\n", mensagens[i].remetente, mensagens[i].destinatario);
        printf("Mensagem: %s\n", mensagens[i].mensagem);
    }
}

int main() {
    Funcionario funcionarios[100];
    Cliente clientes[100];
    Entrega entregas[100];
    Mensagem mensagens[100];
    int numFuncionarios = 0;
    int numClientes = 0;
    int numEntregas = 0;
    int numMensagens = 0;
    int opcao;
    int idEntrega;

    do {
        printf("\n*** Menu Principal ***\n");
        printf("1. Funcionários\n");
        printf("2. Clientes\n");
        printf("3. Entregas\n");
        printf("4. Comunicações\n");
        printf("5. Fechar o programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n*** Menu de Funcionários ***\n");
                printf("1. Adicionar Funcionário\n");
                printf("2. Listar Funcionários\n");
                printf("3. Voltar ao Menu Principal\n");
                printf("Escolha uma opção: ");
                scanf("%d", &opcao);
                switch (opcao) {
                    case 1:
                        adicionarFuncionario(funcionarios, &numFuncionarios);
                        break;
                    case 2:
                        listarFuncionarios(funcionarios, numFuncionarios);
                        break;
                }
                break;

            case 2:
                printf("\n*** Menu de Clientes ***\n");
                printf("1. Adicionar Cliente\n");
                printf("2. Listar Clientes\n");
                printf("3. Voltar ao Menu Principal\n");
                printf("Escolha uma opção: ");
                scanf("%d", &opcao);
                switch (opcao) {
                    case 1:
                        adicionarCliente(clientes, &numClientes);
                        break;
                    case 2:
                        listarClientes(clientes, numClientes);
                        break;
                }
                break;

            case 3:
                printf("\n*** Menu de Entregas ***\n");
                printf("1. Adicionar Entrega\n");
                printf("2. Listar Entregas em Andamento\n");
                printf("3. Marcar Entrega como Concluída\n");
                printf("4. Voltar ao Menu Principal\n");
                printf("Escolha uma opção: ");
                scanf("%d", &opcao);
                switch (opcao) {
                    case 1:
                        adicionarEntrega(entregas, &numEntregas, funcionarios, numFuncionarios, clientes, numClientes);
                        break;
                    case 2:
                        listarEntregas(entregas, numEntregas, funcionarios, numFuncionarios, clientes, numClientes);
                        break;
                    case 3:
                        printf("Digite o ID da entrega a ser marcada como concluída: ");
                        scanf("%d", &idEntrega);
                        for (int i = 0; i < numEntregas; i++) {
                            if (entregas[i].idFuncionario == idEntrega) {
                                entregas[i].concluida = 1;
                                printf("Entrega marcada como concluída.\n");
                                break;
                            }
                        }
                        break;
                }
                break;

            case 4:
                printf("\n*** Menu de Comunicações ***\n");
                printf("1. Enviar Mensagem\n");
                printf("2. Listar Mensagens\n");
                printf("3. Voltar ao Menu Principal\n");
                printf("Escolha uma opção: ");
                scanf("%d", &opcao);
                switch (opcao) {
                    case 1:
                        enviarMensagem(mensagens, &numMensagens, funcionarios, numFuncionarios, clientes, numClientes);
                        break;
                    case 2:
                        listarMensagens(mensagens, numMensagens);
                        break;
                }
                break;

            case 5:
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
