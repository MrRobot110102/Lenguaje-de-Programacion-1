/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   operadoresSobrecargados.h
 * Author: Sebastian
 *
 * Created on 21 de abril de 2023, 18:54
 */

#ifndef OPERADORESSOBRECARGADOS_H
#define OPERADORESSOBRECARGADOS_H

bool operator >>(ifstream &arch,TconductorSt &conductor);
bool operator >>(ifstream &arch,TInfraccionSt &infraccion);
bool operator >>(ifstream &arch,TInfraccionEstabSt &infraccionEstab);
void operator +(TconductorSt &conductor,const TInfraccionSt &infraccion);
void operator +(TconductorSt &conductor,const TInfraccionEstabSt &infraccionEstab);
void operator ++(TconductorSt  &conductor);
ofstream & operator<<(ofstream &arch,const TconductorSt &conductor);
void imprimirLinea(char car, int cantidad, ofstream &arch);
void operator *(TconductorSt &conductor, const int fecha);
void eliminarInfraccion(TconductorSt &conductor,const int posicion);
void darformato(char *gravedad);


#endif /* OPERADORESSOBRECARGADOS_H */

