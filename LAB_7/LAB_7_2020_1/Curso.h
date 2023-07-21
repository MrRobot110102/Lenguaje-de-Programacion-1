/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Curso.h
 * Author: Sebastian
 *
 * Created on 7 de junio de 2023, 22:49
 */

#ifndef CURSO_H
#define CURSO_H

class Curso {
private:
    char *ccurso;
    int ciclo;
    int nota;
    double credito;
public:
    Curso();
    virtual ~Curso();
    void SetCredito(double credito);
    double GetCredito() const;
    void SetNota(int nota);
    int GetNota() const;
    void SetCiclo(int ciclo);
    int GetCiclo() const;
    void SetCcurso(char *ccur);
    void GetCcurso(char *ccur) const;
    void asignar(const class Curso &curso);
    void operator =(const class Curso &curso);
    bool compare(const class Curso &curso);
    bool operator ==(const class Curso &curso);
};

#endif /* CURSO_H */

