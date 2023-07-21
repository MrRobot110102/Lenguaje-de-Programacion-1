/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoCola.cpp
 * Author: Sebastian
 * 
 * Created on 30 de junio de 2023, 23:38
 */

#include <cstring>

#include "NodoCola.h"

NodoCola::NodoCola() {
    libsol = nullptr;
    sig = nullptr;
}

NodoCola::~NodoCola() {
    if(libsol != nullptr) delete libsol;
}

void NodoCola::SetCarne(int carne) {
    this->carne = carne;
}

int NodoCola::GetCarne() const {
    return carne;
}

void NodoCola::SetLibsol(char *lib) {
    if(libsol != nullptr) delete libsol;
    libsol = new char[strlen(lib) + 1];
    strcpy(libsol,lib);
}

void NodoCola::GetLibsol(char *lib) const {
    if(libsol == nullptr) lib[0] = 0;
    else strcpy(lib,libsol);
}

