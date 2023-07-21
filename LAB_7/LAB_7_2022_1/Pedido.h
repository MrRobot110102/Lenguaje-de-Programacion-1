/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ClasePedido.h
 * Author: Sebastian
 *
 * Created on 31 de mayo de 2023, 22:46
 */

#ifndef CLASEPEDIDO_H
#define CLASEPEDIDO_H


class Pedido {
private:
    int codigo;
    char *nombre;
    int cantidad;
    double precio;
    int dni;
    int fecha;
public:
    Pedido();
    Pedido(const class Pedido &obj);
    virtual ~Pedido();
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetNombre(char* nomb);
    void GetNombre(char* nomb) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void operator = (const Pedido &c);
};

#endif /* CLASEPEDIDO_H */

