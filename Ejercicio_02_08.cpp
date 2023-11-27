// Materia: Programación I, Paralelo 4
// Autor: Jaime Ignacio Huaycho Clavel
// Fecha creación: 20/11/2023
// Fecha modificación: 26/11/2023
// Número de ejericio: 2
// Problema planteado: Escriba un programa que cree un fichero de texto llamado "PERSONAS.BIN" en el que se
//                      guarde la información de un número indeterminado de personas.
//                      La información que se guardará por cada persona será:
//                      • Nombre: De 1 a 30 caracteres.
//                      • Edad numérico (>= 1 y <=100)
//                      • Sexo CHAR (M/F).
//                      • FechaNacimiento CHAR(10) (formato dd/mm/yyyy)
//                      La información correspondiente a cada persona se leerá del teclado.
//                      El proceso finalizará cuando se teclee un campo "Nombre" que esté solamente con el carácter
//                      de espacio.
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct structpersonas{
    char nombre[30];
    int edad;
    char sexo;
    char fecha_nacimiento[10];
};

void copiardatos(structpersonas persona){
    ofstream archivo;
    archivo.open("PERSONAS.bin",ios::app | ios::binary);
    archivo.write((char*)&persona,sizeof(structpersonas));
    archivo.close();
}

structpersonas ingresardatos(){
    structpersonas persona;
    cout<<"Nombre: ";
    cin.getline(persona.nombre,30);
    cout<<"Edad: ";
    cin>>persona.edad;
    cout<<"Sexo: ";
    cin>>persona.sexo;
    cout<<"Fecha de nacimiento: "
    ;cin.getline(persona.fecha_nacimiento,10);
    cin.ignore();
    return persona;
}

int main(){
    remove("PERSONAS.bin");
    while (true){
        structpersonas persona;
        persona=ingresardatos();
        if (persona.nombre[0]==' ')
            break;
        else{
            copiardatos(persona);
        }
    }
    return 0;
}