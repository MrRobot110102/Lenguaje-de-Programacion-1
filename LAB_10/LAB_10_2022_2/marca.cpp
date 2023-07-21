/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   marca.cpp
 * Author: Sebastian
 * 
 * Created on 25 de junio de 2023, 11:53
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "marca.h"

marca::marca() {
    laboratorio = nullptr;
}

marca::~marca() {
    if(laboratorio != nullptr) delete laboratorio;
}

void marca::SetLaboratorio(char *lab) {
    if(laboratorio != nullptr) delete laboratorio;
    laboratorio = new char[strlen(lab) + 1];
    strcpy(laboratorio,lab);
}

void marca::GetLaboratorio(char *lab) const {
    if(laboratorio == nullptr) lab[0] = 0;
    else strcpy(lab,laboratorio);
}

void marca::SetLote(int lote) {
    this->lote = lote;
}

int marca::GetLote() const {
    return lote;
}

void marca::lee(ifstream &arch){
    char lab[100];
    medicamento::lee(arch);
    arch.getline(lab,100,',');
    arch>>lote;
    SetLaboratorio(lab);
}

void marca::imprime(ofstream &arch){
    char lab[100];
    medicamento::imprime(arch);
    GetLaboratorio(lab);
    arch<<left<<setw(5)<<" "<<setw(30)<<lab<<GetLote()<<endl;
}

void marca::actualiza(){
    SetPrecio(GetPrecio() * (1.20));
}

