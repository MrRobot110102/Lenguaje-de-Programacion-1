 /*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Libro.h
 * Author: Sebastian
 *
 * Created on 21 de junio de 2023, 20:50
 */

#ifndef LIBRO_H
#define LIBRO_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

class Libro {
private:
    char *codigo;
    char *titulo;
    char *autor;
    int cantidad;
    int anho;
    double precio;
public:
    Libro();
    virtual ~Libro();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetAutor(char *aut);
    void GetAutor(char *aut) const;
    void SetTitulo(char *tit);
    void GetTitulo(char *tit) const;
    void SetCodigo(char *cod);
    void GetCodigo(char *cod) const;
    void AsignaDatos(char *cod,char *tit,char *aut,int aa, int numero,double precio);
    void ObtieneDatos(char *cod,char *tit,char *aut,int &aa, int &numero,double &precio);
    virtual void Actualiza(int dias,int fecha,double precio) = 0;
    virtual void AsignaZona(int zona) = 0;
    virtual void Imprimir(ofstream &arch) = 0;
};

#endif /* LIBRO_H */

