/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ClLista.h
 * Author: Sebastian
 *
 * Created on 17 de junio de 2023, 20:32
 */

#ifndef CLLISTA_H
#define CLLISTA_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ClNodo.h"

template <typename T>
class ClLista {
private:
    class ClNodo<T> *lista;
    void imprimeRecursivo(ofstream& arch,class ClNodo<T> *lista);
public:
    ClLista();
    virtual ~ClLista();
    void crear(const char *nombArch);
    void insertar(const T &dato);
    void imprimir(const char *nombArch);
    void imprimirR(const char *nombArch);
};

template <typename T>
ClLista<T>::ClLista() {
    lista = nullptr;
}

template <typename T>
ClLista<T>::~ClLista() {
    class ClNodo<T> *sale;
    while(lista){
        sale = lista;
        lista = lista->sig;
        delete sale;
    }
}

template <typename T>
void ClLista<T>::crear(const char*nombArch){
    ifstream archIn(nombArch,ios::in);
    if(not archIn.is_open()){
        cout<<"ERROR: no se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    T dato;
    while(true){
        archIn>>dato;
        if(archIn.eof()) break;
        insertar(dato);
    }
}

template <typename T>
void ClLista<T>::insertar(const T &dato){
    class ClNodo<T> *ls = lista, *ant = nullptr, *nuevo;
    nuevo = new class ClNodo<T>;
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

template <typename T>
void ClLista<T>::imprimir(const char*nombArch){
    ofstream archOut(nombArch,ios::out);
    if(not archOut.is_open()){
        cout<<"ERROR: no se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    archOut<<"Datos de la lista"<<endl;
    class ClNodo<T> *ls = lista;
    while(ls){
        archOut<<ls->dato<<endl;
        ls = ls->sig;
    }
    archOut<<endl;
}

template <typename T>
void ClLista<T>::imprimirR(const char*nombArch){
    ofstream arch(nombArch, ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    imprimeRecursivo(arch,lista);
    arch<<endl;
}

template <typename T>
void ClLista<T>::imprimeRecursivo(ofstream& arch, ClNodo<T>* lista) {
    if (lista == nullptr) return;
    imprimeRecursivo(arch, lista->sig);
    arch<<lista->dato<<endl;
}


#endif /* CLLISTA_H */

