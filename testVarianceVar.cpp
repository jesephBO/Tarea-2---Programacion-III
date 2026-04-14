#include "core_numeric.hpp"
#include "clasesPrueba.h"
using namespace core_numeric;

int main() {
    cout << "TEST VARIANCE VARIADIC\n";

    cout << variance_variadic(1,2,3,4) << "\n";

    Vector3D v1{1,2,3}, v2{2,3,4};
    cout << "Vector3D: " << variance_variadic(v1,v2) << "\n";

    Coordenadas c1{1,2}, c2{2,3};
    cout << "Coord: " << variance_variadic(c1,c2) << "\n";

    Complejo z1{1,1}, z2{2,2};
    cout << "Complejo: " << variance_variadic(z1,z2) << "\n";

    /*variance_variadic(v1, c1);
     *falla porque los tipos no son compatibles con las operaciones (- y *),
     *necesarias para el cálculo de varianza, por lo que la expresión del fold no es válida.
     *variance_variadic(string("a"), string("b"));
     *falla porque 'string' no soporta operator- ni operator*,
     *requeridos para el cálculo de varianza en la expresión del fold*/
    
    return 0;
}
