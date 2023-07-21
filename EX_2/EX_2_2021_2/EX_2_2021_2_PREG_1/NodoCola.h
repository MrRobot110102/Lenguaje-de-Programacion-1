/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoCola.h
 * Author: Sebastian
 *
 * Created on 30 de junio de 2023, 23:38
 */

#ifndef NODOCOLA_H
#define NODOCOLA_H
#include "ColaSol.h"

class NodoCola {
public:
    NodoCola();
    virtual ~NodoCola();
    void SetCarne(int carne);
    int GetCarne() const;
    void SetLibsol(char *lib);
    void GetLibsol(char *lib) const;
    friend class ColaSol;
private:
    char *libsol;
    int carne;
    class NodoCola *sig;
};

#endif /* NODOCOLA_H */

