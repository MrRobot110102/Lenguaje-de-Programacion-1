/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcionesAuxliares.h
 * Author: Sebastian
 *
 * Created on 26 de marzo de 2023, 16:52
 */

#ifndef FUNCIONESAUXLIARES_H
#define FUNCIONESAUXLIARES_H

using namespace std;

void leerImprimirEspecialidadesFechaVenc(char *especialidad1,char *especialidad2,
                                 int &ddven,int &mmven,int &aaven);
int cantidadLetras(char *palabra);
void obtenerEspecialidad(char *palabra, char *especialidad,int cantidad);
void imprimirLinea(char car, int cantidad);
void leerMedico(char *codigo, char *dato,char *especialidad1,char *especialidad2,int ddven,int mmven,int aaven);
void procesarPacientes(char *especialidad, char *especialidad1, char *especialidad2, int ddven, int mmven, int aaven, int cantEsp1, int cantEsp2);
int cmpEsp(char *especialidad1, char *especialidad2, char *especialidad, int cantEsp1, int cantEsp2);
int convertirFecha(int dd, int mm, int aa);

#endif /* FUNCIONESAUXLIARES_H */

