/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.cpp
 * Author: Sebastian
 * 
 * Created on 27 de junio de 2023, 23:05
 */

#include "Lista.h"
#include "Pedido.h"


Lista::Lista() {
    lini = nullptr;
    lfin = nullptr;
}

Lista::~Lista() {
    class Nodo *sale;
    while(lini){
        sale = lini;
        lini = lini->sig;
        delete sale;
    }
}

void Lista::llenarLista(ifstream& arch) {
    class Nodo *nuevo;
    class Pedido *ped;
    while(true){
        ped = new class Pedido;
        ped->leer(arch);
        if(arch.eof()){
            if(ped != nullptr) delete ped;
            break;
        }
        nuevo = new class Nodo;
        nuevo->ped = ped;
        insertar(nuevo);
    }
}

Pedido* Lista::leePedido(ifstream& arch) {
    int codigo,cant,dni,dd,mm,aa;
    double monto;
    char car;
    class Pedido *ped;
    arch>>codigo;
    if(arch.eof()) return nullptr;
    arch>>car>>cant>>car>>monto>>car>>dni>>car>>dd>>car>>mm>>car>>aa;
    ped = new class Pedido;
    ped->SetCodigo(codigo);
    ped->SetCantidad(cant);
    ped->SetTotal(monto);
    ped->SetDni(dni);
    ped->SetFecha(aa * 10000 + mm * 100 + dd);
    return ped;
}

void Lista::insertar(Nodo* nuevo) {
    class Nodo *ls = lini, *ant = nullptr;
    if(lini == nullptr){
        lini = nuevo;
        lfin = nuevo;
    }else{
        while(ls){
            if(ls->ped->GetFecha() > nuevo->ped->GetFecha()) break;
            ant = ls;
            ls = ls->sig;
        }
        nuevo->sig = ls;
        if(ant == nullptr) lini = nuevo;
        else{
            ant->sig = nuevo;
            if(ls == nullptr) lfin = nuevo;
        }
    }
    
}

void Lista::imprimirLista(ofstream& arch) {
    class Nodo *recorrido = lini;
    while(recorrido){
        recorrido->ped->imprime(arch);
        recorrido = recorrido->sig;
    }
}

void Lista::obtenerCodigos(int* codProductos, int& n) {
    class Nodo *recorrido = lini;
    n = 0;
    while (recorrido) {
        codProductos[n] = recorrido->ped->GetCodigo();
        recorrido = recorrido->sig;
        n++;
    }
}

void Lista::reordena(int* prioridades) {
    class Nodo *p = lini->sig, *ant = lini;
    int i=1;
    while(p){
        if(prioridades[i]==1){
            p->ped->SetOrden(1);
            ant->sig = p->sig;
            p->sig = lini;
            lini = p;
            p=ant->sig;
            if(p==nullptr)lfin = ant;
        }else {
            p->ped->SetOrden(0);
            ant = p;
            p= p->sig;
        }
        i++;
    }
}






