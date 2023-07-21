/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Conductor.h
 * Author: Sebastian
 *
 * Created on 4 de junio de 2023, 14:46
 */

#ifndef CONDUCTOR_H
#define CONDUCTOR_H
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Conductor.h"
#include "FaltaCond.h"
#include "Falta.h"
#include "Infraccion.h"
using namespace std;

class Conductor {
private:
    int licencia;
    char *nombre;
    class FaltaCond lfaltas[100];
    int numFaltas;
    double montoTotal;
public:
    Conductor();
    virtual ~Conductor();
    void SetMontoTotal(double montoTotal);
    double GetMontoTotal() const;
    void SetNumFaltas(int numFaltas);
    int GetNumFaltas() const;
    void SetNombre(char* nomb);
    void GetNombre(char *nomb) const;
    void SetLicencia(int licencia);
    int GetLicencia() const;
    void imprimeFaltas(ofstream &arch) const;
    void operator +(const class Falta &falta);
    void operator +(const class Infraccion &infraccion);
    void operator ++(int a);
    void operator *(const int fecha);
};

#endif /* CONDUCTOR_H */

