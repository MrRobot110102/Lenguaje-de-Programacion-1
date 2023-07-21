/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "PriorityQueu.h"
enum cola {INI,FIN};
enum nodo {DATO,ANT,SIG};

void creacola(void *&cola,void *(*lee)(ifstream &),int (*prioridad)(void *),const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void *dato;
    void **cl = new void *[2];
    cl[INI] = nullptr;
    cl[FIN] = nullptr;
    cola = cl;
    while(true){
        dato = lee(arch);
        if(dato == nullptr) break;
        encolar(cola,dato,prioridad);
    }
}

void encolar(void *&cola,void *dato,int (*prioridad)(void *)){
    void **cl = (void **)cola, **nuevo,**recorrido;
    nuevo = new void*[3];
    nuevo[DATO] = dato;
    nuevo[SIG] = nullptr;
    nuevo[ANT] = nullptr;
    if(colavacia(cola)){
        cl[INI] = nuevo;
        cl[FIN] = nuevo;
        return;
    }
    int prioridadNuevo = prioridad(dato);
    int prioridadRecorrido;
    recorrido =(void **)cl[FIN];
    while(recorrido){
        prioridadRecorrido = prioridad(recorrido[DATO]);
        if((prioridadRecorrido-prioridadNuevo)>=0) break;
        if(recorrido[ANT] == nullptr) break;//para el caso que el nodo nuevo sea la cabeza de cola
        recorrido = (void **)(recorrido[ANT]);    
    }
    if(recorrido[ANT] == nullptr and (prioridadRecorrido - prioridadNuevo < 0)){//nuevo dato cabeza 
        nuevo[SIG] = recorrido;
        cl[INI] = nuevo;
        recorrido[ANT] = nuevo;
    }else{
        if(recorrido[SIG] == nullptr){
            recorrido[SIG] = nuevo;
            nuevo[ANT] = recorrido;
            cl[FIN] = nuevo;
        }else{
            void **aux = (void **)recorrido[SIG];
            recorrido[SIG] = nuevo;
            aux[ANT] = nuevo;
            nuevo[SIG] = aux;
            nuevo[ANT] = recorrido;
        }
    }
}

int colavacia(void *cola){
    void **cl = (void **)cola;
    return cl[INI] == nullptr;
}
    
void prueba(void *cola,void (*imprime)(void *,ofstream &),const char *nombArch){
    ofstream archReporte(nombArch,ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    archReporte.precision(2);archReporte<<fixed;
    if(colavacia(cola)) archReporte<<"COLA VACIA"<<endl;
    void **cl = (void **)cola;
    void **recorrido = (void **)cl[INI];
    while(recorrido){
        imprime(recorrido[DATO],archReporte);
        recorrido = (void **)(recorrido[SIG]);
    }
}
    
void descargacola(void *&cola,void (*imprime)(void *,ofstream &),const char *nombArch){
    ofstream archReporte(nombArch,ios::out);
    archReporte.precision(2);archReporte<<fixed;
    int i=1;
    void *sale;
    while(not colavacia(cola)){
        sale = desencola(cola);
        archReporte<<right<<setw(3)<<i<<')'<<"   "<<left;
        imprime(sale,archReporte);
        i++;
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