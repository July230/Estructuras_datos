/*
Ian Julián Estrada Castro - A01352823

Archivo que crea un árbol de búsqueda binaria para implementar el ordenamiento de manera alfabética y la búsqueda
*/

#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
#include <string>
#include <fstream>
#include "archivo.h"

using namespace std;

template <class T> class Arbol;

template <class T>
class NodoArbol{
  private:
    T valor;
    NodoArbol<T> *izquierda;
    NodoArbol<T> *derecha;
    int nivel, balance; // profundidad y factor de balance
  public:
    NodoArbol(T);
    NodoArbol(T, NodoArbol<T>*, NodoArbol<T>*, int, int);

    void inorder(stringstream&) const;
    void preorder(stringstream&) const;
    void removeChilds();

    // Implementación AVL
    
    
    friend class Arbol<T>;
};

template <class T>
NodoArbol<T>::NodoArbol(T val){
  valor = val;
  izquierda = NULL;
  derecha = NULL;
  nivel = 0;
  balance = 0;
}

template <class T>
NodoArbol<T>::NodoArbol(T val, NodoArbol<T> *izq, NodoArbol<T> *der, int n, int bal){
  valor = val;
  izquierda = izq;
  derecha = der;
  nivel = n;
  balance = bal;
}

template <class T>
void NodoArbol<T>::inorder(stringstream &aux) const {
  if (izquierda != 0) {
    izquierda->inorder(aux);
  }
  // tellp() devuelve el valor del puntero
  if (aux.tellp() != 1) {
    aux << "\n";
  }
  aux << valor;
  if (derecha != 0) {
    derecha->inorder(aux);
  }
}

template <class T>
void NodoArbol<T>::preorder(std::stringstream &aux) const {
  aux << valor;
  if (izquierda != 0) {
    aux << "\n";
    izquierda->preorder(aux);
  }
  if (derecha != 0) {
    aux << "\n";
    derecha->preorder(aux);
  }
}

template <class T>
void NodoArbol<T>::removeChilds() {
  if(izquierda != NULL){
    izquierda->removeChilds();
    delete izquierda;
    izquierda = NULL;
  }
  if(derecha != NULL){
    derecha->removeChilds();
    delete derecha;
    derecha = NULL;
  }

}

template <class T> 
class Arbol{  
  private:
    NodoArbol<T> *raiz;

    // Función auxiliar para insertar un jugador en el árbol
    // Al ser funciones que alteran la estructura, se declaran como 
    // private para mantener el encapsulamiento y coherencia del árbol
    NodoArbol<T>* insertar(NodoArbol<T> *nodo, const T& jugador);
    NodoArbol<T>* borrar(NodoArbol<T> *nodo, const T& jugador);
    NodoArbol<T>* sucesor(NodoArbol<T> *nodo);
    NodoArbol<T>* rot_izquierda(NodoArbol<T> *);
    NodoArbol<T>* rot_derecha(NodoArbol<T> *);
    NodoArbol<T>* rot_izquierda_derecha(NodoArbol<T> *);
    NodoArbol<T>* rot_derecha_izquierda(NodoArbol<T> *);
    NodoArbol<T>* verificar(T *, NodoArbol<T> *, bool *);
    NodoArbol<T>* balancear();
  public:
    Arbol();
    ~Arbol();
    void removeAll();

    void CargarArchivo(const string& nombreArchivo);

    bool empty() const;
    void InsertaJugador(const T& jugador); 
    bool buscar(const string& nombre, T& jugadorEncontrado) const;
    bool buscaJugador(const NodoArbol<T>* nodo, const string& nombre, T& jugadorEncontrado) const;
    void borraJugador(const T& jugador);
    string inorder() const;
    string preorder() const;

    int altura(NodoArbol<T>*);

    // Funciones para sobreescribir el archivo CSV
    void escribir(NodoArbol<T>*, ofstream&) const;
    void sobreescribir(const char*) const;
    friend class NodoArbol<T>;    
};

template <class T>
Arbol<T>::Arbol(){
  raiz = 0;
}

