/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Virtual.h
 * Author: Sebastian
 *
 * Created on 6 de julio de 2023, 23:16
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H
#include "Alumno.h"

class Virtual :public Alumno{
public:
    Virtual();
    virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(char *licen);
    void GetLicencia(char *licen) const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void actualiza(int descuento,int num);
private:
    char *licencia;
    double total;
};

#endif /* VIRTUAL_H */

