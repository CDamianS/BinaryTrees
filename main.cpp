#include <cstddef>
#include <iostream>
#include <time.h>
#include <algorithm>
#include <fstream>
#include <sstream>
#define NOMBRE_ARCHIVO "bitacora.csv"
using namespace std;
#include "lista.h"
#include "hashtablevd.h"
#include "bst.h"

int main(int argc, char *argv[]) {
  ifstream archivo(NOMBRE_ARCHIVO);
  string linea;
  char delimitador = ',';
  // Leemos la primer línea para descartarla, pues es el encabezado
  getline(archivo, linea);
  // Leemos todas las líneas
  BST<string> bst;
  while (getline(archivo, linea)) {
    stringstream stream(linea); // Convertir la cadena a un  stream
    string id, first_name, last_name, gender, dob, phone, email, ZIP, city,
        state;
    // Extraer todos los valores de esa fila

    getline(stream, id, delimitador);
    getline(stream, first_name, delimitador);
    getline(stream, last_name, delimitador);
    getline(stream, gender, delimitador);
    getline(stream, dob, delimitador);
    getline(stream, phone, delimitador);
    getline(stream, email, delimitador);
    getline(stream, ZIP, delimitador);
    getline(stream, city, delimitador);
    getline(stream, state, delimitador);
    // Persona persona(id, ZIP, first_name, last_name, city);
    // BST
    bst.insert(city);
  }
  // cout << bst << endl;

  cout << "root: " << bst.getroot() << endl;
  bst.remove("Marina");
  cout << "root: " << bst.getroot() << endl;
  bst.ComparadorHeight();
  // bst.inOrden();
  return 0;
}
