/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Renovacion.cpp
 * Author: Sebastian
 * 
 * Created on 1 de julio de 2023, 13:28
 */

#include "Renovacion.h"

Renovacion::Renovacion() {
    exmedico = 0;
    multa = 0;
    tramite = 0;
}

Renovacion::Renovacion(const Renovacion& orig) {
    *this = orig;
}

void Renovacion::SetExmedico(double exmedico) {
    this->exmedico = exmedico;
}

double Renovacion::GetExmedico() const {
    return exmedico;
}

void Renovacion::SetTramite(double tramite) {
    this->tramite = tramite;
}

double Renovacion::GetTramite() const {
    return tramite;
}

void Renovacion::SetMulta(double multa) {
    this->multa = multa;
}

double Renovacion::GetMulta() const {
    return multa;
}

void Renovacion::operator=(const class Renovacion& renova) {
    SetExmedico(renova.GetExmedico());
    SetMulta(renova.GetMulta());
    SetTramite(renova.GetTramite());
}




