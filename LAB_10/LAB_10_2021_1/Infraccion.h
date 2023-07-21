/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Infraccion.h
 * Author: Sebastian
 *
 * Created on 26 de junio de 2023, 16:08
 */

#ifndef INFRACCION_H
#define INFRACCION_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Infraccion {
private:
    int codigo;
    char *gravedad;
    double multa;
public:
    Infraccion();
    Infraccion(const Infraccion& orig);
    virtual ~Infraccion();
    void SetMulta(double multa);
    double GetMulta() const;
    void SetGravedad(const char *grav);
    void GetGravedad(char *grav) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void lee(int codigo) = 0;
    virtual void imprimir(ofstream &arch);
};

#endif /* INFRACCION_H */

