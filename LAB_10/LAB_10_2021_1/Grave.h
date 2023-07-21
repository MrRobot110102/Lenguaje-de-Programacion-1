/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Grave.h
 * Author: Sebastian
 *
 * Created on 26 de junio de 2023, 16:09
 */

#ifndef GRAVE_H
#define GRAVE_H
#include "Infraccion.h"


class Grave : public Infraccion{
private:
    double descuento;
    int puntos;
public:
    void SetPuntos(int puntos);
    int GetPuntos() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(int codigo);
    void imprimir(ofstream &arch);
};

#endif /* GRAVE_H */

