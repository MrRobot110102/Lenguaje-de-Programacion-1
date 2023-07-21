/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Arbol.cpp
 * Author: Sebastian
 * 
 * Created on 25 de junio de 2023, 11:53
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Arbol.h"
#include "generico.h"
#include "marca.h"

Arbol::Arbol() {
    raiz = nullptr;
}

Arbol::~Arbol() {
    elimina(raiz);
}

void Arbol::elimina(class Nodo *raiz){
    if(raiz){
        elimina(raiz->izq);
        elimina(raiz->der);
        delete raiz;
    }
}

void Arbol::crear(ifstream &arch){
    int tipo;
    class Nodo *nuevo;
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        nuevo = new class Nodo;
        if(tipo == 0) nuevo->med = new class generico;
        else if(tipo == 1) nuevo->med = new class marca;
        nuevo->med->lee(arch); //polimorfismo
        insertar(raiz,nuevo);
    }
}

void Arbol::insertar(class Nodo *&raiz,class Nodo *nuevo){
    if(raiz == nullptr){
        raiz = nuevo;
        return;
    }
    if(raiz->med->GetCodigo() > nuevo->med->GetCodigo()) insertar(raiz->izq,nuevo);
    else insertar(raiz->der,nuevo);
}

void Arbol::actualizar(ifstream &arch){
    int codigo;
    while(true){
        arch>>codigo;
        if(arch.eof()) break;
        buscarR(raiz,codigo);
    }
}

void Arbol::buscarR(class Nodo* raiz, int codigo){
    if(raiz == nullptr) return;
    if(raiz->med->GetCodigo() == codigo){
        raiz->med->actualiza();//polimorfismo
        return;
    }
    if(raiz->med->GetCodigo()>codigo) return buscarR(raiz->izq,codigo);
    else return buscarR(raiz->der,codigo);    
}

void Arbol::imprimir(ofstream &arch){
    arch<<right<<setw(65)<<"REPORTE DE MEDICAMENTOS"<<endl;
    imprimirLinea(arch,104,'=');
    arch<<left<<setw(10)<<"Codigo"<<setw(40)<<"Nombre del Medicamento"<<setw(9)<<"Stock"<<setw(11)<<"Precio"<<setw(30)<<"Pais/Laboratorio"<<"Lote"<<endl;
    imprimirLinea(arch,104,'=');
    mostrarEnOrden(raiz,arch);
}

void Arbol::imprimirLinea(ofstream &arch,int cantidad, char car){
    for (int i = 0; i < cantidad; i++) arch<<car;
    arch<<endl;
}

void Arbol::mostrarEnOrden(class Nodo* raiz,ofstream &arch){
    if(raiz){
        mostrarEnOrden(raiz->izq,arch);
        raiz->med->imprime(arch);
        mostrarEnOrden(raiz->der,arch);
    }
}



