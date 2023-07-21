/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   LibroPrestado.h
 * Author: Sebastian
 *
 * Created on 5 de junio de 2023, 18:22
 */

#ifndef LIBROPRESTADO_H
#define LIBROPRESTADO_H

class LibroPrestado {
private:
    int carne;
    char tipo;
    char *codigoLib;
    int fechaDeRetiro;
    int deuda;
public:
    LibroPrestado();
    virtual ~LibroPrestado();
    void SetDeuda(int deuda);
    int GetDeuda() const;
    void SetFechaDeRetiro(int fechaDeRetiro);
    int GetFechaDeRetiro() const;
    void SetCodigoLib(char *codLib);
    void GetCodigoLib(char *codLib) const;
    void SetTipo(char tipo);
    char GetTipo() const;
    void SetCarne(int carne);
    int GetCarne() const;
    void operator = (const class LibroPrestado &libPrestado);
    
};

#endif /* LIBROPRESTADO_H */

