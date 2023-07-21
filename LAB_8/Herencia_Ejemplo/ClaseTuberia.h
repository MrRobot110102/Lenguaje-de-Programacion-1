/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ClaseTuberia.h
 * Author: Sebastian
 *
 * Created on 9 de junio de 2023, 18:46
 */

#ifndef CLASETUBERIA_H
#define CLASETUBERIA_H
#include "ClaseCilindro.h"


class ClaseTuberia : public ClaseCilindro{
private:
    double radioInterior;
public:
    ClaseTuberia(double,double,double);
    void SetRadioInterior(double radioInterior);
    double GetRadioInterior() const;
    double volumen(void);
    double area(void);
    void mostrarResultados(void);
};

#endif /* CLASETUBERIA_H */

