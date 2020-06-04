#include <iostream>
#include <cassert>
#include <iomanip>
#include "Lista.h"

using namespace std;

struct funcion{
	
	double x,y;
	funcion(double xi = 0, double yi = 0):x(xi),y(yi){}
	
};

class escalonada{
	
	public:
		
		inline escalonada(double x, double y);
		void insertar(double x, double y);
		void imprimir();
		void valorpunto(double xi);
		double valormin();
		double valormax();
		void transladar(double xi, double w, double z);
		void eliminar(double xi);
		
	private:
			
		Lista<funcion> l;
	
};

inline escalonada::escalonada(double x, double y){ funcion f(x,y); l.insertar(f,l.primera()); }

void escalonada::insertar(double xi, double yi){

	Lista<funcion>::posicion p = l.primera();
	
	bool encontrado = false;
	
	while(p!=l.fin() && !encontrado){
		
		
		if(l.elemento(p).x == xi){
			
			l.elemento(p).y = yi;
			encontrado = true;
		}
		
		else if( !(l.siguiente(p) == l.fin()) ){
			
			if(l.elemento(p).x < xi && l.elemento(l.siguiente(p)).x > xi){
				
				l.insertar(funcion(xi,yi), l.siguiente(p));
				encontrado = true;
				
			}
		}
		
		else{
			
			if(l.elemento(p).x < xi){
				
				l.insertar(funcion(xi,yi), l.fin());
				encontrado = true;
			}
			
			else{
				
				l.insertar(funcion(xi,yi),p);
				encontrado = true;
			
			}
		}
		
		p = l.siguiente(p);
	}
}

void escalonada::imprimir(){
	
	Lista<funcion>::posicion p = l.primera();
	
	while(p != l.fin()){
		
		cout<<l.elemento(p).x<<setw(6);
		cout<<l.elemento(p).y<<endl;
		p = l.siguiente(p);
		
	}
	
}

void escalonada::eliminar(double xi){
	
	Lista<funcion>::posicion p = l.primera();
	bool encontrado = false;
	
	while(p!= l.fin() && !encontrado){
		
		if(l.elemento(p).x == xi){
			
			l.eliminar(p);
			encontrado = true;
		} 
		
		p = l.siguiente(p);	
	}
	
}

void escalonada::valorpunto(double xi){
	
	Lista<funcion>::posicion p = l.primera();
	bool encontrado = false;
	
	while(p!= l.fin() && !encontrado){
		
		if(l.elemento(p).x == xi){
			
			cout<<l.elemento(p).y<<endl;
			encontrado = true;
		} 
		
		p = l.siguiente(p);	
	}
	
}

double escalonada::valormin(){
	
	Lista<funcion>::posicion p = l.primera();
	double min;
	min = l.elemento(l.primera()).y;
	
	while(p!= l.fin()){
				
		if(l.siguiente(p) != l.fin()){
			
			if(l.elemento(p).y <= min) min = l.elemento(p).y;		
		}
		
		p = l.siguiente(p);	
	}
	
	return min;
}

double escalonada::valormax(){
	
	Lista<funcion>::posicion p = l.primera();
	double max;
	max = l.elemento(l.primera()).y;
	
	while(p!= l.fin()){
		
		if(l.siguiente(p) != l.fin()){
			
			if(l.elemento(p).y >= max) max = l.elemento(p).y;
		}
		
		p = l.siguiente(p);	
	}
	
	return max;
}
		
void escalonada::transladar(double xi, double w, double z)
{
	Lista<funcion>::posicion p = l.primera();
	bool encontrado = false;
	double max;
	
	while(p!= l.fin() && !encontrado){
	
		if(l.elemento(p).x == xi){
			
			l.elemento(p).x += w;
			l.elemento(p).y += z;
		}
		
		p = l.siguiente(p);
	}
	

			
}


