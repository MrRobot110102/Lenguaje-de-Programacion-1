/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   paciente.h
 * Author: Sebastian
 *
 * Created on 3 de junio de 2023, 22:21
 */

#ifndef PACIENTE_H
#define PACIENTE_H
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "cita.h"
#include "medico.h"
using namespace std;

class paciente {
private:
    int dni;
    char *nombre;
    class cita lcitas[100];
    int telefono;
    double totalgastado;
public:
    paciente();
    virtual ~paciente();
    void SetTotalgastado(double totalgastado);
    double GetTotalgastado() const;
    void SetTelefono(int telefono);
    int GetTelefono() const;
    void SetNombre(char* nomb);
    void GetNombre(char *nomb) const;
    void SetDni(int dni);
    int GetDni() const;
    void operator +=(const class cita &cit);
    void imprimeCitas(ofstream &arch) const;
    void actualizaTarifas(const class medico *arrMedicos);
    void operator ++(int a);
};

#endif /* PACIENTE_H */

