/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Curso.h
 * Author: Sebastian
 *
 * Created on 6 de julio de 2023, 23:29
 */

#ifndef CURSO_H
#define CURSO_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Curso {
public:
    Curso();
    Curso(const Curso& orig);
    virtual ~Curso();
    void SetNota(int nota);
    int GetNota() const;
    void SetSemestre(int semestre);
    int GetSemestre() const;
    void SetCodigo(char *cod);
    void GetCodigo(char *cod) const;
    void operator =(const Curso &cur);
    void imprimirCurso(ofstream &arch);
    bool operator <(const Curso &cur);
private:
    char *codigo;
    int semestre;
    int nota;
};

#endif /* CURSO_H */

