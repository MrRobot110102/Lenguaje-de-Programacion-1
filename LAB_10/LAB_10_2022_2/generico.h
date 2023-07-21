/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   generico.h
 * Author: Sebastian
 *
 * Created on 25 de junio de 2023, 11:53
 */

#ifndef GENERICO_H
#define GENERICO_H
#include "medicamento.h"


class generico : public medicamento{
private:
    char *pais;
public:
    generico();
    virtual ~generico();
    void SetPais(char *pa);
    void GetPais(char *pa) const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void actualiza();
};

#endif /* GENERICO_H */

