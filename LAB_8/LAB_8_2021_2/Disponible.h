/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Disponible.h
 * Author: Sebastian
 *
 * Created on 10 de junio de 2023, 11:37
 */

#ifndef DISPONIBLE_H
#define DISPONIBLE_H

class Disponible {
private:
    int zona;
public:
    Disponible();
    virtual ~Disponible();
    void SetZona(int zona);
    int GetZona() const;
};

#endif /* DISPONIBLE_H */

