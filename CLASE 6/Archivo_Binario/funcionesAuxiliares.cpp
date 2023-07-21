/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "funcionesAuxiliares.h"

void crearBinario(const char *nomArchText,const char *nomArchBin){
    int dd,mm,aa,serie,secuencia,referencia;
    char car,codCli[9],tipoDoc;
    double monto,totalFac=0, totalNC=0,saldoFinal;
    
    ifstream archText(nomArchText,ios::in);
    if(not archText.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nomArchText<<endl;
        exit(1);
    }
    ofstream archBin(nomArchBin,ios::out | ios::binary);
    if(not archBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nomArchBin<<endl;
        exit(1);
    }
    
    while(true){
        //lectura del archivo de textos
        archText>>dd;
        if(archText.eof()) break;
        archText>>car>>mm>>car>>aa;
        archText>>codCli>>tipoDoc>>serie>>car>>secuencia>>monto>>referencia;
        
        //grabar en el archivo binario
        archBin.write(reinterpret_cast<const char*>(&dd),sizeof(int));
        archBin.write(reinterpret_cast<const char*>(&mm),sizeof(int));
        archBin.write(reinterpret_cast<const char*>(&aa),sizeof(int));
        archBin.write(reinterpret_cast<const char*>(codCli),sizeof(char)*9);
        archBin.write(reinterpret_cast<const char*>(&tipoDoc),sizeof(char));
        archBin.write(reinterpret_cast<const char*>(&serie),sizeof(int));
        archBin.write(reinterpret_cast<const char*>(&secuencia),sizeof(int));
        archBin.write(reinterpret_cast<const char*>(&monto),sizeof(double));
        archBin.write(reinterpret_cast<const char*>(&referencia),sizeof(int));
    }
}

void leerBinarioV1(const char *nomArchBin,const char *nombArchText){
    int dd,mm,aa,serie,secuencia,referencia;
    char car,codCli[9],tipoDoc;
    double monto,totalFac=0, totalNC=0,saldoFinal;
    
    ifstream archBin(nomArchBin, ios::in | ios::binary);
    if(not archBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nomArchBin<<endl;
        exit(1);
    }
    ofstream archText(nombArchText, ios::out);
    if(not archText.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchText<<endl;
        exit(1);
    }
    
    generarEncabezado(archText);
    archText.precision(2);
    archText<<fixed;
    
    while(true){
        archBin.read(reinterpret_cast<char*>(&dd),sizeof(int));
        if(archBin.eof()) break;
        archBin.read(reinterpret_cast<char*>(&mm),sizeof(int));
        archBin.read(reinterpret_cast<char*>(&aa),sizeof(int));
        archBin.read(reinterpret_cast<char*>(codCli),sizeof(char)*9);
        archBin.read(reinterpret_cast<char*>(&tipoDoc),sizeof(char));
        archBin.read(reinterpret_cast<char*>(&serie),sizeof(int));
        archBin.read(reinterpret_cast<char*>(&secuencia),sizeof(int));
        archBin.read(reinterpret_cast<char*>(&monto),sizeof(double));
        archBin.read(reinterpret_cast<char*>(&referencia),sizeof(int));
        
        if(tipoDoc == 'F') totalFac = totalFac + monto;
        else totalNC = totalNC + monto;
        
        imprimirDetalle(dd,mm,aa,codCli,tipoDoc,serie,secuencia,monto,referencia,archText);
    }
    imprimirLinea('=',100,archText);
    saldoFinal = totalFac - totalNC;
    archText<<left<<setw(63)<<"TOTALES:"<<right<<setw(12)<<totalFac<<setw(11)<<totalNC<<endl;
    archText<<"SALDO FINAL:"<<setw(12)<<saldoFinal<<endl;
}

