/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Boleta.h
 * Author: Sebastian
 *
 * Created on 6 de julio de 2023, 23:22
 */

#ifndef BOLETA_H
#define BOLETA_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Alumno.h"

class Boleta {
public:
    Boleta();
    virtual ~Boleta();
    void escoger(char tipo);
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    void getDatosAlumno(int &cod,char *nomb,int &esca,double &cred,double &tot);
    void setDatosAlumno(int cod,char *nomb,int esca,double cred,double tot);
    void actualiza(int descuento,int num);
    void elimina();
    int getCodigo();
private:
    class Alumno *pboleta;
};

#endif /* BOLETA_H */

