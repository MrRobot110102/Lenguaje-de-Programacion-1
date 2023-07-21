/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ClaseCliente.h
 * Author: Sebastian
 *
 * Created on 31 de mayo de 2023, 22:45
 */

#ifndef CLASECLIENTE_H
#define CLASECLIENTE_H
#include "Pedido.h"
#include <fstream>
using namespace std;

class Cliente {
private:
    int dni;
    char categoria;
    char *nombre;
    class Pedido lped[100];
    int numped;
    double total;
public:
    Cliente();
    virtual ~Cliente();
    void SetTotal(double total);
    double GetTotal() const;
    void SetNumped(int numped);
    int GetNumped() const;
    void SetNombre(char* nomb);
    void GetNombre(char *nomb) const;
    void SetCategoria(char categoria);
    char GetCategoria() const;
    void SetDni(int dni);
    int GetDni() const;
    void imprimeLinea(ofstream &arch,int cantidad, char car) const;
    void imprimeProductos(ofstream &arch) const;
    void operator =(const class Pedido &ped);
    void operator -=(const class Pedido &ped);
    void operator /(double descuento);
};

#endif /* CLASECLIENTE_H */

