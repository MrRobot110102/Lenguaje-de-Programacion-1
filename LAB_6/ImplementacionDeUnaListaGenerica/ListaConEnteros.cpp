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

void *leeEntero(ifstream &arch){
    int dato, *d;
    arch>>dato;
    if(arch.eof()) return nullptr;
    d = new int;
    *d = dato;
    return d;
}

int cmpEntero(const void *a,const void *b){
    int *ai = (int *)a, *bi = (int *)b;
    return *ai - *bi;
}

void imprimeEntero(void *d){
    int *dato = (int *)d;
    cout<<right<<setw(4)<<*dato<<endl;
}

void eliminaEntero(void *d){
    int *dato = (int *)d;
    delete dato;
}

