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
enum CreacionCola {INI,FIN};
enum DatosCola {DATO,SIG};

void creaCola(void *&cola,void *(*lee)(ifstream &),const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void **cl = new void *[2];
    void *dato;
    cl[INI] = nullptr;
    cl[FIN] = nullptr;
    cola = cl;
    while(true){
        dato = lee(arch);
        if(dato == nullptr) break;
        encola(cola,dato);
    }
}

void encola(void *&cola, void *dato){
    void **nuevo =new void *[2];
    void **cl = (void **)cola;
    nuevo[DATO] = dato;
    nuevo[SIG] = nullptr;
    if(colavacia(cola)){
        cl[INI] = nuevo;
        cl[FIN] = nuevo;
        return;
    }
    void **aux = (void **)cl[FIN];
    aux[SIG] = nuevo;
    cl[FIN] = nuevo;
}

int colavacia(void *cola){
    void **cl = (void **)cola;
    return cl[INI] == nullptr;
}

void imprimir(void *cola,void (*imprime)(void *,ofstream &),const char *nombArch){
    ofstream arch(nombArch,ios::out);
    arch.precision(2);arch<<fixed;
    void **cl = (void **)cola;
    void **recorrido = (void **)cl[INI];
    if(colavacia(cola)) arch<<"COLA VACIA"<<endl;
    while(recorrido){
        imprime(recorrido[DATO],arch);
        arch<<endl;
        recorrido = (void **)recorrido[SIG];
    }
}

void *desencola(void *cola){
    if(colavacia(cola)) return nullptr;
    void **cl = (void **)cola;
    void **sale = (void **)cl[INI];
    cl[INI] = sale[SIG];
    void *dato = sale[DATO];
    if(cl[INI] == cl[FIN]) cl[FIN] = nullptr;
    delete sale;
    return dato;
}