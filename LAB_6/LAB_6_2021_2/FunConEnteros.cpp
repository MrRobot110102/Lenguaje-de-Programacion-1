/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FunConEnteros.h"

void *leenumero(ifstream &arch){
    int dato, *d;
    arch>>dato;
    if(arch.eof()) return nullptr;
    d = new int;
    *d = dato;
    return d;
}

void imprimirnum(void *d,ofstream &arch){
    int *dato = (int *)d;
    arch<<right<<setw(4)<<*dato<<endl;
}

int prioridadnumero(void *d){
    int *dato = (int *)d;
    if(*dato < 50) return 3;
    else if(*dato >= 50 and *dato<=100) return 2;
    else if(*dato > 100) return 1;
}

void muestranumero(int i,void *d,ofstream &arch){
    int *dato = (int *)d;
    arch<<right<<setw(3)<<i<<left<<setw(4)<<right<<setw(5)<<*dato<<left<<endl;
    delete dato;
}

void imprimeprioridadnumero(void *prioridad1,void *prioridad2, void *prioridad3,ofstream &archReporte){
    int *pri1 = (int *)prioridad1;
    int *pri2 = (int *)prioridad2;
    int *pri3 = (int *)prioridad3;
    archReporte<<left<<"Prioridad 1: "<<*pri1<<endl;
    archReporte<<left<<"Prioridad 2: "<<*pri2<<endl;
    archReporte<<left<<"Prioridad 3: "<<*pri3<<endl;
}
