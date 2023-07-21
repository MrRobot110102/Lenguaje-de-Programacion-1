/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Cliente.h
 * Author: Sebastian
 *
 * Created on 13 de junio de 2023, 17:51
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include <fstream>
using namespace std;

class Cliente {
private:
    int dni;
    char categoria;
    char *nombre;
    int cantped;
    double totalped;
public:
    Cliente();
    virtual ~Cliente();
    void SetTotalped(double totalped);
    double GetTotalped() const;
    void SetCantped(int cantped);
    int GetCantped() const;
    void SetNombre(char* nomb);
    void GetNombre(char *nomb) const;
    void SetCategoria(char categoria);
    char GetCategoria() const;
    void SetDni(int dni);
    int GetDni() const;
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
    virtual void calcula() = 0;
    void imprimeLinea(ofstream &arch,int cantidad,char car);
};

#endif /* CLIENTE_H */

