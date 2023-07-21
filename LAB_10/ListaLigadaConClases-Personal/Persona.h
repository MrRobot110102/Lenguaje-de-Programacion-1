/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Persona.h
 * Author: Sebastian
 *
 * Created on 17 de junio de 2023, 20:32
 */

#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

class Persona {
private:
    int dni;
    char *nombre;
    double sueldo;
public:
    Persona();
    Persona(const Persona& orig);
    virtual ~Persona();
    void SetSueldo(double sueldo);
    double GetSueldo() const;
    void SetNombre(char *nomb);
    void GetNombre(char *nomb) const;
    void SetDni(int dni);
    int GetDni() const;
    void operator =(const class Persona &per);
    bool operator >(const class Persona &per);
};

ifstream & operator >>(ifstream &arch,class Persona &per);
ofstream & operator <<(ofstream &arch,const class Persona &per);

#endif /* PERSONA_H */

