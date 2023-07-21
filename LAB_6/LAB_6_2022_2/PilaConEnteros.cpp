/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "PilaConEnteros.h"

void *leenumero(ifstream &arch){
    int dato, *d;
    arch>>dato;
    if(arch.eof()) return nullptr;
    d = new int;
    *d = dato;
    return d;
}

int cmpnumero(const void *a,const void *b){
    void **ai = (void **)a, **bi = (void **)b;
    int *codA = (int *)(*ai), *codB = (int *)(*bi);
    return *codB - *codA;
}

void imprimenumero(void *d,ofstream &arch){
    int *dato = (int *)d;
    arch<<right<<setw(4)<<*dato<<endl;
}

