/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Libro.cpp
 * Author: Sebastian
 * 
 * Created on 5 de junio de 2023, 18:22
 */

#include <cstring>

#include "Libro.h"
#include "LibroPrestado.h"

Libro::Libro() {
    autor = nullptr;
    codigo = nullptr;
    titulo = nullptr;
    cantAdm = 0;
    cantDoc = 0;
    cantEst = 0;
    prestados = 0;
}

Libro::~Libro() {
    if(autor != nullptr) delete autor;
    if(codigo != nullptr) delete codigo;
    if(titulo != nullptr) delete titulo;
}

void Libro::SetCantAdm(int cantAdm) {
    this->cantAdm = cantAdm;
}

int Libro::GetCantAdm() const {
    return cantAdm;
}

void Libro::SetCantDoc(int cantDoc) {
    this->cantDoc = cantDoc;
}

int Libro::GetCantDoc() const {
    return cantDoc;
}

void Libro::SetCantEst(int cantEst) {
    this->cantEst = cantEst;
}

int Libro::GetCantEst() const {
    return cantEst;
}

void Libro::SetPrestados(int prestados) {
    this->prestados = prestados;
}

int Libro::GetPrestados() const {
    return prestados;
}

void Libro::SetPrecio(double precio) {
    this->precio = precio;
}

double Libro::GetPrecio() const {
    return precio;
}

void Libro::SetStock(int stock) {
    this->stock = stock;
}

int Libro::GetStock() const {
    return stock;
}

void Libro::SetAutor(char* aut) {
    if(autor != nullptr) delete autor;
    autor = new char[strlen(aut) + 1];
    strcpy(autor,aut);
}

void Libro::GetAutor(char *aut) const {
    if(autor == nullptr) autor[0] = 0;
    strcpy(aut,autor);
}

void Libro::SetTitulo(char* tit) {
    if(titulo != nullptr) delete titulo;
    titulo = new char[strlen(tit) + 1];
    strcpy(titulo,tit);
}

void Libro::GetTitulo(char *tit) const {
    if(titulo == nullptr) titulo[0] = 0;
    strcpy(tit,titulo);
}

void Libro::SetCodigo(char* cod) {
    if(codigo != nullptr) delete codigo;
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo,cod);
}

void Libro::GetCodigo(char *cod) const {
    if(codigo == nullptr) strcpy(cod,"0");
    else strcpy(cod,codigo);
}

void Libro::operator +=(const class LibroPrestado &libPrestado){
    if(libPrestado.GetTipo() == 'E') SetCantEst(GetCantEst() + 1);
    else if(libPrestado.GetTipo() == 'A') SetCantAdm(GetCantAdm() + 1);
    else if(libPrestado.GetTipo() == 'D') SetCantDoc(GetCantDoc() + 1);
    SetPrestados(GetPrestados() + 1);
}

