/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   MovimientosEnTablero.h
 * Author: Sebastian
 *
 * Created on 13 de junio de 2023, 14:43
 */

#ifndef MOVIMIENTOSENTABLERO_H
#define MOVIMIENTOSENTABLERO_H
#include "Tablero.h"

class MovimientosEnTablero {
private:
    class Tablero tablero;
public:
    void cargar_Y_MoverFichas(const char*, const char*,const char*);
};

#endif /* MOVIMIENTOSENTABLERO_H */

