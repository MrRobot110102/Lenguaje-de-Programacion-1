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
#include "BibliotecaListaGenerica.h"
enum Reg {DATO,SIG};


void crearLista(ifstream &arch,void *&lista,void *(*lee)(ifstream &),int (*comp)(const void *,const void *)){
    void *dato;
    lista = nullptr;
    while(true){
        dato = lee(arch);
        if(dato == nullptr) break;
        insertarLista(lista,dato,comp);
    }
}
//2 -> 3 -> 5
void insertarLista(void *&lista,void *dato,int (*comp)(const void *,const void *)){
    void **p = (void **)lista, **ant = nullptr, **nuevo;
    nuevo = new void*[2];
    nuevo[DATO] = dato;
    while(p){
        if(comp(p[DATO], dato)>0) break;
        ant = p;
        p = (void **)(p[SIG]);    
    }
    nuevo[SIG] = p;
    if(ant == nullptr) lista = nuevo;
    else ant[SIG] = nuevo;
}
    
void imprimirLista(void *lista,void (*imprime)(void *)){
    void **ls = (void **)lista;
    while(ls){
        imprime(ls[DATO]);
        ls = (void **)(ls[SIG]);
    }
}
    
void eliminarLista(void *lista,void (*elimina)(void *)){
    void **ls=(void**)lista, **sale;
    while(ls){
        sale = ls;
        ls = (void**)(ls[SIG]);
        elimina(sale[DATO]);
        delete sale;
    }
}