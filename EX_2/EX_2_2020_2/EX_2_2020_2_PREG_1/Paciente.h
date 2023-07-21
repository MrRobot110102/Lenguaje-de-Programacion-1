/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Paciente.h
 * Author: Sebastian
 *
 * Created on 3 de julio de 2023, 18:50
 */

#ifndef PACIENTE_H
#define PACIENTE_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Paciente {
public:
    Paciente();
    Paciente(const Paciente& orig);
    virtual ~Paciente();
    void SetCodMed(char *cod);
    void GetCodMed(char *cod) const;
    void SetNombre(char *nomb);
    void GetNombre(char *nomb) const;
    void SetDni(int dni);
    int GetDni() const;
    void operator =(const Paciente &pac);
    virtual void leer(ifstream &arch);
    virtual int prioridad() = 0;
    virtual void imprimir(ofstream &arch);
    virtual void observacion(char *obs) = 0;
    virtual int imprimirReferencia(ofstream &arch) = 0;
    void SetEdad(int edad);
    int GetEdad() const;
private:
    int dni;
    int edad;
    char *nombre;
    char *codMed;
};

#endif /* PACIENTE_H */

