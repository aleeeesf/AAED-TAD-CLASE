#include<iostream>
#include <cstdlib>
#include "Pila.h"

using namespace std;

class Postfijo{

	public:
		
		Postfijo();
		void insertar(const string& cadena, const string& variables);
		int valor(const char& incognita);
	
	private:
	
		Pila<int> p;
		Pila<char> valores, auxvalores;
};

Postfijo::Postfijo(){};

void Postfijo::insertar(const string& cadena, const string& variables)
{
	
	int i=0;
	
	while(i!=variables.length()){				//Introducimos las variables en una pila
		
		valores.push(variables[i]);
		i++;
		
	}
	
	i=0;
	
	while(i!=cadena.length()){			
		
		if(cadena[i] != '+' && cadena[i] != '-' && cadena[i] != '/' && cadena[i] != '*'){
			
			p.push(valor(cadena[i]));
			
		}
		
		else{
			
			int res,a,b;
			
			switch(cadena[i]){
				
				case '+':	a=p.tope();
							p.pop();
							b=p.tope();
							p.pop();
							res=b+a;
							p.push(res);
							break;
				case '-':	
							a=p.tope();
							p.pop();
							b=p.tope();
							p.pop();
							res=b-a;
							p.push(res);				
							break;
							
				case '*':	a=p.tope();
							p.pop();
							b=p.tope();
							p.pop();
							res=b*a;
							p.push(res);				
							break;
							
				case '/':	a=p.tope();
							p.pop();
							b=p.tope();
							p.pop();
							res=b/a;
							p.push(res);				
							break;			
				
				
			}
			
		}
		
		i++;	//Incrementamos a la siguiente posicion de la cadena
		
	}
	
	int resultado = p.tope();
	cout<<resultado<<endl;
	
}


int Postfijo::valor(const char& incognita)
{
	
	while(valores.tope()!=incognita){
	
		auxvalores.push(valores.tope());
		valores.pop();
	}
	
	int x = atoi(&auxvalores.tope());
	
	while(!auxvalores.vacia()){
		
		valores.push(auxvalores.tope());
		auxvalores.pop();
	}
	
	return x;
	
}

