/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   MuyGrave.h
 * Author: Sebastian
 *
 * Created on 17 de junio de 2023, 14:25
 */

#ifndef MUYGRAVE_H
#define MUYGRAVE_H
#include "Infraccion.h"


class MuyGrave : public Infraccion{
private:
    int puntos;
    int meses;
public:
    MuyGrave();
    virtual ~MuyGrave();
    void SetMeses(int meses);
    int GetMeses() const;
    void SetPuntos(int puntos);
    int GetPuntos() const;
    void lee(ifstream &arch,int codInfraccion);
    void imprime(ofstream &arch);
    void aplica();
    void acumula(double &montoMulta,int &puntosPerdidos,int &mesesSancionados);
};

#endif /* MUYGRAVE_H */

