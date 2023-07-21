/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Libro.cpp
 * Author: Sebastian
 * 
 * Created on 25 de junio de 2023, 19:27
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Libro.h"

Libro::Libro() {
    autor = nullptr;
    codigo = nullptr;
    titulo = nullptr;
}

Libro::Libro(const Libro& orig) {
    autor = nullptr;
    codigo = nullptr;
    titulo = nullptr;
    *this = orig;
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

void Libro::SetAnho(int anho) {
    this->anho = anho;
}

int Libro::GetAnho() const {
    return anho;
}

void Libro::SetStock(int stock) {
    this->stock = stock;
}

int Libro::GetStock() const {
    return stock;
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

void Libro::operator = (const class Libro &libro){
    char autor[100],codigo[20],titulo[100];
    
    libro.GetAutor(autor);
    libro.GetCodigo(codigo);
    libro.GetTitulo(titulo);
    
    SetAnho(libro.GetAnho());
    SetAutor(autor);
    SetCantidad(libro.GetCantidad());
    SetCodigo(codigo);
    SetPrecio(libro.GetPrecio());
    SetStock(libro.GetStock());
    SetTitulo(titulo);
}

ifstream & operator >>(ifstream &arch,class Libro &libro){
    char autor[100],codigo[20],titulo[100],car;
    int anio,cantidad;
    double precio;
    arch.getline(codigo,20,',');
    if(arch.eof()) return arch;
    arch.getline(titulo,100,',');
    arch.getline(autor,100,',');
    arch>>anio>>car>>cantidad>>car>>precio;
    arch.get();
    libro.SetAnho(anio);
    libro.SetAutor(autor);
    libro.SetCantidad(cantidad);
    libro.SetCodigo(codigo);
    libro.SetPrecio(precio);
    libro.SetStock(cantidad);
    libro.SetTitulo(titulo);
    return arch;
}

ofstream & operator <<(ofstream &arch,const class Libro &libro){
    char autor[100],codigo[20],titulo[100];
    arch.precision(2);arch<<fixed;
    libro.GetAutor(autor);
    libro.GetCodigo(codigo);
    libro.GetTitulo(titulo);
    arch<<left<<"Codigo:"<<codigo<<endl;
    arch<<left<<"Titulo:"<<titulo<<endl;
    arch<<left<<"Autor: "<<autor<<endl;
    //arch<<left<<"Anio:  "<<libro.GetAnho()<<endl;
    //arch<<left<<"Precio:"<<libro.GetPrecio()<<endl;
    arch<<left<<"Cantidad:  "<<libro.GetCantidad()<<endl;
    arch<<left<<"Stock:     "<<libro.GetStock()<<endl;
    return arch;
}

