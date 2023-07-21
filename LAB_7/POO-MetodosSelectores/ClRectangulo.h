/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ClRectangulo.h
 * Author: Sebastian
 *
 * Created on 25 de mayo de 2023, 17:07
 */

#ifndef CLRECTANGULO_H
#define CLRECTANGULO_H

class ClRectangulo {
private:
    char *nombre;
    double base;
    double altura;  
public:
    ClRectangulo(void);  //CONSTRUCTOR POR DEFECTO
    ClRectangulo(const char*, double , double ); //Constructor
    ClRectangulo(const ClRectangulo &); //constructor copia
    ~ClRectangulo(void); //DESTRUCTOR
    void SetAltura(double altura);
    double GetAltura() const;
    void SetBase(double base);
    double GetBase() const;
    void leeDatos(void);
    void imprimeDatos(void);
    double area(void);
    double perimetro(void);
    void imprimeResultados(void);
    void SetNombre(const char* nombre);
    void GetNombre(char *) const;
    void inicializar(void);
    void elimina(void); 
};

#endif /* CLRECTANGULO_H */

