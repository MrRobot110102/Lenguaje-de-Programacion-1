/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "PilaConRegistros.h"

void *leeregistro(ifstream &arch){
    void **registro = new void*[3];
    int cod,*codigo = new int;
    double *peso = new double;
    char *nombre,car;
    arch>>cod;
    if(arch.eof()) return nullptr;
    arch.get();
    *codigo = cod;
    nombre = leerCadena(arch,',');
    arch>>*peso;
    registro[0] = codigo;
    registro[1] = nombre;
    registro[2] = peso;
    return registro;
}

char *leerCadena(ifstream &arch,char car){
    char *aux, buff[200];
    arch.getline(buff,200,car);
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}

int cmpregistro(const void *a,const void *b){
    void **ai = (void **)a, **bi = (void **)b;
    void **registroA = (void **)(*ai), **registroB  = (void **)(*bi);
    double *pesoA = (double *)registroA[2], *pesoB = (double *)registroB[2];
    int *codA = (int *)registroA[0], *codB = (int *)registroB[0];
    if(*pesoB == *pesoA) return *codB - *codA;
    return (*pesoB - *pesoA);
}

void imprimeregistro(void *reg, ofstream &arch){
    void **registro = (void **)reg;
    int *codigo = (int *)registro[0];
    char *nombre = (char *)registro[1];
    double *peso = (double *)registro[2];
    arch<<left<<setw(10)<<*codigo<<setw(60)<<nombre<<right<<setw(10)<<*peso<<left<<endl;
}

