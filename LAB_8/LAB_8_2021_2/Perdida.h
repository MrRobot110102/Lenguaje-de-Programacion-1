/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Perdida.h
 * Author: Sebastian
 *
 * Created on 10 de junio de 2023, 11:37
 */

#ifndef PERDIDA_H
#define PERDIDA_H

class Perdida {
private:
    double precio;
public:
    Perdida();
    virtual ~Perdida();
    void SetPrecio(double precio);
    double GetPrecio() const;
};

#endif /* PERDIDA_H */

