/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   C.h
 * Author: Sebastian
 *
 * Created on 13 de junio de 2023, 14:13
 */

#ifndef C_H
#define C_H
#include "Ficha.h"


class C : public Ficha{
public:
    void imprime(ofstream &);
    void mover(char, int);
};

#endif /* C_H */

