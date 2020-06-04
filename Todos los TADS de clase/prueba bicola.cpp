#include <iostream>
#include "BICOLA.h"
using namespace std;
int main(){
	
	BicolaD<int> c;
	
	c.pushDer(3);
	c.pushDer(4);
	c.pushDer(6);
	cout<<c.frenteDer()<<endl;
	cout<<c.frenteIzq()<<endl;
	
	/*
	-------------------------
		3		4		6		-->	6
	-------------------------
	*/
	
		
	c.popIzq();
	
	/*
	-------------------------
			4		6	
	-------------------------
	*/
	
	cout<<c.frenteIzq()<<endl;
	
	c.popDer();
	
	
		/*
	-------------------------
				4	
	-------------------------
	*/
	
	cout<<c.frenteIzq()<<endl;
	
	
	c.popDer();

	
	
	if(c.vacia()) cout<<"Esta vacia"<<endl;
	
	c.popDer();
	return 0;
}
