/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ACurso.cpp
 * Author: Sebastian
 * 
 * Created on 7 de junio de 2023, 22:50
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ACurso.h"

ACurso::ACurso() {
}

ACurso::~ACurso() {
}

void ACurso::SetOperacion(char operacion) {
    this->operacion = operacion;
}

char ACurso::GetOperacion() const {
    return operacion;
}

void ACurso::SetClcurso(Curso clcurso) {
    this->clcurso = clcurso;
}

void ACurso::GetClcurso(class Curso &curso) const {
    curso = clcurso;
}

void ACurso::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int ACurso::GetCodigo() const {
    return codigo;
}

ifstream & operator >>(ifstream &arch,class ACurso &aCurso){
    int codigo,nota,ciclo,semestre;
    char operacion,codCurso[7],car;
    double credito;
    arch>>codigo;
    if(arch.eof()) return arch;
    arch>>codCurso>>nota>>ciclo>>car>>semestre>>credito>>operacion;
    aCurso.SetCodigo(codigo);
    aCurso.SetOperacion(operacion);
    class Curso auxCurso;
    auxCurso.SetCcurso(codCurso);
    auxCurso.SetCiclo(ciclo * 100 + semestre);
    auxCurso.SetNota(nota);
    auxCurso.SetCredito(credito);
    aCurso.SetClcurso(auxCurso);
    return arch;
}



