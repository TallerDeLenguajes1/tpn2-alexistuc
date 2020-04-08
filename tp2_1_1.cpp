//bibliotecas
#include<stdio.h>
#include<stdlib.h>
//variables superglobales
#define N 4
#define M 5
//funcion principal
int main(int argc, char const *argv[])
{  
    int f,c;
    double mt[N][M];
    //...
    for(f = 0;f<N; f++)
    {
        for(f = 0;f<N; f++)
        {
        printf("%lf", mt[f][c]);
        }
        printf("\n");
    }
    /* code */
    getchar();
    return 0;
}