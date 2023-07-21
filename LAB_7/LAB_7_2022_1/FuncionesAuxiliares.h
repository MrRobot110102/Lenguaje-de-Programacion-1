/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 3 de junio de 2023, 22:03
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void leerClientes(class Cliente *cliente,const char *nombArch);
void leerPedidos(class Pedido *pedido,const char *nombArch);
void agregarPedidos(class Cliente *cliente, class Pedido *pedido);
void eliminarPedidos(class Cliente *cliente,const char *nombArch);
void aplicarDescuento(class Cliente *cliente);
void imprimirClientes(class Cliente *cliente,const char *nombArch);
void imprimirPedidos(class Pedido *pedido,const char *nombArch);

#endif /* FUNCIONESAUXILIARES_H */

