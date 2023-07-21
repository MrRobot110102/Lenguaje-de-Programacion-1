/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Paciente_Medicina.h
 * Author: Sebastian
 *
 * Created on 28 de junio de 2023, 21:00
 */

#ifndef PACIENTE_MEDICINA_H
#define PACIENTE_MEDICINA_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <list>
#include <map>
using namespace std;
#include "Paciente.h"
#include "Medicina_Cantidad.h"
#include "Medicina.h"

class Paciente_Medicina {
public:
    Paciente_Medicina();
    void SetTotalDeGastos(double totalDeGastos);
    double GetTotalDeGastos() const;
    int GetDni();
    int GetFechaUltimaConsulta();
    void totalizar(map<int,Medicina>med);
    void operator = (const class Paciente &pac);
    void LeerMedicinas(ifstream &arch);
    int operator <(const class Paciente &pac);
    list<class Medicina_Cantidad>::iterator buscarMedicina(int codMedicina);
    void actualizarFechaYMedico(int fecha,char *codMedico);
    void imprimirPaciente(ofstream &arch);
private:
    class Paciente paciente;
    list<class Medicina_Cantidad>medicina_cantidad;
    double totalDeGastos;
};

#endif /* PACIENTE_MEDICINA_H */

