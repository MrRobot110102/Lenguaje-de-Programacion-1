/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   activo.h
 * Author: Sebastian
 *
 * Created on 29 de junio de 2023, 15:22
 */

#ifndef ACTIVO_H
#define ACTIVO_H
#include "medicamento.h"


class activo : public medicamento{
public:
    activo();
    virtual ~activo();
    void SetVendedor(char *vend);
    void GetVendedor(char *vend) const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void lee(ifstream &arch,const char *inspec,int fechBaja);
    void imprime(ofstream &arch);
    void actualiza(int fechBaja, const char *inspec,int codigo, char *nomb, int stock, int fechavenc);
private:
    double precio;
    char *vendedor;
};

#endif /* ACTIVO_H */

