/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Conductor.h
 * Author: Sebastian
 *
 * Created on 17 de junio de 2023, 14:25
 */

#ifndef CONDUCTOR_H
#define CONDUCTOR_H

class Conductor {
private:
    int licencia;
    char *nombre;
public:
    Conductor();
    virtual ~Conductor();
    void SetNombre(char *nomb);
    void GetNombre(char *nomb) const;
    void SetLicencia(int licencia);
    int GetLicencia() const;
    
};

#endif /* CONDUCTOR_H */

