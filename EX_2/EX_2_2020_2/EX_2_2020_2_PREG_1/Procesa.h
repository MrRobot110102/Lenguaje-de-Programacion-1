/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.h
 * Author: Sebastian
 *
 * Created on 3 de julio de 2023, 19:12
 */

#ifndef PROCESA_H
#define PROCESA_H
#include "NPacientes.h"

class Procesa {
public:
    void lee(const char *nombArch);
    void ordena();
    void imprime(const char *nombArch);
private:
    class NPacientes lpacientes[150];
};

#endif /* PROCESA_H */

