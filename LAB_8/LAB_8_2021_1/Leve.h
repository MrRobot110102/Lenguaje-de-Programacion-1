/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Leve.h
 * Author: Sebastian
 *
 * Created on 11 de junio de 2023, 13:27
 */

#ifndef LEVE_H
#define LEVE_H
#include "Infraccion.h"
#include "Falta.h"

class Leve : public Infraccion, public Falta{
private:
    double descuento;
public:
    Leve();
    virtual ~Leve();
    void SetDescuento(double descuento);
    double GetDescuento() const;
    
};

#endif /* LEVE_H */

