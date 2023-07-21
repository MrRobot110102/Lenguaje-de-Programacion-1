/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Administrativo.h
 * Author: Sebastian
 *
 * Created on 30 de junio de 2023, 23:37
 */

#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H
#include "Usuario.h"

class Administrativo : public Usuario{
public:
    Administrativo();
    virtual ~Administrativo();
    void SetArea(char *are);
    void GetArea(char *are) const;
    void leer(ifstream &arch);
    void imprime(ofstream &arch);
private:
    char *area;
};

#endif /* ADMINISTRATIVO_H */

