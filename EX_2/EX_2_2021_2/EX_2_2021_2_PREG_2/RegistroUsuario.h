/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RegistroUsuario.h
 * Author: Sebastian
 *
 * Created on 1 de julio de 2023, 11:50
 */

#ifndef REGISTROUSUARIO_H
#define REGISTROUSUARIO_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <list>
#include "RegistroPrestamo.h"
#include "Usuario.h"
using namespace std;

class RegistroUsuario {
public:
    void operator =(const class Usuario &usuario);
    void imprimeUsuario(ofstream &arch);
    void agregarPrestamo(const class RegistroPrestamo &regPrestamo);
    bool estaSuspendido(int fecha);
    void imprimeDatosPersonalesUsuario(ofstream &arch);
    int getCodigo();
    char getTipo();
private:
    class Usuario usuario;
    list<RegistroPrestamo> prestamos;
};

#endif /* REGISTROUSUARIO_H */

