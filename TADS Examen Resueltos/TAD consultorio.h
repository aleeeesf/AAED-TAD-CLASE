#include <iostream>
#include "Lista.h"
#include "ColaD.h"

using namespace std;

struct medico{
	string id;		//nombre del medico
	ColaD<string> pacientes;
};

class Consultorio{
	
	public:
		Consultorio();
		void altamedico(const string& nombre);
		void bajamedico(const string& nombre);
		bool buscarmedico(const string& nombre);
		Lista<medico>::posicion posmedico(const string& nombre);
		void nuevo_paciente(const string& nombremedico,const string& nombrepaciente);
		void prox_paciente(const string& nombre);
		void atender_paciente(const string& nombre);
		void comprobar_espera(const string& nombre);
		~Consultorio();
		
	private:
	
		Lista<medico> l;	
		
};

inline Consultorio::Consultorio(){}; //Constructor

/*Funcion para consultar si el medico existe, devuelve true si lo
encuentra y false si no lo encuentra*/
bool Consultorio::buscarmedico(const string& nombre){
	
	Lista<medico>::posicion p = l.primera();
	bool encontrado = false;
	
	while(p!=l.fin() && !encontrado){
		
		if(l.elemento(p).id == nombre){
			 
			 encontrado = true;
			 return true;
		}
		p=l.siguiente(p);
	}
	
	if(!encontrado){
		
		return false;
	}
}

/*Funcion para devolver la posicion de un medico en la lista, si no existe devuelve la ultima
posicion de la lista()*/
typename Lista<medico>::posicion Consultorio::posmedico(const string& nombre){
	
	Lista<medico>::posicion p = l.primera();
	bool encontrado = false;
	
	while(p!=l.fin() && !encontrado){
		
		if(l.elemento(p).id == nombre){
			 
			 encontrado = true;
			 return p;
		}
		p=l.siguiente(p);
	}
	
	if(!encontrado){
		
		return l.fin();
	}
}

void Consultorio::altamedico(const string& nombre){
	
	if(!buscarmedico(nombre)){
		
		medico m;						//Creo una estructura medico con su nombre y una cola vacia
		m.id=nombre;
		l.insertar(m,l.fin());
		
	}
	else cout<<"Ya hay un medico con el mismo nombre"<<endl;
}
	
void Consultorio::bajamedico(const string& nombre){
	
	if(buscarmedico(nombre)) l.eliminar(posmedico(nombre));
	else cout<<"Medico no encontrado"<<endl;

}

		
void Consultorio::nuevo_paciente(const string& nombremedico, const string& nombrepaciente){
	
	if(buscarmedico(nombremedico)) l.elemento(posmedico(nombremedico)).pacientes.push(nombrepaciente);
	else cout<<"Nombre de medico no encontrado"<<endl;
		
}
			
void Consultorio::prox_paciente(const string& nombre){
	
	if(buscarmedico(nombre)) cout<<l.elemento(posmedico(nombre)).pacientes.frente()<<endl;
	else cout<<"Nombre de medico no encontrado"<<endl;
}
				
void Consultorio::atender_paciente(const string& nombre){
	
	if(buscarmedico(nombre)) l.elemento(posmedico(nombre)).pacientes.pop();
	else cout<<"Nombre de medico no encontrado"<<endl;
}


void Consultorio::comprobar_espera(const string& nombre){
	
	bool waiting;
		
	if(buscarmedico(nombre)){
		
		waiting = l.elemento(posmedico(nombre)).pacientes.vacia();
		if(!waiting) cout<<"Tiene pacientes en espera"<<endl;
		else cout<<"No tiene pacientes en espera"<<endl;
	} 
	
 	else cout<<"Nombre de medico no encontrado"<<endl;	
}
	
	
Consultorio::~Consultorio(){delete this;};				
