/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Prestamo.h
 * Author: Sebastian
 *
 * Created on 10 de junio de 2023, 11:37
 */

#ifndef PRESTAMO_H
#define PRESTAMO_H

class Prestamo {
private:
    int dias;
    int fecha;
public:
    Prestamo();
    virtual ~Prestamo();
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDias(int dias);
    int GetDias() const;
    
};

#endif /* PRESTAMO_H */