template <class T>
Arbol<T>::~Arbol(){
  removeAll();
}


// Verificar si la raíz esta vacia
template <class T>
bool Arbol<T>::empty() const {
  if(raiz == NULL){
    return true;
  }
  return false;
}


template <class T>
void Arbol<T>::removeAll() {
  if(!empty()){
    raiz->removeChilds();
    delete raiz;
    raiz = NULL;
  }
}

// Función para calcular la altura de un nodo
template <class T>
int Arbol<T>::altura(NodoArbol<T>* nodo) {
  if (nodo == NULL) {
    return 0;
  }
  int altura_izquierda = altura(nodo->izquierda);
  int altura_derecha = altura(nodo->derecha);
  
  return 1 + max(altura_izquierda, altura_derecha);
}

// Función para insertar un jugador en el árbol
template <class T>
void Arbol<T>::InsertaJugador(const T& jugador) {
  raiz = insertar(raiz, jugador);
}

// Función auxiliar para insertar un jugador en el árbol
template <class T>
NodoArbol<T>* Arbol<T>::insertar(NodoArbol<T> *nodo, const T& jugador) {
  if(nodo == NULL){
    // Si el nodo actual es nulo, se ha encontrado la ubicación para insertar.
    // Crear nuevo nodo y devolver como el nodo insertado.
    return new NodoArbol<T>(jugador);
  }

  // Comparar el valor de jugador con el nodo actual
  if(jugador < nodo->valor){
    // Si es menor o igual (<=0), se va a la izquierda
    nodo->izquierda = insertar(nodo->izquierda, jugador);
  } else if (jugador > nodo->valor) {
    // Si es mayor (>0), se va a la derecha
    nodo->derecha = insertar(nodo->derecha, jugador);
  } else {
  // Devuelve el nodo actual
  return nodo;
  }
  // Implementación AVL
  // Actualizar la altura del nodo actual
  nodo->nivel = 1 + max(altura(nodo->izquierda), altura(nodo->derecha));

  // Calcular el factor de balance del nodo
  int balance = altura(nodo->izquierda) - altura(nodo->derecha);

  // Hacer las rotaciones y balancear según el factor de balance
  // Esto también actualiza el valor de nodo->nivel
  if (balance > 1) {
    if (jugador < nodo->izquierda->valor) {
      return rot_derecha(nodo);
    } else {
      return rot_izquierda_derecha(nodo);
    }
  }

  if (balance < -1) {
    if (jugador > nodo->derecha->valor) {
      return rot_izquierda(nodo);
    } else {
      return rot_derecha_izquierda(nodo);
    }
  }

  return nodo;
}

// Cargar el archivo csv 
template <class T>
void Arbol<T>::CargarArchivo(const string& nombreArchivo){
  ifstream archivo(nombreArchivo);

  // Error al abrir el archivo
  if (!archivo) {
    cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
    return;
    }

  string linea;
  // Leer cada línea del archivo
  while(getline(archivo,linea)){
    stringstream ss(linea); // Linea del archivo
    string nombre;
    int idjugador, puntos;

    // Tomar los atributos del archivo y almacenarlos en el arreglo jugadores
    getline(ss,nombre,',');
    ss >> idjugador;
    ss.ignore(); // Ignorar el salto de linea
    ss >> puntos; 
    // Crear un objeto tipo Player e insertarlo en el árbol
    Player jugador(nombre, idjugador, puntos);
    InsertaJugador(jugador);
  }
  archivo.close(); // Cerrar archivo
}


template <class T>
bool Arbol<T>::buscar(const string& nombre, T& jugadorEncontrado) const {
    // Se llama a buscaJugador
    return buscaJugador(raiz, nombre, jugadorEncontrado);
}

