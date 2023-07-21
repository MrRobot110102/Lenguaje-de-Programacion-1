/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   StFalta.h
 * Author: Sebastian
 *
 * Created on 21 de abril de 2023, 18:54
 */

#ifndef STFALTA_H
#define STFALTA_H

typedef struct FaltaSt{
    char placa[10];
    int fecha;
    int codInf;
    double multa;
    char gravedad[15];
}TFaltaSt;

#endif /* STFALTA_H */

