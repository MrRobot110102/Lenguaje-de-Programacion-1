/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   conreceta.h
 * Author: Sebastian
 *
 * Created on 9 de junio de 2023, 21:46
 */

#ifndef CONRECETA_H
#define CONRECETA_H
#include "medicamento.h"


class conreceta : public medicamento{
private:
    int codmed;
    char *especialidad;
public:
    conreceta();
    virtual ~conreceta();
    void SetEspecialidad(char *espec);
    void GetEspecialidad(char *espec) const;
    void SetCodmed(int codmed);
    int GetCodmed() const;
    
};

#endif /* CONRECETA_H */

