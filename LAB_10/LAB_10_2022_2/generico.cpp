/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   generico.cpp
 * Author: Sebastian
 * 
 * Created on 25 de junio de 2023, 11:53
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "generico.h"

generico::generico() {
    pais = nullptr;
}

generico::~generico() {
    if(pais != nullptr) delete pais;
}

void generico::SetPais(char *pa) {
    if(pais != nullptr) delete pais;
    pais = new char[strlen(pa) + 1];
    strcpy(pais,pa);
}

void generico::GetPais(char *pa) const {
    if(pais == nullptr) pa[0] = 0;
    else strcpy(pa,pais);
}

void generico::lee(ifstream &arch){
    char pa[20];
    medicamento::lee(arch);
    arch.getline(pa,20);
    SetPais(pa);
}

void generico::imprime(ofstream &arch){
    char pa[20];
    medicamento::imprime(arch);
    GetPais(pa);
    arch<<left<<setw(5)<<" "<<pa<<endl;
}

void generico::actualiza(){
}

