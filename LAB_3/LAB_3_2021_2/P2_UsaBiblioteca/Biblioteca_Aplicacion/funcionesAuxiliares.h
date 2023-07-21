/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 24 de abril de 2023, 23:11
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void leerUsuarios(T_St_Usuario *usuarios,int &numUsuarios);
void leerLibros(T_St_Libro *libros,int &numLibros);
void leerPrestamos(T_St_Usuario *usuarios,T_St_Libro *libros,
                   const int numUsuarios,const int numLibros);
void determinarDeudas(T_St_Usuario *usuarios,T_St_Libro *libros,
                      const int numUsuarios,const int numLibros);
void emitirReporte(T_St_Usuario *usuarios,T_St_Libro *libros,
                   const int numUsuarios,const int numLibros);

#endif /* FUNCIONESAUXILIARES_H */

