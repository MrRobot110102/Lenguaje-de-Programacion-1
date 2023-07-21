/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NUsuario.cpp
 * Author: Sebastian
 * 
 * Created on 30 de junio de 2023, 23:38
 */
#include "NUsuario.h"
#include "Estudiante.h"
#include "Docente.h"
#include "Administrativo.h"

NUsuario::NUsuario() {
    pusuario = nullptr;
}

NUsuario::NUsuario(const NUsuario& orig) {
    *this = orig;
}

void NUsuario::operator=(const NUsuario& orig) {
    pusuario = orig.pusuario;
}

void NUsuario::leeUsuario(ifstream& arch) {
    int carne;
    arch>>carne;
    if(arch.eof()) return;
    char tipo = arch.get();
    arch.get();
    if(tipo == 'E') pusuario = new class Estudiante;
    else if(tipo == 'D') pusuario = new class Docente;
    else if(tipo == 'A') pusuario = new class Administrativo;
    pusuario->SetCarne(carne);
    pusuario->leer(arch);
}

int NUsuario::getCarne() {
    return pusuario->GetCarne();
}

void NUsuario::imprimeUsuario(ofstream& arch) {
    pusuario->imprime(arch);
}




