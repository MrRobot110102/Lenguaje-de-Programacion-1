/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Copia.cpp
 * Author: Sebastian
 * 
 * Created on 21 de junio de 2023, 20:59
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Copia.h"
#include "Disponible.h"
#include "Perdida.h"
#include "Prestamo.h"


Copia::Copia() {
    estado = nullptr;
    Olibro = nullptr;
}

Copia::~Copia() {
    if(estado != nullptr) delete estado;
    if(Olibro != nullptr) delete Olibro;
}

void Copia::SetEstado(const char* est) {
    if(estado != nullptr) delete estado;
    estado = new char[strlen(est) + 1];
    strcpy(estado,est);
}

void Copia::GetEstado(char *est) const {
    if(estado == nullptr) est[0] = 0;
    else strcpy(est,estado);
}

void Copia::SetNumero(int numero) {
    this->numero = numero;
}

int Copia::GetNumero() const {
    return numero;
}

void Copia::asignaLibro(int zona,char *cod,char *tit,char *aut,int aa, int numero,double precio){
    Olibro = new class Disponible;
    Olibro->AsignaDatos(cod,tit,aut,aa,numero,precio);
    Olibro->AsignaZona(zona);
}

void Copia::GetCodigo(char *cod){
    Olibro->GetCodigo(cod);
}

void Copia::asignaPrestamoPerdida(int dias,int fecha){
    char cod[100],tit[100],aut[100];
    int aa,numero;
    double precio;
    Olibro->ObtieneDatos(cod,tit,aut,aa,numero,precio);
    if(Olibro != nullptr) delete Olibro;
    if(dias < 60){
        SetEstado("Prestamo");
        Olibro = new class Prestamo;
    }else{
        SetEstado("Perdida");
        Olibro = new class Perdida;
    }
    Olibro->AsignaDatos(cod,tit,aut,aa,numero,precio);
    Olibro->Actualiza(dias,fecha,Olibro->GetPrecio());
}

void Copia::imprimirEncabezado(ofstream &arch){
    char cod[100],tit[100],aut[100];
    Olibro->GetTitulo(tit);
    Olibro->GetAutor(aut);
    Olibro->GetCodigo(cod);
    arch<<"Codigo:   "<<cod<<endl;
    arch<<"Titulo:   "<<tit<<endl;
    arch<<"Autor:    "<<aut<<endl;
    arch<<"Cantidad: "<<Olibro->GetCantidad()<<endl;
}

void Copia::imprime(ofstream &arch){
    Olibro->Imprimir(arch);
}

