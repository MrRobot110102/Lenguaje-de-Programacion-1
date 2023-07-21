/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   B.h
 * Author: Sebastian
 *
 * Created on 13 de junio de 2023, 14:07
 */

#ifndef B_H
#define B_H
#include "Ficha.h"


class B : public Ficha{
public:
    void imprime(ofstream &);
    void mover(char, int);
};

#endif /* B_H */

