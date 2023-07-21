/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ALibro.cpp
 * Author: Sebastian
 * 
 * Created on 25 de junio de 2023, 19:27
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "ALibro.h"
#include "NLibro.h"
#include "Libro.h"

ALibro::ALibro() {
    Raiz = nullptr;
}

ALibro::~ALibro() {
    elimina(Raiz);
}

void ALibro::elimina(class NLibro *arbol){
    if(arbol){
        elimina(arbol->izq);
        elimina(arbol->der);
        delete arbol;
    }
}

void ALibro::crear(ifstream &arch){
    class Libro dato;
    class NLibro *nuevo;
    while(true){
        arch>>dato;
        if(arch.eof()) break;
        nuevo = new class NLibro;
        nuevo->dlibro = dato;
        insertarNuevo(Raiz,nuevo);
    }
}

void ALibro::insertarNuevo(class NLibro*& arbol, NLibro* nuevo) {
    if(arbol == nullptr){
        arbol = nuevo;
        return;
    }
    char codigo[100],codigoComparar[100];
    arbol->dlibro.GetCodigo(codigo);
    nuevo->dlibro.GetCodigo(codigoComparar);
    if(strcmp(codigo,codigoComparar) > 0) insertarNuevo(arbol->izq,nuevo);
    else insertarNuevo(arbol->der,nuevo);
}


void ALibro::insertar(class NLibro *&arbol,const class Libro &dato){
    if(arbol == nullptr){
        arbol = new class NLibro;
        arbol->dlibro = dato;
        return;
    }
    char codigo[100],codigoComparar[100];
    arbol->dlibro.GetCodigo(codigo);
    dato.GetCodigo(codigoComparar);
    if(strcmp(codigo,codigoComparar) > 0) insertar(arbol->izq,dato);
    else insertar(arbol->der,dato);
}

void ALibro::actualizar(ifstream &arch){
    int codigo,dd,mm,aa;
    char car,codLibro[100];
    while(true){
        arch>>codigo;
        if(arch.eof()) break;
        arch>>car>>car;
        arch.getline(codLibro,100,',');
        arch>>dd>>car>>mm>>car>>aa;
        buscar(Raiz,codLibro);
    }
}

void ALibro::buscar(class NLibro *arbol,char *codLibro){
    char codigo[100];
    if(arbol == nullptr) return;
    arbol->dlibro.GetCodigo(codigo);
    if(strcmp(codigo,codLibro) == 0){
        arbol->dlibro.SetStock(arbol->dlibro.GetStock() - 1);
        return;
    }
    if(strcmp(codigo,codLibro)>0) return buscar(arbol->izq,codLibro);
    else return buscar(arbol->der,codLibro);
}

void ALibro::imprimir(ofstream &arch){
    mostrarEnOrden(Raiz,arch);
    arch<<endl;
}

void ALibro::mostrarEnOrden(class NLibro* arbol,ofstream &arch){
    if(arbol){
        mostrarEnOrden(arbol->izq,arch);
        arch<<arbol->dlibro;
        imprimirLinea(arch,100,'-');
        mostrarEnOrden(arbol->der,arch);
    }
}

void ALibro::imprimirLinea(ofstream &arch,int cantidad, char car){
    for (int i = 0; i < cantidad; i++) arch<<car;
    arch<<endl;
}

