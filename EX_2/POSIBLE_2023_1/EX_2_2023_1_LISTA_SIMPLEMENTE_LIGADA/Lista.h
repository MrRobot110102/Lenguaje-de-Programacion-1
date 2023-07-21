/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.h
 * Author: Sebastian
 *
 * Created on 6 de julio de 2023, 23:28
 */

#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
#include "Curso.h"

class Lista {
public:
    Lista();
    virtual ~Lista();
    void crearLista(ifstream &arch);
    void imprimirLista(ofstream &arch);
    void ingresaCursos(ifstream &arch);
    void ordenaCursos();
    void eliminaCurso(const char *nombCurso);
    void eliminaAlumnosSinCursos();
    void eliminaUnAlumno(int codigoAlumno);
    void eliminaRangoCursos(int semestre);
    void actualiza(int anio,int descuento);
    void ingresaCursoAlumno(int codigo,const Curso &cur);
private:
    class Nodo *lini;
    class Nodo *lfin;
    void insertar(class Nodo *nuevo);
    Nodo *buscarAlumno(int cod);
    void eliminaAlumno(class Nodo *sale);
    void actualizaAlumno(class Nodo *sale,int descuento);
    void actualizaPolimorfismo(class Nodo *sale,int descuento);
};

#endif /* LISTA_H */

