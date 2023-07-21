/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ClaseCilindro.h
 * Author: Sebastian
 *
 * Created on 9 de junio de 2023, 18:37
 */

#ifndef CLASECILINDRO_H
#define CLASECILINDRO_H
#include "ClaseCirculo.h"

class ClaseCilindro : public ClaseCirculo{
private:
    double altura;
public:
    ClaseCilindro(double, double);
    void SetAltura(double altura);
    double GetAltura() const;
    double volumen(void);
    double area(void);
    void mostrarResultados(void);
};

#endif /* CLASECILINDRO_H */

