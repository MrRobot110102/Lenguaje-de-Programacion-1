/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   almacen.h
 * Author: Sebastian
 *
 * Created on 29 de junio de 2023, 15:23
 */

#ifndef ALMACEN_H
#define ALMACEN_H
#include "Arbol.h"

class almacen {
public:
    void carga(int fecha,const char *nombProfesor);
    void actualiza(int fecha, const char *apellido);
    void imprime();
private:
    class Arbol arbolalma;
};

#endif /* ALMACEN_H */

