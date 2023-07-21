/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 27 de abril de 2023, 22:49
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void leerMedicos(struct StMedico *medicos,int &numMedicos);
void leerPacientes(struct StPaciente *pacientes, int &numPacientes);
void leerCitas(struct StMedico *medicos,struct StPaciente *pacientes,const int numPacientes);
void emitirReporte(struct StPaciente *pacientes,const int numPacientes);

#endif /* FUNCIONESAUXILIARES_H */

