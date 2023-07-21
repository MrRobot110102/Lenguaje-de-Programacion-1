/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   LFalta.cpp
 * Author: Sebastian
 * 
 * Created on 26 de junio de 2023, 16:09
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "LFalta.h"
#include "NFalta.h"
#include "Grave.h"
#include "Leve.h"
#include "MuyGrave.h"

LFalta::LFalta() {
    lini = nullptr;
    lfin = nullptr;
}

LFalta::~LFalta() {
    class NFalta *sale;
    while(lini){
        sale = lini;
        lini = lini->sig;
        delete sale;
    }
}

void LFalta::leer(const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class NFalta *nuevo;
    class Falta fal;
    int codigo;
    while(true){
        fal.leer(arch);
        if(arch.eof()) break;
        arch>>codigo;
        nuevo = new class NFalta;
        if(codigo/100 == 1) nuevo->pfalta = new class Grave;
        else if(codigo /100 == 2) nuevo->pfalta = new class Leve;
        else if(codigo/100 == 3) nuevo->pfalta = new class MuyGrave;
        nuevo->dfalta = fal;
        nuevo->pfalta->lee(codigo);
        insertar(nuevo);
    }
}

void LFalta::insertar(class NFalta *nuevo){
    class NFalta *ls = lini, *ant = nullptr;
    if(lini == nullptr){
        lini = nuevo;
        lfin = nuevo;
    }else{
        while(ls){
            if(ls->dfalta.GetFecha() > nuevo->dfalta.GetFecha()) break;
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
    
void LFalta::unir(class LFalta &lista2){
    lfin->sig = lista2.lini;
    lfin = lista2.lfin;
    lista2.lini = nullptr;
    lista2.lfin = nullptr;
}
    
void LFalta::imprimir(const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    arch<<setw(12)<<left<<"Fecha"<<setw(12)<<left<<"Licencia"<<setw(15)<<left
            <<"Placa"<<setw(16)<<left<<"Infraccion"<<setw(10)<<left<<
            "Monto"<<setw(11)<<left<<"Descuento"
        <<setw(10)<<left<<"Puntos"<<setw(10)<<left<<"Meses Susp"<<endl;
    imprimeLinea(arch,110,'-');
    class NFalta *recorrido = lini;
    while(recorrido){
        arch<<recorrido->dfalta;
        recorrido->pfalta->imprimir(arch);
        recorrido = recorrido->sig;
    }
}

void LFalta::imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}



