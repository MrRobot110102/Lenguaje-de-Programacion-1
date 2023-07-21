/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Grave.h
 * Author: Sebastian
 *
 * Created on 11 de junio de 2023, 13:27
 */

#ifndef GRAVE_H
#define GRAVE_H
#include "Infraccion.h"
#include "Falta.h"

class Grave : public Infraccion, public Falta{
private:
    double descuento;
    int puntos;
public:
    Grave();
    virtual ~Grave();
    void SetPuntos(int puntos);
    int GetPuntos() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
};

#endif /* GRAVE_H */

