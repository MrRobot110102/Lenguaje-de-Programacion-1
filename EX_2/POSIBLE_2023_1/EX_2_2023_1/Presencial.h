/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Presencial.h
 * Author: Sebastian
 *
 * Created on 6 de julio de 2023, 23:06
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H
#include "Alumno.h"

class Presencial : public Alumno{
public:
    Presencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void actualiza(int descuento,int num);
private:
    double recargo;
    double total;
};

#endif /* PRESENCIAL_H */

