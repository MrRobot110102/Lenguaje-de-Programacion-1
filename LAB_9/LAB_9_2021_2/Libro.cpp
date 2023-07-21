/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Libro.cpp
 * Author: Sebastian
 * 
 * Created on 21 de junio de 2023, 20:50
 */

#include <cstring>

#include "Libro.h"

Libro::Libro() {
    titulo = nullptr;
    autor = nullptr;
    codigo = nullptr;
}

Libro::~Libro() {
    if(titulo != nullptr) delete titulo;
    if(autor != nullptr) delete autor;
    if(codigo != nullptr) delete codigo;
}

void Libro::SetPrecio(double precio) {
    this->precio = precio;
}

double Libro::GetPrecio() const {
    return precio;
}

void Libro::SetAnho(int anho) {
    this->anho = anho;
}

int Libro::GetAnho() const {
    return anho;
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

void Libro::AsignaDatos(char *cod,char *tit,char *aut,int aa, int numero,double precio){
    SetAnho(aa);
    SetAutor(aut);
    SetCantidad(numero);
    SetCodigo(cod);
    SetPrecio(precio);
    SetTitulo(tit);
}

void Libro::ObtieneDatos(char *cod,char *tit,char *aut,int &aa, int &numero,double &precio){
    aa = GetAnho();
    numero = GetCantidad();
    precio = GetPrecio();
    GetCodigo(cod);
    GetTitulo(tit);
    GetAutor(aut);
}

