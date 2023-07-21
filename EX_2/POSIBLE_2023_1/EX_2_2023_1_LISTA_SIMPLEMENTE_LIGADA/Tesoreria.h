/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tesoreria.h
 * Author: Sebastian
 *
 * Created on 6 de julio de 2023, 23:36
 */

#ifndef TESORERIA_H
#define TESORERIA_H
#include "Lista.h"

class Tesoreria {
public:
    void cargaAlumnos();
    void imprimeAlumnos(const char *nombArch);
    void cargaCursos();
    void ordenarCursos();
    void borrarCurso(const char *nombCurso);
    void eliminaAlumnosSinCursos();
    void eliminaUnAlumno(int codigoAlumno);
    void eliminaRangoCursos(int semestre);
    void actualizar(int anio,int descuento);
private:
    class Lista Lboletas;
};

#endif /* TESORERIA_H */