void leerBinarioV2(const char *nomArchBin,const char *nombArchText){
    int dd,mm,aa,serie,secuencia,referencia;
    char car,codCli[9],tipoDoc;
    double monto,totalFac=0, totalNC=0,saldoFinal;
    
    ifstream archBin(nomArchBin, ios::in | ios::binary);
    if(not archBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nomArchBin<<endl;
        exit(1);
    }
    ofstream archText(nombArchText, ios::out);
    if(not archText.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchText<<endl;
        exit(1);
    }
    
    generarEncabezado(archText);
    archText.precision(2);
    archText<<fixed;
    
    int tamDelRegistro,tamDelArchivo,numRegistros;
    tamDelRegistro = sizeof(int) * 6 + sizeof(char) * 10 + sizeof(double);
    archBin.seekg(0,ios::end);
    tamDelArchivo = archBin.tellg();
    archBin.seekg(0,ios::beg);
    numRegistros = tamDelArchivo/tamDelRegistro;
    
    for(int i=0;i<numRegistros;i++){
        archBin.read(reinterpret_cast<char*>(&dd),sizeof(int));
        archBin.read(reinterpret_cast<char*>(&mm),sizeof(int));
        archBin.read(reinterpret_cast<char*>(&aa),sizeof(int));
        archBin.read(reinterpret_cast<char*>(codCli),sizeof(char)*9);
        archBin.read(reinterpret_cast<char*>(&tipoDoc),sizeof(char));
        archBin.read(reinterpret_cast<char*>(&serie),sizeof(int));
        archBin.read(reinterpret_cast<char*>(&secuencia),sizeof(int));
        archBin.read(reinterpret_cast<char*>(&monto),sizeof(double));
        archBin.read(reinterpret_cast<char*>(&referencia),sizeof(int));
        
        if(tipoDoc == 'F') totalFac = totalFac + monto;
        else totalNC = totalNC + monto;
        
        imprimirDetalle(dd,mm,aa,codCli,tipoDoc,serie,secuencia,monto,referencia,archText);
    }
    imprimirLinea('=',100,archText);
    saldoFinal = totalFac - totalNC;
    archText<<left<<setw(63)<<"TOTALES:"<<right<<setw(12)<<totalFac<<setw(11)<<totalNC<<endl;
    archText<<"SALDO FINAL:"<<setw(12)<<saldoFinal<<endl;
}

void accesoDirectoV1(const char *nombArchBin){
    int dd,mm,aa,serie,secuencia,referencia;
    char car,codCli[9],tipoDoc;
    double monto,totalFac=0, totalNC=0,saldoFinal;
    
    ifstream archBin(nombArchBin, ios::in | ios::binary);
    if(not archBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchBin<<endl;
        exit(1);
    }
    
    int tamDelRegistro,tamDelArchivo,numRegistros,numReg;
    tamDelRegistro = sizeof(int) * 6 + sizeof(char) * 10 + sizeof(double);
    archBin.seekg(0,ios::end);
    tamDelArchivo = archBin.tellg();
    archBin.seekg(0,ios::beg);
    numRegistros = tamDelArchivo/tamDelRegistro;
    
    while(true){
        cout<<"Ingrese numero de registro: ";
        cin>>numReg;
        if(numReg == 0) break;
        if(numReg>=1 and numReg <=numRegistros){
            archBin.seekg((numReg - 1)*tamDelRegistro,ios::beg);
            archBin.read(reinterpret_cast<char*>(&dd),sizeof(int));
            archBin.read(reinterpret_cast<char*>(&mm),sizeof(int));
            archBin.read(reinterpret_cast<char*>(&aa),sizeof(int));
            archBin.read(reinterpret_cast<char*>(codCli),sizeof(char)*9);
            archBin.read(reinterpret_cast<char*>(&tipoDoc),sizeof(char));
            archBin.read(reinterpret_cast<char*>(&serie),sizeof(int));
            archBin.read(reinterpret_cast<char*>(&secuencia),sizeof(int));
            archBin.read(reinterpret_cast<char*>(&monto),sizeof(double));
            archBin.read(reinterpret_cast<char*>(&referencia),sizeof(int));
            cout<<right<<setw(2)<<numReg<<"  "<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<aa
            <<setfill(' ');
    
            cout<<setw(13)<<codCli;

            cout<<left<<setw(5)<<" "<<setw(20);

            if(tipoDoc == 'F') cout<<"FACTURA";
            else cout<<"NOTA DE CREDITO";

            cout<<right<<setfill('0')<<setw(5)<<secuencia<<setfill(' ')<<setw(5)<<" ";
            cout<<setfill('0')<<setw(4)<<serie<<setfill(' ');

            cout<<left<<setw(5)<<" "<<right;

            if(tipoDoc == 'F') cout<<setw(8)<<monto<<setw(11)<<" ";
            else cout<<setw(11)<<" "<<setw(8)<<monto;

            cout<<setw(5)<<" "<<setfill('0')<<setw(5)<<referencia<<setfill(' ')<<endl;
        }else cout<<"Error en el numero de registro"<<endl<<endl;
    }
}

