/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   MuyGrave.h
 * Author: Sebastian
 *
 * Created on 11 de junio de 2023, 13:27
 */

#ifndef MUYGRAVE_H
#define MUYGRAVE_H
#include "Infraccion.h"
#include "Falta.h"

class MuyGrave : public Infraccion, public Falta{
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
};

#endif /* MUYGRAVE_H */

