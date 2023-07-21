/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.cpp
 * Author: Sebastian
 * 
 * Created on 29 de junio de 2023, 15:23
 */

#include "Nodo.h"

Nodo::Nodo() {
    med = nullptr;
    izq = nullptr;
    der = nullptr;
}

Nodo::~Nodo() {
    if(med != nullptr) delete med;
}

