/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NUsuario.h
 * Author: Sebastian
 *
 * Created on 30 de junio de 2023, 23:38
 */

#ifndef NUSUARIO_H
#define NUSUARIO_H
#include "Usuario.h"


class NUsuario {
public:
    NUsuario();
    NUsuario(const NUsuario& orig);
    void operator=(const NUsuario &orig);
    void leeUsuario(ifstream &arch);
    void imprimeUsuario(ofstream &arch);
    int getCarne();
private:
    class Usuario *pusuario;
};

#endif /* NUSUARIO_H */

