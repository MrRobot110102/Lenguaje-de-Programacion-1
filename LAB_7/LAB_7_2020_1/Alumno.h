/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Alumno.h
 * Author: Sebastian
 *
 * Created on 7 de junio de 2023, 22:50
 */

#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Curso.h"
#include "ACurso.h"

class Alumno {
private:
    int codigo;
    char tipo;
    char *nombre;
    class Curso lcurso[100];
    int numcur;
public:
    Alumno();
    virtual ~Alumno();
    void SetNumcur(int numcur);
    int GetNumcur() const;
    void SetNombre(char* nomb);
    void GetNombre(char *nomb) const;
    void SetTipo(char tipo);
    char GetTipo() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void operator +(const class ACurso &aCurso);
    void operator *(const class ACurso &aCurso);
    void operator -(const class ACurso &aCurso);
    double operator /(int ciclo) const;
    double operator --() const;
    double operator ++() const;
    void obtenerCurso(int i,class Curso &curso) const;
};

ifstream & operator >>(ifstream &arch,class Alumno &alumno);
ofstream & operator <<(ofstream &arch,const class Alumno &alumno);
void imprimirLinea(ofstream &arch, char car, int cantidad);

#endif /* ALUMNO_H */

