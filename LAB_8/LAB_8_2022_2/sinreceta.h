/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   sinreceta.h
 * Author: Sebastian
 *
 * Created on 9 de junio de 2023, 21:46
 */

#ifndef SINRECETA_H
#define SINRECETA_H
#include "medicamento.h"


class sinreceta : public medicamento{
private:
    int dni;
    char *nombre;
public:
    sinreceta();
    virtual ~sinreceta();
    void SetNombre(char* nomb);
    void GetNombre(char *nomb) const;
    void SetDni(int dni);
    int GetDni() const;
    
};

#endif /* SINRECETA_H */

