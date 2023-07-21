/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   cita.cpp
 * Author: Sebastian
 * 
 * Created on 3 de junio de 2023, 22:21
 */

#include "cita.h"
#include "medico.h"

cita::cita() {
    dni = 0;
    tarifa = 0;
}
cita::~cita() {
}

void cita::SetTarifa(double tarifa) {
    this->tarifa = tarifa;
}

double cita::GetTarifa() const {
    return tarifa;
}

void cita::SetFecha(int fecha) {
    this->fecha = fecha;
}

int cita::GetFecha() const {
    return fecha;
}

void cita::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int cita::GetCodigo() const {
    return codigo;
}

void cita::SetDni(int dni) {
    this->dni = dni;
}

int cita::GetDni() const {
    return dni;
}

void cita::operator = (const class cita &cit){
    codigo = cit.GetCodigo();
    dni = cit.GetDni();
    fecha = cit.GetFecha();
    tarifa = cit.GetTarifa();
}

void cita::operator <=(const class medico *arrMedicos){
    for (int i = 0; arrMedicos[i].GetCodigo(); i++) 
        if(arrMedicos[i].GetCodigo() == GetCodigo()) SetTarifa(arrMedicos[i].GetTarifa());
}

