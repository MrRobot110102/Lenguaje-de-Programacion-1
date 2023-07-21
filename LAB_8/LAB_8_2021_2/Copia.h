/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Copia.h
 * Author: Sebastian
 *
 * Created on 10 de junio de 2023, 11:37
 */

#ifndef COPIA_H
#define COPIA_H
#include "Libro.h"
#include "Disponible.h"
#include "Prestamo.h"
#include "Perdida.h"

class Copia : public Libro{
private:
    int numero;
    char *estado;
    class Disponible Odisponible;
    class Prestamo Oprestamo;
    class Perdida Operdida;
public:
    Copia();
    virtual ~Copia();
    void SetEstado(const char *est);
    void GetEstado(char *est) const;
    void SetNumero(int numero);
    int GetNumero() const;
    void SetDisponible(int zona);
    void SetPrestamo(int dias,int fecha);
    void SetPerdida(double precio);
    void imprimeDisponible(ofstream &arch);
    void imprimePrestamo(ofstream &arch);
    void imprimePerdida(ofstream &arch);
};

#endif /* COPIA_H */