void accesoDirectoV2(const char *nomArchBin){
    int dd,mm,aa,serie,secuencia,referencia;
    char car,codCli[9],tipoDoc;
    double monto,totalFac=0, totalNC=0,saldoFinal;
    
    ifstream archBin(nomArchBin,ios::in | ios::binary);
    if(not archBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nomArchBin<<endl;
        exit(1);
    }
    
    int tamDelRegistro,tamDelArchivo,numRegistros,numReg;
    tamDelRegistro = sizeof(int) * 6 + sizeof(char) * 10 + sizeof(double);
    archBin.seekg(0,ios::end);
    tamDelArchivo = archBin.tellg();
    archBin.seekg(0,ios::beg);
    numRegistros = tamDelArchivo/tamDelRegistro;

    while(true){
        cout<<"Ingrese el numero del registro: ";
        cin>>numReg;
        if(numReg == 0) break;
        if(numReg > 0 && numReg<numRegistros){
            archBin.seekg((numReg - 1)*tamDelRegistro,ios::beg);
            archBin.seekg(sizeof(int)*3,ios::cur);
            archBin.read(reinterpret_cast<char*>(codCli),sizeof(char)*9);
            archBin.read(reinterpret_cast<char*>(&tipoDoc),sizeof(char));
            archBin.seekg(sizeof(int)*2,ios::cur);
            archBin.read(reinterpret_cast<char*>(&monto),sizeof(double));
            archBin.read(reinterpret_cast<char*>(&referencia),sizeof(int));
            cout<<right;
    
            cout<<setw(13)<<codCli;

            cout<<left<<setw(5)<<" "<<setw(20);

            if(tipoDoc == 'F') cout<<"FACTURA";
            else cout<<"NOTA DE CREDITO";

            cout<<left<<setw(5)<<" "<<right;

            if(tipoDoc == 'F') cout<<setw(8)<<monto<<setw(11)<<" ";
            else cout<<setw(11)<<" "<<setw(8)<<monto;

            cout<<setw(5)<<" "<<setfill('0')<<setw(5)<<referencia<<setfill(' ')<<endl;
        }else cout<<"Error en el numero de registro"<<endl<<endl;
    }
}

void accesoDirectoV3(const char *nomArchBin){
    int dd,mm,aa,serie,secuencia,referencia;
    char car,codCli[9],tipoDoc;
    double monto,totalFac=0, totalNC=0,saldoFinal;
    
    fstream archBin(nomArchBin, ios::out | ios::in | ios::binary);
    if(not archBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nomArchBin<<endl;
        exit(1);
    }
    
    int tamDelRegistro,tamDelArchivo,numRegistros,numReg;
    tamDelRegistro = sizeof(int) * 6 + sizeof(char) * 10 + sizeof(double);
    archBin.seekg(0,ios::end);
    tamDelArchivo = archBin.tellg();
    archBin.seekg(0,ios::beg);
    numRegistros = tamDelArchivo/tamDelRegistro;
    
    while(1){
        cout<<"Ingrese el numero del registro: ";
        cin>>numReg;
        if(numReg == 0) break;
        if(numReg > 0 && numReg<numRegistros){
            archBin.seekg((numReg - 1)*tamDelRegistro,ios::beg);
            archBin.seekg(sizeof(int)*3,ios::cur);
            archBin.read(reinterpret_cast<char*>(codCli),sizeof(char)*9);
            archBin.read(reinterpret_cast<char*>(&tipoDoc),sizeof(char));
            archBin.seekg(sizeof(int)*2,ios::cur);
            archBin.read(reinterpret_cast<char*>(&monto),sizeof(double));
            archBin.read(reinterpret_cast<char*>(&referencia),sizeof(int));
            cout<<right;
    
            cout<<setw(13)<<codCli;

            cout<<left<<setw(5)<<" "<<setw(20);

            if(tipoDoc == 'F') cout<<"FACTURA";
            else cout<<"NOTA DE CREDITO";

            cout<<left<<setw(5)<<" "<<right;

            if(tipoDoc == 'F') cout<<setw(8)<<monto<<setw(11)<<" ";
            else cout<<setw(11)<<" "<<setw(8)<<monto;

            cout<<setw(5)<<" "<<setfill('0')<<setw(5)<<referencia<<setfill(' ')<<endl;
            
            // ******************************************************
            // Le pedimos que ingrese un nuevo monto y
            // corregimos con él, el archivo.
            // *******************************************************
            
            cout<<"Ingrese un nuevo monto: ";
            cin>>monto;
            archBin.seekg((numReg - 1)*tamDelRegistro,ios::beg);
            archBin.seekg(sizeof(int)*5+sizeof(char)*10,ios::cur);
            archBin.write(reinterpret_cast<const char*>(&monto),sizeof(double));
            archBin.flush(); // Descarga el buffer en el archivo
        }else cout<<"Error en el numero de registro"<<endl<<endl;
    }   
}

