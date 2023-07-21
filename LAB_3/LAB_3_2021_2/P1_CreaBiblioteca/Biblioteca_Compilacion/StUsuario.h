/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   StUsuario.h
 * Author: Sebastian
 *
 * Created on 23 de abril de 2023, 23:29
 */

#ifndef STUSUARIO_H
#define STUSUARIO_H
#include "StLibroPrestado.h"

typedef struct St_Usuario{
    int carne;
    char tipo[20];
    char nombre[100];
    struct St_LibroPrestado libPrest[20];
    int numLibPrest;
    char condicion[20];
}T_St_Usuario;

#endif /* STUSUARIO_H */

