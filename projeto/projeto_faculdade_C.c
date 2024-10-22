#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_USERS 100
#define MAX_NAME 50
#define MAX_PASSWORD 20

//Armazenamento de dados do usuário
typedef struct {
    char nome[MAX_NAME];
    char senha[MAX_PASSWORD];
    int ativo;
} Usuario;

Usuario usuarios[MAX_USERS];
int totalUsuarios = 0;

// Funções
void cadastrarUsuario() {
    if (totalUsuarios >= MAX_USERS) {
        printf("Limite de usuários atingido!\n");
        return;
    }

    printf("Cadastro de novo usuário\n");
    printf("Nome: ");
    scanf("%s", usuarios[totalUsuarios].nome);
    printf("Senha: ");
    scanf("%s", usuarios[totalUsuarios].senha);

    usuarios[totalUsuarios].ativo = 1; //usuário em atividade
    totalUsuarios++;
    printf("Usuário cadastrado com sucesso!\n");
}

void alterarSenha() {
    char nome[MAX_NAME], senhaAtual[MAX_PASSWORD], novaSenha[MAX_PASSWORD];
    int i, encontrado = 0;

    printf("Alteração de senha\n");
    printf("Nome do usuário: ");
    scanf("%s", nome);

    for (i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuarios[i].nome, nome) == 0 && usuarios[i].ativo) {
            encontrado = 1;
            printf("Senha atual: ");
            scanf("%s", senhaAtual);

            if (strcmp(usuarios[i].senha, senhaAtual) == 0) {
                printf("Nova senha: ");
                scanf("%s", novaSenha);
                strcpy(usuarios[i].senha, novaSenha);
                printf("Senha alterada com sucesso!\n");
            } else {
                printf("Senha atual incorreta!\n");
            }
            break;
        }
    }

    if (!encontrado) {
        printf("Usuário não encontrado!\n");
    }
}

void realizarLogin() {
    char nome[MAX_NAME], senha[MAX_PASSWORD];
    int i, sucesso = 0;

    printf("Login\n");
    printf("Nome: ");
    scanf("%s", nome);
    printf("Senha: ");
    scanf("%s", senha);

    for (i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuarios[i].nome, nome) == 0 && strcmp(usuarios[i].senha, senha) == 0 && usuarios[i].ativo) {
            printf("Login realizado com sucesso! Bem-vindo(a) %s!\n", nome);
            sucesso = 1;
            break;
        }
    }

    if (!sucesso) {
        printf("Nome ou senha incorretos ou usuário não ativo!\n");
    }
}

void excluirUsuario() {
    char nome[MAX_NAME];
    int i, encontrado = 0;

    printf("Exclusão de usuário\n");
    printf("Nome do usuário: ");
    scanf("%s", nome);

    for (i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuarios[i].nome, nome) == 0 && usuarios[i].ativo) {
            usuarios[i].ativo = 0; //deixar usuário inativo
            encontrado = 1;
            printf("Usuário %s excluído com sucesso!\n", nome);
            break;
        }
    }

    if (!encontrado) {
        printf("Usuário não encontrado!\n");
    }
}

void exibirMenu() {
    printf("=== MENU ===\n");
    printf("1 - Cadastrar novo usuário\n");
    printf("2 - Alterar senha\n");
    printf("3 - Realizar login\n");
    printf("4 - Excluir usuário\n");
    printf("5 - Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    int opcao;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarUsuario();
                break;
            case 2:
                alterarSenha();
                break;
            case 3:
                realizarLogin();
                break;
            case 4:
                excluirUsuario();
                break;
            case 5:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }

        printf("\n");
    } while (opcao != 5);

    return 0;
}