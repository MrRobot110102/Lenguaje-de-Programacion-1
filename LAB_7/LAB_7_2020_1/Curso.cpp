/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Curso.cpp
 * Author: Sebastian
 * 
 * Created on 7 de junio de 2023, 22:49
 */

#include <cstring>

#include "Curso.h"

Curso::Curso() {
    ccurso = nullptr;
}

Curso::~Curso() {
    if(ccurso != nullptr) delete ccurso;
}

void Curso::SetCredito(double credito) {
    this->credito = credito;
}

double Curso::GetCredito() const {
    return credito;
}

void Curso::SetNota(int nota) {
    this->nota = nota;
}

int Curso::GetNota() const {
    return nota;
}

void Curso::SetCiclo(int ciclo) {
    this->ciclo = ciclo;
}

int Curso::GetCiclo() const {
    return ciclo;
}

void Curso::SetCcurso(char *ccur) {
    if(ccurso != nullptr) delete ccurso;
    ccurso = new char[strlen(ccur) + 1];
    strcpy(ccurso,ccur);
}

void Curso::GetCcurso(char *ccur) const {
    if(ccurso == nullptr) strcpy(ccur,"0");
    else strcpy(ccur,ccurso);
}

void Curso::asignar(const class Curso &curso){
    ciclo = curso.GetCiclo();
    nota = curso.GetNota();
    credito = curso.GetCredito();
    char cadena[50];
    curso.GetCcurso(cadena);
    SetCcurso(cadena);
}

void Curso::operator =(const class Curso &curso){
    asignar(curso);
}

bool Curso::compare(const class Curso &curso){
    char cadenaCurso[50],cadenaComparar[50];
    GetCcurso(cadenaCurso);
    curso.GetCcurso(cadenaComparar);
    if((strcmp(cadenaCurso,cadenaComparar) == 0) and GetCiclo() == curso.GetCiclo()) return true;
    else return false; 
}   

bool Curso::operator ==(const class Curso &curso){
    return compare(curso);
}

