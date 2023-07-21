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
#include "BibliotecaPilaGenerica.h"
enum pila {CIMA,NUMDATOS};
enum nodo {SIG,DATO};

void cargaarreglo(void *&arreglo,int (*cmp)(const void *,const void *),void *(*lee)(ifstream &),const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void *aux[100], **arr;
    int numDatos = 0;
    while(true){
        aux[numDatos] = lee(arch);
        if(aux[numDatos] == nullptr) break;
        numDatos++;
    }
    arr = new void*[numDatos+1]{};
    for (int i = 0; i < numDatos; i++) arr[i] = aux[i];
    arreglo = arr;
    qsort(arreglo,numDatos,sizeof(void *),cmp);
}
    
void cargapila(void *&pilaini,void *arreglo){
    void **pila = new void *[2];
    void **arr = (void **)arreglo;
    int *longitud = new int;
    *longitud = 0;
    pila[CIMA] = nullptr;
    pila[NUMDATOS] = longitud;
    pilaini = pila;
    for (int i = 0; arr[i]; i++) push(pilaini,arr[i]);
}

void push(void *pilaini,void *d){
    void **pila = (void **)pilaini;
    void **nuevo = new void *[2];
    nuevo[SIG] = nullptr;
    nuevo[DATO] = d;
    int *longitud = (int *)pila[NUMDATOS];
    (*longitud)++;
    if(pilaVacia(pilaini)){
        pila[CIMA] = nuevo;
        return;
    }
    nuevo[SIG] = pila[CIMA];
    pila[CIMA] = nuevo;
}

void *pop(void *pila){
    if(pilaVacia(pila)) return nullptr;
    void **pl = (void **)pila;
    void **recorrido = (void **)pl[CIMA];
    int *longitud = (int *)pl[NUMDATOS];
    pl[CIMA] = recorrido[SIG];
    (*longitud)--;
    void *dato = recorrido[DATO];
    delete recorrido;
    return dato;
}

int pilaVacia(void *pila){
    void **pl = (void **)pila; 
    return pl[CIMA] == nullptr;
}

void muevepila(void *&pilaini,void *&pilafin){
    void **plfin = new void *[2];
    int *longitud = new int;
    *longitud = 0;
    plfin[CIMA] = nullptr;
    plfin[NUMDATOS] = longitud;
    pilafin = plfin;
    
    void **pila = (void **)pilaini;
    int *n = (int *)pila[NUMDATOS];

    void *pilaAux;
    void **plAux = new void *[2];
    int *lonAux = new int;
    *lonAux = 0;
    plAux[CIMA] = nullptr;
    plAux[NUMDATOS] = lonAux;
    pilaAux = plAux;
    
    hanoi(*n,pilaini,pilaAux,pilafin);
    delete plAux;
}

void hanoi(int n,void *&pilaini, void *&pilaAux, void *&pilafin){
    if(n == 1){
        void *dato = pop(pilaini);
        push(pilafin,dato);
    }else{
        hanoi(n-1,pilaini,pilafin,pilaAux);
        void *dato = pop(pilaini);
        push(pilafin,dato);
        hanoi(n-1,pilaAux,pilaini,pilafin);
    }
}
    
void imprimepila(void *&pilafin,void (*imprime)(void *,ofstream &),const char *nombArch){
    ofstream archReporte(nombArch,ios::out);
    archReporte.precision(2);archReporte<<fixed;
    void **pila = (void **)pilafin;
    void **recorrido = (void **)pila[CIMA];
    while(recorrido){
        imprime(recorrido[DATO],archReporte);
        recorrido = (void **)(recorrido[SIG]);
    }
}