// Materia: Programación I, Paralelo 4
// Autor: Jaime Ignacio Huaycho Clavel
// Fecha creación: 20/11/2023
// Fecha modificación: 26/11/2023
// Número de ejericio: 3
// Problema planteado: Amplíe el programa anterior que procesa clientes de una agencia matrimonial para que tome
//                      los datos de todos los candidatos a estudiar del fichero PERSONAS.DAT del ejercicio anterior,
//                      lea el cliente del teclado y finalmente genere como resultado un listado por pantalla con los
//                      nombres de los candidatos aceptados y un fichero llamado ACEPTADOS.DAT con toda la
//                      información correspondiente a los candidatos aceptados.
//                      Una persona del fichero PERSONAS.DAT se considerará aceptable como candidato si tiene
//                      diferente sexo y que haya nacido en el mes y año (El programa debe ser capaz de trabajar con
//                      cualquier número de personas en el fichero PERSONAS.DAT).
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct structpersonas{
    char nombre[30];
    int edad;
    char sexo;
    char fecha_nacimiento[10];
}usu[100];

int cargardatos(){
    ifstream archivo;
    structpersonas persona;
    int c=0;
    archivo.open("PERSONAS.bin",ios::in | ios::binary);
    while (archivo.read((char*)&persona, sizeof(structpersonas))){
        usu[c].nombre[30]=*persona.nombre;
        usu[c].edad=persona.edad;
        usu[c].edad=persona.sexo;
        usu[c].fecha_nacimiento[10]=*persona.fecha_nacimiento;
        c++;
    }
    return c;
}

void guardar_aceptados(int c,char fecha_actual[]){
    ofstream arch;
    arch.open("PERSONAS.DAT");
    for (int i=0;i<c;i++){
        if (fecha_actual==usu[i].fecha_nacimiento){
            arch<<usu[i].nombre<<";"<<usu[i].edad<<";"<<usu[i].sexo<<";"<<usu[i].fecha_nacimiento<<";\n";
        }
    }
    arch.close();
}

void inicio(){
    remove("PERSONAS.DAT");
    char fecha_actual[10];
    cout<<"Fehca auctual: ";cin>>fecha_actual;
    int c=cargardatos();
    guardar_aceptados(c,fecha_actual);
}

int main(){
    inicio();
    return 0;
}