/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Urgencia.h
 * Author: Sebastian
 *
 * Created on 3 de julio de 2023, 19:02
 */

#ifndef URGENCIA_H
#define URGENCIA_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Paciente.h"

class Urgencia : public Paciente{
public:
    void SetPorcUrgencia(double porcUrgencia);
    double GetPorcUrgencia() const;
    void SetPorcSeguro(double porcSeguro);
    double GetPorcSeguro() const;
    void leer(ifstream &arch);
    int prioridad();
    void imprimir(ofstream &arch);
    void observacion(char *obs);
    int imprimirReferencia(ofstream &arch);
private:
    double porcSeguro;
    double porcUrgencia;
};

#endif /* URGENCIA_H */

