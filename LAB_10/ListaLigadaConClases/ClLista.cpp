/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ClLista.cpp
 * Author: Sebastian
 * 
 * Created on 13 de junio de 2023, 15:43
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "ClNodo.h"
#include "ClLista.h"

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

void ClLista::crear(const char *nombArch){
    ifstream archIn(nombArch,ios::in);
    if(not archIn.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int dato;
    while(true){
        archIn>>dato;
        if(archIn.eof()) break;
        insertar(dato);
    }
}

void ClLista::insertar(int d){
    class ClNodo *ls = lista, *ant = nullptr , *nuevo;
    nuevo = new class ClNodo;
    nuevo->dato = d;
    while(ls){
        if(ls->dato > d) break;
        ant = ls;
        ls = ls->sig;
    }
    nuevo->sig = ls;
    if(ant != nullptr) ant->sig = nuevo;
    else lista = nuevo;
}

void ClLista::imprimir(const char *nombArch){
    ofstream archOut(nombArch,ios::out);
    if(not archOut.is_open()){
        cout<<"ERROR: no se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    archOut<<"Datos de la lista:"<<endl;
    class ClNodo *recorrido = lista;
    while(recorrido){
        archOut << setw(4)<<recorrido->dato;
        recorrido = recorrido->sig;
    }
    archOut<<endl;
}

void ClLista::imprimirR(const char*nombArch){
    ofstream archOut(nombArch,ios::out);
    if(not archOut.is_open()){
        cout<<"ERROR: no se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    //class ClNodo *ls = lista;
    imprimeRecursivo(archOut,lista);
    archOut<<endl;
}

void ClLista::imprimeRecursivo(ofstream &archOut, class ClNodo *lista){
    if(lista == nullptr) return;
    imprimeRecursivo(archOut,lista->sig);
    archOut<<setw(4)<<lista->dato;  
}



