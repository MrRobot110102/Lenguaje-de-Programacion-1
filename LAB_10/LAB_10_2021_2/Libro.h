/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Libro.h
 * Author: Sebastian
 *
 * Created on 25 de junio de 2023, 19:27
 */

#ifndef LIBRO_H
#define LIBRO_H

class Libro {
private:
    char *codigo;
    char *titulo;
    char *autor;
    int cantidad;
    int stock;
    int anho;
    double precio;
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetAutor(char *aut);
    void GetAutor(char *aut) const;
    void SetTitulo(char *tit);
    void GetTitulo(char *tit) const;
    void SetCodigo(char *cod);
    void GetCodigo(char *cod) const;
    void operator = (const class Libro &libro);
};

ifstream & operator >>(ifstream &arch,class Libro &libro);
ofstream & operator <<(ofstream &arch,const class Libro &libro);

#endif /* LIBRO_H */

