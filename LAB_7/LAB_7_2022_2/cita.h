/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   cita.h
 * Author: Sebastian
 *
 * Created on 3 de junio de 2023, 22:21
 */

#ifndef CITA_H
#define CITA_H
#include "medico.h"

class cita {
private:
    int dni;
    int codigo;
    int fecha;
    double tarifa;
public:
    cita();
    virtual ~cita();
    void SetTarifa(double tarifa);
    double GetTarifa() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void SetDni(int dni);
    int GetDni() const;
    void operator =(const class cita &cit);
    void operator <=(const class medico *arrMedicos);
};

#endif /* CITA_H */

