/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   LibroPrestado.cpp
 * Author: Sebastian
 * 
 * Created on 5 de junio de 2023, 18:22
 */

#include <cstring>

#include "LibroPrestado.h"

LibroPrestado::LibroPrestado() {
    codigoLib = nullptr;
}

LibroPrestado::~LibroPrestado() {
    if(codigoLib != nullptr) delete codigoLib;
}

void LibroPrestado::SetDeuda(int deuda) {
    this->deuda = deuda;
}

int LibroPrestado::GetDeuda() const {
    return deuda;
}

void LibroPrestado::SetFechaDeRetiro(int fechaDeRetiro) {
    this->fechaDeRetiro = fechaDeRetiro;
}

int LibroPrestado::GetFechaDeRetiro() const {
    return fechaDeRetiro;
}

void LibroPrestado::SetCodigoLib(char* codLib) {
    if(codigoLib != nullptr) delete codigoLib;
    codigoLib = new char[strlen(codLib) + 1];
    strcpy(codigoLib,codLib);
}

void LibroPrestado::GetCodigoLib(char *codLib) const {
    if(codigoLib == nullptr) codigoLib[0] = 0;
    strcpy(codLib,codigoLib);
}

void LibroPrestado::SetTipo(char tipo) {
    this->tipo = tipo;
}

char LibroPrestado::GetTipo() const {
    return tipo;
}

void LibroPrestado::SetCarne(int carne) {
    this->carne = carne;
}

int LibroPrestado::GetCarne() const {
    return carne;
}
void LibroPrestado::operator = (const class LibroPrestado &libPrestado){
    carne = libPrestado.GetCarne();
    fechaDeRetiro = libPrestado.GetFechaDeRetiro();
    tipo = libPrestado.GetTipo();
    char cadena[10];
    libPrestado.GetCodigoLib(cadena);
    SetCodigoLib(cadena);
}
