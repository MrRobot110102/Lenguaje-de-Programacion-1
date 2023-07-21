/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RegistroUsuario.cpp
 * Author: Sebastian
 * 
 * Created on 1 de julio de 2023, 11:50
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <list>
#include <iterator>
#include "RegistroUsuario.h"

void RegistroUsuario::operator=(const class Usuario& usu) {
    usuario = usu;
}

void RegistroUsuario::imprimeUsuario(ofstream& arch) {
    usuario.imprimeDatos(arch);
    for (list<RegistroPrestamo>::iterator it = prestamos.begin();it != prestamos.end();it++) 
        it->imprimeDatos(arch);
}

void RegistroUsuario::agregarPrestamo(const class RegistroPrestamo& regPrestamo) {
    prestamos.push_back(regPrestamo);
}

bool RegistroUsuario::estaSuspendido(int fecha) {
    for (list<RegistroPrestamo>::iterator it = prestamos.begin();it != prestamos.end();it++)
        if(fecha - it->GetFecha() > 7) return true;
    return false;
}

void RegistroUsuario::imprimeDatosPersonalesUsuario(ofstream& arch) {
    usuario.imprimeDatos(arch);
}

int RegistroUsuario::getCodigo() {
    return usuario.GetCodigo();
}

char RegistroUsuario::getTipo() {
    return usuario.GetTipo();
}





