/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Docente.h
 * Author: Sebastian
 *
 * Created on 30 de junio de 2023, 23:37
 */

#ifndef DOCENTE_H
#define DOCENTE_H
#include "Usuario.h"

class Docente : public Usuario{
public:
    void SetAnexo(int anexo);
    int GetAnexo() const;
    void leer(ifstream &arch);
    void imprime(ofstream &arch);
private:
    int anexo;
};

#endif /* DOCENTE_H */

