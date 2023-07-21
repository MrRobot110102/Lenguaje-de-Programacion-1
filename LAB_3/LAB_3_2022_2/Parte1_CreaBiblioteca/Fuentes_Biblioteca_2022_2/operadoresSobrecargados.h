/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   operadoresSobrecargados.h
 * Author: Sebastian
 *
 * Created on 25 de abril de 2023, 10:20
 */

#ifndef OPERADORESSOBRECARGADOS_H
#define OPERADORESSOBRECARGADOS_H

bool operator >>(ifstream &arch,struct StMedico &medico);
void obtenerEspecialidad(char *nombre,char *especialidad);
bool operator >>(ifstream &arch,struct StPaciente &paciente);
int operator >>(ifstream &arch,struct StCita &cita);
bool operator <=(struct StCita &cita,struct StMedico *medico);
bool operator +=(struct StPaciente &paciente,struct StCita &cita);
bool operator ++(struct StPaciente &paciente);
ofstream & operator <<(ofstream &arch,struct StPaciente &paciente);
void imprimirLinea(char car, int cantidad, ofstream &arch);


#endif /* OPERADORESSOBRECARGADOS_H */

