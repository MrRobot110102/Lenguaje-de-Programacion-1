/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: Sebastian
 *
 * Created on 6 de julio de 2023, 23:00
 */

#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Alumno {
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(char *nomb);
    void GetNombre(char *nomb) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void operator =(const Alumno &alum);
    void getDatos(int &cod,char *nomb,int &esca,double &cred,double &tot);
    void setDatos(int cod,char *nomb,int esca,double cred,double tot);
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
    virtual void actualiza(int descuento,int num) = 0;
private:
    int codigo;
    char *nombre;
    int escala;
    double creditos;
    double total;
};

#endif /* ALUMNO_H */

