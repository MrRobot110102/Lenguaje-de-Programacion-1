/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 7 de abril de 2023, 15:30
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void crearArchConductoresBin();
void crearArchFaltasCometidasBin();
void mostrarConductoresBin();
void convertirFecha(int ,int &,int &,int &);
void mostrarFaltasCometidasBin();
void crearArchListadoInfracciones();
void mostrarListadoInfracciones();
int obtenerMonto(int ,fstream &);
void actualizarRegistro(int &,int &,int &,double &,double &,double &,double &,
                        fstream &,char *,int ,double ,int );
void actualizarConductores(int , char *,double ,fstream &);
void actualizarArchivos();
#endif /* FUNCIONESAUXILIARES_H */

