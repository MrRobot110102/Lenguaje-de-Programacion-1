/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Biblioteca.h
 * Author: Sebastian
 *
 * Created on 25 de junio de 2023, 19:27
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "ALibro.h"

class Biblioteca {
private:
    class ALibro AStock;
public:
    void LeeLibros();
    void ActualizaLibros();
    void ImprimeLibros();
};

#endif /* BIBLIOTECA_H */

