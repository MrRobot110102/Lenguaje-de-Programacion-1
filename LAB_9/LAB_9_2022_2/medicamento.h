/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   medicamento.h
 * Author: Sebastian
 *
 * Created on 16 de junio de 2023, 21:50
 */

#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

class medicamento {
private:
    int codigo;
    char *nombre;
    int cantidad;
    double precio;
    int fecha;
    double total;
public:
    medicamento();
    virtual ~medicamento();
    void SetTotal(double total);
    double GetTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetNombre(char* nomb);
    void GetNombre(char *nomb) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void leemedicamento(ifstream &arch,int codMed);
    virtual void imprimedicamento(ofstream &arch);
    virtual void aplicadescuento();
    int buscarMedicamento(int codMed,char *nombMedicamento,double &precio);
};

#endif /* MEDICAMENTO_H */

