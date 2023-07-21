/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Falta.h
 * Author: Sebastian
 *
 * Created on 4 de junio de 2023, 14:46
 */

#ifndef FALTA_H
#define FALTA_H

class Falta {
private:
    int licencia;
    char *placa;
    int codInf;
    int fecha;
public:
    Falta();
    virtual ~Falta();
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetCodInf(int codInf);
    int GetCodInf() const;
    void SetPlaca(char* plac);
    void GetPlaca(char *plac) const;
    void SetLicencia(int licencia);
    int GetLicencia() const;
    
};

#endif /* FALTA_H */

