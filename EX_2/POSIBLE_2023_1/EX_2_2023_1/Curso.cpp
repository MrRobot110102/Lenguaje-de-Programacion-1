/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Curso.cpp
 * Author: Sebastian
 * 
 * Created on 6 de julio de 2023, 23:29
 */

#include <cstring>
#include "Curso.h"

Curso::Curso() {
    codigo = nullptr;
}

Curso::Curso(const Curso& orig) {
    codigo = nullptr;
    *this = orig;
}

Curso::~Curso() {
    if(codigo != nullptr) delete codigo;
}

void Curso::SetNota(int nota) {
    this->nota = nota;
}

int Curso::GetNota() const {
    return nota;
}

void Curso::SetSemestre(int semestre) {
    this->semestre = semestre;
}

int Curso::GetSemestre() const {
    return semestre;
}

void Curso::SetCodigo(char *cod) {
    if(codigo != nullptr) delete codigo;
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo,cod);
}

void Curso::GetCodigo(char *cod) const {
    if(codigo == nullptr) cod[0] = 0;
    else strcpy(cod,codigo);
}

void Curso::operator=(const Curso& cur) {
    char cod[100];
    cur.GetCodigo(cod);
    SetCodigo(cod);
    SetNota(cur.GetNota());
    SetSemestre(cur.GetSemestre());
}

void Curso::imprimirCurso(ofstream& arch) {
    char cod[100];
    GetCodigo(cod);
    arch<<left<<setw(10)<<cod<<setw(10)<<GetSemestre()<<setw(10)<<GetNota()<<endl;
}

bool Curso::operator<(const Curso& cur) {
    char codCurso[100],codCursoComparar[100];
    GetCodigo(codCurso);
    cur.GetCodigo(codCursoComparar);
    //if(strcmp(codCurso,codCursoComparar) != 0) return strcmp(codCurso,codCursoComparar) < 0;
    //else if((strcmp(codCurso,codCursoComparar) == 0) and GetSemestre() < cur.GetSemestre()) return GetSemestre() < cur.GetSemestre();
    if(GetSemestre() < cur.GetSemestre()) return GetSemestre() < cur.GetSemestre();
    else if((GetSemestre() == cur.GetSemestre()) and strcmp(codCurso,codCursoComparar) != 0) return strcmp(codCurso,codCursoComparar) < 0; 
}



