/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   oferta.cpp
 * Author: Sebastian
 * 
 * Created on 16 de junio de 2023, 21:50
 */

#include "oferta.h"
#include "conreceta.h"
#include "sinreceta.h"

oferta::oferta() {
    poferta = nullptr;
}

oferta::~oferta() {
    if(poferta != nullptr) delete poferta;
}

void oferta::asignaReceta(ifstream &arch){
    int codMed;
    arch>>codMed;
    if(arch.eof()) return;
    arch.get();
    if((codMed/10000) % 2 == 0) poferta = new class conreceta;
    else poferta = new class sinreceta;
    poferta->leemedicamento(arch,codMed);
}

void oferta::operator =(class medicamento *pt){
    poferta = pt;
}

int oferta::validaReceta(){
    return poferta != nullptr;
}

void oferta::imprimir(ofstream &arch){
    poferta->imprimedicamento(arch);
}

void oferta::aplicarDescuento(){
    poferta->aplicadescuento();
}

