/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ColaSol.cpp
 * Author: Sebastian
 * 
 * Created on 30 de junio de 2023, 23:38
 */

#include "ColaSol.h"

ColaSol::ColaSol() {
    inicola = nullptr;
    fincola = nullptr;
    n = 0;
}

ColaSol::~ColaSol() {
    class NodoCola *sale;
    while(inicola){
        sale = inicola;
        inicola = inicola->sig;
        delete sale;
    }
}

void ColaSol::SetN(int n) {
    this->n = n;
}

int ColaSol::GetN() const {
    return n;
}

void ColaSol::crearCola(ifstream& arch) {
    int carne;
    char car,libro[20];
    class NodoCola *nuevo;
    while(true){
        arch>>carne;
        if(arch.eof()) break;
        arch>>car>>car;
        arch.getline(libro,20);
        nuevo = new class NodoCola;
        nuevo->SetCarne(carne);
        nuevo->SetLibsol(libro);
        encolar(nuevo);
    }
}

void ColaSol::encolar(NodoCola* nuevo) {
    class NodoCola *cl = inicola;
    if(cl == nullptr){
        inicola = nuevo;
        fincola = nuevo;
    }else{
        fincola->sig = nuevo;
        fincola = nuevo;
    }
    SetN(GetN() + 1);
}

void ColaSol::atiendeCola(char *libro, int &carne) {
    class NodoCola *auxiliar;
    auxiliar = desencolar();
    auxiliar->GetLibsol(libro);
    carne = auxiliar->GetCarne();
    delete auxiliar;
}

void ColaSol::ingresaCola(char* libro, int carne) {
    class NodoCola *nuevo;
    nuevo = new class NodoCola;
    nuevo->SetCarne(carne);
    nuevo->SetLibsol(libro);
    encolar(nuevo);
}

NodoCola* ColaSol::desencolar() {
    class NodoCola *sale;
    sale = inicola;
    inicola = inicola->sig;
    SetN(GetN() - 1);
    return sale;
}

int ColaSol::colaVacia() {
    return GetN() == 0;
}






