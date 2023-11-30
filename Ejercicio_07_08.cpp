// Materia: Programación I, Paralelo 4
// Autor: Jaime Ignacio Huaycho Clavel
// Fecha creación: 29/11/2023
// Fecha modificación: 29/11/2023
// Número de ejericio: 7
// Problema planteado: Escriba un programa que tenga como entrada un fichero que contenga un texto y dé como
//                      resultado una estadística del número de palabras.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string obtener_texto(){
    ifstream archivo;
    string texto;
    archivo.open("texto_ejercicio7.txt");
    getline(archivo,texto);
    return texto;
}

int main(){
    string texto=obtener_texto();
    int cont=0;
    for (int i=0;i<texto.size();i++){
        if (texto[i]==' ')
            cont++;
    }
    cout<<"El numero de palabras es "<<cont+1;
    return 0;
}