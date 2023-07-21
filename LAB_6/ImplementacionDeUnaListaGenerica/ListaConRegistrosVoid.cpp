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
#include "ListaConRegistrosVoid.h"

void *leeRegistro(ifstream &arch){
    void **registro;
    int *codigo,cod;
    char *nombre;
    double *sueldo;
    codigo = new int;
    sueldo = new double;
    arch>>cod;
    if(arch.eof()) return nullptr;
    arch.get();
    *codigo = cod;
    nombre = leeNomb(arch);
    arch>>*sueldo;
    registro = new void*[3];
    registro[0] = codigo;
    registro[1] = nombre;
    registro[2] = sueldo;
    return registro;
}

int cmpRegCodigo(const void *a,const void *b){
    void **ai = (void **)a, **bi = (void **)b;
    int *codigoA = (int *)ai[0], *codigoB = (int *)bi[0];
    return *codigoA - *codigoB;
}

int cmpRegNombre(const void *a,const void *b){
    void **ai = (void **)a, **bi = (void **)b;
    char *nombreA = (char *)ai[1], *nombreB = (char *)bi[1];
    return strcmp(nombreA,nombreB);
}

int cmpRegSueldo(const void *a,const void *b){
    void **ai = (void **)a, **bi = (void **)b;
    double *sueldoA = (double *)ai[2], *sueldoB = (double *)bi[2];
    return *sueldoA - *sueldoB;
}

char *leeNomb(ifstream &arch){
    char *aux, buff[100];
    arch.getline(buff,100,',');
    aux  = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}

void imprimeRegistro(void *reg){
    void **registro = (void **)reg;
    int *codigo = (int *)registro[0];
    char *nombre = (char *)registro[1];
    double *sueldo = (double *)registro[2];
    cout.precision(2);cout<<fixed;
    cout<<left<<setw(10)<<*codigo<<setw(60)<<nombre<<right<<setw(10)<<*sueldo<<left<<endl;
}

void eliminaRegistro(void *reg){
    void **registro = (void **)reg;
    int *codigo = (int *)registro[0];
    char *nombre = (char *)registro[1];
    double *sueldo = (double *)registro[2];
    delete codigo;
    delete nombre;
    delete sueldo;
    delete registro;
}
