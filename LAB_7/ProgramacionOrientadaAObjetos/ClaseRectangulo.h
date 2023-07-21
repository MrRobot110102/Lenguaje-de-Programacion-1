/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ClaseRectangulo.h
 * Author: Sebastian
 *
 * Created on 25 de mayo de 2023, 16:24
 */

#ifndef CLASERECTANGULO_H
#define CLASERECTANGULO_H

class ClaseRectangulo {
private:
    double base;
    double altura;
public:
    void asignarBase(double);
    void asignarAltura(double);
    void leeDatos(void);    
    double entregarBase(void);
    double entregarAltura(void);
    void imprimeDatos(void);
    double area(void);
    double perimetro(void);
    void imprimeResultados(void);
};

#endif /* CLASERECTANGULO_H */

