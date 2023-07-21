/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Medico.h
 * Author: Sebastian
 *
 * Created on 6 de junio de 2023, 14:09
 */

#ifndef MEDICO_H
#define MEDICO_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Paciente.h"
using namespace std;

class Medico {
private:
    char *codigo;
    char *nombre;
    char *especialidad;
    double tarifa;
    class Paciente lpacientes[100];
    int numPac;
    double ingresosP;
    double ingresosS;
public:
    Medico();
    virtual ~Medico();
    void SetIngresosS(double ingresosS);
    double GetIngresosS() const;
    void SetIngresosP(double ingresosP);
    double GetIngresosP() const;
    void SetNumPac(int numPac);
    int GetNumPac() const;
    void SetTarifa(double tarifa);
    double GetTarifa() const;
    void SetEspecialidad(char* espec);
    void GetEspecialidad(char* espec) const;
    void SetNombre(char *nomb);
    void GetNombre(char *nomb) const;
    void SetCodigo(char* cod);
    void GetCodigo(char *cod) const;
    void operator +(const class Paciente &paciente);
    void operator *(int fecha);
    void operator -(int fecha);
    void operator ++(int a);
    void imprimirPacientesAtendidos(ofstream &arch) const;
    void imprimirPacientesPorAtender(ofstream &arch) const;
};

ifstream & operator >>(ifstream &arch,class Medico &medico);
ofstream & operator <<(ofstream &arch,const class Medico &medico);
void imprimeLinea (char car, int num, ofstream &arch);

#endif /* MEDICO_H */

