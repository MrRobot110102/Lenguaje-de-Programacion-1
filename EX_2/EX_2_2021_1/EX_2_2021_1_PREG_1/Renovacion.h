/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Renovacion.h
 * Author: Sebastian
 *
 * Created on 1 de julio de 2023, 13:28
 */

#ifndef RENOVACION_H
#define RENOVACION_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Renovacion {
public:
    Renovacion();
    Renovacion(const Renovacion& orig);
    void SetExmedico(double exmedico);
    double GetExmedico() const;
    void SetTramite(double tramite);
    double GetTramite() const;
    void SetMulta(double multa);
    double GetMulta() const;
    void operator =(const class Renovacion &renova);
    virtual void lee(ifstream &arch,int licencia) = 0;
    virtual void imprime(ofstream &arch) = 0;
private:
    double multa;
    double tramite;
    double exmedico;
};

#endif /* RENOVACION_H */

