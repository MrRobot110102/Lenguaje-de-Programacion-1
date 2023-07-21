/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   StLibro.h
 * Author: Sebastian
 *
 * Created on 23 de abril de 2023, 23:29
 */

#ifndef STLIBRO_H
#define STLIBRO_H
#include "StUsuarioPrestamo.h"

typedef struct St_Libro{
    char codigo[15];
    char titulo[100];
    int stock;
    double precio;
    int prestados;
    struct St_UsuarioPrestamo estudiantes[20];
    struct St_UsuarioPrestamo docentes[20];
    struct St_UsuarioPrestamo administrativos[20];
    int cantEst;
    int cantDoc;
    int cantAdm;
} T_St_Libro;

#endif /* STLIBRO_H */

