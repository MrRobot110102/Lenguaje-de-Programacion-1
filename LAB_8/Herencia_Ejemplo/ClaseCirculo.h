/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ClaseCirculo.h
 * Author: Sebastian
 *
 * Created on 9 de junio de 2023, 18:30
 */

#ifndef CLASECIRCULO_H
#define CLASECIRCULO_H

class ClaseCirculo {
private:
    double radio;
public:
    ClaseCirculo(double);
    void SetRadio(double radio);
    double GetRadio() const;
    double area(void);
    double circunferencia(void);
    void mostrarResultados(void);
};

#endif /* CLASECIRCULO_H */

