/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "BibliotecaColaGenerica.h"
#include "Funcioneslaboratorio1.h"

void *leenumero(ifstream &arch){
    int dato, *d;
    arch>>dato;
    if(arch.eof()) return nullptr;
    d = new int;
    *d = dato;
    return d;
}

void imprimenumero(void *d,ofstream &arch){
    int *dato = (int *)d;
    arch<<right<<setw(4)<<*dato<<left;
}

void atiendeNumero(void *&cola){
    void *sale;
    while(not colavacia(cola)){
        sale = desencola(cola);
        int *dato = (int *)sale;
        delete dato;
    }
}

