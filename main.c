#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_CONTAS 5

typedef struct
{
    int numero;
    char cliente[510];
    int especial;
    float saldo;
} Conta;

void inserir(Conta *contas, int *totalContas)
{
    char aux[51];

    srand(time(NULL));

    if (*totalContas >= MAX_CONTAS)
    {
        printf("Limite de contas atingido! \n");
        return;
    }

    Conta novaConta;

    printf("Numero da conta: %d \n", novaConta.numero = rand());
    fflush(stdin);
    // printf("Numero da conta: \n");
    // scanf("%d", &novaConta.numero);

    // Verifica se o numero da conta já existe. Seria uma validação de segurança, pois usando a função rand com base no relogio, o número nunca se repetira.
    for (int i = 0; i < *totalContas; i++)
    {
        if (contas[i].numero == novaConta.numero)
        {
            printf("Ja existe uma conta com este numero! \n");
            return;
        }
    }

    printf("Nome do cliente (Apenas primeiro nome): ");
    fgets(novaConta.cliente, sizeof(novaConta.cliente), stdin);

    printf("Conta especial (1 - Sim, 0 - Nao): ");
    scanf("%d", &novaConta.especial);

    printf("Saldo atual: ");
    scanf("%f", &novaConta.saldo);

    contas[*totalContas] = novaConta;
    (*totalContas)++;

    printf("Conta inserida com sucesso! \n");
}

void alterar(Conta *contas, int totalContas)
{

    int numeroConta;

    if (totalContas == 0)
    {
        printf("Nenhuma conta foi adicionada ainda!");
        return;
    }
    else
    {
        printf("Digite o numero da conta a ser alterada: ");
        scanf("%d", &numeroConta);
        fflush(stdin);

        for (int i = 0; i < totalContas; i++)
        {
            if (contas[i].numero == numeroConta)
            {
                printf("Novo nome do cliente: ");
                fgets(contas[i].cliente, sizeof(contas[i].cliente), stdin);

                printf("Conta especial (1 - Sim, 0 - Nao): ");
                scanf("%d", &contas[i].especial);

                printf("Dados da conta alterados com sucesso!\n");
                return;
            }
        }
    }

    printf("Conta nao encontrada!\n");
}

void procurar(Conta *contas, int totalContas)
{
    int numeroConta;

    printf("Digite o numero da conta a ser procurada: ");
    scanf("%d", &numeroConta);

    for (int i = 0; i < totalContas; i++)
    {
        if (contas[i].numero == numeroConta)
        {
            printf("Numero da conta: %d \n", contas[i].numero);
            printf("Nome do cliente: %s \n", contas[i].cliente);
            printf("Tipo de conta: %s \n", contas[i].especial ? "Especial" : "Normal");
            printf("Saldo atual: %.2f \n", contas[i].saldo);
            return;
        }
    }

    printf("Conta nao encontrada! \n");
}

void listar(Conta *contas, int totalContas)
{

    if (totalContas == 0)
    {
        printf("Nenhuma conta cadastrada! \n");
        return;
    }

    printf("Total de contas cadastradas: %d \n", totalContas);

    for (int i = 0; i < totalContas; i++)
    {
        printf("Numero da conta: %d \n", contas[i].numero);
        printf("Nome do cliente: %s \n", contas[i].cliente);
        printf("Tipo de conta: %s \n", contas[i].especial ? "Especial" : "Normal");
        printf("Saldo atual: %.2f \n", contas[i].saldo);
        printf("-------------------------\n");
    }
}

void depositar(Conta *contas, int totalContas)
{

    int numeroConta;
    float valor;

    printf("Digite o numero da conta para deposito: ");
    scanf("%d", &numeroConta);

    for (int i = 0; i < totalContas; i++)
    {
        // Faço uma busca para encontrar a conta digitada acima
        if (contas[i].numero == numeroConta)
        {
            printf("Digite o valor do deposito: ");
            scanf("%f", &valor);

            // Valida se o valor digitado é negativo ou menor que 0
            if (valor <= 0)
            {
                printf("Valor invalido para deposito!\n");
                return;
            }

            contas[i].saldo += valor;
            printf("Deposito realizado com sucesso!\n");
            return;
        }
    }

    printf("Conta nao encontrada!\n");
}

void sacar(Conta *contas, int totalContas)
{

    int numeroConta;
    float valor;

    printf("Digite o numero da conta para saque: ");
    scanf("%d", &numeroConta);

    // Faço uma busca para encontrar a conta digitada acima
    for (int i = 0; i < totalContas; i++)
    {
        if (contas[i].numero == numeroConta)
        {
            printf("Digite o valor do saque: ");
            scanf("%f", &valor);

            if (valor <= 0)
            {
                printf("Valor invalido para saque!\n");
                return;
            }

            if (valor > contas[i].saldo)
            {
                printf("Saldo insuficiente!\n");
                return;
            }

            contas[i].saldo -= valor;
            printf("Saque realizado com sucesso!\n");
            return;
        }
    }

    printf("Conta nao encontrada!\n");
}

void imprimir(Conta *contas, int totalContas)
{

    int numeroConta;
    printf("Digite o numero da conta a ser impressa: ");
    scanf("%d", &numeroConta);

    for (int i = 0; i < totalContas; i++)
    {
        if (contas[i].numero == numeroConta)
        {
            printf("Numero da conta: %d \n", contas[i].numero);
            printf("Nome do cliente: %s \n", contas[i].cliente);
            printf("Tipo de conta: %s \n", contas[i].especial ? "Especial" : "Normal");
            printf("Saldo atual: %.2f \n", contas[i].saldo);
            return;
        }
    }

    printf("Conta não encontrada!\n");
}

void saldoGeral(Conta *contas, int totalContas)
{

    float saldoTotal = 0;

    for (int i = 0; i < totalContas; i++)
    {
        saldoTotal += contas[i].saldo;
    }

    printf("Saldo total de todas as contas: %.2f\n", saldoTotal);
}

int main()
{
    Conta contas[MAX_CONTAS];
    int totalContas = 0;
    int opcao;

    do
    {
        printf("\n -----Menu ----- \n");
        printf("1. Inserir nova conta \n");
        printf("2. Alterar dados de uma conta \n");
        printf("3. Procurar uma conta \n");
        printf("4. Listar todas as contas \n");
        printf("5. Realizar deposito \n");
        printf("6. Realizar saque \n");
        printf("7. Imprimir dados de uma conta \n");
        printf("8. Mostrar saldo geral \n");
        printf("0. Sair \n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            inserir(contas, &totalContas);
            break;
        case 2:
            alterar(contas, totalContas);
            break;
        case 3:
            procurar(contas, totalContas);
            break;
        case 4:
            listar(contas, totalContas);
            break;
        case 5:
            depositar(contas, totalContas);
            break;
        case 6:
            sacar(contas, totalContas);
            break;
        case 7:
            imprimir(contas, totalContas);
            break;
        case 8:
            saldoGeral(contas, totalContas);
            break;
        case 0:
            printf("Encerrando o programa...\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}