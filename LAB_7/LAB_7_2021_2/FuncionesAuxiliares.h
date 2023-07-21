/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 6 de junio de 2023, 0:07
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void leerUsuarios(class Usuario *usuarios,const char *nombArch);
void leerLibros(class Libro *libros,const char *nombArch);    
void agregarLibrosPrestados(class Usuario *usuarios,class Libro *libros,const char *nombArch);
void determinarDeudas(class Usuario *usuarios,int fecha);
void imprimirUsuarios(class Usuario *usuarios,const char *nombArch);
void imprimirLibros(class Libro *libros,const char *nombArch);
int buscarUsuario(class Usuario *usuarios,int carne,char tipo);
int buscarLibro(class Libro *libros,char *cod);

#endif /* FUNCIONESAUXILIARES_H */

