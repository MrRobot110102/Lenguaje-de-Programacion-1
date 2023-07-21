/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.cpp
 * Author: Sebastian
 * 
 * Created on 29 de junio de 2023, 15:23
 */

#include "Arbol.h"
#include "activo.h"
#include "vencido.h"

Arbol::Arbol() {
    raiz = nullptr;
}

Arbol::~Arbol() {
    elimina(raiz);
}

void Arbol::elimina(Nodo* arbol) {
    if(arbol){
        elimina(arbol->izq);
        elimina(arbol->der);
        delete arbol;
    }
}

void Arbol::crear(ifstream& arch,int fechaComparar, const char* nombProfesor) {
    class Nodo *nuevo;
    int fecha;
    while(true){
        arch>>fecha;
        if(arch.eof()) break;
        arch.get();
        nuevo = new class Nodo;
        if(fecha < fechaComparar) nuevo->med = new class vencido;
        else if(fecha > fechaComparar) nuevo->med = new class activo;
        nuevo->med->SetFechavenc(fecha);
        nuevo->med->lee(arch,nombProfesor,fechaComparar);
        insertar(raiz,nuevo);
    }
}

void Arbol::insertar(Nodo*& raiz, Nodo* nuevo) {
    if(raiz == nullptr){
        raiz = nuevo;
        return;
    }
    if(raiz->med->GetFechavenc() > nuevo->med->GetFechavenc() or 
      (raiz->med->GetFechavenc() == nuevo->med->GetFechavenc() and 
       raiz->med->GetCodigo() > nuevo->med->GetCodigo())) insertar(raiz->izq,nuevo);
    else insertar(raiz->der,nuevo);
}

void Arbol::actualizar(int fechaComparar, const char* apellido) {
    buscar(raiz,fechaComparar,apellido);
}

void Arbol::buscar(Nodo *raiz, int fechaComparar, const char* apellido) {
    int codigo, stock, fechavenc;
    char nomb[100];
    if(raiz){
        buscar(raiz->izq,fechaComparar,apellido);
        if(raiz->med->GetFechavenc()<fechaComparar and raiz->med->GetEstado() == 1){
            raiz->med->GetDatos(codigo,nomb,stock,fechavenc);
            //cout<<fechavenc<<'-'<<codigo<<"-"<<nomb<<'-'<<stock<<endl;
            if(raiz->med != nullptr) delete raiz->med;
            raiz->med = new class vencido;
            raiz->med->actualiza(fechaComparar,apellido,codigo,nomb,stock,fechavenc);
        }
        buscar(raiz->der,fechaComparar,apellido);
    }   
}

void Arbol::imprimir(ofstream& arch) {
    mostrarEnOrden(raiz,arch);
}

void Arbol::mostrarEnOrden(Nodo* raiz, ofstream& arch) {
    if(raiz){
        mostrarEnOrden(raiz->izq,arch);
        raiz->med->imprime(arch);
        mostrarEnOrden(raiz->der,arch);
    }
}





