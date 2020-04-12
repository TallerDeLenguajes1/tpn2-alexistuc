/*
3) Escribe un programa en el que se cargue una matriz de 15 filas con números enteros
aleatorios entre 100 y 999. Cada fila se cargará en forma dinámica. La cantidad de
columnas estará dada por un número aleatorio entre [5, 15]. Mostrar por pantalla la matriz.
a) Luego determinar para cada fila cuántos números son pares.
b) Por último, generar un nuevo vector dinámico de 15 elementos con la cantidad de
pares por fila obtenidos en el punto anterior.
c) Subir los cambios al repositorio remoto.
*/

//bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<time.h>//esta biblioteca carga la semilla para los numeros aleatorios

//variables superglobales
#define filas 15

//funcion principal
int main()
{
	srand (time(NULL));//semilla para generar numeros aleatorios
	int columnas = rand() % 11 + 5;//las columnas deben ser aleatorias entre 5 y 15
	int matrizAleatoria[filas][columnas];
	for (int i = 0; i < filas; ++i)
	{
		for (int j = 0; j < columnas; ++j)
		{
			//srand(time(NULL));
			matrizAleatoria[i][j] = rand() % 1000 + 100;
			printf(" %.4d ", matrizAleatoria[i][j]);
		}
		printf("\n");
	}


	/* code */
	getchar();
	return 0;
}
