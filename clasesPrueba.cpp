//
// Created by burgo on 13/4/2026.
//

#include "clasesPrueba.h"

//Clase Complejo
Complejo Complejo::operator+(const Complejo &other) const {
        return Complejo(real+other.real,imag+other.imag);
}

Complejo Complejo::operator-(const Complejo &other) const {
    return Complejo(real-other.real,imag-other.imag);
}

Complejo Complejo::operator*(const Complejo &other) const {
    return Complejo(real*other.real-imag*other.imag,real*other.imag+imag*other.real);
}

Complejo Complejo::operator/(const Complejo &other) const {
    auto denomin = real*other.real+imag*other.imag;
    auto numeReal = (real*other.real+imag*other.imag)/denomin ;
    auto numeImag =(imag*other.real-real*other.imag)/denomin;
    return Complejo(numeReal,numeImag);
}

Complejo Complejo::operator/(size_t n) const {
    auto divisor = static_cast<double>(n);
    return Complejo(real/divisor,imag/divisor);
}

bool Complejo::operator>(const Complejo &other) const {
    return sqrt(real*real+imag*imag)>sqrt(other.real*other.real+other.imag*other.imag);
}

bool Complejo::operator<(const Complejo &other) const {
    return sqrt(real*real+imag*imag)<sqrt(other.real*other.real+other.imag*other.imag);
}

bool Complejo::operator==(const Complejo &other) const {
    return sqrt(real*real+imag*imag)==sqrt(other.real*other.real+other.imag*other.imag);
}

ostream& operator<<(ostream& os, const Complejo& c) {
    os<<c.real<<" ";
    if (c.imag<0)
        os<<c.imag<<"i";
    else
        os<<"- "<<c.imag<<"i";
    return os;
}


//Clase Vector3D
Vector3D Vector3D::operator+(const Vector3D &other) const {
    return Vector3D(x+other.x,y+other.y,z+other.z);
}

Vector3D Vector3D::operator/(const Vector3D &other) const {
    return Vector3D(x/other.x,y/other.y,z/other.z);
}

Vector3D Vector3D::operator/(size_t n) const {
    auto divisor = static_cast<double>(n);
    return Vector3D(x/divisor,y/divisor,z/divisor);
}

Vector3D Vector3D::operator-(const Vector3D &other) const {
    return Vector3D(x-other.x,y-other.y,z-other.z);
}

Vector3D Vector3D::operator*(const Vector3D &other) const {
    return Vector3D(x*other.x,y*other.y,z*other.z);
}

bool Vector3D::operator>(const Vector3D &other) const {
    return sqrt(x*x+y*y+z*z)>sqrt(other.x*other.x+other.y*other.y+other.z*other.z);
}

bool Vector3D::operator<(const Vector3D &other) const {
    return sqrt(x*x+y*y+z*z)<sqrt(other.x*other.x+other.y*other.y+other.z*other.z);
}

bool Vector3D::operator==(const Vector3D &other) const {
    return sqrt(x*x+y*y+z*z)==sqrt(other.x*other.x+other.y*other.y+other.z*other.z);
}

ostream& operator<<(ostream& os,const Vector3D& coor) {
    os<<"x: "<<coor.x<<endl;
    os<<"y: "<<coor.y<<endl;
    os<<"z: "<<coor.y<<endl;
    return os;
}

//Clase Coordenadas
Coordenadas Coordenadas::operator+(const Coordenadas &other) const {
    return Coordenadas(x+other.x,y+other.y);
}

Coordenadas Coordenadas::operator/(const Coordenadas &other) const {
    return Coordenadas(x/other.x,y/other.y);
}

Coordenadas Coordenadas::operator/(size_t n) const {
    auto divisor = static_cast<double>(n);
    return Coordenadas(x/divisor,y/divisor);
}

Coordenadas Coordenadas::operator-(const Coordenadas &other) const {
    return Coordenadas(x-other.x,y-other.y);
}

Coordenadas Coordenadas::operator*(const Coordenadas &other) const {
    return Coordenadas(x*other.x,y*other.y);
}

bool Coordenadas::operator>(const Coordenadas &other) const {
    return sqrt(x*x+y*y) > sqrt(other.x*other.x+other.y*other.y);
}

bool Coordenadas::operator<(const Coordenadas &other) const {
    return sqrt(x*x+y*y) < sqrt(other.x*other.x+other.y*other.y);
}

bool Coordenadas::operator==(const Coordenadas &other) const {
    return sqrt(x*x+y*y) == sqrt(other.x*other.x+other.y*other.y);
}

ostream& operator<<(ostream& os,const Coordenadas& coor) {
    os<<"x: "<<coor.x<<endl;
    os<<"y: "<<coor.y<<endl;
    return os;
}


