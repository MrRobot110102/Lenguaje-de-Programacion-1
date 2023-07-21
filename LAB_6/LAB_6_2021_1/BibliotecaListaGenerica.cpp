/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "BibliotecaListaGenerica.h"
enum lista {INI,FIN};
enum nodo {DATO,SIG};

void creaLista(void *&lista,void *(*lee)(ifstream &),int (*cmp)(const void *,const void *),const char *nombArch){
    ifstream archFaltas(nombArch,ios::in);
    if(not archFaltas.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void *dato;
    void **ls;
    ls = new void*[2];
    ls[INI] = nullptr;
    ls[FIN] = nullptr;
    lista = ls;
    while(true){
        dato = lee(archFaltas);
        if(dato == nullptr) break;
        insertarLista(lista,dato,cmp);
    }
}

void insertarLista(void *&lista, void *dato,int (*cmp)(const void *,const void *)){
    void **p = (void **)lista, **ant = nullptr, **nuevo,**recorrido;
    nuevo = new void*[2];
    nuevo[DATO] = dato;
    nuevo[SIG] = nullptr;
    if(listaVacia(lista)){
        p[INI] = nuevo;
        p[FIN] = nuevo;
        return;
    }
    recorrido =(void **)p[INI];
    while(recorrido){
        if(cmp(recorrido[DATO], dato)>0) break;
        ant = recorrido;
        recorrido = (void **)(recorrido[SIG]);    
    }
    nuevo[SIG] = recorrido;
    if(ant == nullptr) p[INI] = nuevo;
    else{
        ant[SIG] = nuevo;
        if(recorrido == nullptr) p[FIN] = nuevo;
    }
}

int listaVacia(void *lista){
    void **ls=(void **)lista;
    return ls[INI]==nullptr;
}
    
void uneLista(void *&lista1,void *&lista2){
    void **ls1=(void **)lista1;
    void **ls2=(void **)lista2;
    void **ultimoLs1 = (void **)ls1[FIN];
    ultimoLs1[SIG] = ls2[INI];
    ls1[FIN] = ls2[FIN];
    ls2[INI] = nullptr;
    ls2[FIN] = nullptr;
}
    
void imprimeLista(void *lista,void (*imprime)(void *,ofstream &,void *&),const char *nombArch){
    ofstream archReporte(nombArch,ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void **ls=(void **)lista;
    void **recorrido = (void **)ls[INI],*datoAnterior = nullptr;
    while(recorrido){
        imprime(recorrido[DATO],archReporte,datoAnterior);
        recorrido = (void **)(recorrido[SIG]);
    }
}
