/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.h
 * Author: Sebastian
 *
 * Created on 30 de junio de 2023, 23:38
 */

#ifndef PROCESA_H
#define PROCESA_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <list>
#include <vector>
#include <iterator>
using namespace std;
#include "Libro.h"
#include "ColaSol.h"
#include "NUsuario.h"

class Procesa {
public:
    void Carga();
    void CargaLibros();
    void CargaUsuarios();
    void LeeSolicitudes();
    void Atiende();
    void Actualizar(char *libro,int carne);
    void Imprime();
    void Imprimelibros();
    void ImprimeCola();
    void ImprimeUsuario(int carne,ofstream &arch);
    
private:
    list<class Libro>llibros;
    class ColaSol cola;
    vector<class NUsuario> vusuarios;
};

#endif /* PROCESA_H */

