/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Infraccion.h
 * Author: Sebastian
 *
 * Created on 17 de junio de 2023, 14:25
 */

#ifndef INFRACCION_H
#define INFRACCION_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

class Infraccion {
private:
    int codigo;
    char *gravedad;
    double multa;
public:
    Infraccion();
    virtual ~Infraccion();
    void SetMulta(double multa);
    double GetMulta() const;
    void SetGravedad(const char *grav);
    void GetGravedad(char *grav) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void lee(ifstream &arch,int codInfraccion) = 0;
    virtual void imprime(ofstream &arch) = 0;
    virtual void aplica()=0;
    virtual void acumula(double &montoMulta,int &puntosPerdidos,int &mesesSancionados)=0;
};

#endif /* INFRACCION_H */

