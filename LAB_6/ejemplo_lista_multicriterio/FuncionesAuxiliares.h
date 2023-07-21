/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 1 de junio de 2023, 18:49
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void insertar_lista(void *&, void *);
void insertar_lista_ordenado(void *&, void *, int(*)(const void*, const void*));
void * leer_entero(ifstream &);
void * leer_registro(ifstream &);
int cmp_registro_multi_criterio(const void* , const void* );
void imprimir_lista(void *, void (*)(void*));
void imprimir_registro(void* );
void eliminar_registro(void* );
void crear_lista(ifstream &, void *&, void*(*)(ifstream &));
void crear_lista(ifstream &, void *&, void*(*)(ifstream &), int(*)(const void*, const void*));
void eliminar_lista(void *, void(*)(void*));
void imprimir_entero(void* );

#endif /* FUNCIONESAUXILIARES_H */

