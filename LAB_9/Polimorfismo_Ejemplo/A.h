/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   A.h
 * Author: Sebastian
 *
 * Created on 13 de junio de 2023, 13:55
 */

#ifndef A_H
#define A_H
#include "Ficha.h"


class A : public Ficha{
public:
    void imprime(ofstream &);
    void mover(char, int);
};

#endif /* A_H */

