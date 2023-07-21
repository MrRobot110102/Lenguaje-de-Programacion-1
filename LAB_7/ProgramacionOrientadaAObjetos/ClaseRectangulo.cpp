/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ClaseRectangulo.cpp
 * Author: Sebastian
 * 
 * Created on 25 de mayo de 2023, 16:24
 */
#include <iostream>
#include <iomanip>  
#include "ClaseRectangulo.h"
using namespace std;

void ClaseRectangulo::asignarBase(double b){
    base = b;
}

void ClaseRectangulo::asignarAltura(double a){
    altura = a;
}

double ClaseRectangulo::entregarBase(){
    return base;
}

double ClaseRectangulo::entregarAltura(){
    return altura;
}

void ClaseRectangulo::leeDatos(){
    cout<<"Ingrese la base: ";
    cin>>base;
    cout<<"Ingrese la altura: ";
    cin>>altura;
}

void ClaseRectangulo::imprimeDatos(){
    cout.precision(2);cout<<fixed;
    cout<<"Base:      "<<setw(10)<<base<<endl;
    cout<<"Altura:    "<<setw(10)<<altura<<endl;
}

double ClaseRectangulo::area(){
    return entregarBase()*entregarAltura();
}

double ClaseRectangulo::perimetro(){
    return 2*(entregarBase() + entregarAltura());
}

void ClaseRectangulo::imprimeResultados(){
    imprimeDatos();
    cout<<"Area:      "<<setw(10)<<area()<<endl;
    cout<<"Perimetro: "<<setw(10)<<perimetro()<<endl;
}







