/*
ESTA ES LA INFORMACION PROPORCIONADA POR EL GIT STATUS:
usuario@LAPTOP-QCK9SD3E MINGW64 ~/Documents/myPenDrive/Taller de Lenguaje I/2020/ALEXIS ALE TRABAJO PRACTICO 2/tpn2-alexistuc (Opcion_2)
$ git status
On branch Opcion_2
nothing to commit, working tree clean
*/

/*
d) En el archivo tp2_1_2.cpp escriba el código anterior, pero con aritmética de punteros para
recorrer la matriz. 
*/
//bibliotecas
#include<stdio.h>
#include<stdlib.h>
//variables superglobales
#define N 4
#define M 5
//funcion principal
int main()
{  
    int f,c;
    double mt[N][M];
    double *pMT;//declaro el puntero
    pMT = &mt[0][0];//el puntero debe apuntar a la direccion del primer elemento de la matriz
    
    //fabrico la matriz, de lo contrario obtendre basura en cada elemento. la fabrico a traves del puntero
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
          {
              *pMT = (double)(i+j);
              //printf("%.lf ", *pMT); con esta linea podria directemente imprimir los resultados desde el puntero
              pMT++;              
          }  
    }

    //imprimo la matriz con notacion sub-indexada
    printf("La matriz con notacion sub-indexada: \n");
    for(f = 0;f < N; f++)
    {
        for(c = 0; c < M; c++)
        {
            printf(" %.1f ", mt[f][c]);
        }
        printf("\n");
    }

    printf("\n----------------------------------------\n");

    //imprimo la matriz con el puntero
    printf("La matriz con el puntero: \n");
    pMT = &mt[0][0];//regreso el puntero al primer elemento de la matriz
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            printf(" %.1f ", *pMT);//imprimo el valor de lo apuntado
            pMT++;//voy corriedo hacia el siguiente valor
        }
        printf("\n");
    }

    //final del programa
    printf("\n");
    getchar();
    return 0;
}
