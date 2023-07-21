/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Arbol.cpp
 * Author: Sebastian
 * 
 * Created on 20 de junio de 2023, 21:18
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
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
    int dato;
    while(true){
        arch>>dato;
        if(arch.eof()) break;
        insertarR(arbol,dato);
    }
}

void Arbol::insertar(int dato){
    insertarR(arbol,dato);
}

void Arbol::insertarR(class Nodo *&arbol, int dato){
    if(arbol == nullptr){
        arbol = new class Nodo;
        arbol->dato = dato;
        return;
    }
    if(dato < arbol->dato) insertarR(arbol->izq,dato);
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
        arch<<setw(4)<<arbol->dato;
        mostrarEnOrdenR(arbol->der,arch);
    }
}

void Arbol::buscar(int dato){
    int datoEncontrado = buscarR(arbol,dato);
    if(datoEncontrado != -1) cout<<"Se encontro el dato: "<<dato<<endl;
    else cout<<"No se pudo encontrar el dato "<<dato<<" en el ABB"<<endl;
}

int Arbol::buscarR(class Nodo* arbol, int dato){
    if(arbol == nullptr) return -1;
    if(arbol->dato == dato) return dato;
    if(dato<arbol->dato) return buscarR(arbol->izq,dato);
    else return buscarR(arbol->der,dato);
}

