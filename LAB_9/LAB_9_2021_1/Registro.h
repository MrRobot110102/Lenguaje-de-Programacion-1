/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Registro.h
 * Author: Sebastian
 *
 * Created on 17 de junio de 2023, 14:26
 */

#ifndef REGISTRO_H
#define REGISTRO_H
#include "Conductor.h"
#include "Falta.h"
#include "Infraccion.h"

class Registro : public Conductor, public Falta{
private:
    class Infraccion *pfalta;
public:
    Registro();
    virtual ~Registro();
    void asignaRegistro(int codInfraccion);
    void operator =(class Infraccion *pt);
    int validarRegistro();
    void imprimir(ofstream &arch);
    void aplicarDescuentos();
    void acumularMontos(double &montoMulta,int &puntosPerdidos,int &mesesSancionados);
};

#endif /* REGISTRO_H */

