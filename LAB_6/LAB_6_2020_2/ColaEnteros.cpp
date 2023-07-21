/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "ColaEnteros.h"
    
void *leenumero(ifstream &arch){
    void **registro = new void *[2];
    int prioridad;
    int *pri = new int;
    int *d = new int;
    arch>>prioridad;
    if(arch.eof()) return nullptr;
    arch>>*d;
    *pri = prioridad;
    registro[0] = pri;
    registro[1] = d;
    return registro;
}

int prioridadnumero(void *d){
    void **registro = (void **)d;
    int *prioridad = (int *)registro[0];
    return *prioridad;
}

void imprimenumero(void *d,ofstream &arch){
    void **registro = (void **)d;
    int *prioridad = (int *)registro[0];
    int *dato = (int *)registro[1];
    arch<<'('<<*prioridad<<','<<*dato<<')'<<endl;
}
