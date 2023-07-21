/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Ficha.cpp
 * Author: Sebastian
 * 
 * Created on 13 de junio de 2023, 13:46
 */

#include <cstring>

#include "Ficha.h"

Ficha::Ficha() {
    id = nullptr;
}

Ficha::~Ficha() {
    if(id != nullptr) delete id;
}

void Ficha::SetCol(int col) {
    this->col = col;
}

int Ficha::GetCol() const {
    return col;
}

void Ficha::SetFil(int fil) {
    this->fil = fil;
}

int Ficha::GetFil() const {
    return fil;
}

void Ficha::SetId(const char* ident) {
    if(id != nullptr) delete id;
    id = new char[strlen(ident) + 1];
    strcpy(id,ident);
}

void Ficha::GetId(char *ident) const {
    if(id == nullptr) ident[0] = 0;
    else strcpy(ident,id);
}

void Ficha::asigna(char *ident,int fil,int col){
    SetId(ident);
    SetFil(fil);
    SetCol(col);
}

