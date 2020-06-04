#include <iostream>
#include <cassert>
#include <iomanip>
#include "Pila.h"

using namespace std;


enum Trazos{I,D,S,B};


class Simbolo{
	
	public:
		
		inline Simbolo();
		inline void anadirtrazos(const Trazos& t);
		void simetriaX();
		void simetriaY();
		void SimpetriaXY();
		inline void eliminartrazos(const int& nelmto);
		void mostrar();
	
	private:
			
		Pila<Trazos> p;
		int n;
	
};

inline Simbolo::Simbolo():n(0){}

inline void Simbolo::anadirtrazos(const Trazos& t)
{
	p.push(t);
	n++;
}

void Simbolo::simetriaX()
{
	Pila<Trazos> aux;
	
	while(!p.vacia()){
		
		aux.push(p.tope());
		p.pop();		
	}	
	
	while(!aux.vacia()){
		
		switch(aux.tope()){
			
			case S: p.push(B); break;
			case B: p.push(S); break;
			default: p.push(aux.tope());
		}
	
		aux.pop();
	}
}

void Simbolo::simetriaY()
{
	Pila<Trazos> aux;
	
	while(!p.vacia()){
		
		aux.push(p.tope());
		p.pop();		
	}	
	
	while(!aux.vacia()){
		
		switch(aux.tope()){
			
			case I: p.push(D); break;
			case D: p.push(I); break;
			default: p.push(aux.tope());
		}
	
		aux.pop();
	}	
}

void Simbolo::SimpetriaXY()
{
	Pila<Trazos> aux;
	
	while(!p.vacia()){
		
		aux.push(p.tope());
		p.pop();		
	}	
	
	while(!aux.vacia()){
		
		switch(aux.tope()){
			
			case I: p.push(D); break;
			case D: p.push(I); break;
			case S: p.push(B); break;
			case B: p.push(S); break;
		}
	
		aux.pop();
	}
}

inline void Simbolo::eliminartrazos(const int& nelmto)
{
	assert(nelmto<n);
	
	int i=0;
	
	while(i<n){
		
		p.pop();
		n--;
	}
}
void Simbolo::mostrar()
{
	Pila<Trazos> aux;
	Pila<Trazos> segunda(p);
	
	while(!segunda.vacia())
	{
		aux.push(segunda.tope());
		segunda.pop();
		
	}	
	
	while(!aux.vacia()){
		
		switch(aux.tope()){
		
		case I: cout<<"I"<<setw(2); break;
		case D: cout<<"D"<<setw(2); break;
		case S: cout<<"S"<<setw(2); break;
		case B: cout<<"B"<<setw(2); break;
		}
		
		aux.pop();
		
	}
	
}