// Búsqueda por nombre, auxiliar
// jugadorEncontrado determina si la condición se cumple o no
template <class T>
bool Arbol<T>::buscaJugador(const NodoArbol<T>* nodo, const string& nombre, T& jugadorEncontrado) const {
    // Si el nodo apunta a nulo
    if (nodo == NULL) {
      return false; 
    }

    // Encuentra una coincidencia
    if (nombre == nodo->valor.get_nombre()) {
      jugadorEncontrado = nodo->valor; // Se encontró el jugador
      return true;
    }

    // Es menor
    if (nombre < nodo->valor.get_nombre()) {
      // Buscar a la izquierda recursivamente
      return buscaJugador(nodo->izquierda, nombre, jugadorEncontrado); 
    } else {
      // Buscar a la derecha recursivamente
      return buscaJugador(nodo->derecha, nombre, jugadorEncontrado); 
    }
}

template <class T>
NodoArbol<T>* Arbol<T>::sucesor(NodoArbol<T>* nodo){

  NodoArbol<T> * succesor = nodo->izquierda;
  // Ancestro apunta al nodo actual
  NodoArbol<T> * ancestro = nodo;

  // Enfoque a menor de los mayores
  if(succesor == NULL){
      succesor = nodo->derecha;
    if(nodo->izquierda == NULL){
      return NULL;
    } else {
      // Sucesor avanza hasta el final
      while(succesor->izquierda != NULL){
        // Ancestro apunta a donde sucesor apuntaba
        ancestro = succesor;
        succesor = succesor->izquierda;
      }
      // Ancestro apunta al hijo de sucesor
      if(succesor->derecha != NULL){
        ancestro->izquierda = succesor->derecha;
      }
      succesor->derecha = NULL;
      return succesor;
    }
  }
  // En su defecto, mayor de los menores
  else {
    if(succesor->derecha == NULL){
      ancestro->izquierda = succesor->izquierda;
      succesor->izquierda = NULL;
      return succesor;
    }
    while(succesor->derecha != NULL){
      ancestro = succesor;
      succesor = succesor->derecha;
    }
    ancestro->derecha = succesor->izquierda;
    succesor->izquierda = NULL;
    return succesor;
  }
}


// Función para eliminar un jugador del árbol
template <class T>
void Arbol<T>::borraJugador(const T& jugador){
  raiz = borrar(raiz, jugador);
}

template <class T>
NodoArbol<T>* Arbol<T>::borrar(NodoArbol<T> *nodo, const T& valor){
  if(nodo == NULL){
    return nodo; // No se encontró el valor a eliminar
  }

  // Ir al lado izquierdo si es menor
  if(valor < nodo->valor){
    nodo->izquierda = borrar(nodo->izquierda, valor);
  } 
  // Ir al lado derecho si es mayor
  else if (valor > nodo->valor) {
    nodo->derecha = borrar(nodo->derecha, valor);
  } else {
    // Si el nodo tiene un hijo o es una hoja
    if (nodo->izquierda == NULL) {
      NodoArbol<T>* temp = nodo->derecha;
      delete nodo;
      return temp;
    }
    else if (nodo->derecha == NULL) {
      NodoArbol<T>* temp = nodo->izquierda;
      delete nodo;
      return temp;
    }

    // Si el nodo tiene hijos, encontrar el sucesor
    NodoArbol<T>* sucesorNodo = sucesor(nodo);
    // Actualizar el valor del nodo actual con el sucesor
    nodo->valor = sucesorNodo->valor;
    // Borrar el sucesor del subárbol derecho
    nodo->derecha = borrar(nodo->derecha, sucesorNodo->valor);
  }
  
  // Actualizar la altura del nodo actual
  nodo->nivel = 1 + max(altura(nodo->izquierda), altura(nodo->derecha));

  // Calcular el factor de balance del nodo
  int balance = altura(nodo->izquierda) - altura(nodo->derecha);

  // Hacer las rotaciones y balancear según el factor de balance
  // Esto también actualiza el valor de nodo->nivel
  if (balance > 1) {
    if (altura(nodo->izquierda->izquierda) >= altura(nodo->izquierda->derecha)) {
      return rot_derecha(nodo);
    } else {
      return rot_izquierda_derecha(nodo);
    }
  }

  if (balance < -1) {
    if (altura(nodo->derecha->derecha) >= altura(nodo->derecha->izquierda)) {
      return rot_izquierda(nodo);
    } else {
      return rot_derecha_izquierda(nodo);
    }
  }

  return nodo;
}


