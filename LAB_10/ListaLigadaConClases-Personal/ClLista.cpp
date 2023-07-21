/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ClLista.cpp
 * Author: Sebastian
 * 
 * Created on 17 de junio de 2023, 20:32
 */

#include "ClLista.h"
#include "ClNodo.h"

ClLista::ClLista() {
    lista = nullptr;
}

ClLista::~ClLista() {
    class ClNodo *sale;
    while(lista){
        sale = lista;
        lista = lista->sig;
        delete sale;
    }
}

void ClLista::crear(const char*nombArch){
    ifstream archIn(nombArch,ios::in);
    if(not archIn.is_open()){
        cout<<"ERROR: no se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class Persona dato;
    while(true){
        archIn>>dato;
        if(archIn.eof()) break;
        insertar(dato);
    }
}

void ClLista::insertar(const class Persona &dato){
    class ClNodo *ls = lista, *ant = nullptr, *nuevo;
    nuevo = new class ClNodo;
    nuevo->dato = dato;
    while(ls){
        if(ls->dato > dato) break;
        ant = ls;
        ls = ls->sig;
    }
    nuevo->sig = ls;
    if(ant != nullptr) ant->sig = nuevo;
    else lista = nuevo;
}

void ClLista::imprimir(const char*nombArch){
    ofstream archOut(nombArch,ios::out);
    if(not archOut.is_open()){
        cout<<"ERROR: no se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    archOut<<"Datos de la lista"<<endl;
    class ClNodo *ls = lista;
    while(ls){
        archOut<<ls->dato;
        ls = ls->sig;
    }
    archOut<<endl;
}

void ClLista::imprimirR(const char*nombArch){
    ofstream arch(nombArch, ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    imprimeRecursivo(arch,lista);
    arch<<endl;
}

void ClLista::imprimeRecursivo(ofstream& arch, ClNodo* lista) {
    if (lista == nullptr) return;
    imprimeRecursivo(arch, lista->sig);
    arch<<lista->dato;
}

