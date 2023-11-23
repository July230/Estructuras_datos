/*
Ian Julián Estrada Castro - A01352823

Archivo correspondiente a la clase archivo y sus métodos
La clase archivo será la encargada de leer el archivo CSV y
ordenar a los jugadores por puntuación.
Esto se hará a través de un arreglo Player<T>.

*/

#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "player.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <class T> class Archivo {
private:
  void swap(vector<Player> &, int, int);

public:
  vector<Player> cargarCSV(const string &nombreArchivo); // Cargar el archivo CSV
  void ordenaShell(vector<Player> &jugadores);
  void eliminarJugador(vector<Player>&, const string&);
};

template <class T>
vector<Player> Archivo<T>::cargarCSV(const string &nombreArchivo) {
  vector<Player> jugadores;
  ifstream archivo(nombreArchivo); // Abrir archivo

  string linea; // Lectura al contenido del archivo

  // Verificar si el archivo se cargó correctamente
  if (!archivo) {
    cout << "Error al cargar el archivo CSV." << endl;
    return jugadores;
  }

  cout << "Abriendo archivo: " << nombreArchivo << endl;

  // Leer cada línea del archivo
  while (getline(archivo, linea)) {
    stringstream ss(linea); // Linea del archivo
    string nombre;
    int idjugador, puntos;

    // Tomar los atributos del archivo y almacenarlos en el arreglo jugadores
    getline(ss, nombre, ',');
    ss >> idjugador;
    ss.ignore(); // Ignorar el salto de linea
    ss >> puntos;

    // Se agrega una posición y se guardan los atributos de jugador
    jugadores.push_back(Player(nombre, idjugador, puntos));
  }
  archivo.close(); // Cerrar archivo
  return jugadores;
}

template <class T>
// El metodo swap cambia la posicion de dos valores de un arreglo
void Archivo<T>::swap(vector<Player> &jugadores, int i, int j) {
  Player aux = jugadores[i];
  jugadores[i] = jugadores[j];
  jugadores[j] = aux;
}

// Ordenar los jugadores por puntaje usando ShellSort, descendente
template <class T> void Archivo<T>::ordenaShell(vector<Player> &jugadores) {
  // El tamaño es la cantidad de lineas en el CSV
  int tamanio = jugadores.size();
  int gap = tamanio / 2;

  // Se detiene cuando gap sea menor a 1
  while (gap > 0) {

    // Leer el arreglo
    for (int i = gap; i < tamanio; i++) {

      // Camparar si j es mayor al que esta gap posiciones atras
      // Utiliza get_puntos para las comparaciones
      for (int j = i; j >= gap && jugadores[j].get_puntos() > jugadores[j - gap].get_puntos();
           j -= gap) {
        swap(jugadores, j, j - gap); // Cambio de posiciones
      }
    }
    gap /= 2; // Se reduce gap por cada ciclo
  }
}


// Eliminar jugador de un vector
template <class T>
void Archivo<T>::eliminarJugador(vector<Player>& jugadores, const string& nombre) {
  // Utiliza la función remove_if() para eliminar el jugador del vector
  // Busca a un jugador que coincida con el nombre a eliminar
  jugadores.erase(std::remove_if(jugadores.begin(), jugadores.end(),
      [nombre](const Player& jugador) { return jugador.get_nombre() == nombre; }),        jugadores.end());
}


#endif /*ARCHIVO_H*/