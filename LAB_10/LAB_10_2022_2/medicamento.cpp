/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   medicamento.cpp
 * Author: Sebastian
 * 
 * Created on 25 de junio de 2023, 11:53
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "medicamento.h"

medicamento::medicamento() {
    nombre = nullptr;
}

medicamento::medicamento(const medicamento& orig) {
    nombre = nullptr;
    *this = orig;
}

medicamento::~medicamento() {
    if(nombre != nullptr) delete nombre;
}

void medicamento::SetPrecio(double precio) {
    this->precio = precio;
}

double medicamento::GetPrecio() const {
    return precio;
}

void medicamento::SetStock(int stock) {
    this->stock = stock;
}

int medicamento::GetStock() const {
    return stock;
}

void medicamento::SetNombre(char *nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre,nomb);
}

void medicamento::GetNombre(char *nomb) const {
    if(nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb,nombre);
}

void medicamento::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int medicamento::GetCodigo() const {
    return codigo;
}

void medicamento::lee(ifstream &arch){
    char car,nomb[100];
    arch>>codigo>>car;
    arch.getline(nomb,100,',');
    arch>>stock>>car>>precio>>car;
    SetNombre(nomb);
}

void medicamento::imprime(ofstream &arch){
    char nomb[100];
    GetNombre(nomb);
    arch.precision(2);arch<<fixed;
    arch<<left<<setw(10)<<GetCodigo()<<setw(35)<<nomb<<right<<setw(10)<<GetStock()<<setw(10)<<GetPrecio();
}
