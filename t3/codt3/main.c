#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct item
{
    unsigned long long chave;
    int valor;
} item;

void imprime(item *v, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", v[i].valor);
    printf("\n\n");
}

unsigned long long DistanciaGenomica(int n, int *v, int *w)
{
    unsigned long long cont = 0;
    item aux;
    int f, achou, pos_ult_inv, lim_dir;
    item x[n];
    item y[n];

    for (int i = 0; i < n; i++)
    {
        x[i].chave = i + 1;
        x[i].valor = v[i];
        y[i].valor = w[i];
    }

    for (int i = 0; i < n; i++)
    {
        f = 0;
        achou = 0;
        while (achou == 0)
        {
            if (x[i].valor == y[f].valor)
            {
                y[f].chave = x[i].chave;
                achou = 1;
            }
            f++;
        }
    }

    //bubbleSort
    lim_dir = n;
    for (int j = 0; j < n; j++)
    {
        pos_ult_inv = 0;
        for (int i = 1; i < lim_dir; i++){
            if (y[i - 1].chave > y[i].chave)
            {
                aux = y[i - 1];
                y[i - 1] = y[i];
                y[i] = aux;
                pos_ult_inv = i;
                cont++;
            }
        }
        lim_dir = pos_ult_inv;
    }
    return cont;
}

int main(int argc, char *argv[])
{
    char file_name[MAX];
    FILE *entrada;
    int i, n;
    unsigned long long num_inv = 0;

    if (argc != 1)
    {
        printf("Numero incorreto de parametros. Ex: .\\nome_arquivo_executavel\n");
        return 0;
    }
    scanf("%s", file_name);
    entrada = fopen(file_name, "r");
    if (entrada == NULL)
    {
        printf("\nNao encontrei o arquivo! Informe o nome da instancia\n");
        exit(EXIT_FAILURE);
    }
    // lendo do arquivo da instância
    fscanf(entrada, "%d", &n);
    int *v = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        fscanf(entrada, "%d", &v[i]);
    // imprime(v, n);
    int *w = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        fscanf(entrada, "%d", &w[i]);
    // imprime(w, n);
    // crie uma funcao que calcule o numero de inversoes entre v e w

    num_inv = DistanciaGenomica(n, &v[0], &w[0]);

    // printf("%I64u\n", num_inv);
    printf("%llu\n", num_inv);

    free(v);
    free(w);

    fclose(entrada);
    return 0;
}
