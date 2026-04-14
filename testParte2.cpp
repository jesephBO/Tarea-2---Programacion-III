#include "core_numeric.hpp"
#include <vector>
using namespace core_numeric;

// CLASES

struct Coordenadas {
    double x, y;
    Coordenadas operator-(const Coordenadas& o) const {
        return {x - o.x, y - o.y};
    }

    Coordenadas operator+(const Coordenadas& o) const {
        return {x + o.x, y + o.y};
    }

    bool operator<(const Coordenadas& o) const {
        return x < o.x;
    }
};

struct Vector3D {
    double x, y, z;
    Vector3D operator-(const Vector3D& o) const {
        return {x - o.x, y - o.y, z - o.z};
    }

    Vector3D operator+(const Vector3D& o) const {
        return {x + o.x, y + o.y, z + o.z};
    }

    bool operator<(const Vector3D& o) const {
        return x < o.x;
    }
};




int main() {


    // SUM
    std::cout << "sum_variadic:\n";
    std::cout << sum_variadic(1,2,3,4) << "\n";
    std::cout << sum_variadic(1.5,2.5,3.0) << "\n";
    // MEAN
    std::cout << "mean_variadic:\n";
    std::cout << mean_variadic(1,2,3) << "\n";
    std::cout << mean_variadic(1.0,2.0,3.0) << "\n\n";

    // VARIANCE
    std::cout << "variance_variadic:\n";
    std::cout << variance_variadic(1,2,3,4) << "\n\n";

    // MAX
    std::cout << "max_variadic:\n";
    std::cout << max_variadic(1,5,2,9) << "\n";
    std::cout << max_variadic('a','z','m') << "\n\n";


    std::cout << "Ahora con clases \n\n";

    Coordenadas c1{1,2}, c2{3,4};
    auto csum = sum_variadic(c1,c2);
    std::cout << "Coordenadas sum: (" << csum.x << "," << csum.y << ")\n";

    Vector3D v1{1,2,3}, v2{4,5,6};
    auto vsum = sum_variadic(v1,v2);
    std::cout << "Vector3D sum: (" << vsum.x << "," << vsum.y << "," << vsum.z << ")\n";

    Esfera e1{2}, e2{3}, e3{1};
    auto emax = max_variadic(e1,e2,e3);
    std::cout << "Esfera max r: " << emax.r << "\n";

    std::vector<Esfera> ves{{1},{2},{3}};
    auto tr = transform_reduce(ves, [](Esfera e){ return e.r; });
    std::cout << "transform_reduce Esfera: " << tr << "\n";


   //==================== CASOS INVALIDOS ====================

    //  string + int
    // auto e1 = sum_variadic(std::string("a"), 2);
    // no existe Addable entre string e int
    // Porque el operador + no está definido entre estos tipos

    //  clase sin operator+
    /*
    struct A { int x; };
    auto e2 = sum_variadic(A{1}, A{2});
    */
    // no compila porque Addable requiere operator+

    // max con tipo sin comparación
    /*
    struct B { int x; };
    auto e3 = max_variadic(B{1}, B{2});
    */
    // falta operator< requerido por Comparable

    //  transform_reduce con tipo no sumable
    /*
    struct C { int x; };
    std::vector<C> v{{1},{2}};
    auto e4 = transform_reduce(v, [](C c){ return c; });
    */
    // no existe operator+ para reducir resultados

    std::cout << "\nFIN DE PRUEBAS\n";

    return 0;
}