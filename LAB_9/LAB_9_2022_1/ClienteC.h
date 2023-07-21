/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ClienteC.h
 * Author: Sebastian
 *
 * Created on 13 de junio de 2023, 17:53
 */

#ifndef CLIENTEC_H
#define CLIENTEC_H
#include "Cliente.h"


class ClienteC : public Cliente{
private:
    double flete;
public:
    ClienteC();
    virtual ~ClienteC();
    void SetFlete(double flete);
    double GetFlete() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void calcula();
};

#endif /* CLIENTEC_H */

