/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ClaseCirculo.cpp
 * Author: Sebastian
 * 
 * Created on 9 de junio de 2023, 18:30
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "ClaseCirculo.h"
#define PI 3.1416   

ClaseCirculo::ClaseCirculo(double r) {
    radio = r;
}

void ClaseCirculo::SetRadio(double radio) {
    this->radio = radio;
}

double ClaseCirculo::GetRadio() const {
    return radio;
}

double ClaseCirculo::area(void){
    return PI * GetRadio() * GetRadio();
}

double ClaseCirculo::circunferencia(void){
    return 2 * PI * GetRadio();
}

void ClaseCirculo::mostrarResultados(void){
    cout.precision(2);cout<<fixed;
    cout<<"Radio:     "<<setw(10)<<GetRadio()<<endl;
    cout<<"Area:      "<<setw(10)<<area()<<endl;
    cout<<"Perimetro: "<<setw(10)<<circunferencia()<<endl;
}





