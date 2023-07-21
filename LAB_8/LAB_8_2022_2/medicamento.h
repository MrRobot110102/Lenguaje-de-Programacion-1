/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   medicamento.h
 * Author: Sebastian
 *
 * Created on 9 de junio de 2023, 21:45
 */

#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H

class medicamento {
private:
    int codigo;
    char *nombre;
    int cantidad;
    double precio;
    int fecha;
public:
    medicamento();
    virtual ~medicamento();
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetNombre(char *nomb);
    void GetNombre(char *nomb) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
};

#endif /* MEDICAMENTO_H */

