/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Procesa.h
 * Author: Sebastian
 *
 * Created on 17 de junio de 2023, 14:26
 */

#ifndef PROCESA_H
#define PROCESA_H
#include "Registro.h"

class Procesa {
private:
    class Registro lregistro[1000];
    int cantidad;
public:
    Procesa();
    virtual ~Procesa();
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void leer();
    void imprimir();
    void aplicar();
    void consolidar();
    int buscarConductor(int licencia,char *nomb);
};

#endif /* PROCESA_H */

