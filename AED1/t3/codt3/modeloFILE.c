#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void imprime(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
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
    num_inv = 0;

    // printf("%I64u\n", num_inv);
    printf("%llu\n", num_inv);

    free(v);
    free(w);

    fclose(entrada);
    return 0;
}
