/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Falta.h
 * Author: Sebastian
 *
 * Created on 17 de junio de 2023, 14:25
 */

#ifndef FALTA_H
#define FALTA_H

class Falta {
private:
    int fecha;
    char *placa;
public:
    Falta();
    virtual ~Falta();
    void SetPlaca(char *plac);
    void GetPlaca(char *plac) const;
    void SetFecha(int fecha);
    int GetFecha() const;
    
};

#endif /* FALTA_H */

