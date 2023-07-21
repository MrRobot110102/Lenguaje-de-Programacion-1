/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ColaSol.h
 * Author: Sebastian
 *
 * Created on 30 de junio de 2023, 23:38
 */

#ifndef COLASOL_H
#define COLASOL_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "NodoCola.h"

class ColaSol {
public:
    ColaSol();
    virtual ~ColaSol();
    void SetN(int n);
    int GetN() const;
    void crearCola(ifstream &arch);
    void atiendeCola(char *libro,int &carne);
    void ingresaCola(char *libro,int carne);
    int colaVacia();
private:
    class NodoCola *inicola;
    class NodoCola *fincola;
    int n;
    void encolar(class NodoCola *nuevo);
    NodoCola *desencolar();
};

#endif /* COLASOL_H */

