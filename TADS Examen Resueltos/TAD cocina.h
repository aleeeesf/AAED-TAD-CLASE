#include <iostream>
#include "Lista.h"

using namespace std;

struct mueble{
	
	int posicion, anchura;
	mueble(int p, int a):posicion(p),anchura(a){}
	
};

class cocina{
	
	public:
		
		cocina(int longi);
		bool colocable(int anc, int pos);
		void insertar(int anc, int pos);
		mueble devolver();
		void eliminar();
		void mover();
		~cocina();	
	
	private:
		int longitud;
		int nmuebles;
		Lista<mueble> l;
};

cocina::cocina(int longi):longitud(longi),nmuebles(0){};

bool cocina::colocable(int anc, int pos){
	
	
	
	
	
}

void cocina::insertar(int anc, int pos){
	
	if()
	
	
	
}

void cocina::consultar(){
	
}

void cocina::eliminar(int pos){
	
}

void cocina::mover(){
	
}

cocina::~cocina(){delete this;}
