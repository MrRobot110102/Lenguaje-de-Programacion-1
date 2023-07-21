/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   operadoresSobrecargados.h
 * Author: Sebastian
 *
 * Created on 23 de abril de 2023, 23:28
 */

#ifndef OPERADORESSOBRECARGADOS_H
#define OPERADORESSOBRECARGADOS_H

bool operator >>(ifstream &arch,T_St_Libro &libro);
bool operator >>(ifstream &arch,T_St_Usuario &usuario);
void operator +=(T_St_Usuario &usuario,const T_St_LibroPrestado &libPrestamo);
void operator +=(T_St_Libro &libro,const T_St_UsuarioPrestamo &usuPrestamo);
void operator <=(T_St_Usuario &usuario,const int fecha);
void operator <=(T_St_Libro &libro,const int fecha);
ofstream & operator<<(ofstream &arch,const T_St_Usuario &usuario);
ofstream & operator <<(ofstream &arch,const T_St_Libro &libro);
void imprimirLinea(char car, int cantidad, ofstream &arch);

#endif /* OPERADORESSOBRECARGADOS_H */

