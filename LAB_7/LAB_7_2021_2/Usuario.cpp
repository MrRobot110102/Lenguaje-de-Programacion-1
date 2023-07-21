/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Usuario.cpp
 * Author: Sebastian
 * 
 * Created on 5 de junio de 2023, 18:22
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "SobrecargaOperadores.h"
#include "LibroPrestado.h"
#include "Usuario.h"

Usuario::Usuario() {
    nombre = nullptr;
    numLibPrest = 0;
}

Usuario::~Usuario() {
    if(nombre != nullptr) delete nombre;
}

void Usuario::SetCondicion(int condicion) {
    this->condicion = condicion;
}

int Usuario::GetCondicion() const {
    return condicion;
}

void Usuario::SetNumLibPrest(int numLibPrest) {
    this->numLibPrest = numLibPrest;
}

int Usuario::GetNumLibPrest() const {
    return numLibPrest;
}

void Usuario::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre,nomb);
}

void Usuario::GetNombre(char *nomb) const {
    if(nombre == nullptr) nombre[0] = 0;
    strcpy(nomb,nombre);
}

void Usuario::SetTipo(char tipo) {
    this->tipo = tipo;
}

char Usuario::GetTipo() const {
    return tipo;
}

void Usuario::SetCarne(int carne) {
    this->carne = carne;
}

int Usuario::GetCarne() const {
    return carne;
}
void Usuario::imprimirLibrosPrestados(ofstream &arch) const{
    for (int i = 0; i < GetNumLibPrest(); i++) arch<<libPrest[i];
}

void Usuario::operator +=(const class LibroPrestado &libPrestado){
    libPrest[numLibPrest] = libPrestado;
    numLibPrest++;
}

void Usuario::operator *(int fecha){
    for (int i = 0; i < GetNumLibPrest(); i++) {
        if(libPrest[i].GetFechaDeRetiro() > fecha){
            if(GetTipo() == 'E'){
                if(libPrest[i].GetFechaDeRetiro() - fecha > 10) libPrest[i].SetDeuda(1);
                else libPrest[i].SetDeuda(0);
            }else if(GetTipo() == 'D'){
                if(libPrest[i].GetFechaDeRetiro() - fecha > 15) libPrest[i].SetDeuda(1);
                else libPrest[i].SetDeuda(0);
            }else if(GetTipo() == 'A'){
                if(libPrest[i].GetFechaDeRetiro() - fecha > 7) libPrest[i].SetDeuda(1);
                else libPrest[i].SetDeuda(0);
            }
        }else libPrest[i].SetDeuda(0);
    }
    for (int i = 0; i < GetNumLibPrest(); i++)
        if(libPrest[i].GetDeuda() == 1){
            SetCondicion(0);
            return;
        }
    SetCondicion(1);
}

