/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FunNumeros.h"
enum arbolGenerico {DATO,IZQ,DER};

void *leenumero(ifstream &arch){
    int dato, *d = new int;
    arch>>dato;
    if(arch.eof()) return nullptr;
    *d = dato;
    return d;
}

int cmpnumero(const void *a,const void *b){
    int *ai = (int *)a, *bi = (int *)b;
    return *ai - *bi;
}

void imprimenumero(void *d,ofstream &arch, int &cabecera){
    int *dato = (int *)d;
    arch<<right<<setw(4)<<*dato<<left<<endl;
}
