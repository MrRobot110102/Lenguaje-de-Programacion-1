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
enum cola {INI,FINP1,FINP2,FINP3,FIN};
enum nodo {DATO,SIG};

void creacola(void *&cola,void *(*lee)(ifstream &),int (*prioridad) (void *),const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void *dato;
    void **cl;
    cl = new void*[5];
    cl[INI] = nullptr;
    cl[FINP1] = nullptr;
    cl[FINP2] = nullptr;
    cl[FINP3] = nullptr;
    cl[FIN] = nullptr;
    cola = cl;
    while(true){
        dato = lee(arch);
        if(dato == nullptr) break;
        encolar(cola,dato,prioridad);
    }
}

void encolar(void *&cola,void *dato,int (*prioridad) (void *)){
    void **cl = (void **)cola, **nuevo,**recorrido;
    int prioridadNuevo,prioridadFin;
    nuevo = new void*[2];
    nuevo[DATO] = dato;
    nuevo[SIG] = nullptr;
    prioridadNuevo = prioridad(dato);
    if(colaVacia(cola)){
        cl[INI] = nuevo;
        cl[FIN] = nuevo;
        if(prioridadNuevo == 1) cl[FINP1] = nuevo;
        else if(prioridadNuevo == 2) cl[FINP2] = nuevo;
        else if(prioridadNuevo == 3) cl[FINP3] = nuevo;
    }else{
        if(prioridadNuevo == 1){
            recorrido = (void **)cl[FINP1];
            if(recorrido == nullptr){//primer dato en prioridad 1
                nuevo[SIG] = cl[INI];
                cl[INI] = nuevo;
                cl[FINP1] = nuevo;
            }else{
                if(recorrido[SIG] == nullptr) cl[FIN] = nuevo;
                else nuevo[SIG] = recorrido[SIG];
                recorrido[SIG] = nuevo;
                cl[FINP1] = nuevo;
            }
        }
        if(prioridadNuevo == 2){
            recorrido = (void **)cl[FINP2];
            if(recorrido == nullptr){//primer dato en prioridad 2
                void **aux = (void **)cl[FIN];
                prioridadFin = prioridad(aux[DATO]);
                if(prioridadFin == 1){
                    aux[SIG] = nuevo;
                    cl[FIN] = nuevo;
                    cl[FINP2] = nuevo;
                }   
                if(prioridadFin == 3){
                    if(cl[FINP1] == nullptr){
                        nuevo[SIG] = cl[INI];
                        cl[FINP2] = nuevo;
                        cl[INI] = nuevo;
                    }else{
                        void **aux = (void **)cl[FINP1];
                        nuevo[SIG] = aux[SIG];
                        aux[SIG] = nuevo;
                        cl[FINP2] = nuevo;
                    }
                }
            }else{
                void **aux = (void **)cl[FINP2];
                if(cl[FINP2] == cl[FIN]){
                   aux[SIG] = nuevo;
                   cl[FIN] = nuevo;
                   cl[FINP2] = nuevo;
                }else{ 
                   nuevo[SIG] = aux[SIG];
                   aux[SIG] = nuevo;
                   cl[FINP2] = nuevo;
                }
            }
        }
        if(prioridadNuevo == 3){
            void **aux = (void **)cl[FIN];
            aux[SIG] = nuevo;
            cl[FIN] = nuevo;
            cl[FINP3] = nuevo;
        }
    } 
}

void imprimeCola(void *cola,void (*imprime)(void *,ofstream &),void (*imprimeprioridad)(void *,void *,void *,ofstream &),const char *nombArch){
    ofstream archReporte(nombArch,ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }           
    void **cl = (void **)cola;
    void **recorrido = (void **)cl[INI];
    while(recorrido){
        imprime(recorrido[DATO],archReporte);
        recorrido = (void **)(recorrido[SIG]);
    }
    void **prioridad1 = (void **)cl[FINP1];
    void **prioridad2 = (void **)cl[FINP2];
    void **prioridad3 = (void **)cl[FINP3];
    imprimeprioridad(prioridad1[DATO],prioridad2[DATO],prioridad3[DATO],archReporte);
}

void descargarcola(void *&cola,void (*muestra)(int,void *,ofstream &),const char *nombArch){
    ofstream archReporte(nombArch,ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int i=1;
    void *sale;
    while(not colaVacia(cola)){
        sale = desencola(cola);
        muestra(i,sale,archReporte);
        i++;
    }
    cola = nullptr;
}

void *desencola(void *cola){
    if(colaVacia(cola)) return nullptr;
    void **cl = (void **)cola;
    void **sale = (void **)cl[INI];
    cl[INI] = sale[SIG];
    void *dato = sale[DATO];
    if(cl[INI] == cl[FIN]){
        cl[FIN] = nullptr;
        cl[FINP1] = nullptr;
        cl[FINP2] = nullptr;
        cl[FINP3] = nullptr;
    }
    delete sale;
    return dato;
}

int colaVacia(void *cola){
    void **cl=(void **)cola;
    return cl[INI]==nullptr;
}