#include "core_numeric.hpp"
#include "clasesPrueba.h"
using namespace core_numeric;

int main() {
    cout << " TEST MAX VARIADIC \n";

    cout << max_variadic(1,5,2,9) << "\n";

    Vector3D v1{1,2,3}, v2{5,5,5};
    cout << "Vector3D: " << max_variadic(v1,v2) << "\n";

    Coordenadas c1{1,2}, c2{3,4};
    cout << "Coord: " << max_variadic(c1,c2) << "\n";

    Complejo z1{1,2}, z2{3,4};
    cout << "Complejo: " << max_variadic(z1,z2) << "\n";


    /*cout << max_variadic(v1, c1) << "\n";
    *falla porque Vector3D y Coordenadas son tipos distintos y no existe una relación de orden definida
    *entre ellos (no hay operator< entre ambos ni una conversión a un tipo común comparable)
    *por lo que el concept 'Comparable' se rompe y el algoritmo no puede determinar cuál es "mayor"*/

    /*cout << max_variadic('a','z','m') << "\n";
    *Puede fallar dependiendo de la deducción de tipos y constraints: aunque char es comparable, si los concepts
    *o la promoción a common_type no encajan correctamente con las restricciones de Comparable/Restable
    *o si se mezcla con otros tipos en overloads, la evaluación del fold expression puede no ser válida*/

    return 0;
}