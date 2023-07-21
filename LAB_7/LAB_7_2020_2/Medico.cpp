/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Medico.cpp
 * Author: Sebastian
 * 
 * Created on 6 de junio de 2023, 14:09
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Medico.h"
#include "Paciente.h"

Medico::Medico() {
    codigo = nullptr;
    especialidad = nullptr;
    nombre = nullptr;
    numPac = 0;
    ingresosP = 0.0;
    ingresosS = 0.0;
}

Medico::~Medico() {
    if(codigo != nullptr) delete codigo;
    if(especialidad != nullptr) delete especialidad;
    if(nombre != nullptr) delete nombre;
}

void Medico::SetIngresosS(double ingresosS) {
    this->ingresosS = ingresosS;
}

double Medico::GetIngresosS() const {
    return ingresosS;
}

void Medico::SetIngresosP(double ingresosP) {
    this->ingresosP = ingresosP;
}

double Medico::GetIngresosP() const {
    return ingresosP;
}

void Medico::SetNumPac(int numPac) {
    this->numPac = numPac;
}

int Medico::GetNumPac() const {
    return numPac;
}

void Medico::SetTarifa(double tarifa) {
    this->tarifa = tarifa;
}

double Medico::GetTarifa() const {
    return tarifa;
}

void Medico::SetEspecialidad(char* espec) {
    if(especialidad != nullptr) delete especialidad;
    especialidad = new char[strlen(espec) + 1];
    strcpy(especialidad,espec);
}

void Medico::GetEspecialidad(char* espec) const {
    if(especialidad == nullptr) especialidad[0] = 0;
    strcpy(espec,especialidad);
}

void Medico::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre,nomb);
}

void Medico::GetNombre(char* nomb) const {
    if(nombre == nullptr) nombre[0] = 0;
    strcpy(nomb,nombre);
}

void Medico::SetCodigo(char *cod) {
    if(codigo != nullptr) delete codigo;
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo,cod);
}

void Medico::GetCodigo(char *cod) const {
    if(codigo == nullptr) strcpy(cod,"0");
    else strcpy(cod,codigo);
}

ifstream & operator >>(ifstream &arch,class Medico &medico){
    char cod[10], nomb[50], esp[20];
    double tar;
    arch>>cod;
    //cout<<cod<<endl;
    if(arch.eof()) return arch;
    arch>>nomb>>esp>>tar;
    medico.SetCodigo(cod);
    medico.SetNombre(nomb);
    medico.SetEspecialidad(esp);
    medico.SetTarifa(tar);
    return arch;
}

void Medico::operator +(const class Paciente &paciente){
    lpacientes[numPac] = paciente;
    numPac++;
}

void Medico::operator *(int fecha){
    for (int i = 0; i < GetNumPac(); i++)
        if(lpacientes[i].GetFecha() == fecha and lpacientes[i].GetEstado() == 'R')
            lpacientes[i].SetEstado('A');
}

void Medico::operator -(int fecha){
    for (int i = 0; i < GetNumPac(); i++)
        if(lpacientes[i].GetFecha() == fecha and lpacientes[i].GetEstado() == 'R')
            lpacientes[i].SetEstado('E');
}

void Medico::operator ++(int a){
    for (int i = 0; i < GetNumPac(); i++) {
        if(lpacientes[i].GetEstado() == 'A'){
            ingresosP += (lpacientes[i].GetPrima()/100)*tarifa;
            ingresosS += ((100-lpacientes[i].GetPrima())/100)*tarifa;
        }
    }
}

ofstream & operator <<(ofstream &arch,const class Medico &medico){
    arch.precision(2);arch<<fixed;
    char nomb[50],cod[10],esp[20];
    medico.GetNombre(nomb);
    medico.GetCodigo(cod);
    medico.GetEspecialidad(esp);
    arch<<"Medico:  "<<nomb<<endl;
    arch<<"Codigo:  "<<cod<<endl;
    arch<<"Especialidad: "<<esp<<endl;
    arch<<"Honorarios por cita: "<<medico.GetTarifa()<<endl;
    imprimeLinea('=',100,arch);
    arch<<"Pacientes atendidos:"<<endl;
    imprimeLinea('-',100,arch);
    arch<< left <<setw(7)<< "No." << setw(13) << "Fecha"<< setw(15) << "Paciente" << setw(9) << "Pago" << "Seguro" << endl;
    medico.imprimirPacientesAtendidos(arch);
    imprimeLinea('=',100,arch);
    arch<<"Pacientes por atender:"<<endl;
    imprimeLinea('-',100,arch);
    arch<< left <<setw(7)<< "No." << setw(13) << "Fecha"<< setw(15) << "Paciente" << endl;
    medico.imprimirPacientesPorAtender(arch);
    imprimeLinea('=',100,arch);
    arch<<left<<"Monto Total recibido por pacientes: "<<right<<setw(10)<<medico.GetIngresosP()<<endl;
    arch<<left<<"Monto a solicitar al seguro:        "<<right<<setw(10)<<medico.GetIngresosS()<<endl;
}

void Medico::imprimirPacientesAtendidos(ofstream &arch) const{
    int contador = 0;
    for (int i = 0; i < GetNumPac(); i++) 
        if(lpacientes[i].GetEstado() == 'A'){
            arch<<right<<setw(2)<<contador+1<<')'<<left<<"    ";
            arch<<lpacientes[i];
            arch<<right<<setw(10)<<(lpacientes[i].GetPrima()/100)*GetTarifa();
            arch<<right<<setw(10)<<((100 - lpacientes[i].GetPrima())/100)*GetTarifa()<<endl;
            contador++;
        }
}

void Medico::imprimirPacientesPorAtender(ofstream &arch) const{
    int contador = 0;
    for (int i = 0; i < GetNumPac(); i++) 
        if(lpacientes[i].GetEstado() == 'R'){
            arch<<right<<setw(2)<<contador+1<<')'<<left<<"    ";
            arch<<lpacientes[i]<<endl;
            contador++;
        }
}

void imprimeLinea (char car, int num, ofstream &arch) {
    for (int i = 0; i < num; i++) arch.put(car);
    arch << endl;
}

