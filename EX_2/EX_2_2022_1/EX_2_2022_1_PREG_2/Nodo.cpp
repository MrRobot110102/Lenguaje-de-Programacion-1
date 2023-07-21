/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.cpp
 * Author: Sebastian
 * 
 * Created on 27 de junio de 2023, 23:05
 */

#include "Nodo.h"

Nodo::Nodo() {
    ped = nullptr;
    sig = nullptr;
}

Nodo::~Nodo() {
    if(ped != nullptr) delete ped;
}

