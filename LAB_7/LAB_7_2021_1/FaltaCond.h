/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   FaltaCond.h
 * Author: Sebastian
 *
 * Created on 4 de junio de 2023, 14:46
 */

#ifndef FALTACOND_H
#define FALTACOND_H

class FaltaCond {
private:
    char *placa;
    int fecha;
    int codInf;
    double multa;
    char *gravedad;
public:
    FaltaCond();
    virtual ~FaltaCond();
    void SetGravedad(char* grav);
    void GetGravedad(char *grav) const;
    void SetMulta(double multa);
    double GetMulta() const;
    void SetCodInf(int codInf);
    int GetCodInf() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetPlaca(char* plac);
    void GetPlaca(char *plac) const;
};

#endif /* FALTACOND_H */

