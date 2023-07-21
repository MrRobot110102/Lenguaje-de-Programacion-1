/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Semipresencial.h
 * Author: Sebastian
 *
 * Created on 6 de julio de 2023, 23:13
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H
#include "Alumno.h"

class Semipresencial : public Alumno{
public:
    Semipresencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void actualiza(int descuento,int num);
private:
    double descuento;
    double total;
};

#endif /* SEMIPRESENCIAL_H */

