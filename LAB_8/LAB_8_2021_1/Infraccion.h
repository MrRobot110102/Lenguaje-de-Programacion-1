/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Infraccion.h
 * Author: Sebastian
 *
 * Created on 11 de junio de 2023, 13:26
 */

#ifndef INFRACCION_H
#define INFRACCION_H

class Infraccion {
private:
    int codigo;
    char *gravedad;
    double multa;
public:
    Infraccion();
    virtual ~Infraccion();
    void SetMulta(double multa);
    double GetMulta() const;
    void SetGravedad(const char *grav);
    void GetGravedad(char *grav) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
};

#endif /* INFRACCION_H */

