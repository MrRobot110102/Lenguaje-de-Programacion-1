/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Paciente_Medicina.cpp
 * Author: Sebastian
 * 
 * Created on 28 de junio de 2023, 21:00
 */
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
#include "Paciente_Medicina.h"

Paciente_Medicina::Paciente_Medicina() {
    totalDeGastos = 0.0;
}
void Paciente_Medicina::SetTotalDeGastos(double totalDeGastos) {
    this->totalDeGastos = totalDeGastos;
}

double Paciente_Medicina::GetTotalDeGastos() const {
    return totalDeGastos;
}

int Paciente_Medicina::GetDni() {
    return paciente.GetDni();
}

int Paciente_Medicina::GetFechaUltimaConsulta() {
    return paciente.GetFechaUltimaConsulta();
}


void Paciente_Medicina::operator=(const class Paciente& pac) {
    char nomb[100],codMedico[20];
    paciente.SetDni(pac.GetDni());
    paciente.SetFechaUltimaConsulta(pac.GetFechaUltimaConsulta());
    pac.GetNombre(nomb);
    paciente.SetNombre(nomb);
    pac.GetCodigoDelMedicoDeUltimaConsulta(codMedico);
    cout<<codMedico<<endl;
    //cout<<"1"<<endl;
    //paciente.SetCodigoDelMedicoDeUltimaConsulta(codMedico);
    //cout<<"2"<<endl;
    //pac.GetNombre(nomb);
    //cout<<pac.GetDni()<<endl;
    //cout<<pac.GetFechaUltimaConsulta()<<endl;
    //cout<<nomb<<endl;
    //paciente = pac;
    //paciente.GetNombre(nomb);
    //cout<<paciente.GetDni()<<endl;
    //cout<<paciente.GetFechaUltimaConsulta()<<endl;
    //cout<<nomb<<endl;
}

int Paciente_Medicina::operator<(const class Paciente& pac) {
    return paciente.GetFechaUltimaConsulta() < pac.GetFechaUltimaConsulta();
}

void Paciente_Medicina::LeerMedicinas(ifstream& arch) {
    class Medicina_Cantidad medicina;
    list<Medicina_Cantidad>::iterator itMedicina;
    while(true){
        arch>>medicina;
        //cout<<right<<setw(8)<<medicina.GetCodigo();
        itMedicina = buscarMedicina(medicina.GetCodigo());
        if(itMedicina == medicina_cantidad.end())//nueva medicina
            medicina_cantidad.push_back(medicina);
        else
            itMedicina->SetCantidad(itMedicina->GetCantidad() + medicina.GetCantidad());
        if(arch.get() == '\n') break;
    }
}

list<Medicina_Cantidad>::iterator Paciente_Medicina::buscarMedicina(int codMedicina) {
    for (list<Medicina_Cantidad>::iterator it = medicina_cantidad.begin(); it!=medicina_cantidad.end();it++)
        if(it->GetCodigo() == codMedicina) return it;
    return medicina_cantidad.end();
}

void Paciente_Medicina::actualizarFechaYMedico(int fecha,char *codMedico) {
    paciente.SetFechaUltimaConsulta(fecha);
    paciente.SetCodigoDelMedicoDeUltimaConsulta(codMedico);
}

void Paciente_Medicina::imprimirPaciente(ofstream& arch) {
    char nomb[100];
    //paciente.GetNombre(nomb);
    arch.precision(2);arch<<fixed;
    //arch<<left<<setw(10)<<paciente.GetDni()<<setw(50)<<nomb<<setw(10)<<paciente.GetFechaUltimaConsulta()<<endl;
    paciente.imprimirDatos(arch);
    paciente.GetCodigoDelMedicoDeUltimaConsulta(nomb);
    arch<<nomb<<endl;
    for (list<Medicina_Cantidad>::iterator it = medicina_cantidad.begin(); it!=medicina_cantidad.end();it++)
        it->imprimeMedicina(arch);
    arch<<GetTotalDeGastos()<<endl;
}

void Paciente_Medicina::totalizar(map<int, Medicina> med) {
    for (list<Medicina_Cantidad>::iterator it = medicina_cantidad.begin(); it!=medicina_cantidad.end();it++)
        SetTotalDeGastos(GetTotalDeGastos() + (it->GetCantidad() *med[it->GetCodigo()].GetPrecio()));
}