void accesoDirectoV4(const char *nomArchBin){
    int dd,mm,aa,serie,secuencia,referencia;
    char car,codCli[9],tipoDoc;
    double monto,totalFac=0, totalNC=0,saldoFinal;
    
    fstream archBin(nomArchBin,ios::in | ios ::out | ios::binary);
    if(not archBin.is_open()){
        cout << "ERROR: No se pudo abrir el archivo Registro.bin" << endl;
        exit(1);
    }
    
    int tamDelRegistro,tamDelArchivo,numRegistros;
    tamDelRegistro = sizeof(int) * 6 + sizeof(char) * 10 + sizeof(double);
    archBin.seekg(0,ios::end);
    tamDelArchivo = archBin.tellg();
    archBin.seekg(0,ios::beg);
    numRegistros = tamDelArchivo/tamDelRegistro;
    
    for (int numReg = 0; numReg < numRegistros; numReg++) {
        archBin.seekg(numReg*tamDelRegistro,ios::beg);
        archBin.seekg(sizeof(int)*5+sizeof(char)*10,ios::cur);
        archBin.read(reinterpret_cast<char*>(&monto),sizeof(double));
        monto += monto * 0.18;
        archBin.seekg(numReg*tamDelRegistro,ios::beg);
        archBin.seekg(sizeof(int)*5+sizeof(char)*10,ios::cur);
        archBin.write(reinterpret_cast<const char*>(&monto),sizeof(double));
        archBin.flush(); // Descarga el buffer en el archivo
    }
}

void generarEncabezado(ofstream &reporte){
    reporte<<"REGISTRO DE VENTAS"<<endl;
    imprimirLinea('=',100,reporte);
    reporte<<left<<setw(15)<<"FECHA"<<setw(14)<<"CLIENTE"<<setw(17)<<"TIPO"
              <<setw(12)<<"SECUENCIA"<<setw(9)<<"SERIE"<<setw(14)<<"FACTURAS"
              <<setw(8)<<"N/C"<<"REFERENCIA"<<endl;
    imprimirLinea('-',100,reporte);
}


void imprimirLinea(char car, int cantidad,ofstream &reporte){
    for (int i = 0; i < cantidad; i++) reporte<<car;
    reporte<<endl;
}

void imprimirDetalle(int dd,int mm,int aa,char *codCli,char tipoDoc,int serie,
                     int secuencia,double monto,int referencia,ofstream &reporte){
    reporte<<right<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<aa
        <<setfill(' ');
    
    reporte<<setw(13)<<codCli;
    
    reporte<<left<<setw(5)<<" "<<setw(20);
    
    if(tipoDoc == 'F') reporte<<"FACTURA";
    else reporte<<"NOTA DE CREDITO";
    
    reporte<<right<<setfill('0')<<setw(5)<<secuencia<<setfill(' ')<<setw(5)<<" ";
    reporte<<setfill('0')<<setw(4)<<serie<<setfill(' ');
    
    reporte<<left<<setw(5)<<" "<<right;
    
    if(tipoDoc == 'F') reporte<<setw(8)<<monto<<setw(11)<<" ";
    else reporte<<setw(11)<<" "<<setw(8)<<monto;
    
    reporte<<setw(5)<<" "<<setfill('0')<<setw(5)<<referencia<<setfill(' ')<<endl;
}