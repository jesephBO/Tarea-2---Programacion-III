#include "core_numeric.hpp"
#include "clasesPrueba.h"

int main() {
    vector<int> data1{10,20,30,40,50,60};
    auto v1 = core_numeric::variance(data1);
    cout<<v1<<endl;
    //Al ser datos 'int', cumple con los concepts 'Addable', 'Multiplicable' y 'Divisible' que implica la varianza

    vector<float> data2{5.0,15.0,25.0,30.5,45.5};
    auto v2 = core_numeric::variance(data2);
    cout<<v2<<endl;
    //Al ser datos 'float', cumple con los concepts 'Addable', 'Multiplicable' y 'Divisible' que implica la varianza

    vector<string> data3{"a","b","c"};
    //auto v3 = core_numeric::variance(data3);
    /*Falla el concept 'Mutiplicable' ya que los strings no se pueden multiplicar entre si. Asimismo, fallaria en el
     *concept Divisible por el mismo motivo*/

    vector<char> data4{'N','U','E','S','T','R','O'};
    //auto v4 = core_numeric::variance(data4);
    /*Falla en el concept 'Multiplicable' ya que la multiplicacion de strings devuelve un entero; sin embargo, el concept
     *requiere que la operacion devuelva el mismo tipo de valor que los inputs. Por el mismo motivo falla en el concept
     *'Divisible' y 'Addable'*/

    vector<Coordenadas> data6{{10,20},{5,15},{9,19},{3,13}};
    auto v6 = core_numeric::variance(data6);
    cout<<v6;
    /*Se puede aplicar correctamente la funcion 'variance' a objetos de la clase 'Coordenadas' ya que estos cuentan con
     *una sobrecarga de los operadores '+','*' y division entre 'size_t'. Por lo cual, cumple con los concepts 'Addable',
     *'Multiplicable' y 'Divisible'*/

    return 0;
}
