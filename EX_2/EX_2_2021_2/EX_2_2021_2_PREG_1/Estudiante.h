/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estudiante.h
 * Author: Sebastian
 *
 * Created on 30 de junio de 2023, 23:38
 */

#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include "Usuario.h"

class Estudiante : public Usuario{
public:
    void SetCelular(int celular);
    int GetCelular() const;
    void leer(ifstream &arch);
    void imprime(ofstream &arch);
private:
    int celular;
};

#endif /* ESTUDIANTE_H */