// Recorrido en orden
template <class T>
string Arbol<T>::inorder() const {
  std::stringstream aux;

  if (!empty()) {
    raiz->inorder(aux);
  }
  aux << "\n";
  return aux.str();
}

// Recorrido preorder
template <class T>
string Arbol<T>::preorder() const {
  std::stringstream aux;

  if (!empty()) {
    raiz->preorder(aux);
  }
  return aux.str();
}

template <class T>
void Arbol<T>::escribir(NodoArbol<T>* nodo, ofstream& archivo) const {
  // Muestra los jugadores en orden
  if (nodo != NULL) {
    escribir(nodo->izquierda, archivo);
    archivo << nodo->valor << "\n";  // Usar sobrecarga de operador "<<"
    escribir(nodo->derecha, archivo);
    }
}

template <class T>
void Arbol<T>::sobreescribir(const char* nombreArchivo) const {
    ofstream archivo(nombreArchivo, std::ios_base::trunc);  // Abre el archivo y trunca su contenido
    if (!archivo) {
        cerr << "Error al abrir el archivo para escribir." << endl;
        return;
    }
    // Se llama a la función escribir
    escribir(raiz, archivo);
    archivo.close();
}


// Implementación de AVL para evitar degeneración del árbol binario

//Rotación izquierda
template <class T>
NodoArbol<T>* Arbol<T>::rot_izquierda(NodoArbol<T>* a){
  NodoArbol<T> *b, *temp = 0;
  if (a->derecha != 0){
    b = a->derecha;
    if (b->izquierda != 0)
      temp = b->izquierda;
    b->izquierda = a;
    if(temp != 0){
      a->derecha = temp;
    }else{
      a->derecha = 0;
    }
  }
  return b;
}

// Rotación derecha
template <class T>
NodoArbol<T>* Arbol<T>::rot_derecha(NodoArbol<T>* a){
  NodoArbol<T> *b, *temp = 0;
  if (a->izquierda != 0){
    b = a->izquierda;
    if (b->derecha != 0)
      temp = b->derecha;
    b->derecha = a;
    if(temp != 0){
      a->izquierda = temp;
    }else{
      a->izquierda = 0;
    }
  }
  return b;
}

// Rotación izquierda derecha
template <class T>
NodoArbol<T>* Arbol<T>::rot_izquierda_derecha(NodoArbol<T>* a){
  a->izquierda = rot_izquierda(a->izquierda);
  a = rot_derecha(a);
  return a;
}

// Rotación derecha izquierda
template <class T>
NodoArbol<T>*  Arbol<T>::rot_derecha_izquierda(NodoArbol<T>* a){
  a->derecha = rot_derecha(a->derecha);
  a = rot_izquierda(a);
  return a;
}

// Función para verificar el balance del árbol
template <class T>
NodoArbol<T>* Arbol<T>::verificar(T *check_val, NodoArbol<T> *parent, bool *checked) {
  NodoArbol<T>*le = 0, *ri = 0, *a = 0;
  if (raiz != 0){
    raiz->verificar(check_val, 0, checked);
  }
  if (*checked == false){
    a = balancear();
    *check_val = raiz->valor;
    *checked = true;
    raiz = a;
  }
  return a;
}

// Función para balancear el árbol
template <class T>
NodoArbol<T>* Arbol<T>::balancear() {
  NodoArbol<T> *a = raiz, *le = raiz->izquierda, *ri = raiz->derecha;
  int old_value = raiz->valor;
  if (raiz->balance > 0) {
    if (le->balance > 0){
      a = rot_derecha(a);
    }else{
      a = rot_izquierda_derecha(a);
    }
  }else{
    if (ri->balance < 0){
      a = rot_izquierda(a);
    }else{
      a = rot_derecha_izquierda(a);
    }
  }
  // Nuevo valor del nodo
  return a;
}

#endif /*ARBOL_H*/