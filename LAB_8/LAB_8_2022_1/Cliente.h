/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Cliente.h
 * Author: Sebastian
 *
 * Created on 9 de junio de 2023, 19:15
 */

#ifndef CLIENTE_H
#define CLIENTE_H

class Cliente {
private:
    int dni;
    char categoria;
    char *nombre;
public:
    Cliente();
    virtual ~Cliente();
    void SetNombre(char *nomb);
    void GetNombre(char *nomb) const;
    void SetCategoria(char categoria);
    char GetCategoria() const;
    void SetDni(int dni);
    int GetDni() const;
    
};

#endif /* CLIENTE_H */

