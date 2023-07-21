/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NPacientes.h
 * Author: Sebastian
 *
 * Created on 3 de julio de 2023, 19:11
 */

#ifndef NPACIENTES_H
#define NPACIENTES_H

class NPacientes {
public:
    NPacientes();
    NPacientes(const NPacientes& orig);
    void leer(ifstream &arch);
    void operator =(class Paciente *pac);
    void operator =(const NPacientes &pac);
    int estaActivo();
    int getDni();
    bool operator <(const NPacientes &pac);
    void imprimir(ofstream &arch);
    void actualizarCantidades(int &numRiesgo,int &numMenoresEdad);
private:
    class Paciente *ppaciente;
};

#endif /* NPACIENTES_H */

