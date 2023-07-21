/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Prestamo.h
 * Author: Sebastian
 *
 * Created on 21 de junio de 2023, 21:03
 */

#ifndef PRESTAMO_H
#define PRESTAMO_H
#include "Libro.h"

class Prestamo : public Libro{
private:
    int dias;
    int fecha;
public:
    Prestamo();
    virtual ~Prestamo();
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDias(int dias);
    int GetDias() const;
    void Actualiza(int dias, int fecha, double precio);
    void AsignaZona(int zona) ;
    void Imprimir(ofstream &arch);
};

#endif /* PRESTAMO_H */

