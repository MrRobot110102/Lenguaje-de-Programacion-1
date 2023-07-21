    /*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Leve.cpp
 * Author: Sebastian
 * 
 * Created on 11 de junio de 2023, 13:27
 */

#include "Leve.h"

Leve::Leve() {
}

Leve::~Leve() {
}

void Leve::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Leve::GetDescuento() const {
    return descuento;
}

