/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Disponible.h
 * Author: Sebastian
 *
 * Created on 21 de junio de 2023, 21:02
 */

#ifndef DISPONIBLE_H
#define DISPONIBLE_H
#include "Libro.h"

class Disponible : public Libro{
private:
    int zona;
public:
    Disponible();
    virtual ~Disponible();
    void SetZona(int zona);
    int GetZona() const;
    void AsignaZona(int zona);
    void Actualiza(int dias,int fecha,double precio);
    void Imprimir(ofstream &arch);
};

#endif /* DISPONIBLE_H */

