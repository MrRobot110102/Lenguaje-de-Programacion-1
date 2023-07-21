/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Pedido.h
 * Author: Sebastian
 *
 * Created on 13 de junio de 2023, 18:08
 */

#ifndef PEDIDO_H
#define PEDIDO_H

class Pedido {
private:
    int codigo;
    int cantidad;
    int dni;
    int fecha;
    double total;
public:
    Pedido();
    virtual ~Pedido();
    void SetTotal(double total);
    double GetTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
};

#endif /* PEDIDO_H */

