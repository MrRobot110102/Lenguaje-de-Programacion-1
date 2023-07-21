/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vencido.cpp
 * Author: Sebastian
 * 
 * Created on 29 de junio de 2023, 15:23
 */

#include <cstring>

#include "vencido.h"

vencido::vencido() {
    inspector = nullptr;
}

vencido::~vencido() {
    if(inspector != nullptr) delete inspector;
}

void vencido::SetInspector(const char *inspec) {
    if(inspector != nullptr) delete inspector;
    inspector = new char[strlen(inspec) + 1];
    strcpy(inspector,inspec);
}

void vencido::GetInspector(char *inspec) const {
    if(inspector == nullptr) inspec[0] = 0;
    else strcpy(inspec,inspector);
}

void vencido::SetFechabaja(int fechabaja) {
    this->fechabaja = fechabaja;
}

int vencido::GetFechabaja() const {
    return fechabaja;
}

void vencido::lee(ifstream& arch, const char* inspec, int fechBaja) {
    medicamento::lee(arch,inspec,fechBaja);
    while(arch.get() != '\n');
    SetInspector(inspec);
    SetFechabaja(fechBaja);
    SetEstado(0);
}

void vencido::actualiza(int fechBaja, const char* inspec,int codigo, char *nomb, int stock, int fechavenc) {
    medicamento::SetDatos(codigo,nomb,stock,fechavenc);
    SetFechabaja(fechBaja);
    SetInspector(inspec);
    SetEstado(0);
}

void vencido::imprime(ofstream& arch) {
    char inspec[100];
    medicamento::imprime(arch);
    GetInspector(inspec);
    int fech = GetFechabaja();
    int dd,mm,aa;
    aa = fech / 10000;
    fech = fech % 10000;
    mm = fech / 100;
    dd = fech % 100;
    arch<<left<<setw(10)<<" "<<setw(20)<<inspec
        <<right<<setw(5)<<" "<<setfill('0')<<aa<<'/'<<setw(2)<<mm<<'/'<<setw(2)<<dd<<setfill(' ')<<endl;
}



