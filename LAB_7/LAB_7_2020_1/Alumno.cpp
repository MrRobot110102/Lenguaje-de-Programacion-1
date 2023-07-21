/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Alumno.cpp
 * Author: Sebastian
 * 
 * Created on 7 de junio de 2023, 22:50
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Alumno.h"
#include "FuncionesAuxiliares.h"

Alumno::Alumno() {
    codigo = 0;
    nombre = nullptr;
    numcur = 0;
}

Alumno::~Alumno() {
    if(nombre != nullptr) delete nombre;
}

void Alumno::SetNumcur(int numcur) {
    this->numcur = numcur;
}

int Alumno::GetNumcur() const {
    return numcur;
}

void Alumno::SetNombre(char *nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre,nomb);
}

void Alumno::GetNombre(char *nomb) const {
    if(nombre == nullptr) nombre[0] = 0;
    strcpy(nomb,nombre);
}

void Alumno::SetTipo(char tipo) {
    this->tipo = tipo;
}

char Alumno::GetTipo() const {
    return tipo;
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

void Alumno::operator +(const class ACurso &aCurso){
    Curso auxCurso;
    aCurso.GetClcurso(auxCurso);
    lcurso[numcur] = auxCurso;
    numcur++;
}

void Alumno::operator *(const class ACurso &aCurso){
    Curso auxCurso;
    for (int i = 0; i < GetNumcur(); i++){
        aCurso.GetClcurso(auxCurso);
        if(lcurso[i] == auxCurso){
            lcurso[i] = auxCurso;
            return;
        }
    }    
}

void Alumno::operator -(const class ACurso &aCurso){
    Curso auxCurso;
    for (int i = 0; i < GetNumcur(); i++){
        aCurso.GetClcurso(auxCurso);
        if(lcurso[i] == auxCurso){
            for (int k = i+1; k < GetNumcur(); k++) lcurso[k-1] = lcurso[k];
            numcur--;
            return;
        }
    }
}

double Alumno::operator /(int ciclo) const{
    int numCursos = 0;
    double suma = 0.0;
    for (int i = 0; i < GetNumcur(); i++){
        if(lcurso[i].GetCiclo() == ciclo){
            suma += lcurso[i].GetNota();
            numCursos++;
        }
    }
    return suma/numCursos;
}

double Alumno::operator --() const{
    double cred = 0.0;
    for (int i = 0; i < GetNumcur(); i++) cred += lcurso[i].GetCredito();
    return cred;
}
    
double Alumno::operator ++() const{
    double cred = 0.0;
    for (int i = 0; i < GetNumcur(); i++)
        if(lcurso[i].GetNota()>=11) cred += lcurso[i].GetCredito();
    return cred;
}

void Alumno::obtenerCurso(int i,class Curso &curso) const{
    curso = lcurso[i];
}

ifstream & operator >>(ifstream &arch,class Alumno &alumno){
    char tipo,nomb[100],espec[100],facultad[4];
    int codigo;
    arch>>tipo;
    if(arch.eof()) return arch;
    arch>>codigo>>nomb>>espec>>facultad;
    alumno.SetTipo(tipo);
    alumno.SetCodigo(codigo);
    alumno.SetNombre(nomb);
    return arch;
}

ofstream & operator <<(ofstream &arch,const class Alumno &alumno){
    arch.precision(2);arch<<fixed;
    char nomb[50];
    alumno.GetNombre(nomb);
    arch<<left<<"Nombre: "<<nomb<<endl;
    arch<<"Codigo: "<<alumno.GetCodigo()<<endl;
    imprimirLinea(arch,'=',100);
    arch<<right<<setw(15)<<"CICLO"<<setw(20)<<"PROMEDIO"<<endl;
    int semestre,ciclo,pos,numCursos=0;
    int cursos[alumno.GetNumcur()]{};
    Curso auxCurso;
    for (int i = 0; i < alumno.GetNumcur(); i++) {
        alumno.obtenerCurso(i,auxCurso);
        pos = buscarCurso(auxCurso.GetCiclo(),cursos);
        if(pos == -1){
            cursos[numCursos] = auxCurso.GetCiclo();
            numCursos++;
            ciclo = (auxCurso.GetCiclo())/100;
            semestre = (auxCurso.GetCiclo())%100;
            arch<<right<<setw(2)<<numCursos<<')'<<setw(10)<<ciclo<<'-'<<semestre<<setw(10)<<(alumno/auxCurso.GetCiclo())<<endl;
        }
    }
    arch<<left<<"Creditos Cursados:  "<<--alumno<<endl;
    arch<<left<<"Creditos Aprobados: "<<++alumno<<endl;
}

void imprimirLinea(ofstream &arch, char car, int cantidad){
    for (int i = 0; i < cantidad; i++) arch<<car;
    arch<<endl;
}



