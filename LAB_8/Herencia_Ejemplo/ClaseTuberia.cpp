/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ClaseTuberia.cpp
 * Author: Sebastian
 * 
 * Created on 9 de junio de 2023, 18:46
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "ClaseTuberia.h"
#define PI 3.1416 

ClaseTuberia::ClaseTuberia(double r, double h, double rI):ClaseCilindro(r,h){
    radioInterior = rI;
}

void ClaseTuberia::SetRadioInterior(double radioInterior) {
    this->radioInterior = radioInterior;
}

double ClaseTuberia::GetRadioInterior() const {
    return radioInterior;
}

double ClaseTuberia::volumen(void){
    return ClaseCilindro::volumen() - PI * GetRadioInterior() * GetRadioInterior() * GetAltura();
}

double ClaseTuberia::area(void){
    return ClaseCilindro::area() - 2 * ClaseCirculo::area();
}
    
void ClaseTuberia::mostrarResultados(void){
    cout.precision(2);cout<<fixed;
    cout<<"Radio:          "<<setw(10)<<GetRadio()<<endl;
    cout<<"Altura:         "<<setw(10)<<GetAltura()<<endl;
    cout<<"Radio interior: "<<setw(10)<<GetRadioInterior()<<endl;
    cout<<"Volumen:        "<<setw(10)<<volumen()<<endl;
    cout<<"Area de la sup.:"<<setw(10)<<area()<<endl;
    cout<<"Circunferencia: "<<setw(10)<<circunferencia()<<endl;
}

