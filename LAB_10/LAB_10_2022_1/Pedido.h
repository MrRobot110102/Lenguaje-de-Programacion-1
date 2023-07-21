/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Pedido.h
 * Author: Sebastian
 *
 * Created on 23 de junio de 2023, 22:01
 */

#ifndef PEDIDO_H
#define PEDIDO_H

class Pedido {
private:
    int codigo;
    char *nombre;
    int cantidad;
    int dni;
    int fecha;
    double total;
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetTotal(double total);
    double GetTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetNombre(char *nomb);
    void GetNombre(char *nomb) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
    virtual void exonerarFlete() = 0;
};

#endif /* PEDIDO_H */

