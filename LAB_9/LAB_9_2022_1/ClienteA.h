/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ClienteA.h
 * Author: Sebastian
 *
 * Created on 13 de junio de 2023, 17:52
 */

#ifndef CLIENTEA_H
#define CLIENTEA_H
#include "Cliente.h"

class ClienteA : public Cliente{
private:
    double descuento;
public:
    ClienteA();
    virtual ~ClienteA();
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void calcula();
};

#endif /* CLIENTEA_H */

