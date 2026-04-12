//
// Created by burgo on 12/4/2026.
//

#ifndef TAREA2_CORE_NUMERIC_H
#define TAREA2_CORE_NUMERIC_H
#include <iostream>
#include <concepts>
#include <iterator>
#include <cmath>
#include <vector>

using namespace std;


template<typename C>
concept Iterable = requires (C c)
{
    begin(c);
    end(c);
};

template<typename T>
concept Addable = requires(T a, T b)
{
    {a+b} -> same_as<T>;
};

template<typename T>
concept Divisible = requires(T a, size_t n)
{
    {a/n}->same_as<T>;
};

template<typename T>
concept Comparable = requires(T a, T b)
{
    {a>b}->convertible_to<bool>;
};

template<typename T>
concept Multiplicable = requires (T a, T b)
{
    {a*b}->same_as<T>;
};

template<typename T>
concept Restable = requires (T a, T b)
{
  {a-b}-> same_as<T>;
};


namespace core_numeric {
    template <Iterable C>
    requires Addable<typename C::value_type>
    auto sum(const C& container) {
        using T = typename C::value_type;
        T result{};
        for (const auto& value: container)
            result = result + value;
        return result;
    }

    template<Iterable D>
    requires Divisible<typename D::value_type>
    auto mean(const D& container) {
        using T = typename D::value_type;
        auto numerador = sum(container);
        auto n = distance(begin(container),end(container));
        return numerador/static_cast<T>(n);
    }

    template<Iterable E>
    requires Addable<typename E::value_type>
    auto variance(const E& container) {
        auto promedio = mean(container);
        using T = typename E::value_type;
        T sumatoria{};
        for (const auto& i:container)
            sumatoria+=(i-promedio)*(i-promedio);
        auto n = distance(begin(container),end(container));
        return sumatoria/static_cast<T>(n);
    }

    template<Iterable F>
    requires Comparable<typename F::value_type>
    auto max(const F& container) {
        auto it = begin(container);
        auto resultado = *it;
        ++it;
        for (;it!=container(end);++it)
            if (*it>resultado)
                resultado = *it;
        return resultado;
        }
    }




#endif //TAREA2_CORE_NUMERIC_H
