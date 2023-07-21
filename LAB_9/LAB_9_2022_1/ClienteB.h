/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ClienteB.h
 * Author: Sebastian
 *
 * Created on 13 de junio de 2023, 17:53
 */

#ifndef CLIENTEB_H
#define CLIENTEB_H

#include "Cliente.h"


class ClienteB : public Cliente{
private:
    double descuento;
    double flete;
public:
    ClienteB();
    virtual ~ClienteB();
    void SetFlete(double flete);
    double GetFlete() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void calcula();
};

#endif /* CLIENTEB_H */

