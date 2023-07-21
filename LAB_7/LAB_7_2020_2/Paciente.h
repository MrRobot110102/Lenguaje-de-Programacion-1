/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Paciente.h
 * Author: Sebastian
 *
 * Created on 6 de junio de 2023, 14:09
 */

#ifndef PACIENTE_H
#define PACIENTE_H
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Paciente {
private:
    int fecha;
    int codigo;
    char *nombre;
    double prima;
    char estado;
public:
    Paciente();
    virtual ~Paciente();
    void SetEstado(char estado);
    char GetEstado() const;
    void SetPrima(double prima);
    double GetPrima() const;
    void SetNombre(char* nomb);
    void GetNombre(char *nomb) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void operator =(const class Paciente &paciente);
};

ifstream & operator >>(ifstream &arch,class Paciente &paciente);
ofstream & operator <<(ofstream &arch,const class Paciente &paciente);
#endif /* PACIENTE_H */

