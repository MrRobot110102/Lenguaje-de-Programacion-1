/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Lista.cpp
 * Author: Sebastian
 * 
 * Created on 23 de junio de 2023, 22:42
 */

#include "Lista.h"
#include "Nodo.h"
#include "PedidoEspecial.h"
#include "PedidoEventual.h"
#include "PedidoUsual.h"

Lista::Lista() {
    lfin = nullptr;
    lini = nullptr;
}

Lista::~Lista() {
    class Nodo *sale;
    while(lini){
        sale = lini;
        lini = lini->sig;
        delete sale;
    }
}

void Lista::crearLista(ifstream &arch){
    int codigo;
    class Nodo *nuevo;
    
    while(true){
        arch>>codigo;
        if(arch.eof()) break;
        arch.get();
        nuevo = new class Nodo;
        if(codigo < 400000) nuevo->ped = new class PedidoEspecial;
        else if(codigo >= 400000 and codigo < 600000) nuevo->ped = new class PedidoUsual;
        else if(codigo >= 600000) nuevo->ped = new class PedidoEventual;
        nuevo->ped->SetCodigo(codigo);
        nuevo->ped->lee(arch); //polimorfismo
        insertar(nuevo);
    }
}

void Lista::insertar(class Nodo *nuevo){
    class Nodo *ls = lini, *ant = nullptr;
    if(lini == nullptr){
        lini = nuevo;
        lfin = nuevo;
    }else{
        while(ls){
            if(ls->ped->GetDni() > nuevo->ped->GetDni() or 
              (ls->ped->GetDni() == nuevo->ped->GetDni() and 
               ls->ped->GetFecha() > nuevo->ped->GetFecha())) break;
            ant = ls;
            ls = ls->sig;
        }
        nuevo->sig = ls;
        nuevo->ant = ant;
        if(ant != nullptr) ant->sig = nuevo;
        else lini = nuevo;
        if(ls != nullptr) ls->ant = nuevo;
        else lfin = nuevo;
    }
}

void Lista::actualizarLista(ifstream &arch){
    int codigo,dd,mm,aa;
    char car;
    while(true){
        arch>>codigo;
        if(arch.eof()) break;
        arch>>car>>dd>>car>>mm>>car>>aa;
        actualizaCliente(codigo, aa * 10000 + mm * 100 + dd);
    }
}

void Lista::actualizaCliente(int dni, int fecha){
    class Nodo *recorrido = lfin;
    while(recorrido){
        if(recorrido->ped->GetDni() == dni and recorrido->ped->GetFecha() < fecha) break;
        recorrido = recorrido->ant;
    }
    while(recorrido and recorrido->ped->GetDni() == dni){
        recorrido->ped->exonerarFlete();
        recorrido = recorrido->ant;
    }
}

void Lista::imprimirLista(ofstream &arch){
    class Nodo *recorrido = lini;
    while(recorrido){
        recorrido->ped->imprime(arch);
        recorrido = recorrido->sig;
    }
}



