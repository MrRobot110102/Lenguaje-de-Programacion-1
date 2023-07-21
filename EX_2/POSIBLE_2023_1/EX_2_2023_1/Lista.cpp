/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.cpp
 * Author: Sebastian
 * 
 * Created on 6 de julio de 2023, 23:28
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
#include "Lista.h"
#include "Nodo.h"
#include "Curso.h"

Lista::Lista() {
    lini = nullptr;
    lfin = nullptr;
}

Lista::~Lista() {
    class Nodo *sale;
    while(lini){
        sale = lini;
        lini = lini->sig;
        delete sale;
    }
}

void Lista::crearLista(ifstream& arch) {
    char tipo;
    class Nodo *nuevo;
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        nuevo = new class Nodo;
        nuevo->dboleta.escoger(tipo);
        nuevo->dboleta.leer(arch);
        //cout<<nuevo->dboleta.getCodigo()<<endl;
        insertar(nuevo);
    }
}

void Lista::insertar(Nodo* nuevo) {
    class Nodo *ls = lini, *ant = nullptr;
    if(lini == nullptr){
        lini = nuevo;
        lfin = nuevo;
    }else{
        while(ls){
            if(ls->dboleta.getCodigo() > nuevo->dboleta.getCodigo()) break;
            ant = ls;
            ls = ls->sig;
        }
        nuevo->sig = ls;
        nuevo->ant = ant;
        if(ant != nullptr) ant->sig = nuevo;
        else lini = nuevo;
        if(ls != nullptr) ls->ant = nuevo;
        else lfin = nuevo;
    }
}

void Lista::imprimirLista(ofstream& arch) {
    class Nodo *recorrido = lini;
    while(recorrido){
        recorrido->dboleta.imprimir(arch);
        for (int i = 0; i < recorrido->vCursos.size(); i++) recorrido->vCursos[i].imprimirCurso(arch);
        if(recorrido->vCursos.empty()) arch<<"El alumno no tiene cursos registrados"<<endl;
        arch<<endl;
        recorrido = recorrido->sig;
    }
}

void Lista::ingresaCursos(ifstream& arch) {
    int codigo,semestre,nota;
    char cod[100],car;
    class Curso curso;
    class Nodo *posAlumno;
    while(true){
        arch>>codigo;
        if(arch.eof()) break;
        arch.get();
        arch.getline(cod,100,',');
        arch>>semestre>>car>>nota;
        curso.SetCodigo(cod);
        curso.SetNota(nota);
        curso.SetSemestre(semestre);
        //ingresaCursoAlumno(codigo,curso);
        posAlumno = buscarAlumno(codigo);
        if(posAlumno != nullptr) posAlumno->vCursos.push_back(curso);
    }
}

void Lista::ingresaCursoAlumno(int codigo, const Curso& cur) {
    class Nodo *recorrido = lini;
    while(recorrido){
        if(recorrido->dboleta.getCodigo() == codigo) recorrido->vCursos.push_back(cur);
        recorrido = recorrido->sig;
    }
}

void Lista::ordenaCursos() {
    class Nodo *recorrido = lini;
    while(recorrido){
        sort(recorrido->vCursos.begin(),recorrido->vCursos.end());
        recorrido = recorrido->sig;
    }
}

void Lista::eliminaCurso(const char* nombCurso) {
    class Nodo *recorrido = lini;
    while(recorrido){
        recorrido->eliminaCurso(nombCurso);
        recorrido = recorrido->sig;
    }
}

void Lista::eliminaAlumnosSinCursos() {
    class Nodo *recorrido = lini;
    while (recorrido) {
        if (recorrido->vCursos.empty()) {
            class Nodo *sale = recorrido;
            recorrido = recorrido->sig; // Avanzar al siguiente nodo antes de eliminar el nodo actual
            eliminaAlumno(sale);
        } else recorrido = recorrido->sig; // Avanzar al siguiente nodo 
    }
}

void Lista::eliminaUnAlumno(int codigoAlumno) {
    class Nodo *recorrido = lini;
    while(recorrido){
        if(recorrido->dboleta.getCodigo() == codigoAlumno){
            class Nodo *sale = recorrido;
            recorrido = recorrido->sig; // Avanzar al siguiente nodo antes de eliminar el nodo actual
            eliminaAlumno(sale);
            return;
        }else recorrido = recorrido->sig;
    }
}

void Lista::eliminaRangoCursos(int semestre) {
    class Nodo *recorrido = lini;
    while(recorrido){
        recorrido->eliminaRango(semestre);
        if(recorrido->vCursos.empty()){
            class Nodo *sale = recorrido;
            recorrido = recorrido->sig; // Avanzar al siguiente nodo antes de eliminar el nodo actual
            eliminaAlumno(sale);
        }else recorrido = recorrido->sig;
    }
}

void Lista::actualiza(int anio,int descuento) {
    class Nodo *recorrido = lini;
    while(recorrido){
        if(recorrido->dboleta.getCodigo()/100000 == anio){
            class Nodo *sale = recorrido;
            //actualizaPolimorfismo(sale,descuento);
            recorrido = recorrido->sig;
            actualizaAlumno(sale,descuento);
        }else recorrido = recorrido->sig;
    }
}

void Lista::eliminaAlumno(Nodo *sale) {
    if (sale == nullptr) return; // No hacer nada si el nodo es nullptr
    if (sale == lini) {
        lini = sale->sig;
        if (lini) lini->ant = nullptr;
    } else if (sale == lfin) {
        lfin = sale->ant;
        if (lfin) lfin->sig = nullptr;
    } else {
        Nodo *aux_sale_ant = sale->ant;
        Nodo *aux_sale_sig = sale->sig;
        aux_sale_ant->sig = sale->sig;
        aux_sale_sig->ant = sale->ant;
    }
    delete sale;
}

void Lista::actualizaAlumno(Nodo* sale,int descuento) {
    int cod,esca;
    char nomb[100];
    double cred,tot;
    class Nodo *nuevo = new class Nodo;
    nuevo->dboleta.escoger('S');
    sale->dboleta.getDatosAlumno(cod,nomb,esca,cred,tot);
    nuevo->dboleta.setDatosAlumno(cod,nomb,esca,cred,tot);
    nuevo->vCursos = sale->vCursos;
    //0
    nuevo->dboleta.actualiza(descuento,0);
    //cout<<nuevo->dboleta.getCodigo()<<endl;
    eliminaAlumno(sale);
    insertar(nuevo);
}

void Lista::actualizaPolimorfismo(Nodo* sale, int descuento) {
    int cod,esca;
    char nomb[100];
    double cred,tot;
    sale->dboleta.getDatosAlumno(cod,nomb,esca,cred,tot);
    sale->dboleta.elimina();
    sale->dboleta.escoger('S');
    sale->dboleta.setDatosAlumno(cod,nomb,esca,cred,tot);
    //1
    sale->dboleta.actualiza(descuento,1);
}

Nodo *Lista::buscarAlumno(int cod) {
    class Nodo *recorrido = lini;
    while(recorrido){
        if(recorrido->dboleta.getCodigo() == cod) return recorrido;
        recorrido = recorrido->sig;
    }
    return nullptr;
}








