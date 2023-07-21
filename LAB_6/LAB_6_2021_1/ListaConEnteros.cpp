/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "ListaConEnteros.h"

void *leenum(ifstream &arch){
    int dd,mm,aa, *fecha;
    char buff[150],car;
    fecha = new int;
    arch.getline(buff,150,',');
    if(arch.eof()) return nullptr;
    arch.getline(buff,150,',');
    arch>>dd>>car>>mm>>car>>aa>>car;
    *fecha = aa * 10000 + mm * 100 + dd;
    arch.getline(buff,150);
    return fecha;
}

int cmpnum(const void *a,const void *b){
    int *ai = (int *)a, *bi = (int *)b;
    return *ai - *bi;
}

void imprimenum(void *d,ofstream &arch,void *&dAnterior){
    int *dato = (int *)d, *datoAnterior;
    if(dAnterior == nullptr){//primer Dato
        dAnterior = d;
        arch<<right<<setw(4)<<*dato<<endl;
    }else{
        datoAnterior = (int *)dAnterior;
        if(*datoAnterior != *dato){
            arch<<right<<setw(4)<<*dato<<endl;
            dAnterior = d;
        }
    }
}