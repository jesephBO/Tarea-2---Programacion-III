#include <iostream>
#include <vector>
#include "core_numeric.hpp"
struct Punto {
    int x;

    Punto operator+(const Punto& other) const {
        return {x + other.x};
    }

    Punto operator/(std::size_t n) const {
        return {x / static_cast<int>(n)};
    }

    bool operator<(const Punto& other) const {
        return x < other.x;
    }
};

struct NoSumable {
    int x;
};

int main() {
    int main() {

    std::vector<int> v1{1,2,3};
    auto r1 = core_numeric::transform_reduce(v1, [](int x){ return x * x; });

    auto s1 = core_numeric::sum_variadic(1,2,3,4);
    auto s2 = core_numeric::mean_variadic(1.0,2.0,3.0,4.0);
    auto s3 = core_numeric::variance_variadic(1,2,3,4);
    auto s4 = core_numeric::max_variadic(1,2,3,4);

    std::vector<Punto> vp{{1},{2},{3}};
    auto r2 = core_numeric::transform_reduce(vp, [](Punto p){ return p; });

    std::cout << "transform_reduce int: " << r1 << "\n";
    std::cout << "sum_variadic: " << s1 << "\n";
    std::cout << "mean_variadic: " << s2 << "\n";
    std::cout << "variance_variadic: " << s3 << "\n";
    std::cout << "max_variadic: " << s4 << "\n";
    std::cout << "transform_reduce Punto: " << r2.x << "\n";

    //  Tipos incompatibles
    // auto e1 = core_numeric::sum_variadic(std::string("a"), 2);
    // Falla: std::common_type_t no puede deducir un tipo común entre string e int

    //  Tipo sin operador +
    // auto e2 = core_numeric::sum_variadic(NoSumable{1}, NoSumable{2});
    // Falla: concept Addable no se cumple (no existe operador +)

    // Tipo sin comparación
    // auto e3 = core_numeric::max_variadic(NoSumable{1}, NoSumable{2});
    // Falla: concept Comparable no se cumple (no existe operador <)

    //transform_reduce con tipo no sumable
    // std::vector<NoSumable> vn{{1},{2}};
    // auto e4 = core_numeric::transform_reduce(vn, [](NoSumable x){ return x; });
    // Falla: Addable<ResultType> no se cumple

    //  mean_variadic con enteros
    // auto e5 = core_numeric::mean_variadic(1,2,3,4);
    // Falla: Divisible<int> no se cumple (int / size_t no retorna int)

    return 0;
}
    return 0;
}
