//
// Created by burgo on 13/4/2026.
//

#ifndef TAREA2_CLASESPRUEBA_H
#define TAREA2_CLASESPRUEBA_H
#include "core_numeric.hpp"

class Complejo {
    double real;
    double imag;
public:
    Complejo():real(0),imag(0){}
    Complejo(double _real,double _imag):real(_real),imag(_imag){}
    Complejo operator+(const Complejo& other)const;
    Complejo operator-(const Complejo& other)const;
    Complejo operator*(const Complejo& other)const;
    Complejo operator/(const Complejo& other)const;
    Complejo operator/(size_t n) const;
    bool operator>(const Complejo& other)const;
    bool operator<(const Complejo& other)const;
    bool operator==(const Complejo& other)const;
    friend ostream& operator<<(ostream& os, const Complejo& c);
};


class Vector3D {
    double x;
    double y;
    double z;
public:
    Vector3D():x(0),y(0),z(0){}
    Vector3D(double _x, double _y,double _z):x(_x),y(_y),z(_z){}
    Vector3D operator+(const Vector3D& other)const;
    Vector3D operator/(const Vector3D& other)const;
    Vector3D operator/(size_t n)const;
    Vector3D operator-(const Vector3D& other) const;
    Vector3D operator*(const Vector3D& other)const;
    bool operator>(const Vector3D& other)const;
    bool operator<(const Vector3D& other)const;
    bool operator==(const Vector3D& other)const;
    friend ostream& operator<<(ostream& os,const Vector3D& coor);
};

class Coordenadas {
    double x;
    double y;
public:
    Coordenadas():x(0),y(0){}
    Coordenadas(double _x, double _y):x(_x),y(_y){}
    Coordenadas operator+(const Coordenadas& other)const;
    Coordenadas operator/(const Coordenadas& other)const;
    Coordenadas operator/(size_t n)const;
    Coordenadas operator-(const Coordenadas& other) const;
    Coordenadas operator*(const Coordenadas& other)const;
    bool operator>(const Coordenadas& other)const;
    bool operator<(const Coordenadas& other)const;
    bool operator==(const Coordenadas& other)const;
    friend ostream& operator<<(ostream& os,const Coordenadas& coor);
};

class Esfera {
    double r;
    double x;
    double y;
    double z;
public:
    Esfera():x(0),y(0),z(0),r(0){}
    Esfera(double _x,double _y,double _z,double _r):r(_r),x(_x),y(_y),z(_z){}
    Esfera operator-(const Esfera& o) const;
    Esfera operator+(const Esfera& o) const;
    Esfera operator*(const Esfera& o) const;
    Esfera operator/(const Esfera& o) const;
    Esfera operator/(size_t n) const;
    bool operator<(const Esfera& o) const;
    bool operator>(const Esfera& o) const;
    bool operator==(const Esfera& o) const;
    friend ostream& operator<<(ostream& os,const Esfera& o);
};

class Matriz10x10 {
    double min;
    double max;
    vector<vector<double>> data;
public:
    Matriz10x10():min(0),max(0),data(10,vector<double>(10,0)){}
    Matriz10x10(int _min,int _max);
    Matriz10x10(int _min,int _max,vector<vector<double>> _data):min(_min),max(_max),data(_data){}
    Matriz10x10 operator+(const Matriz10x10& o) const;
    Matriz10x10 operator-(const Matriz10x10& o) const;
    Matriz10x10 operator*(const Matriz10x10& o) const;
    Matriz10x10 operator/(const Matriz10x10& o) const;
    double suma() const;
    bool operator>(const Matriz10x10& o)const;
    bool operator<(const Matriz10x10& o)const;
    bool operator==(const Matriz10x10& o)const;
    friend ostream& operator<<(ostream& os, const Matriz10x10& o);
};


class Estudiante {
    string nombre;
    int codigo;
    string universidad;
public:
    Estudiante():nombre("SinNombre"),codigo(0000),universidad("SinUniversidad"){}
    Estudiante(string _nombre,int _codigo,string _univer):nombre(_nombre),codigo(_codigo),universidad(_univer){}
    void EntrarUniversidad(string nuevaUni,int nuevoCodi);
    void SalirUniversidad();
};


#endif //TAREA2_CLASESPRUEBA_H
