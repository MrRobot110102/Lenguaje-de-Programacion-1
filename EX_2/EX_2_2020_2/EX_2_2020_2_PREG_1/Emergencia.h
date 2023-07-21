/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Emergencia.h
 * Author: Sebastian
 *
 * Created on 3 de julio de 2023, 19:03
 */

#ifndef EMERGENCIA_H
#define EMERGENCIA_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Paciente.h"

class Emergencia : public Paciente{
public:
    Emergencia();
    virtual ~Emergencia();
    void SetNombreRef(char *nomb);
    void GetNombreRef(char *nomb) const;
    void SetTelefonoRef(int telefonoRef);
    int GetTelefonoRef() const;
    void leer(ifstream &arch);
    int prioridad();
    void imprimir(ofstream &arch);
    void observacion(char *obs);
    int imprimirReferencia(ofstream &arch);
private:
    int telefonoRef;
    char *nombreRef;
};

#endif /* EMERGENCIA_H */

