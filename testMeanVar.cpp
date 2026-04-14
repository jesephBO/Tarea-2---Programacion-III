#include "core_numeric.hpp"
#include "clasesPrueba.h"
using namespace core_numeric;

int main() {
    cout << "TEST MEAN VARIADIC \n";

    cout << mean_variadic(1,2,3) << "\n";
    cout << mean_variadic(1.5,2.5,3.0) << "\n";

    Coordenadas c1{2,4}, c2{6,8};
    cout << "Coord: " << mean_variadic(c1,c2) << "\n";

    Vector3D v1{2,4,6}, v2{6,8,10};
    cout << "Vector3D: " << mean_variadic(v1,v2) << "\n";

    Complejo z1{2,2}, z2{4,4};
    cout << "Complejo: " << mean_variadic(z1,z2) << "\n";


    /* mean_variadic(string("a"), string("b"));
     * falla porque 'string' no cumple el concept Divisible,
     * ya que no existe divisibilidad para strings, y mean_variadic exige que el tipo pueda dividirse
     * por lo que el template no se instancia.
     * mean_variadic();
     * falla porque no puede tener argumentos nulos. requires (sizeof...(Args) > 0)*/

    cout << "\nFIN TEST MEAN\n";
    return 0;
}
