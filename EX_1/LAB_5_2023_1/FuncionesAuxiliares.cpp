/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"

void cargarCursos(const char *nomArch,char ***&cursos_datos,int *&cursos_credito,char ****&cursos_alumnos,double **&cursos_informacion_economica){
    ifstream archCursos(nomArch,ios::in);
    char *codigoCurso, *nombreCurso, *codigoEscala,*nombre,car;
    int creditos,flag = 0,j = 0;
    while(true){
        if(flag == 0) codigoCurso = leerCadena(archCursos);
        if(archCursos.eof()) break;
        nombreCurso = leerCadena(archCursos);
        archCursos>>creditos>>car;
        cout<<codigoCurso<<" "<<nombreCurso<<endl;
        while(true){
            codigoEscala = leerCadena(archCursos);
            nombre = leerCadena(archCursos);
            if(verificarError(nombre,codigoCurso)){
                //hay error, se lee nombre y siguiente codigo juntos,por lo que se separa nombre del siguiente curso y ya no se lee ese curso
                flag = 1;
                cout<<codigoEscala<<"   "<<nombre<<endl;
                break;
            }
            cout<<codigoEscala<<"   "<<nombre<<endl;
        }
    }
}

char *leerCadena(ifstream &arch){
    char *aux,buff[300];
    arch.getline(buff,300,',');
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}

int verificarError(char *&nombre,char *&codigoCurso){
    char buffCod[100];
    int aux,i,j=0,k=0;
    int cantidad = strlen(nombre);
    for (i = cantidad-1; i > 0 ; i--) {
        if(nombre[i] == '\n'){
            aux = i+1;
            break;
        }
    }
    if(i == 0) return 0;//no encontro error en el nombre por lo que se devuelve 0
    while(aux <= cantidad){
        buffCod[j] = nombre[aux];
        j++;
        aux++;
    }
    codigoCurso = new char[7];
    strcpy(codigoCurso,buffCod);
    nombre[i] = nombre[cantidad];
    return 1;
}