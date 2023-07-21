/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.cpp
 * Author: Sebastian
 * 
 * Created on 6 de julio de 2023, 23:26
 */

#include "Nodo.h"

Nodo::Nodo() {
    sig = nullptr;
}   

void Nodo::eliminaCurso(const char* nombCurso) {
    char nomb[100];
    for (int i = 0; i < vCursos.size(); i++) {
        vCursos[i].GetCodigo(nomb);
        if(strcmp(nomb,nombCurso) == 0) {
            vCursos.erase(vCursos.begin()+i);
            i--;
        };
    }
}

void Nodo::eliminaRango(int semestre) {
    int cantCursos=0,primero=0,posPrimero;
    for (int i = 0; i < vCursos.size(); i++){
        if(vCursos[i].GetSemestre() == semestre and primero == 0){
            posPrimero = i;
            cantCursos++;
            primero++;
        }else if(vCursos[i].GetSemestre() == semestre and primero != 0) cantCursos++;
    }
    if(cantCursos == 1) vCursos.erase(vCursos.begin()+posPrimero);
    else if(cantCursos > 1) 
        vCursos.erase(vCursos.begin()+posPrimero,vCursos.begin()+posPrimero+cantCursos);
}




