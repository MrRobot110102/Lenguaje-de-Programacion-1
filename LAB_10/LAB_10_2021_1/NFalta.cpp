/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   NFalta.cpp
 * Author: Sebastian
 * 
 * Created on 26 de junio de 2023, 16:09
 */

#include "NFalta.h"

NFalta::NFalta() {
    pfalta = nullptr;
    sig = nullptr;
}

NFalta::~NFalta() {
    if(pfalta != nullptr) delete pfalta;
}

