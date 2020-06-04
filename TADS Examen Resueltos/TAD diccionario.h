#include <iostream>
#include <cassert>
#include <cstring>
#include <string>
#include "Lista.h"

using namespace std; 

struct Traducciones{
	
	string ingles;
	Lista<string> listasp;
	
};


class Diccionario{
	
public:	
	
	Diccionario(); //Constructor
	void insertar(const string& espanol,string inglesa);
	void eliminartraduccion(const string& espanol, const string& inglesa);
	void consultar(const string& inglesa);
	~Diccionario();

private:
	
	Lista<Traducciones> l;
	
};

inline Diccionario::Diccionario(){}

void Diccionario::insertar(const string& espanol, string inglesa)
{
	
	typename Lista<Traducciones>::posicion p = l.primera();
	bool encontrado = false;
	
	while(p!=l.fin() && !encontrado)
	{
		
		if( inglesa == l.elemento(p).ingles )
		{
			encontrado = true;
			
			l.elemento(p).listasp.insertar(espanol,l.elemento(p).listasp.fin());
		}
		
		p=l.siguiente(p);
		
	}
	
	if(!encontrado){										//Si no se ha encontrado creo una estructura con la palabra inglesa
															//y su traduccion en español;
		Traducciones t;
		t.ingles=inglesa;
		t.listasp.insertar(espanol,t.listasp.fin());
		
		l.insertar(t,l.fin());
				
	}
	
	
}

void Diccionario::eliminartraduccion(const string& espanol, const string& inglesa)
{
	
	typename Lista<Traducciones>::posicion p = l.primera();
	bool encontrado = false;
	
	while(p!=l.fin() && !encontrado)
	{
		
		if(inglesa == l.elemento(p).ingles)				//Primero buscamos la palabra en ingles, si la encontramos, 
		{												//buscamos la palabra en español.
			encontrado = true;
			
			bool spencontrado = false;
			
			Lista<string>::posicion j = l.elemento(p).listasp.primera();
			
		
		
				while (j != l.elemento(p).listasp.fin() && !spencontrado){		//Buscamos la palabra en español para eliminarla
					
					if(l.elemento(p).listasp.elemento(j) == espanol){
						
						l.elemento(p).listasp.eliminar(j);
						encontrado = true;
						
					} 
					
					j != l.elemento(p).listasp.siguiente(j);					
				}
			
		}
		
		p=l.siguiente(p);
		
	}

}

void Diccionario::consultar(const string& inglesa)
{
	
	typename Lista<Traducciones>::posicion p = l.primera();
	bool encontrado = false;
	
	while(p!=l.fin() && !encontrado)
	{
		
		if( inglesa == l.elemento(p).ingles )
		{
			encontrado = true;
			
			Lista<string>::posicion j = l.elemento(p).listasp.primera();
			
					while (j != l.elemento(p).listasp.fin()){					//Buscamos el elemento dentro de la lista de traducciones
						
						cout<<l.elemento(p).listasp.elemento(j)<<endl;	
						j != l.elemento(p).listasp.siguiente(j);				
					}
		}
		
		p=l.siguiente(p);
		
	}
	
	if(!encontrado) cout<<"No se ha encontrado palabra inglesa"<<endl;
		
}

Diccionario::~Diccionario(){delete this;};
