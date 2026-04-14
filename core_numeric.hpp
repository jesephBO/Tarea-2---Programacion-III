#ifndef TAREA2_CORE_NUMERIC_H
#define TAREA2_CORE_NUMERIC_H
#include <iostream>
#include <concepts>
#include <iterator>
#include <cmath>
#include <vector>
#include <random>
using namespace std;

//Definimos el namespace core_numeric con las funciones plantilla y conceptos pertinentes
namespace core_numeric {
    //Se define el concept iterable para verificar que los inputs sean algun tipo de contenedor
    template<typename C>
    concept Iterable = requires (C c)
    {
        begin(c);
        end(c);
    };

    /*Se define el concept Addable para verificar que las entradas puedan ser sumadas y se mantenga el mismo tipo de dato
    El gran problema con este concept es que los strings tambien cumplen la condicion, ya que se pueden concatenar.
    Este problema lo solucionaremos a través de otro concept que verifique que la entrada sea numerica*/
    template<typename T>
    concept Addable = requires(T a, T b)
    {
        {a+b}->same_as<T>;
    };

    /*Se define el concept 'Divisible' para verificar que las entradas se puedan dividir.
    No se considera que el resultado sea del mismo tipo que el dividendo(a), ya que el divisor(n) al ser size_t cambia
    el tipo de dato del resultado en ciertos casos. Por ejemplo int/size_t -> size_t
    Por tanto, el concept solo requiere que el tipo dato del resultado se pueda convertir al tipo de dato del dividendo*/
    template<typename T>
    concept Divisible = requires(T a, size_t n)
    {
        {a/n}->convertible_to<T>;
    };

    /*Se define el concept 'Comparable' para verificar que dos entradas pueden ser comparadas entre si
    Al igual que en 'Addable', los strings cumplen con la condición impuesta. Esta situación se soluciona al
    impementar otro concept que verifique que las entradas sean numericas*/
    template<typename T>
    concept Comparable = requires(T a, T b)
    {
        {a>b}->convertible_to<bool>;
        {a<b}->convertible_to<bool>;
        {a==b}->convertible_to<bool>;
    };

    /*Se define el concept 'Multiplicable' para verificar que las entradas puedan ser multiplicadas entre si,
    y se mantenga el mismo tipo de dato*/
    template<typename T>
    concept Multiplicable = requires (T a, T b)
    {
        {a*b}->same_as<T>;
    };

    /*Se define el concept 'Restable' para verificar que las entradas se puedan restar entre si,
    y se mantenga el mismo tipo de dato*/
    template<typename T>
    concept Restable = requires (T a, T b)
    {
        {a-b}-> same_as<T>;
    };

    /*Para el desarrollo de las funciones,si bien podríamos incluir restricciones generales en todos los caos,
     en principio solo queremos restricciones pertinenes para el tipo de operación. Asimismo, queremos alinearnos a
     las indicaciones de la tarea. No obstante, tambien se consideran ciertas excepciones importantes para algunas
     funciones*/

    /*Para garantizar que las entradas sean numericas incluimos el concept 'Restable', ya que esta es una de las
    operaciones que las entradas textuales no pueden realizar*/
    template <Iterable C>
    requires Addable<typename C::value_type> and Restable<typename C::value_type>
    auto sum(const C& container) {
        using T = typename C::value_type;
        T result{};
        for (const auto& value: container)
            result= result + value;
        return result;
    }

    /*Para la funcion 'mean' se requiere que el tipo de valor que almacena el contenedor pueda ser dividio y sumado,
     ya que estas son las operaciones fundamentales para el cauclo de la media(promedio).*/
    template<Iterable D>
    requires Divisible<typename D::value_type>and Addable<typename D::value_type>
    auto mean(const D& container) {
        using T = typename D::value_type;
        auto numerador = core_numeric::sum(container);
        auto denominador = distance(begin(container),end(container));
        if constexpr (is_integral_v<T>)
            return static_cast<double>(numerador)/denominador;
        /*En el caso que el tipo de valor del contenedor sea 'int', casteamos el tipo de dato del numerador a 'double'
         para evitar perder exactitud en la division que realiza el promedio. Si no hicieramos ello, la division se
         podria truncar. Asimismo, evitamos la logica en tiempo de ejecucion, y esta se realiza al compilar.*/
        else
            return numerador/denominador;
        /*Esta segunda opcion se utiliza para datos 'float', 'double', clases, etc. Para este caso podriamos castear
         el denominador al tipo de dato del contenedor y asi mantener una homogeneidad; no obstante, al trabajar con
         clases, no todas van tener un constructor que reciba un solo dato, lo cual haria imposible la operacion de
         division.*/
    }

