/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;
#include "FuncionesDePunterosVoid.h"

void leerDatos(void *&personal, int &nd){
    ifstream arch("personal.csv",ios::in);
    void *buffPersonal[30], **persona;
    while(true){
        buffPersonal[nd] = leerRegistro(arch);
        if(buffPersonal[nd] == nullptr) break;
        nd++;
    }
    persona = new void*[nd+1]{};
    for (int i = 0; i < nd; i++) persona[i] = buffPersonal[i];
    personal = persona;
}

void *leerRegistro(ifstream &arch){
    int *codigo,cod;
    char *nombre;
    double *sueldo;
    void **registro;
    codigo = new int;
    sueldo = new double;
    arch>>cod;
    if(arch.eof()) return nullptr;
    arch.get();
    *codigo = cod;
    nombre = leerCadena(arch,',');
    arch>>*sueldo;
    registro = new void*[3];
    registro[0] = codigo;
    registro[1] = nombre;
    registro[2] = sueldo;
    return registro;
}

char *leerCadena(ifstream &arch,char car){
    char *aux, buff[100];
    arch.getline(buff,100,car);
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}

void imprimirPersonal(void *pers){
    void **personal = (void **)pers;
    for (int i = 0; personal[i]; i++) imprimirDatos(personal[i]);
}

void imprimirDatos(void *pers){
    void **personal = (void **)pers;
    int *codigo = (int *)personal[0];
    char *nombre = (char *)personal[1];
    double *sueldo= (double *)personal[2];
    cout.precision(2);cout<<fixed;
    cout<<left<<setw(10)<<*codigo<<setw(60)<<nombre<<right<<setw(10)<<*sueldo<<left<<endl;
}

int cmpPunterosVoidCodigo(const void *a,const void *b){
    void **ai = (void **)a, **bi = (void **)b;
    void **registroA = (void **)(*ai), **registroB  = (void **)(*bi);
    int *codA = (int *)registroA[0], *codB = (int *)registroB[0];
    return *codA - *codB;
}
int cmpPunterosVoidNombres(const void *a,const void *b){
    void **ai = (void **)a, **bi = (void **)b;
    void **registroA = (void **)(*ai), **registroB  = (void **)(*bi);
    char *nombreA = (char *)registroA[1], *nombreB = (char *)registroB[1];
    return strcmp(nombreA,nombreB);
}
int cmpPunterosVoidSueldo(const void *a,const void *b){
    void **ai = (void **)a, **bi = (void **)b;
    void **registroA = (void **)(*ai), **registroB  = (void **)(*bi);
    double *sueldoA = (double *)registroA[2], *sueldoB = (double *)registroB[2];
    return *sueldoA - *sueldoB;
}