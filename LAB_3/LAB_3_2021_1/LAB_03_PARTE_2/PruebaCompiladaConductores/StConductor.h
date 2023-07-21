/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   StConductor.h
 * Author: Sebastian
 *
 * Created on 21 de abril de 2023, 18:54
 */

#ifndef STCONDUCTOR_H
#define STCONDUCTOR_H
#include "StFalta.h"

typedef struct ConductorSt{
    int licencia;
    char nombre[50];
    struct FaltaSt faltas[20];
    int numFaltas;
    int numFaltasLeves;
    int numFaltasGraves;
    int numFaltasMuyGraves;
    double montoFaltasLeves;
    double montoFaltasGraves;
    double montoFaltasMuyGraves;
}TconductorSt;


#endif /* STCONDUCTOR_H */

