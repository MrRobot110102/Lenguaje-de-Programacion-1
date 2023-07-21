/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   medico.h
 * Author: Sebastian
 *
 * Created on 9 de junio de 2023, 21:45
 */

#ifndef MEDICO_H
#define MEDICO_H

class medico {
private:
    int codigo;
    char *nombre;
    char *especialidad;
public:
    medico();
    virtual ~medico();
    void SetEspecialidad(char* espec);
    void GetEspecialidad(char *espec) const;
    void SetNombre(char* nomb);
    void GetNombre(char *nomb) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
};

#endif /* MEDICO_H */

