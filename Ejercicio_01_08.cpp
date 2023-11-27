// Materia: Programación I, Paralelo 4
// Autor: Jaime Ignacio Huaycho Clavel
// Fecha creación: 26/11/2023
// Fecha modificación: 23/11/2023
// Número de ejericio: 1
// Problema planteado: Escribir un programa con la opción de encriptar y de desencriptar un fichero de texto.
//                      La encriptación consiste en que dado un fichero de texto de entrada genere otro fichero de
//                      salida de extensión <nombre>.COD donde el texto estará codificado (encriptado).
//                      Esta codificación consiste en reemplazar cada carácter por el tercero siguiente según la tabla
//                      ASCII.
//                      La opción de desencriptado consiste en leer un fichero <nombre>.COD y recuperar la
//                      información original.
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void encriptar(string archivoEntrada,string archivoSalida) {
    ifstream entrada(archivoEntrada);
    ofstream salida(archivoSalida + ".COD");

    char c;
    while (entrada.get(c)){
        salida.put(static_cast<char>(c+3));
    }
    entrada.close();
    salida.close();
}

void desencriptar(string archivoEntrada,string archivoSalida) {
    ifstream entrada(archivoEntrada);
    ofstream salida(archivoSalida);
    char c;
    while (entrada.get(c)) {
        salida.put(static_cast<char>(c - 3));
    }
    entrada.close();
    salida.close();
}

int main() {
    string archivo="Ejercicio_01";
    int opcion;
    cout<<"1) Encriptar\n2) Desencriptar\nOpcion: ";
    cin>>opcion;
    if (opcion==1) {
        encriptar(archivo+".txt", archivo);
        cout<<"Archivo encriptado con éxito."<<endl;
    } else if (opcion==2) {
        desencriptar(archivo+".COD", archivo+"_desencriptado.txt");
        cout<<"Archivo desencriptado con éxito."<<endl;
    }
    return 0;
}