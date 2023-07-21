/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ambulatorio.h
 * Author: Sebastian
 *
 * Created on 3 de julio de 2023, 18:58
 */

#ifndef AMBULATORIO_H
#define AMBULATORIO_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Paciente.h"


class Ambulatorio : public Paciente{
public:
    void SetPorcSeguro(double porcSeguro);
    double GetPorcSeguro() const;
    void leer(ifstream &arch);
    int prioridad();
    void imprimir(ofstream &arch);
    void observacion(char *obs);
    int imprimirReferencia(ofstream &arch);
private:
    double porcSeguro;
};

#endif /* AMBULATORIO_H */

