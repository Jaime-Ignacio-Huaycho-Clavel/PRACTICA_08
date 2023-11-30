// Materia: Programación I, Paralelo 4
// Autor: Jaime Ignacio Huaycho Clavel
// Fecha creación: 29/11/2023
// Fecha modificación: 29/11/2023
// Número de ejericio: 8
// Problema planteado: Escribir un programa que genere a partir de un fichero de entrada que contiene una tabla de
//                      números reales otro fichero de salida <nombre>.BIN grabado en formato binario.
//                      Ej:
//                                  1.23 3.45 12.5
//                                  4.8 3.9 0.83 ........................
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const char* nombreArchivoEntrada = "numeros.txt";
const char* nombreArchivoSalida = "numeros.bin";

void convertirAFormatoBinario(const char* nombreArchivoEntrada, const char* nombreArchivoSalida) {
    ifstream archivoEntrada(nombreArchivoEntrada);
    archivoEntrada.open(nombreArchivoEntrada);
    ofstream archivoSalida(nombreArchivoSalida, ios::binary);
    archivoSalida.open(nombreArchivoSalida,ios::app | ios::binary);
    double numero;
    while (archivoEntrada >> numero) {
        archivoSalida.write(reinterpret_cast<char*>(&numero), sizeof(numero));
    }
    archivoEntrada.close();
    archivoSalida.close();
}

int main() {

    convertirAFormatoBinario(nombreArchivoEntrada, nombreArchivoSalida);
    return 0;
}

