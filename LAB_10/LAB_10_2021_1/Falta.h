/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Falta.h
 * Author: Sebastian
 *
 * Created on 26 de junio de 2023, 16:09
 */

#ifndef FALTA_H
#define FALTA_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Falta {
private:
    int licencia;
    int fecha;
    char *placa;
public:
    Falta();
    Falta(const Falta& orig);
    virtual ~Falta();
    void SetPlaca(char *plac);
    void GetPlaca(char *plac) const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetLicencia(int licencia);
    int GetLicencia() const;
    void operator =(const class Falta &fal);
    void leer(ifstream &arch);
};

ofstream & operator <<(ofstream &arch,const class Falta &fal);

#endif /* FALTA_H */

