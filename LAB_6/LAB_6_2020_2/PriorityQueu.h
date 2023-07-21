/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PriorityQueu.h
 * Author: Sebastian
 *
 * Created on 24 de mayo de 2023, 15:37
 */

#ifndef PRIORITYQUEU_H
#define PRIORITYQUEU_H

void creacola(void *&cola,void *(*lee)(ifstream &),int (*prioridad)(void *),const char *nombArch);
void encolar(void *&cola,void *dato,int (*prioridad)(void *));
int colavacia(void *cola);
void prueba(void *cola,void (*imprime)(void *,ofstream &),const char *nombArch);
void descargacola(void *&cola,void (*imprime)(void *,ofstream &),const char *nombArch);
void *desencola(void *cola);
#endif /* PRIORITYQUEU_H */

