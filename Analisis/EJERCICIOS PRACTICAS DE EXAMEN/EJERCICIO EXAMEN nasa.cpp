/*Imagine que forma parte del equipo de programadores de un importante proyecto de la NASA.
En cierto programa para tan importante proyecto hay que ordenar vectores de longitud 10000,
para lo que se va a utilizar uno de los algoritmos directos de ordenacion por comparación, que
como es conocido son de orden cuadrático. La corrección del programa es vital por el éxito del
proyecto, por lo que se decide realizar una prueba exhaustiva de tamaño 10000.
Para la prueba se reserva una hora para un supercomputador de la NASA con potencia de cálculo
aproxiamda equivalente a un millón de veces el de un ordenador medio

	a)Escriba el programa para realizar la prueba
	b)¿Se podrá llevar a cabo la prueba?
*/

#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

void ord_burbuja(int v[],int tam);
unsigned long long int factorial(int n);
void caja_negra(int v[],int n);

int main()
{

	int tam=20;
	int v[tam];
	const size_t randn = sizeof v/sizeof *v;

	for(int i=0; i<tam; i++)
	{

		v[i]=rand();
	}
	


	for(int i=0; i<factorial(20); i++)	//Habrá 10000! permutaciones del vector
	{

		ord_burbuja(v,tam);					//Ordenos los elementos del vector
		caja_negra(v,tam);					//Realizo prueba de caja negra para ver si estan ordenados
		random_shuffle(v,v+randn); 			//Permuto los elementos del vector

	}
	
	
	return 0;


}

/*Funcion para ordenar los elementos de un vector (Ordenamiento burbuja)*/
void ord_burbuja(int v[],int tam)
{

	for(int i=0; i<tam; i++)
	{

		for(int j=0; j<tam; j++)
		{

			if(v[j+1]<v[j]) swap(v[j],v[j+1]);
		}
	}



}

/*Funcion que recibe un numero entero y devuelve el factorial del numero*/
unsigned long long int factorial(int fact)
{

	double factor=1;

	for(int i=fact; i>0 ; i--)
	{

		factor=factor*i;
	}

	return factor;
}

/*Función que determina si el vector está ordenado o no; Si no lo esta sale del programa
y lo finaliza sin terminar de ejecutar las demas pruebas*/
void caja_negra(int v[],int n)
{

	for(int i=0; i<n; i++)
	{

		if(v[i+1]<v[i])
		{
			cout<<"ERROR"<<endl;
			break;
		}

	}


}
