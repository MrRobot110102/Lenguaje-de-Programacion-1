/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Antiguo.h
 * Author: Sebastian
 *
 * Created on 1 de julio de 2023, 13:28
 */

#ifndef ANTIGUO_H
#define ANTIGUO_H
#include "Renovacion.h"

class Antiguo : public Renovacion{
public:
    Antiguo();
    void SetEstado(int estado);
    int GetEstado() const;
    void SetExmanejo(double exmanejo);
    double GetExmanejo() const;
    void lee(ifstream &arch,int licencia);
    void imprime(ofstream &arch);
private:
    double exmanejo;
    int estado;
};

#endif /* ANTIGUO_H */

