/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   medico.h
 * Author: Sebastian
 *
 * Created on 3 de junio de 2023, 22:21
 */

#ifndef MEDICO_H
#define MEDICO_H

class medico {
private:
    int codigo;
    char *nombre;
    double tarifa;
public:
    medico();
    virtual ~medico();
    void SetTarifa(double tarifa);
    double GetTarifa() const;
    void SetNombre(char* nomb);
    void GetNombre(char *nomb) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
};

#endif /* MEDICO_H */

