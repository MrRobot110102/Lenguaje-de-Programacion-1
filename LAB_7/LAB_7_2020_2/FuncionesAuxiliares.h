/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 6 de junio de 2023, 16:04
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

int buscarMedico(class Medico *medicos,char *cod);
void leerMedicos(class Medico *medico,const char *nombArch);
void leerYAgregarPacientes(class Medico *medico,const char *nombArch);
void imprimirMedicos(class Medico *medico,const char *nombArch);

#endif /* FUNCIONESAUXILIARES_H */

