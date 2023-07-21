/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   medicamento.cpp
 * Author: Sebastian
 * 
 * Created on 16 de junio de 2023, 21:50
 */

#include <cstring>

#include "medicamento.h"

medicamento::medicamento() {
    nombre = nullptr;
    total = 0.0;
}

medicamento::~medicamento() {
    if(nombre != nullptr) delete nombre;
}

void medicamento::SetTotal(double total) {
    this->total = total;
}

double medicamento::GetTotal() const {
    return total;
}

void medicamento::SetFecha(int fecha) {
    this->fecha = fecha;
}

int medicamento::GetFecha() const {
    return fecha;
}

void medicamento::SetPrecio(double precio) {
    this->precio = precio;
}

double medicamento::GetPrecio() const {
    return precio;
}

void medicamento::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int medicamento::GetCantidad() const {
    return cantidad;
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

void medicamento::leemedicamento(ifstream &arch,int codMed){
    int cantidad,dd,mm,aa,codigoMedico,dni;
    char car,nombMedicamento[100];
    double precio;
    arch>>cantidad>>car>>dd>>car>>mm>>car>>aa>>car;
    SetCantidad(cantidad);
    SetFecha(aa * 10000 + mm * 100 + dd);
    SetCodigo(codMed);
    if(buscarMedicamento(codMed,nombMedicamento,precio)){
        SetNombre(nombMedicamento);
        SetPrecio(precio);
    }
}

void medicamento::imprimedicamento(ofstream &arch){
    int dd,mm,aa,fecha;
    char nombMedicina[100],espec[100];
    fecha = GetFecha();
    aa = fecha / 10000;
    fecha = fecha % 10000;
    mm = fecha/100;
    dd = fecha%100;
    arch<<right<<setfill('0')<<setw(4)<<aa<<'/'<<setw(2)<<mm<<'/'<<setw(2)<<dd<<setfill(' ')
        <<left<<setw(5)<<" "<<setw(10)<<GetCodigo();
    GetNombre(nombMedicina);
    arch<<setw(60)<<nombMedicina<<right<<setw(5)<<GetCantidad()<<setw(7)<<GetPrecio()<<setw(10)<<GetTotal();
}

void medicamento::aplicadescuento(){
    SetTotal((GetCantidad() * GetPrecio()) * 0.90);
}

int medicamento::buscarMedicamento(int codMed,char *nombMedicamento,double &precio){
    ifstream arch("medicamentos.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo medicamentos.csv"<<endl;
        exit(1);
    }
    int codigo;
    char car;
    while(true){
        arch>>codigo;
        if(arch.eof()) break;
        arch.get();
        arch.getline(nombMedicamento,100,',');
        arch>>precio;
        if(codigo == codMed) return 1;
    }
    return 0;
}

