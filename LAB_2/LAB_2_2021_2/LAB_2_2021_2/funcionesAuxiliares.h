/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 14 de abril de 2023, 18:58
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void crearLibrosBin();
void mostrarLibrosBin();
void crearUsuariosPrestamosBin();
void mostrarUsuariosBin();
void mostrarPrestamosBin();
int compararCadenas(char *cadena1,char *cadena2);
void actualizarArchLibrosBin();
void leerFecha(int &fechaD,int &fechaE,int &fechaA,ifstream &archFechas);
int asignarRetraso(char tipo,int fecha,int fechaD,int fechaE,int fechaA);
double asignarMulta(char tipo,char *codLib, ifstream &archLibBin);
void actualizarUsuariosBin();


#endif /* FUNCIONESAUXILIARES_H */

