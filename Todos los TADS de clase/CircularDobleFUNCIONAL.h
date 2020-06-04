#ifndef LISTA_DOBLE_H
#define LISTA_DOBLE_H
#include <cassert>
#include <iostream>
#define POS_NULA NULL
template <typename T> class ListaCir {
		struct nodo; // declaración adelantada privada
	public:
		typedef nodo* posicion; // posición de un elemento
		ListaCir(); // constructor, requiere ctor. T()
		ListaCir(const ListaCir<T>& l); // ctor. de copia, requiere ctor. T()
		ListaCir<T>& operator =(const ListaCir<T>& l); // asignación entre

		void insertar(const T& x, posicion p);
		void eliminar(posicion p);
		const T& elemento(posicion p) const; // acceso a elto, lectura
		T& elemento(posicion p); // acceso a elto, lectura/escritura
		posicion inipos() const;
		posicion buscar(const T& x) const; // T requiere operador ==
		posicion siguiente(posicion p) const;
		posicion anterior(posicion p) const;
		posicion primera() const;
	
		~ListaCir(); // destructor
		
	private:
		
		struct nodo {
			T elto;
			nodo *ant, *sig;
			nodo(const T& e, nodo* a = 0, nodo* s = 0) :
				elto(e), ant(a), sig(s) {}
		};
		nodo* L; // lista circular doblemente enlazada de nodos
		void copiar(const ListaCir<T>& l);
};

// Método privado
template <typename T>
void ListaCir<T>::copiar(const ListaCir<T> &l) {
	L = new nodo(T()); // crear el nodo cabecera
	L->ant = L->sig = L; // estructura circular
// Copiar elementos de l
	for (nodo* q = l.L->sig; q != l.L; q = q->sig)
		L->ant = L->ant->sig = new nodo(q->elto, L->ant, L);
}

template <typename T>
inline ListaCir<T>::ListaCir() : L(0) {}

template <typename T>
inline ListaCir<T>::ListaCir(const ListaCir<T>& l) {
	copiar(l);
}

template <typename T>
ListaCir<T>& ListaCir<T>::operator =(const ListaCir<T>& l) {
	if (this != &l) { // evitar autoasignación
		this->~Lista(); // vaciar la lista actual
		copiar(l);
	}
	return *this;
}

template <typename T> inline
void ListaCir<T>::insertar(const T& x, ListaCir<T>::posicion p) {
	
	if(L == 0) {L = new nodo(x); L->ant=L->sig=L;} 
	
	else p->sig = p->sig->ant = new nodo(x, p, p->sig);
	// el nuevo nodo con x queda en la posición p
}

template <typename T>
inline void ListaCir<T>::eliminar(ListaCir<T>::posicion p) {
	assert(p != POS_NULA); // p no es nula
	nodo* q = p->sig;
	p->sig = q->sig;
	p->sig->ant = p;
	delete q;
	//EL NODO SIGUIENTE QUEDA EN LA POSICIÓN P	
}

template <typename T> inline
const T& ListaCir<T>::elemento(ListaCir<T>::posicion p) const {
	assert(p != 0); // p no es nula
	return p->sig->elto;
}

template <typename T>
inline T& ListaCir<T>::elemento(ListaCir<T>::posicion p) {
	assert(p != 0); // p no es nula
	return p->sig->elto;
}


template <typename T> inline
typename ListaCir<T>::posicion
ListaCir<T>::inipos() const {
	
	if(L == 0) return POS_NULA;
	else return L;
}

template <typename T>
typename ListaCir<T>::posicion
ListaCir<T>::buscar(const T& x) const {
	nodo* q = L;
	bool encontrado = false;
	while (q->sig != L && !encontrado)
		if (q->sig->elto == x)
			encontrado = true;
		else q = q->sig;
	return q;
}

template <typename T> inline
typename ListaCir<T>::posicion
ListaCir<T>::siguiente(ListaCir<T>::posicion p) const {

	if(p == POS_NULA) return L->sig;
	else return p->sig;
}

template <typename T> inline
typename ListaCir<T>::posicion
ListaCir<T>::anterior(ListaCir<T>::posicion p) const {
	assert(p != POS_NULA); // p no es la primera posición
	return p->ant;
}

template <typename T>
inline typename ListaCir<T>::posicion ListaCir<T>::primera() const {
	return inipos();
}


template <typename T>
ListaCir<T>::~ListaCir() {
	nodo* q;
	while (L->sig != L) {
		q = L->sig;
		L->sig = q->sig;
		delete q;
	}
	delete L;
}
#endif // LISTA_DOBLE_H
