/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ServicioDeSalud.h
 * Author: Sebastian
 *
 * Created on 28 de junio de 2023, 21:00
 */

#ifndef SERVICIODESALUD_H
#define SERVICIODESALUD_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <map>
#include <list>
using namespace std;
#include "Medicina.h"
#include "Paciente_Medicina.h"

class ServicioDeSalud {
public:
    void leerMedicinas(const char *nombArch);
    void imprimirMedicinas(const char *nombArch);
    void leerConsultas(const char *nombArch);
    void imprimirPacientes(const char *nombArch);
    void totalizar();
    list<Paciente_Medicina>::iterator buscarPaciente(int dni);
private:
    map<int,Medicina>medicina;
    list<Paciente_Medicina>paciente_medicina;
};

#endif /* SERVICIODESALUD_H */

