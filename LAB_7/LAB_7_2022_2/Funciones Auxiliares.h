/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Funciones Auxiliares.h
 * Author: Sebastian
 *
 * Created on 4 de junio de 2023, 13:18
 */

#ifndef FUNCIONES_AUXILIARES_H
#define FUNCIONES_AUXILIARES_H

void leerMedicos(class medico *medicos,const char *nombArch);
void leerPacientes(class paciente *pacientes,const char *nombArch);
void agregarCitas(class paciente *pacientes,const char *nombArch);
void actualizarTarifas(class paciente *pacientes,class medico *medicos);
void imprimirMedicos(class medico *medicos,const char *nombArch);
void imprimirPacientes(class paciente *pacientes,const char *nombArch);
int buscarPaciente(class paciente *paciente,int dni);

#endif /* FUNCIONES_AUXILIARES_H */

