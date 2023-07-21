/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Procesa.h
 * Author: Sebastian
 *
 * Created on 11 de junio de 2023, 13:27
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
    void lee();
    void imprime();
    void procesa();
    int buscarConductor(int licencia, char *nomb);
    void procesarFaltas(int licencia, double &montoMulta, int &puntosPerdidos, int &mesesSancionado);
    void imprimeLinea(ofstream &arch, int cantidad, char car);
};

#endif /* PROCESA_H */

