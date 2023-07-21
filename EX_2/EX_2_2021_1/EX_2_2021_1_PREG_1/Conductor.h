/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conductor.h
 * Author: Sebastian
 *
 * Created on 1 de julio de 2023, 13:28
 */

#ifndef CONDUCTOR_H
#define CONDUCTOR_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Conductor {
public:
    Conductor();
    Conductor(const Conductor& orig);
    virtual ~Conductor();
    void SetNombre(char *nomb);
    void GetNombre(char *nomb) const;
    void SetLicencia(int licencia);
    int GetLicencia() const;
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    void operator =(const class Conductor &conduc);
private:
    int licencia;
    char *nombre;   
};

#endif /* CONDUCTOR_H */

