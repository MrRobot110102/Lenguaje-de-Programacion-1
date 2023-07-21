/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   NFalta.h
 * Author: Sebastian
 *
 * Created on 26 de junio de 2023, 16:09
 */

#ifndef NFALTA_H
#define NFALTA_H
#include "Infraccion.h"
#include "Falta.h"
#include "LFalta.h"

class NFalta {
private:
    class Infraccion *pfalta;
    class Falta dfalta;
    class NFalta *sig;
public:
    NFalta();
    virtual ~NFalta();
    friend class LFalta;
};

#endif /* NFALTA_H */

