/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Libro.h
 * Author: Sebastian
 *
 * Created on 10 de junio de 2023, 11:37
 */

#ifndef LIBRO_H
#define LIBRO_H

class Libro {
private:
    char *codigo;
    char *titulo;
    char *autor;
    int cantidad;
    double precio;
public:
    Libro();
    virtual ~Libro();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetAutor(char *aut);
    void GetAutor(char *aut) const;
    void SetTitulo(char *tit);
    void GetTitulo(char *tit) const;
    void SetCodigo(char* cod);
    void GetCodigo(char *cod) const;
};

#endif /* LIBRO_H */

