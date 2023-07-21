/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: Sebastian
 *
 * Created on 6 de julio de 2023, 23:26
 */

#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;
#include "Lista.h"
#include "Boleta.h"
#include "Curso.h"

class Nodo {
public:
    Nodo();
    void eliminaCurso(const char *nombCurso);
    void eliminaRango(int semestre);
    friend class Lista;
private:
    class Boleta dboleta;
    vector<Curso>vCursos;
    class Nodo *sig;
};

#endif /* NODO_H */

