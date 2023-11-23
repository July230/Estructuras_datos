/*
Ian Julián Estrada Castro - A01352823
Archivo main correspondiente al avance 2, ahora se incluyen las funciones de ordenamiento de manera alfabética y la búsqueda, ambas a través de un árbol de búsqueda binaria
*/

#include <iostream>
#include <cctype> // Para la función isdigit
#include <unistd.h> // Para la función sleep
#include "archivo.h"
#include "arbol.h"

using namespace std;

int main() {
  Archivo<string> datos;
  // Un vector a ordenar y uno desordenado
  vector<Player> jugadores = datos.cargarCSV("players.csv");
  vector<Player> ordenado = datos.cargarCSV("players.csv");

  Arbol<Player> arboljugadores; // Árbol binario con objetos tipo Player
  Player jugadorbuscado; 
  string nombrebuscado;

  // Variables para agregar nuevo jugador
  string nuevoNombre;
  int nuevoID, nuevosPuntos;


  int opcion;

  // Cargar los jugadores en el árbol solo una vez al inicio del programa
  for (const Player& jugador : jugadores) {
    arboljugadores.InsertaJugador(jugador);
  }

  cout << "Clasificación de jugadores" << endl;
  do{
    cout << "1 - Mostrar lista de jugadores" << endl;
    cout << "2 - Ordenar por puntaje" << endl;
    cout << "3 - Ordenar lista alfabéticamente" << endl;
    cout << "4 - Buscar jugador por nombre" << endl;
    cout << "5 - Agregar nuevo jugador" << endl;
    cout << "6 - Eliminar jugador" << endl;
    cout << "7 - Salir del programa" << endl;
    cout << "\n";

    string opcionStr;
    cin >> opcionStr;

    // Verificar que la entrada sea un número
    if(isdigit(opcionStr[0])){
      // Convertir la opción a un entero
      opcion = stoi(opcionStr);

      sleep(1); // El programa "duerme" 1 segundo
      switch(opcion){
        case 1:
          {
          if(!jugadores.empty()){
            cout << "Clasificación de jugadores" << endl;

            // Imprimir los jugadores cargados
            for(const Player& jugador : jugadores){
              cout << jugador.get_jugador() << endl;
            }
          }
          else{
            cout << "Error al cargar jugadores" << endl;
          }
          }
          cout << "\n" << endl;
          sleep(1); 
          break;
        case 2:
          {
          if(!jugadores.empty()){
            // Se llama la función ordenaShell
            cout << "Clasificación ordenada" << endl;
            datos.ordenaShell(ordenado);

            // Leer los jugadores del vector ordenado
            for(const Player& jugador : ordenado){
              cout << jugador.get_jugador() << endl;
            }
          }
          else{
            cout << "Error al cargar." << endl;
          }
          }
          cout << "\n" << endl;
          sleep(1); 
          break;
        case 3:
          {
          // Llamar el recorrido en orden
          cout << "Jugadores en orden alfabético:\n" << arboljugadores.inorder() << endl;
          cin.ignore();
          sleep(3); // El programa duerme 3 segundos
          cout << "Recorrido Preorder:\n" << arboljugadores.preorder() << endl;
          }
          cout << "\n" << endl;
          break;
          sleep(1); 
        case 4:
          {
          cout << "Introduce el nombre del jugador que deseas buscar: " << endl;
          cin.ignore(); // Ignorar el salto de línea
          getline(cin, nombrebuscado);


          // Si la búsqueda es exitosa, true
          if (arboljugadores.buscar(nombrebuscado, jugadorbuscado)) {
            cout << "Jugador encontrado: " << jugadorbuscado.get_jugador() << endl;
          } 
          // Si no es exitosa, false
          else {
            cout << "No se encontró ningún jugador con ese nombre." << endl;
          }
          }
          cout << "\n" << endl;
          break;
          sleep(1); 
        case 5:
          {
          // Agregar nuevo jugador
          try {
            cout << "Nombre: " << endl;
            cin.ignore(); // Ignorar el salto de línea 
            getline(cin, nuevoNombre);
            cout << "Escriba el nuevo ID: ";
            cin >> nuevoID;
            cout << "Escriba el puntaje: ";
            cin >> nuevosPuntos;

            // Evitar el ciclo infinito
            if (cin.fail()) { // Verificar si la entrada tiene un error
              cin.clear();  // Restaura el estado de error a un estado válido
              // Limpia el búfer de entrada
              // Descartar 100 caracteres o detenerse hasta el siguiente salto de línea
              cin.ignore(100, '\n'); 
              cout << "Error: Ingresa un valor numérico válido." << endl;
              continue;  // Vuelve al inicio del ciclo
            }

          }
          // Estándar C++ para un argumento no válido
          catch (const std::invalid_argument& e){
            cout << "Error, usuario no valido." << endl;
          }

          // Manejo de excepción si no hay memoria
          try {
            // Crear nuevo objeto tipo Player
            Player nuevojugador(nuevoNombre, nuevoID, nuevosPuntos);

            // Agregar al árbol a través de insertar
            arboljugadores.InsertaJugador(nuevojugador);

            //Agregar a los vectores
            jugadores.push_back(nuevojugador);
            ordenado.push_back(nuevojugador);

            // Sobreescribir el archivo CSV con los datos del árbol
            arboljugadores.sobreescribir("players.csv");

          } 
          // Estándar C++ para OutOfMemory
          catch (const std::bad_alloc& e){
            cout << "Error, no hay suficiente memoria." << endl;
          }
          }
          cout << "\n" << endl;
          sleep(1); 
          break;
        case 6:
          {
          try{
            // Eliminar jugador
            cout << "Nombre: " << endl;
            cin.ignore(); // Ignorar el salto de línea
            getline(cin, nombrebuscado);
            // Se emplea la búsqueda 
            if (arboljugadores.buscar(nombrebuscado, jugadorbuscado)) {
              // Eliminar jugador del árbol
              arboljugadores.borraJugador(jugadorbuscado);
              
              // Eliminar jugador del vector jugadores
              datos.eliminarJugador(jugadores, nombrebuscado);

              // Eliminar jugador del vector jugadores (ordenado)
              datos.eliminarJugador(ordenado, nombrebuscado);
              
              // Sobreescribir el archivo CSV con los datos actualizados
              arboljugadores.sobreescribir("players.csv");
            } 
            // Si no es exitosa, false
            else {
              cout << "No se encontró ningún jugador con ese nombre." << endl;
            }
          } catch (const std::invalid_argument& e) {
            cout << "Error, usuario no valido." << endl;
          }
          }
          cout << "\n" << endl;
          sleep(1); 
          break;
        case 7:
          {
          cout << "Saliendo del programa..." << endl;
          }
          break;
      }
    } else {
      cout << "Opción invalida, elija una opción del menú." << endl;
      sleep(1); // El programa duerme 1 segundo
    }
  }while(opcion != 7);


  return 0;
}