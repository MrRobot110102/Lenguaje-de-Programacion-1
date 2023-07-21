/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Tablero.cpp
 * Author: Sebastian
 * 
 * Created on 13 de junio de 2023, 14:16
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Tablero.h"
#include "Ficha.h"
#include "A.h"
#include "B.h"
#include "C.h"

Tablero::Tablero() {
    numFichas = 0;
}

Tablero::~Tablero() {
    for (int i = 0; i < GetNumFichas(); i++) delete fichas[i];
}

void Tablero::SetNumFichas(int numFichas) {
    this->numFichas = numFichas;
}

int Tablero::GetNumFichas() const {
    return numFichas;
}

void Tablero::leerFichas(ifstream &arch){
    int fil,col;
    char ident[10],tipo;
    while(true){
        arch>>ident;
        if(arch.eof()) break;
        arch>>tipo>>fil>>col;
        colocarFicha(ident,tipo,fil,col);
    }
}
    
void Tablero::colocarFicha(char*ident, char tipo, int fil, int col){
    switch(tipo){
        case 'A':
            fichas[numFichas] = new A;
            break;
        case 'B':
            fichas[numFichas] = new B;
            break;
        case 'C':
            fichas[numFichas] = new C;
            break;
    }
    fichas[numFichas]->asigna(ident,fil,col);
    numFichas++;
}
    
void Tablero::leerMovimientos(ifstream &arch){
    char ident[10],movimiento;
    int cantidad;
    while(true){
        arch>>ident;
        if(arch.eof()) break;
        arch>>movimiento>>cantidad;
        moverFicha(ident,movimiento,cantidad);
    }
}
    
void Tablero::moverFicha(char *id, char mov, int cantidad){
    char ident[10];
    for (int i = 0; i < GetNumFichas(); i++) {
        fichas[i]->GetId(ident);
        if(strcmp(ident,id) == 0){
            fichas[i]->mover(mov,cantidad);
            return;
        }
    }
}
    
void Tablero::imprimeDatos(ofstream &arch){
    for (int i = 0; i < GetNumFichas(); i++) fichas[i]->imprime(arch);
}

