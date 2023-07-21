/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Nodo.cpp
 * Author: Sebastian
 * 
 * Created on 23 de junio de 2023, 22:09
 */

#include "Nodo.h"

Nodo::Nodo() {
    ant = nullptr;
    sig = nullptr;
    ped = nullptr;
}

Nodo::~Nodo(){
    if(ped != nullptr) delete ped;
}


