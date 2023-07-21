/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   activo.cpp
 * Author: Sebastian
 * 
 * Created on 29 de junio de 2023, 15:22
 */

#include <cstring>

#include "activo.h"

activo::activo() {
    vendedor = nullptr;
}

activo::~activo() {
    if(vendedor != nullptr) delete vendedor;
}

void activo::SetVendedor(char *vend) {
    if(vendedor != nullptr) delete vendedor;
    vendedor = new char[strlen(vend) + 1];
    strcpy(vendedor,vend);
}

void activo::GetVendedor(char *vend) const {
    if(vendedor == nullptr) vend[0] = 0;
    else strcpy(vend,vendedor);
}

void activo::SetPrecio(double precio) {
    this->precio = precio;
}

double activo::GetPrecio() const {
    return precio;
}

void activo::lee(ifstream& arch, const char* inspec, int fechBaja) {
    char vend[100];
    medicamento::lee(arch,inspec,fechBaja);
    arch.getline(vend,100,',');
    arch>>precio;
    SetVendedor(vend);
    SetEstado(1);
}

void activo::actualiza(int fechBaja, const char* inspec,int codigo, char *nomb, int stock, int fechavenc) {

}

void activo::imprime(ofstream& arch) {
    char vend[100];
    medicamento::imprime(arch);
    GetVendedor(vend);
    arch.precision(2);arch<<fixed;
    arch<<left<<setw(10)<<" "<<setw(20)<<vend<<right<<setw(10)<<GetPrecio()<<left<<endl;
}



