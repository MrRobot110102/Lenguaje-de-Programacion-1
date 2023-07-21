/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   MuyGrave.h
 * Author: Sebastian
 *
 * Created on 26 de junio de 2023, 16:09
 */

#ifndef MUYGRAVE_H
#define MUYGRAVE_H
#include "Infraccion.h"


class MuyGrave : public Infraccion{
private:
    int puntos;
    int meses;
public:
    void SetMeses(int meses);
    int GetMeses() const;
    void SetPuntos(int puntos);
    int GetPuntos() const;
    void lee(int codigo);
    void imprimir(ofstream &arch);
};

#endif /* MUYGRAVE_H */

