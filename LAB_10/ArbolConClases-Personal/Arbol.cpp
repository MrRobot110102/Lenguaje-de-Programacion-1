/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Arbol.cpp
 * Author: Sebastian
 * 
 * Created on 20 de junio de 2023, 22:29
 */

#include "Arbol.h"

Arbol::Arbol() {
    arbol = nullptr;
}

Arbol::~Arbol() {
    elimina(arbol);
}

void Arbol::elimina(class Nodo *arbol){
    if(arbol){
        elimina(arbol->izq);
        elimina(arbol->der);
        delete arbol;
    }
}

void Arbol::crear(const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class Persona dato;
    while(true){
        arch>>dato;
        if(arch.eof()) break;
        insertarR(arbol,dato);
    }
}

void Arbol::insertar(const class Persona &dato){
    insertarR(arbol,dato);
}

void Arbol::insertarR(class Nodo *&arbol,const class Persona &dato){
    if(arbol == nullptr){
        arbol = new class Nodo;
        arbol->dato = dato;
        return;
    }
    if(arbol->dato > dato) insertarR(arbol->izq,dato);
    else insertarR(arbol->der,dato);
}

void Arbol::mostrarEnOrden(const char *nombArch){
    ofstream archOut(nombArch,ios::out);
    if(not archOut.is_open()){
        cout<<"ERROR: no se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    archOut<<"Datos del abb:"<<endl;
    mostrarEnOrdenR(arbol,archOut);
    archOut<<endl;
}

void Arbol::mostrarEnOrdenR(class Nodo* arbol,ofstream &arch){
    if(arbol){
        mostrarEnOrdenR(arbol->izq,arch);
        arch<<arbol->dato;
        mostrarEnOrdenR(arbol->der,arch);
    }
}

void Arbol::buscar(int dato){
    class Persona per;
    per = buscarR(arbol,dato);
    if(per.GetDni() != -1) cout<<"Dato buscado: "<<per<<endl;
    else cout<<"No se encontro"<<endl;;
}

class Persona Arbol::buscarR(class Nodo* arbol, int dni){
    class Persona p;
    int d;
    p.SetDni(-1);
    if(arbol == nullptr) return p;
    if(arbol->dato == dni) return arbol->dato;
    d = arbol->dato.GetDni();
    if(d>dni) return buscarR(arbol->izq,dni);
    else return buscarR(arbol->der,dni);    
}

