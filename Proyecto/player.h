/*
Ian Julián Estrada Castro - A01352823
Segundo avance de la situción problema

Código correspondiente a la clase player
La clase Player representa a un jugador individual, se utiliza para
crear objetos individuales que representan a cada jugador con
sus atributos específicos.

*/

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Player{
  private:
    string nombre;
    int idjugador, puntos;
  public:
    Player(): nombre(""), idjugador(0), puntos(0){};
    Player(const string nombre, int idjugador, int puntos): nombre(nombre), idjugador(idjugador), puntos(puntos){};
    string get_jugador() const;
    int get_puntos() const;
    string get_nombre() const;


    bool operator<(const Player&) const;
    bool operator>(const Player&) const;
    bool operator==(const Player&) const;

    // Sobrecargar el operador "<<" para leer jugadores del arbol
    friend ostream& operator<<(ostream& os, const Player& jugador) {
        os << jugador.get_jugador(); // Obtener el jugador
        return os;
    }
};

//Devolver una cadena de texto, separado por comas
string Player::get_jugador() const{
  return nombre + "," + to_string(idjugador) + "," + to_string(puntos);
}

// Metodo para obtener los puntos
int Player::get_puntos() const{
  return puntos;
}

// Metodo para obtener el nombre
string Player::get_nombre() const{
  return nombre;
}

bool Player::operator<(const Player& nom) const{
  // Uso de strcmp de la librería string.h
  // Si los nombres (strings) son iguales, devuelve 0
  // Si la primera letra es igual, devuelve -1
  // Devuelve 1 si la primera letra de la izquierda tiene menor valor 

  // Compara dos nombres de dos objetos tipo Player
  int comparacion = strcmp(nombre.c_str(), nom.nombre.c_str());

  if (comparacion < 0) {
      return true; // El objeto actual es menor
  } else {
      return false; // El objeto actual es igual o mayor
  }
}

bool Player::operator>(const Player& nom) const{
  // Compara dos nombres de dos objetos tipo Player
  int comparacion = strcmp(nombre.c_str(), nom.nombre.c_str());

  if (comparacion > 0) {
      return true; // El objeto actual es mayor
  } else {
      return false; // El objeto actual es igual o menor
  }
}

// Si los nombres son iguales
bool Player::operator==(const Player& nom) const{
  return this->nombre == nom.nombre;
}

#endif /*PLAYER_H*/