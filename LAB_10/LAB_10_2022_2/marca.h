/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   marca.h
 * Author: Sebastian
 *
 * Created on 25 de junio de 2023, 11:53
 */

#ifndef MARCA_H
#define MARCA_H
#include "medicamento.h"

class marca : public medicamento{
private:
    int lote;
    char *laboratorio;
public:
    marca();
    virtual ~marca();
    void SetLaboratorio(char *lab);
    void GetLaboratorio(char *lab) const;
    void SetLote(int lote);
    int GetLote() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void actualiza();
};

#endif /* MARCA_H */

