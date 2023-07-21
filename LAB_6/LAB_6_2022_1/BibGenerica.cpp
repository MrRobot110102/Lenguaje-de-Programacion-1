/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "BibGenerica.h"
enum arbolGenerico {DATO,IZQ,DER};

void creaarbol(void *&arbol,void *(*lee)(ifstream &),int (*cmp)(const void *,const void *),const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    arbol = nullptr;
    void *dato;
    while(true){
        dato = lee(arch);
        if(dato == nullptr) break;
        insertanodo(arbol,dato,cmp);
    }
}

void insertanodo(void *&arbol,void *dato,int (*cmp)(const void *,const void *)){
    if(arbolvacio(arbol)){
        void **nodo = new void*[3];
        nodo[DATO] = dato;
        nodo[IZQ] = nullptr;
        nodo[DER] = nullptr;
        arbol = nodo;
        return;
    }
    void **abb = (void **)arbol;
    if(cmp(abb[DATO],dato) > 0) insertanodo(abb[IZQ],dato,cmp);
    else insertanodo(abb[DER],dato,cmp);
}

int arbolvacio(void *arbol){
    return arbol == nullptr;
}
    
void muestraarbol(void *arbol,void (*imprime)(void *,ofstream &,int &),const char *nombArch){
    ofstream archReporte(nombArch,ios::out);
    int cabecera = 0;
    enorden(arbol,imprime,archReporte,cabecera);
}

void enorden(void *arbol,void (*imprime)(void *,ofstream &,int &),ofstream &arch,int &cabecera){
    if(arbolvacio(arbol)) return;
    void **abb = (void **)arbol;
    enorden(abb[IZQ],imprime,arch,cabecera);
    imprime(abb[DATO],arch,cabecera);
    enorden(abb[DER],imprime,arch,cabecera);
}