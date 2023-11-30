// Materia: Programación I, Paralelo 4
// Autor: Jaime Ignacio Huaycho Clavel
// Fecha creación: 29/11/2023
// Fecha modificación: 29/11/2023
// Número de ejericio: 6
// Problema planteado: Escriba un programa que tome como entrada el fichero del ejercicio 4 y una condición sobre el
//                      campo Precio. La condición podrá ser:
//                      Precio mayo o igual a 100 o cualquier otro dato ingresado por teclado.
//                      Este programa debe generar como salida un fichero llamado "salida.dat" que contenga todos
//                      aquellos artículos para los que se cumple la condición de entrada.
//                      Mostrar el archivo de salida “salida.dat” 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct Producto {
    int codigo;
    string nombre;
    int cantidad;
    float precio;
};

bool cumplePrecio(Producto prod, float precioBase) {
    return prod.precio >= precioBase;
}

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void cargarDesdeArchivo(string archivoEntrada, vector<Producto>& inventario) {
    ifstream archivo(archivoEntrada);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo: " << archivoEntrada << endl;
        exit(1);
    }
    string linea;
    while (getline(archivo, linea)) {
        vector<string> tokens = split(linea, ';');
        if (tokens.size() == 4) {
            Producto temp;
            temp.codigo = stoi(tokens[0]);
            temp.nombre = tokens[1];
            temp.cantidad = stoi(tokens[2]);
            temp.precio = stof(tokens[3]);
            inventario.push_back(temp);
        }
    }
    archivo.close();
}

void guardarEnArchivo(const string& archivoSalida, const vector<Producto>& productosFiltrados) {
    ofstream archivo(archivoSalida);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo: " << archivoSalida << endl;
        exit(1);
    }
    for (size_t i = 0; i < productosFiltrados.size(); ++i) {
        archivo << productosFiltrados[i].codigo << ";"<< productosFiltrados[i].nombre << ";"<< productosFiltrados[i].cantidad << ";"<< productosFiltrados[i].precio << ";" << endl;
    }
    archivo.close();
}

int main() {
    vector<Producto> inventarioTotal, inventarioFiltrado;
    cargarDesdeArchivo("ALMACEN1.txt", inventarioTotal);
    float precioMinimo = 100.00;
    for (size_t i = 0; i < inventarioTotal.size(); ++i) {
        if (cumplePrecio(inventarioTotal[i], precioMinimo)) {
            inventarioFiltrado.push_back(inventarioTotal[i]);
        }
    }
    guardarEnArchivo("Salida.det", inventarioFiltrado);
    return 0;
}

