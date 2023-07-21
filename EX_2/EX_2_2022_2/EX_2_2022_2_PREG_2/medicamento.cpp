/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   medicamento.cpp
 * Author: Sebastian
 * 
 * Created on 29 de junio de 2023, 15:22
 */

#include <cstring>

#include "medicamento.h"

medicamento::medicamento() {
    nombre = nullptr;
}

medicamento::medicamento(const medicamento& orig) {
    nombre = nullptr;
    *this = orig;
}

void medicamento::operator=(const medicamento& med) {
    char nomb[100];
    med.GetNombre(nomb);
    SetCodigo(med.GetCodigo());
    SetFechavenc(med.GetFechavenc());
    SetStock(med.GetStock());
    SetNombre(nomb);
    SetEstado(med.GetEstado());
}

medicamento::~medicamento() {
    if(nombre != nullptr) delete nombre;
}

void medicamento::SetEstado(int estado) {
    this->estado = estado;
}

int medicamento::GetEstado() const {
    return estado;
}

void medicamento::SetFechavenc(int fechavenc) {
    this->fechavenc = fechavenc;
}

int medicamento::GetFechavenc() const {
    return fechavenc;
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

void medicamento::lee(ifstream& arch, const char* inspec,int fechBaja) {
    char car,nomb[100];
    arch>>codigo>>car;
    arch.getline(nomb,100,',');
    arch>>stock>>car;
    SetNombre(nomb);
}

void medicamento::GetDatos(int& cod, char* nomb, int& st, int& fecha) {
    cod = GetCodigo();
    st = GetStock();
    fecha = GetFechavenc();
    GetNombre(nomb);
}

void medicamento::SetDatos(int codigo, char* nomb, int stock, int fechavenc) {
    SetCodigo(codigo);
    SetNombre(nomb);
    SetStock(stock);
    SetFechavenc(fechavenc);
}

void medicamento::imprime(ofstream& arch) {
    int fech = GetFechavenc();
    int dd,mm,aa;
    char nomb[100];
    aa = fech / 10000;
    fech = fech % 10000;
    mm = fech / 100;
    dd = fech % 100;
    GetNombre(nomb);
    arch<<right<<setfill('0')<<aa<<'/'<<setw(2)<<mm<<'/'<<setw(2)<<dd<<setfill(' ')
        <<left<<"   "<<setw(10)<<GetCodigo()<<setw(50)<<nomb<<right<<setw(5)<<GetStock();
}





