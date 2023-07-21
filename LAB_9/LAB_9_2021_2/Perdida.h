/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Perdida.h
 * Author: Sebastian
 *
 * Created on 21 de junio de 2023, 21:04
 */

#ifndef PERDIDA_H
#define PERDIDA_H
#include "Libro.h"

class Perdida : public Libro{
private:
    double precio;
public:
    Perdida();
    virtual ~Perdida();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void Actualiza(int dias, int fecha, double precio);
    void AsignaZona(int zona) ;
    void Imprimir(ofstream &arch);
};

#endif /* PERDIDA_H */

