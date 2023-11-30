// Materia: Programación I, Paralelo 4
// Autor: Jaime Ignacio Huaycho Clavel
// Fecha creación: 29/11/2023
// Fecha modificación: 29/11/2023
// Número de ejericio: 4
// Problema planteado: Codifique un programa que cree un fichero para contener los datos relativos a los artículos de
//                      un almacén.
//                      Para cada artículo habrá de guardar la siguiente información:
//                          • Código del artículo (Numérico)
//                          • Nombre del artículo (Cadena de caracteres)
//                          • Existencias actuales (Numérico)
//                          • Precio (Numérico decimal).
//                      Se deberán pedir datos de cada artículo por teclado hasta que como código se teclee el código
//                      0.
//                      El fichero se habrá de crear ordenado por el código del artículo.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct structalmacen{
    int codigo;
    string nombre;
    int existencia;
    float precio;
}articulo[100];

void ordenar(int cant){
    int temp1,temp3;
    string temp2;
    float temp4;
    for (int i=0;i<cant;i++){
        for (int j=0;j<(cant-1-i);j++){
            if (articulo[j].codigo>articulo[j+1].codigo){
                temp1=articulo[j+1].codigo;
                articulo[j+1].codigo=articulo[j].codigo;
                articulo[j].codigo=temp1;
                temp2=articulo[j+1].nombre;
                articulo[j+1].nombre=articulo[j].nombre;
                articulo[j].nombre=temp2;
                temp3=articulo[j+1].existencia;
                articulo[j+1].existencia=articulo[j].existencia;
                articulo[j].existencia=temp3;
                temp4=articulo[j+1].precio;
                articulo[j+1].precio=articulo[j].precio;
                articulo[j].precio=temp4;
            }
        }
    }
}

void guardar1(int cant){
    ofstream archivo;
    archivo.open("ALMACEN1.txt");
    for (int i=0;i<cant;i++){
        archivo<<articulo[i].codigo<<";"<<articulo[i].nombre<<";"<<articulo[i].existencia<<";"<<articulo[i].precio<<";\n";
    }
    archivo.close();
}

void guardar2(int cant){
    ofstream archivo;
    archivo.open("ALMACEN2.txt");
    for (int i=0;i<cant;i++){
        archivo<<articulo[i].codigo<<";"<<articulo[i].nombre<<";"<<articulo[i].existencia<<";"<<articulo[i].precio<<";\n";
    }
    archivo.close();
}

int main(){
    remove("ALMACEN1.txt");
    remove("ALMACEN2.txt");
    int val_codigo,cant=0;
    while (true){
        cout<<"Codigo del articulo: ";cin>>val_codigo;
        if (val_codigo==0)
            break;
        articulo[cant].codigo=val_codigo;
        cout<<"Nombre del articulo: ";cin>>articulo[cant].nombre;
        cout<<"Existenacias actuales: ";cin>>articulo[cant].existencia;
        cout<<"Precio: ";cin>>articulo[cant].precio;
        cant++;
        cout<<"\n";
    }
    guardar1(cant);
    ordenar(cant);
    guardar2(cant);
    return 0;
}