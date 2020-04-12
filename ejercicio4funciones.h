#ifndef EJERCICIO4FUNCIONES_H_
#define EJERCICIO4FUNCIONES_H_
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//estructuras
struct compu {
	int velocidad;//entre 1 y 3 Gherz
	int anio;//entre 2000 y 2017
	int cantidadNucleos;//entre 1 y 4
	char *tipo_cpu;//valores del arreglo tipos
};

//alias de la estructura
typedef struct compu PC;


//defino el arreglo tipos:
char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

//h) Escribe una función que devuelva una PC pasando la estructura como argumento a la función.
PC cargarPC(PC nueva){
	//semilla para generar numeros aleatorios
	srand(time(NULL));
	nueva.velocidad = (rand() % 4 + 1);
	nueva.anio = rand() % 18 + 2000;
	nueva.cantidadNucleos = rand() % 5 + 1;;
	nueva.tipo_cpu = tipos[rand() % 6];
	
	return nueva;
}

//i) Escribe una función a la que se le pase el puntero al arreglo de estructuras y cargue el
//mismo con los valores asignados a las características de cada PC.
void cargarCaracteristicas(PC *arreglo, int cantidad){
	PC aux;//para cargarlas caracteristicas uso una estructura auxiliar
	srand(time(NULL));
	for (int i = 0; i < cantidad; ++i)
	{
		
		aux = cargarPC(aux);
		*arreglo = aux;
		arreglo++;
	}
}

//j) Escribe una función que presente la lista de las PC, cada una con sus caractersticas.
void caracteristicasPC(PC *compu, int cantidad){
	for (int i = 0; i < cantidad; ++i)
	{
		printf("--------------------------------------------------------\n");
		printf("PC NUMERO:\t%d:\n", i+1);
		printf("ANHO:\t%d\n", compu->anio);
		printf("TIPO DE PROCESADOR:\t%s.\n", compu->tipo_cpu);
		printf("VELOCIDAD DE PROCESAMIENTO:\t%dGhz.\n", compu->velocidad);
		printf("CANTIDAD DE NUCLEOS:%d\n", compu->cantidadNucleos);
		printf("--------------------------------------------------------\n");
		compu++;
	}
}

//k) Escribe una función que presente la PC más vieja.
void pcMasAntigua(PC *compu, int cantidad){
	PC *aux;//esta variable auxiliar es para recorrer el arreglo de estructuras
	aux = compu;
	PC *masVieja;//esta variable auxiliar va a almacenar La pc q sea mas antigua mediante un ID
	masVieja = aux;
	int anhoMasAntigua = aux->anio;
    int IDantiguedad = 1;
    compu++;
	for (int i = 1; i < cantidad; i++) {
        if (aux -> anio < anhoMasAntigua) {
            anhoMasAntigua = aux->anio;
            masVieja = aux;
            IDantiguedad++;
        }
        compu++;
        aux = compu;
    }
    //imprimo los resultados
    printf("LA PC MAS ANTIGUA TIENE:\t%d ANHOS.\n", 2020 - anhoMasAntigua);
	printf("MODELO-CPU:\t%d - %s.\n", masVieja -> anio,masVieja -> tipo_cpu);
}

//l) Escribe una función que presente la PC que tiene mayor velocidad.
void pcMasRapida(PC *compu, int cantidad){
	PC *aux;//esta variable auxiliar es para recorrer el arreglo de estructuras
	aux = compu;
	PC *masRapida;//esta variable auxiliar va a almacenar La pc q sea mas antigua mediante un ID
	masRapida = aux;
	int velocidadPCmasRapida = aux -> velocidad;
    int IDPCmasRapida = 1;
    compu++;
	for (int i = 1; i < cantidad; i++) {
        if (aux -> velocidad > velocidadPCmasRapida) {
            velocidadPCmasRapida = aux -> velocidad;
            masRapida = aux;
            IDPCmasRapida++;
        }
        compu++;
        aux = compu;
    }
    //imprimo los resultados
    printf("LA PC MAS RAPIDA TIENE:\t%dGhz.\n", masRapida -> velocidad);
	printf("NUCLEOS-CPU:\t%d - %s.\n", masRapida -> cantidadNucleos, masRapida -> tipo_cpu);
}

#endif /* EJERCICIO4FUNCIONES_H */