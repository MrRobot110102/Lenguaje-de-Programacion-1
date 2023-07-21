/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ClaseCliente.cpp
 * Author: Sebastian
 * 
 * Created on 31 de mayo de 2023, 22:45
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Cliente.h"
#include "SobrecargaOperadores.h"
using namespace std;

Cliente::Cliente() {
    nombre = nullptr;
    numped = 0;
    total = 0.0;
}

Cliente::~Cliente() {
    if(nombre != nullptr) delete nombre;
}

void Cliente::SetTotal(double total) {
    this->total = total;
}

double Cliente::GetTotal() const {
    return total;
}

void Cliente::SetNumped(int numped) {
    this->numped = numped;
}

int Cliente::GetNumped() const {
    return numped;
}

void Cliente::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre,nomb);
}

void Cliente::GetNombre(char *nomb) const {
    if(nombre==nullptr) nomb[0]=0;
    strcpy(nomb,nombre);
}

void Cliente::SetCategoria(char categoria) {
    this->categoria = categoria;
}

char Cliente::GetCategoria() const {
    return categoria;
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

void Cliente::imprimeLinea(ofstream &arch,int cantidad, char car) const {
    for (int i = 0; i < cantidad; i++) arch<<car;
    arch<<endl;
}

void Cliente::imprimeProductos(ofstream &arch) const{
    for (int i = 0; i<GetNumped(); i++) arch<<lped[i];
}

void Cliente::operator =(const class Pedido &ped){
    lped[numped] = ped;
    total += ped.GetCantidad()*ped.GetPrecio();
    numped++;
}

void Cliente::operator -=(const class Pedido &ped){
    for (int i = 0; i < GetNumped(); i++) {
        if(lped[i].GetDni() == ped.GetDni() and lped[i].GetFecha() == ped.GetFecha() 
                and lped[i].GetCodigo() == ped.GetCodigo()){
            total -= lped[i].GetPrecio()*lped[i].GetCantidad();
            for (int k = i+1; k < GetNumped(); k++) lped[k-1] = lped[k];
            numped--;
            return;
        }
    }
}

void Cliente::operator /(double descuento){
    for (int i = 0; i < GetNumped(); i++)
        lped[i].SetPrecio(lped[i].GetPrecio() * (1-descuento/100));
    total *= (1 - descuento/100);
}

