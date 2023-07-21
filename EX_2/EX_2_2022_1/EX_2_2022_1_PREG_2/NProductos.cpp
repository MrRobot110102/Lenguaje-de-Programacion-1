/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NProductos.cpp
 * Author: Sebastian
 * 
 * Created on 27 de junio de 2023, 23:05
 */
#include "NProductos.h"
#include "Categoria1.h"
#include "Categoria2.h"
#include "Categoria3.h"

NProductos::NProductos() {
    prod = nullptr;
}

NProductos::NProductos(const NProductos& orig) {
    *this = orig;
}

void NProductos::operator=(const NProductos& orig) {
    prod = orig.prod;
}

void NProductos::leerProductos(ifstream& arch) {
    int categoria;
    arch>>categoria;
    if(arch.eof()) return;
    arch.get();
    if(categoria == 1) prod = new class Categoria1;
    else if(categoria == 2) prod = new class Categoria2;
    else if(categoria == 3) prod = new class Categoria3;
    prod->leer(arch);
}

void NProductos::imprimirProductos(ofstream& arch) {
    prod->imprime(arch);
}

int NProductos::getCodigo() {
    return prod->GetCodprod();
}

int NProductos::getPrioridad() {
    return prod->Prioridad();
}





