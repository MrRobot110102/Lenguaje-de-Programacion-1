/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vencido.h
 * Author: Sebastian
 *
 * Created on 29 de junio de 2023, 15:23
 */

#ifndef VENCIDO_H
#define VENCIDO_H
#include "medicamento.h"

class vencido : public medicamento{
public:
    vencido();
    virtual ~vencido();
    void SetInspector(const char *inspec);
    void GetInspector(char *inspec) const;
    void SetFechabaja(int fechabaja);
    int GetFechabaja() const;
    void lee(ifstream &arch,const char *inspec,int fechBaja);
    void imprime(ofstream &arch);
    void actualiza(int fechBaja, const char *inspec,int codigo, char *nomb, int stock, int fechavenc);
private:
    int fechabaja;
    char *inspector;
};

#endif /* VENCIDO_H */

