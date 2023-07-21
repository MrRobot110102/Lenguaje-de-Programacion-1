/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   almacen.h
 * Author: Sebastian
 *
 * Created on 25 de junio de 2023, 11:53
 */

#ifndef ALMACEN_H
#define ALMACEN_H
#include "Arbol.h"

class almacen {
private:
    class Arbol arbolalma;
public:
    void carga();
    void actualiza();
    void imprime();
};

#endif /* ALMACEN_H */

