/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nuevo.h
 * Author: Sebastian
 *
 * Created on 1 de julio de 2023, 13:28
 */

#ifndef NUEVO_H
#define NUEVO_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Renovacion.h"

class Nuevo : public Renovacion{
public:
    Nuevo();
    void SetExreglas(double exreglas);
    double GetExreglas() const;
    void lee(ifstream &arch,int licencia);
    void imprime(ofstream &arch);
private:
    double exreglas;
};

#endif /* NUEVO_H */

