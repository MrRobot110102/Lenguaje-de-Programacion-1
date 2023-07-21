/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: Sebastian
 *
 * Created on 1 de julio de 2023, 13:29
 */

#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Renovacion.h"
#include "Conductor.h"

class Nodo {
public:
    Nodo();
    Nodo(const Nodo& orig);
    void leer(ifstream &arch);
    void operator=(const class Nodo &nd);
    int getLicencia() const;
    void imprimir(ofstream &arch);
    bool operator <(const Nodo &nd);
private:
    class Renovacion *pcosto;
    class Conductor chofer;
};

#endif /* NODO_H */

