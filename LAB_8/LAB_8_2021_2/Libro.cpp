/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Libro.cpp
 * Author: Sebastian
 * 
 * Created on 10 de junio de 2023, 11:37
 */

#include <cstring>

#include "Libro.h"

Libro::Libro() {
    autor = nullptr;
    codigo = nullptr;
    titulo = nullptr;
    precio = 0.0;
}

Libro::~Libro() {
    if(autor != nullptr) delete autor;
    if(codigo != nullptr) delete codigo;
    if(titulo != nullptr) delete titulo;
}

void Libro::SetPrecio(double precio) {
    this->precio = precio;
}

double Libro::GetPrecio() const {
    return precio;
}

void Libro::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Libro::GetCantidad() const {
    return cantidad;
}

void Libro::SetAutor(char *aut) {
    if(autor != nullptr) delete autor;
    autor = new char[strlen(aut) + 1];
    strcpy(autor,aut);
}

void Libro::GetAutor(char *aut) const {
    if(autor == nullptr) aut[0] = 0;
    else strcpy(aut,autor);
}

void Libro::SetTitulo(char *tit) {
    if(titulo != nullptr) delete titulo;
    titulo = new char[strlen(tit) + 1];
    strcpy(titulo,tit);
}

void Libro::GetTitulo(char *tit) const {
    if(titulo == nullptr) tit[0] = 0;
    else strcpy(tit,titulo);
}

void Libro::SetCodigo(char *cod) {
    if(codigo != nullptr) delete codigo;
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo,cod);
}

void Libro::GetCodigo(char *cod) const {
    if(codigo == nullptr) cod[0] = 0;
    else strcpy(cod,codigo);
}

