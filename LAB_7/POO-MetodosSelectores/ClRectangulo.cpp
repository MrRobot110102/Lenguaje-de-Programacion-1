/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ClRectangulo.cpp
 * Author: Sebastian
 * 
 * Created on 25 de mayo de 2023, 17:07
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include "ClRectangulo.h"
using namespace std;

ClRectangulo::ClRectangulo(){
    inicializar();   
}

ClRectangulo::ClRectangulo(const char*n, double b, double h) {
    inicializar();
    SetBase(b);
    SetAltura(h);
    SetNombre(n);
}

ClRectangulo::ClRectangulo(const ClRectangulo &obj){
    char n[100];
    obj.GetNombre(n);
    inicializar();
    SetNombre(n);
    SetBase(obj.GetBase());
    SetAltura(obj.GetAltura());
}

ClRectangulo::~ClRectangulo(){
    elimina();
}

void ClRectangulo::SetAltura(double altura) {
    this->altura = altura;
}

double ClRectangulo::GetAltura() const {
    return altura;
}

void ClRectangulo::SetBase(double base) {
    this->base = base;
}

double ClRectangulo::GetBase() const {
    return base;
}

void ClRectangulo::leeDatos(){
    cout<<"Ingrese la base: ";
    cin>>base;
    cout<<"Ingrese la altura: ";
    cin>>altura;
}

void ClRectangulo::imprimeDatos(){
    cout.precision(2);cout<<fixed;
    cout<<"Nombre:    "<<nombre<<endl;
    cout<<"Base:      "<<setw(10)<<base<<endl;
    cout<<"Altura:    "<<setw(10)<<altura<<endl;
}

double ClRectangulo::area(){
    return GetBase()*GetAltura();
}

double ClRectangulo::perimetro(){
    return 2*(GetBase() + GetAltura());
}

void ClRectangulo::imprimeResultados(){
    imprimeDatos();
    cout<<"Area:      "<<setw(10)<<area()<<endl;
    cout<<"Perimetro: "<<setw(10)<<perimetro()<<endl;
}

void ClRectangulo::SetNombre(const char* nom) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nom) + 1];
    strcpy(nombre,nom);
}

void ClRectangulo::GetNombre(char *cad) const {
    strcpy(cad,nombre);
}

void ClRectangulo::inicializar(void){
    if(nombre != nullptr) delete nombre;
}

void ClRectangulo::elimina(void){
    delete nombre;
}







