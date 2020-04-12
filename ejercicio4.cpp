/*
4) Declara un tipo de dato estructura:
d) Para representar a una PC; los campos serán: velocidad de procesamiento en GHz, año
de fabricación, tipo de procesador, cantidad de núcleos.
e) Considera valores enteros aleatorios para la velocidad: entre 1 y 3, para el año: entre 2000
y 2017, para la cantidad de núcleos: entre 1 y 4.
f) Para evitar ingresar por teclado los tipos de procesador, considera que estos se encuentran
en un arreglo de cadenas de caracteres:
char tipos[6][10]={“Intel”, “AMD”, “Celeron”, “Athlon”, “Core”, “Pentium”}
La estructura será la siguiente:
struct compu {
int velocidad;//entre 1 y 3 Gherz
int anio;//entre 2000 y 2017
int cantidad;//entre 1 y 4
char *tipo_cpu;//valores del arreglo tipos
};
g) Define una variable del tipo arreglo de estructura para guardar las características (punto a)
de la cantidad de PC que ingrese el usuario (arreglo dinámico).
h) Escribe una función que devuelva una PC pasando la estructura como argumento a la
función.
i) Escribe una función a la que se le pase el puntero al arreglo de estructuras y cargue el
mismo con los valores asignados a las características de cada PC.
j) Escribe una función que presente la lista de las PC, cada una con sus características.
k) Escribe una función que presente la PC más vieja.
l) Escribe una función que presente la PC que tiene mayor velocidad.
*/

//bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "EJERCICIO4FUNCIONES.h"

//funcion principal
int main()
{
	srand(time(NULL));
	int cantidad;//esta variable recoge la entrada x teclado de la cantidad de pcs requerida
	
	//pido la cantidad de computadoras que se deasean ingresar:
	printf("POR FAVOR INGRESE LA CANTIDAD DE COMPUTADORAS QUE DESEA INGRESAR: \n");
	scanf("%d", &cantidad);
	fflush(stdin);
	
	/*g) Define una variable del tipo arreglo de estructura para guardar las características (punto a)
	de la cantidad de PC que ingrese el usuario (arreglo dinámico).*/
	PC compu[cantidad];
	PC *arregloDeComputadoras;
	arregloDeComputadoras = compu;

	//h) Escribe una función que devuelva una PC pasando la estructura como argumento a lafunción.
	for (int i = 0; i < cantidad; ++i)
	{
		srand(time(NULL));
		compu[i] = cargarPC(compu[i]);
	}

	//i) Escribe una función a la que se le pase el puntero al arreglo de estructuras y cargue el
	//mismo con los valores asignados a las características de cada PC.
	cargarCaracteristicas(arregloDeComputadoras, cantidad);

	//j) Escribe una función que presente la lista de las PC, cada una con sus características.
	caracteristicasPC(arregloDeComputadoras, cantidad);

	//k) Escribe una función que presente la PC más vieja.
	pcMasAntigua(arregloDeComputadoras, cantidad);

	//l) Escribe una función que presente la PC que tiene mayor velocidad.
	pcMasRapida(arregloDeComputadoras, cantidad);

	//final del programa
	printf("\n");
	getchar();
	return 0;
}

//otras funciones

