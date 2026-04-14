#include "core_numeric.hpp"
#include "clasesPrueba.h"

int main() {
    cout << " TEST TRANSFORM REDUCE \n";
    
    vector<int> vi{1,2,3,4};
    auto r1 = core_numeric::transform_reduce(vi, [](int x){ return x*x; });
    cout << "int (x^2): " << r1 << "\n";

    vector<double> vd{1.5,2.0,3.0};
    auto r2 = core_numeric::transform_reduce(vd, [](double x){ return x*2; });
    cout << "double (*2): " << r2 << "\n\n";

    // Coordenadas
    vector<Coordenadas> vc{{1,2},{3,4}};
    auto r3 = core_numeric::transform_reduce(vc, [](Coordenadas c){
        return c + c; // ✔ permitido
    });
    cout << "Coordenadas: " << r3 << "\n";

    // Vector3D
    vector<Vector3D> vv{{1,2,3},{4,5,6}};
    auto r4 = core_numeric::transform_reduce(vv, [](Vector3D v){
        return v * v;
    });
    cout << "Vector3D: " << r4 << "\n";

    // Complejo
    vector<Complejo> vz{{1,2},{3,4}};
    auto r6 = core_numeric::transform_reduce(vz, [](Complejo z){
        return z * z;
    });
    cout << "Complejo: " << r6 << "\n\n";



    /*String (no cumple 'Restable')
    vector<string> vs{"a","b"};
    auto e1 = core_numeric::transform_reduce(vs, [](string s){ return s; });
    e1 no compila porque el constraint del template se evalúa antes de ejecutar la lambda: el tipo value_type (string)
    rompe Restable*/

    /*lambda devuelve tipo sin +
    struct A { int x; };
    vector<A> va{{1},{2}};
    auto e2 = core_numeric::transform_reduce(va, [](A a){ return a; });
    e2 falla porque el tipo A no define operator+ ni operator- ni operaciones aritméticas,
    por lo que el concept Addable/Restable requerido en transform_reduce no se cumple;
    además la lambda devuelve A, pero transform_reduce intenta hacer result + f(x),
    lo que requiere que A soporte suma*/

    return 0;
}