/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   medicamento.h
 * Author: Sebastian
 *
 * Created on 25 de junio de 2023, 11:53
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
    int stock;
    double precio;
public:
    medicamento();
    medicamento(const medicamento& orig);
    virtual ~medicamento();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetNombre(char *nomb);
    void GetNombre(char *nomb) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
    virtual void actualiza() = 0;
};

#endif /* MEDICAMENTO_H */

