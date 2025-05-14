// Informações do estudante
// Nome: Daniel de Souza Sobrinho Macedo 
// Curso: Ciência da Computação (BCC)
// RA: 813524

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int palindromoR(int i, int f, char *s)
{
    int z;

    if (s[i] == s[f])
    {
        if(f - i <= 1)
            z = 1;
        else
            z = palindromoR(i+1, f-1, s);
    }
    else
    {
        z = 0;
    }
     return z;
}

void palindromo(char *s)
{
    int saida = palindromoR(0, strlen(s) - 1, s);

    if (saida)
    {
        printf("eh palindromo\n");
    }
    else
    {
        printf("nao eh palindromo\n");
    }
}

void inversaR(char *str)
{
    // implemente essa função recursiva
    if (*str != '\0')
    {
        inversaR(str + 1);
        printf("%c", *str);
    }
    else
        return;
}

void inversa(char *s)
{
    inversaR(s);
    printf("\n");
}

unsigned long stirlingR(unsigned long n, unsigned long k)
{
    // implemente essa função recursiva
    if (n == 0 && k == 0)
        return 1;
    
    else if (n == 0 || k == 0)
        return 0;
    
    else
        return (n - 1) * stirlingR(n - 1, k) + stirlingR(n - 1, k - 1);
    
}

void stirling(int n, int k)
{
    printf("%lu\n", stirlingR(n, k));
}

void padraoR(unsigned n)
{
    // implemente essa função recursiva
   if (n != 0)
    {
        printf("%u", n);
        padraoR(n - 1);
        printf("%u", n);
    }
    else
    printf("%u%u", 0, 0);
        return;
    
}

void padrao(unsigned n)
{
    padraoR(n);
    printf("\n");
}

int main(int argc, char *argv[])
{
    char file_name[MAX], aux[MAX];
    FILE *entrada;
    int t, a, b;

    scanf("%s", file_name);
    entrada = fopen(file_name, "r");
    if (entrada == NULL)
    {
        printf("Nao encontrei o arquivo!");
        exit(EXIT_FAILURE);
    }

    fscanf(entrada, "%d", &t);

    if (t < 1 || t > 4)
    {
        printf("Parametros incorretos.\n");
        printf("Ex:\n");
        printf("tp01_recursao 1 [para testar palindromo]\n");
        printf("tp01_recursao 2 [para testar inversa]\n");
        printf("tp01_recursao 3 [para testar Stirling]\n");
        printf("tp01_recursao 4 [para testar padrao]\n");
    }

    if (t == 1)
    {
        printf("\nTestando palindromo()\n\n");
        fscanf(entrada, "%s", aux);
        while (aux[0] != '.')
        {
            palindromo(aux);
            fscanf(entrada, "%s", aux);
        }
    }
    else if (t == 2)
    {
        printf("\nTestando inversa()\n\n");
        fscanf(entrada, "%s", aux);
        while (aux[0] != '.')
        {
            inversa(aux);
            fscanf(entrada, "%s", aux);
        }
    }
    else if (t == 3)
    {
        printf("\nTestando Stirling()\n\n");
        fscanf(entrada, "%d %d", &a, &b);
        while (a != -1)
        {
            stirling(a, b);
            fscanf(entrada, "%d %d", &a, &b);
        }
    }
    else if (t == 4)
    {
        printf("\nTestando padrao()\n\n");

        fscanf(entrada, "%d", &a);
        while (a != -1)
        {
            padrao(a);
            fscanf(entrada, "%d", &a);
        }
    }

    return 0;
}