//Esfera

Esfera Esfera::operator-(const Esfera &o) const {
    return Esfera(x-o.x,y-o.y,z-o.z,r-o.r);
}

Esfera Esfera::operator+(const Esfera &o) const {
    return Esfera(x+o.x,y+o.y,z+o.z,r+o.r);
}

Esfera Esfera::operator*(const Esfera &o) const {
    return Esfera(x*o.x,y*o.y,z*o.z,r*o.r);
}

Esfera Esfera::operator/(const Esfera &o) const {
    return Esfera(x/o.x,y/o.y,z/o.z,r/o.r);
}

Esfera Esfera::operator/(size_t n) const {
    auto d = static_cast<double>(n);
    return Esfera(x/d,y/d,z/d,r/d);
}

bool Esfera::operator<(const Esfera &o) const {
    return 4.0/3.0*numbers::pi*r*r*r<4.0/3.0*numbers::pi*o.r*o.r*o.r;
}

bool Esfera::operator>(const Esfera &o) const {
    return 4.0/3.0*numbers::pi*r*r*r>4.0/3.0*numbers::pi*o.r*o.r*o.r;
}

bool Esfera::operator==(const Esfera &o) const {
    return 4.0/3.0*numbers::pi*r*r*r==4.0/3.0*numbers::pi*o.r*o.r*o.r;
}

ostream& operator<<(ostream& os,const Esfera& o) {
    os<<"coor 'x': "<<o.x<<endl;
    os<<"coor 'y': "<<o.y<<endl;
    os<<"coor 'z': "<<o.z<<endl;
    os<<"radio 'r': "<<o.r<<endl;
    return os;
}


//Clase Matriz10x10
Matriz10x10::Matriz10x10(int _min, int _max):min(_min),max(_max),data(10,vector<double>(10)){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(min,max);
    for (size_t i=0;i<10;i++)
        for (size_t j=0;j<10;j++)
            data[i][j]=dist(gen);
}

Matriz10x10 Matriz10x10::operator+(const Matriz10x10 &o) const {
    vector<vector<double>> n_data(10,vector<double>(10,0));
    for (size_t i=0;i<10;i++)
        for (size_t j=0;j<10;j++)
            n_data[i][j] = data[i][j]+o.data[i][j];
    return Matriz10x10(min,max,n_data);
}

Matriz10x10 Matriz10x10::operator-(const Matriz10x10 &o) const {
    vector<vector<double>> n_data(10,vector<double>(10,0));
    for (size_t i=0;i<10;i++)
        for (size_t j=0;j<10;j++)
            n_data[i][j] = data[i][j]-o.data[i][j];
    return Matriz10x10(min,max,n_data);
}

Matriz10x10 Matriz10x10::operator*(const Matriz10x10 &o) const {
    vector<vector<double>> n_data(10,vector<double>(10,0));
    for (size_t i=0;i<10;i++)
        for (size_t j=0;j<10;j++)
            n_data[i][j] = data[i][j]*o.data[i][j];
    return Matriz10x10(min,max,n_data);
}

Matriz10x10 Matriz10x10::operator/(const Matriz10x10 &o) const {
    vector<vector<double>> n_data(10,vector<double>(10,0));
    for (size_t i=0;i<10;i++)
        for (size_t j=0;j<10;j++)
            n_data[i][j] = data[i][j]/o.data[i][j];
    return Matriz10x10(min,max,n_data);
}

double Matriz10x10::suma() const {
    double contador =0;
    for (size_t i=0;i<10;i++)
        for (size_t j=0;j<10;j++)
            contador = contador+data[i][j];
    return contador;
}

bool Matriz10x10::operator>(const Matriz10x10 &o) const{
    double a1 =this->suma();
    double a2 = o.suma();
    return a1>a2;
}

bool Matriz10x10::operator<(const Matriz10x10 &o) const {
    double a1 =this->suma();
    double a2 = o.suma();
    return a1<a2;
}

bool Matriz10x10::operator==(const Matriz10x10 &o) const {
    double a1 =this->suma();
    double a2 = o.suma();
    return a1==a2;
}

ostream& operator<<(ostream& os, const Matriz10x10& o) {
    for (size_t i=0;i<10;i++) {
        for (size_t j=0;j<10;j++)
            os<< o.data[i][j]<<" ";
        os<<endl;
    }
    return os;
}


//Clase Estudiante

void Estudiante::EntrarUniversidad(string nuevaUni,int nuevoCodi) {
    universidad = nuevaUni;
    codigo = nuevoCodi;
}

void Estudiante::SalirUniversidad() {
    universidad="SinUniversidad";
    codigo = 0000;
}
