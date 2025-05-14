// Informações do estudante
// Nome: Daniel de Souza Sobrinho Macedo 
// Curso: Ciência da Computação (BCC)
// RA: 813524

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int resolveJosephus(int n, int m){
    int circulo[n];
    int vivos = n;
    int cont;
    int prox = 0;
    int atual = 0;

    for(int i = 0; i < n; i++){
        circulo[i] = 1;
    }

    while (vivos != 1)
    {   
        cont = 0;
        
        while(cont < m){
            prox++;
            if (prox >= n){
                prox = prox - n;
            }
            if(circulo[prox] == 1){
                cont++;
            }
        }  
        
        if(prox == atual){
            prox++;
            if (prox >= n){
                prox = prox - n;
            }
            circulo[prox] = 0;
        }

        //printf("morreu %d ", prox+1);
        while(circulo[prox] == 0){
            prox++;
            if (prox >= n){
                prox = prox - n;
            }
        }

        atual = prox;
        vivos--;
        //printf("proximo assasino %d\n", prox+1);
    }

    return atual+1;
}

int main () {
    int nroexecs ;

    scanf ("%d", & nroexecs ) ;
    int * n = malloc ( nroexecs * sizeof (int ) ) ;
    int * m = malloc ( nroexecs * sizeof (int ) ) ;

    for (int i = 0; i < nroexecs ; i ++) {
        scanf ("%d", & n [ i ]) ;
        scanf ("%d", & m [ i ]) ;
    }

    for (int i = 0; i < nroexecs ; i ++) {
        printf ("Usando n=%d, m=%d, resultado=%d\n", n [ i ] , m [ i ] , resolveJosephus ( n [ i ] , m [ i ]) ) ;
    }

    return 0;
 }
