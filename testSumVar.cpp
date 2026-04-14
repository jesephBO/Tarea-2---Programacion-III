#include "core_numeric.hpp"
#include "clasesPrueba.h"
using namespace core_numeric;

int main() {
    cout << "TEST SUM VARIADIC \n";

    cout << sum_variadic(1,2,3) << "\n";
    cout << sum_variadic(1.5,2.5) << "\n";

    Coordenadas c1{1,2}, c2{3,4};
    cout << "Coord: " << sum_variadic(c1,c2) << "\n";

    Vector3D v1{1,2,3}, v2{4,5,6};
    cout << "Vector3D: " << sum_variadic(v1,v2) << "\n";

    Complejo z1{1,2}, z2{3,4};
    cout << "Complejo: " << sum_variadic(z1,z2) << "\n";


    /*sum_variadic(string("a"), string("b"));
     *no funciona porque string no cumple el concept Restable,
     *ya que no existe operator- entre strings, y la función exige (Addable && Restable)
     *para todos los tipos Args..., por lo cual el template se descarta en la resolución de sobrecarga*/


    /* sum_variadic(vector<int>{1,2}, vector<int>{3,4});
     * falla porque vector<int> no define operator+ ni operator-,
     * por lo que no cumple los concepts Addable ni Restable,
     * haciendo inválida la instanciación del template*/

    
    return 0;
}