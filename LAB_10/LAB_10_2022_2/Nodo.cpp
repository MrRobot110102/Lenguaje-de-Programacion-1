/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Nodo.cpp
 * Author: Sebastian
 * 
 * Created on 25 de junio de 2023, 11:53
 */

#include "Nodo.h"

Nodo::Nodo() {
    der = nullptr;
    izq = nullptr;
    med = nullptr;
}

Nodo::~Nodo() {
    if(med != nullptr) delete med;
}

