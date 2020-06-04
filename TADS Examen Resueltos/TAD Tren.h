#include <iostream>
#include <cassert>
#include "pila.h"

using namespace std;

class Tren{
	
	Public:
		
		inline Tren();
		void Izquierda();
		void Derecha();
		void Eliminar_Activo();
		void Activo();
		inline bool vacio();		
	
	Private:
		
		Vagon activo;
		Pila<vagon> der, izq;
	
};

inline Tren::Tren(){}

void Tren::Izquierda()
{
	assert(!vacio());
	
	if(!der.vacia()){
	
		izq.push(activo);
		activo = der.tope();
		der.pop();	
	}
	
}
	
void Tren::Derecha()
{
	if(!izq.vacia()){
	
		der.push(izq.tope());
		activo=izq.tope();
		izq.pop();	
	}
	
}
		
void Tren::Eliminar_Activo()
{
	if(!vacio()){
		
		if(der.vacia()){
		
			if(!izq.vacia){
							
				der.push(izq.tope());
				activo=izq.tope();
				izq.pop();
			}
		}
	}
}

const vagon& Tren::Activo()
{
	
	return activo;	
	
}

inline bool Tren::Vacio()
{
	
	return (der.vacia() && izq.vacia()):
	
}
