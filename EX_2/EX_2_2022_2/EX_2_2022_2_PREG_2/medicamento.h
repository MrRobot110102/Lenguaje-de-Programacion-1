/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   medicamento.h
 * Author: Sebastian
 *
 * Created on 29 de junio de 2023, 15:22
 */

#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class medicamento {
public:
    medicamento();
    medicamento(const medicamento& orig);
    void operator = (const medicamento &med);
    virtual ~medicamento();
    void SetEstado(int estado);
    int GetEstado() const;
    void SetFechavenc(int fechavenc);
    int GetFechavenc() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetNombre(char *nomb);
    void GetNombre(char *nomb) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void lee(ifstream &arch,const char *inspec,int fechBaja);
    virtual void imprime(ofstream &arch);
    void GetDatos(int &codigo, char *nomb,int &stock,int &fechavenc);
    void SetDatos(int codigo, char *nomb, int stock, int fechavenc);
    virtual void actualiza(int fechBaja, const char *inspec,int codigo, char *nomb, int stock, int fechavenc) = 0;
private:
    int codigo;
    char *nombre;
    int stock;
    int fechavenc;
    int estado;
};

#endif /* MEDICAMENTO_H */

