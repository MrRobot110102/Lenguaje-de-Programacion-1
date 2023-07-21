/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ACurso.h
 * Author: Sebastian
 *
 * Created on 7 de junio de 2023, 22:50
 */

#ifndef ACURSO_H
#define ACURSO_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Curso.h"

class ACurso {
private:
    int codigo;
    class Curso clcurso;
    char operacion;
public:
    ACurso();
    virtual ~ACurso();
    void SetOperacion(char operacion);
    char GetOperacion() const;
    void SetClcurso(Curso clcurso);
    void GetClcurso(class Curso &curso) const;   
    void SetCodigo(int codigo);
    int GetCodigo() const;
};

ifstream & operator >>(ifstream &arch,class ACurso &aCurso);

#endif /* ACURSO_H */

