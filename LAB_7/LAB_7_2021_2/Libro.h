/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Libro.h
 * Author: Sebastian
 *
 * Created on 5 de junio de 2023, 18:22
 */

#ifndef LIBRO_H
#define LIBRO_H

class Libro {
private:
    char *codigo;
    char *titulo;
    char *autor;
    int stock;
    double precio;
    int prestados;
    int cantEst;
    int cantDoc;
    int cantAdm;
public:
    Libro();
    virtual ~Libro();
    void SetCantAdm(int cantAdm);
    int GetCantAdm() const;
    void SetCantDoc(int cantDoc);
    int GetCantDoc() const;
    void SetCantEst(int cantEst);
    int GetCantEst() const;
    void SetPrestados(int prestados);
    int GetPrestados() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetAutor(char* aut);
    void GetAutor(char *aut) const;
    void SetTitulo(char* tit);
    void GetTitulo(char* tit) const;
    void SetCodigo(char* cod);
    void GetCodigo(char* cod) const;
    void operator +=(const class LibroPrestado &libPrestado);
};

#endif /* LIBRO_H */

