/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ClaseCilindro.cpp
 * Author: Sebastian
 * 
 * Created on 9 de junio de 2023, 18:37
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "ClaseCilindro.h"

ClaseCilindro::ClaseCilindro(double r, double h):ClaseCirculo(r) {
    altura = h;
}

void ClaseCilindro::SetAltura(double altura) {
    this->altura = altura;
}

double ClaseCilindro::GetAltura() const {
    return altura;
}

double ClaseCilindro::volumen() {
    return ClaseCirculo::area()*GetAltura();
}

double ClaseCilindro::area() {
    return 2*ClaseCirculo::area()+circunferencia()*altura;
}

void ClaseCilindro::mostrarResultados(){
    cout.precision(2);cout<<fixed;
    cout<<"Radio:           "<<setw(10)<<GetRadio()<<endl;
    cout<<"Altura:          "<<setw(10)<<GetAltura() <<endl;
    cout<<"Volumen:         "<<setw(10)<<volumen()<<endl;
    cout<<"Area de la sup.: "<<setw(10)<<area()<<endl;
    cout<<"Area de la Base: "<<setw(10)<<ClaseCirculo::area()<<endl;
    cout<<"Circunferencia:  "<<setw(10)<<circunferencia()<<endl;
}

