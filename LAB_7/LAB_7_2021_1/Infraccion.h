/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Infraccion.h
 * Author: Sebastian
 *
 * Created on 4 de junio de 2023, 14:46
 */

#ifndef INFRACCION_H
#define INFRACCION_H

class Infraccion {
private:
    int codigo;
    char *descripcion;
    char *gravedad;
    double multa;
public:
    Infraccion();
    virtual ~Infraccion();
    void SetMulta(double multa);
    double GetMulta() const;
    void SetGravedad(char* grav);
    void GetGravedad(char *grav) const;
    void SetDescripcion(char* desc);
    void GetDescripcion(char *desc) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
};

#endif /* INFRACCION_H */