    /*Para la funcion 'variance' se utilizan los concepts 'Addable', 'Multiplicable' y 'Divisible' ya que son las
    operaciones fundamentales que se realizan para calcular la varianza. Aqui ya no consideramos Restable porque
    los concepts usados ya limitan la entrada de inputs de texto*/
    template<Iterable E>
    requires Multiplicable<typename E::value_type> and Divisible<typename E::value_type>and Addable<typename E::value_type>
    auto variance(const E& container) {
        auto promedio = mean(container);
        using T = typename E::value_type;
        T sumatoria{};
        for (const auto& i:container)
            sumatoria=sumatoria + (i-promedio)*(i-promedio);
        auto n = distance(begin(container),end(container));
        if constexpr (is_integral_v<T>)
            return static_cast<double>(sumatoria)/n;
        else
            return sumatoria/n;
    }

    /*Para la funcion 'max' se requiere, primordialmente, del concept 'Comparable' para verificar que las entradas
     son del mismo tipo y se pueden comparar entre si. Ademas, incluimos el concept restable para garantizar que las
     entradas sean numericas*/
    template<Iterable F>
    requires Comparable<typename F::value_type> and Restable<typename F::value_type>
    auto max(const F& container) {
        auto it = begin(container);
        auto resultado = *it;
        ++it;
        for (;it!=end(container);++it)
            if (*it>resultado)
                resultado = *it;
        return resultado;
        }

    // Transform Reduce
    template <typename C, typename Func>
    // Se asegura que el contenedor sea iterable y que los valores puedan combinarse con +.
    // Además, valida que la función f(x) pueda sumarse consigo misma,
    // ya que el resultado acumulado se construye con result + f(x).
    // Esto evita errores de tipos incompatibles en la reducción.
    requires Iterable<C> &&
         Addable<typename C::value_type> &&
         Restable<typename C::value_type> &&
         requires(Func f, typename C::value_type x) {
        { f(x) + f(x) };
         }
    auto transform_reduce(const C& cont, Func f) {
        using T = typename C::value_type;
        using ResultType = std::decay_t<std::invoke_result_t<Func, T>>;
        auto it = begin(cont);
        auto last = end(cont);
        if (it == last) return ResultType{};
        ResultType result = f(*it);
        ++it;
        for (; it != last; ++it)
            result = result + f(*it);
        return result;
    }

    // Sum Variadic
    template <typename... Args>
    //Se usa para asegurar que todos los tipos Args soporten la operación de suma (+),
    // ya que el fold expression (args + ...) depende de que exista operator+.
    // Además, sizeof...(Args) > 0 evita llamadas vacías que no tienen sentido matemático.
    requires (sizeof...(Args) > 0) &&
             (Restable<Args> && ...) &&
             (Addable<Args> && ...)
    auto sum_variadic(Args... args) {
        return (args + ...);
    }

    // Mean Variadic
    template <typename... Args>
    // Garantiza que todos los tipos soporten la suma (+) para construir el total.
    // No valida directamente la división, pero asume que el resultado puede dividirse entre un entero.
    // Esto evita instanciar el template con tipos que no pueden sumarse.
    requires (sizeof...(Args) > 0) &&
         (Addable<Args> && ...)
    auto mean_variadic(Args... args) {
        using T = std::common_type_t<Args...>;
        T sum = (args + ...);
        std::size_t n = sizeof...(Args);
        if constexpr (std::is_arithmetic_v<T>) {
            return sum / static_cast<T>(n);
        } else {
            // para clases: usa operator/(size_t)
            return sum / n;
        }
    }

    // Variance Variadic
    template <typename... Args>
    // En variance, el uso de Restable puede considerarse redundante, ya que la fórmula implementada no depende de una resta directa entre elementos del contenedor en el concepto de restricción,
    // sino que la operación clave es (i - promedio), donde el promedio ya es del mismo tipo y la resta se asume válida implícitamente dentro de la expresión.
    // Sin embargo, el requerimiento real mínimo sería que el tipo soporte -, *, + y división, por lo que incluir Restable solo es parcialmente representativo del conjunto completo de operaciones necesarias.
    auto variance_variadic(Args... args) {
        auto m = (args + ...) / sizeof...(Args);
        auto sum = (((args - m) * (args - m)) + ...);
        return sum / sizeof...(Args);
    }

    // Max Variadic
    template <typename T, typename... Args>
    // Se usa Comparable para permitir la comparación entre valores usando <.
    // Esto es necesario para determinar el máximo en el fold expression.
    // Restable no es estrictamente necesario aquí porque no se usa operator-.
    requires (Comparable<T> && (Comparable<Args> && ...)) &&
             (Restable<T> && (Restable<Args> && ...))
    auto max_variadic(T first, Args... args) {
        using Common = std::common_type_t<T, Args...>;
        Common max_val = first;
        ((max_val = (max_val < args ? args : max_val)), ...);
        return max_val;
    }
}

#endif //TAREA2_CORE_NUMERIC_H
