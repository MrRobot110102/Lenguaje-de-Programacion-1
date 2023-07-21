/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Producto.h
 * Author: Sebastian
 *
 * Created on 9 de junio de 2023, 19:15
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

class Producto {
private:
    int codprod;
    char *nombre;
    double precio;
    int stock;
public:
    Producto();
    virtual ~Producto();
    void SetStock(int stock);
    int GetStock() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetNombre(char* nomb);
    void GetNombre(char *nomb) const;
    void SetCodprod(int codprod);
    int GetCodprod() const;
    
};

#endif /* PRODUCTO_H */

