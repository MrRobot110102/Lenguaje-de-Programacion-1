/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   SobrecargaOperadores.h
 * Author: Sebastian
 *
 * Created on 31 de mayo de 2023, 23:21
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Cliente.h"
#include "Pedido.h"

#ifndef SOBRECARGAOPERADORES_H
#define SOBRECARGAOPERADORES_H

ifstream & operator >>(ifstream &arch,class Cliente &cli);
ifstream & operator >>(ifstream &arch,class Pedido &ped);
ofstream & operator <<(ofstream &arch,const class Cliente &cli);
ofstream & operator <<(ofstream &arch,const class Pedido &ped);
int buscarCliente(int dni,class Cliente *cliente);

#endif /* SOBRECARGAOPERADORES_H */

