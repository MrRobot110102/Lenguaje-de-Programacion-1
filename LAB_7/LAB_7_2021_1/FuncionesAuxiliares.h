/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 5 de junio de 2023, 18:01
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void leerConductores(class Conductor *conductores,const char *nombArch);
void leerFaltasCometidas(class Conductor *conductores,const char *nombArch);
void leerYAsignarInfracciones(class Conductor *conductores,const char *nombArch);
void calcularMontoTotal(class Conductor *conductores);
void imprimirConductor(class Conductor *conductores,const char *nombArch);
void aplicarAmnistia(class Conductor *conductores,int fecha);

#endif /* FUNCIONESAUXILIARES_H */

