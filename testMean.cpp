#include "core_numeric.hpp"
#include "clasesPrueba.h"


int main() {
    vector<double> data1{18.19,46.12,66.77,12.23,81.18};
    auto v1 = core_numeric::mean(data1);
    cout<<v1<<endl;
    //Al ser datos 'double' cumplen perfectamente con los concepts 'Divisible' y 'Addable'

    vector<char> data2{'B','A','R','C','E','L','O','N','A'};
    //auto v2 = core_numeric::mean(data2);
    /*En primer lugar, al ser datos 'char' no cumplen con el concept 'Addable', ya que al sumarlos retornan un 'int';
     *no obstante, el concept requiere que la salida sea del mismo tipo de dato que los inputs. Del mismo modo, tampoco
     *cumplen con el conept 'Divisible', ya que el resultado es un dato de tipo 'int'*/

    vector<int> data3{1,2,3,4,5,6};
    auto v3 = core_numeric::mean(data3);
    cout<<v3<<endl;
    //Al ser datos 'int' cumplen perfectamente con los concepts 'Divisible' y 'Addable'

    vector<Complejo> data4{{1,2},{3,4},{5,6}};
    auto v4 = core_numeric::mean(data4);
    cout<<v4<<endl;
    /*En este caso, se puede aplicar el promedio a la clase 'Complejo' ya que en esta clase se ha sobrecargado los
     * operadores de suma y division por 'size_t'. Por tanto, la clase cumple con los concepts 'Addable' y 'Divisible'*/

    vector<Matriz10x10> data5{{0,1},{3,6},{7,8},{10,11}};
    //auto v5 = core_numeric::mean(data5);
    /*Para el caso de la clase Matriz10x10, si cumple con el concept 'Addable' ya que la funcion tiene una
     * sobrecarga del operador '+', lo que permite sumar objetos del mismo tipo. Sin embargo, no cumple con el concept
     * 'Divisible' ya que la clase no tiene una sobrecarga para dividir un objeto propio entre un 'size_t'*/

    vector<Vector3D> data6{{1,2,3},{7.8,6.5,9.9},{10,20,30},{3.6,12.2,5.12}};
    auto v6 = core_numeric::mean(data6);
    cout<<v6;
    /*En este caso, se puede aplicar apropiadamente la funcion 'mean' a objetos de la clase 'Vector3D', ya que estos
     *cuentan con una sobrecarga de los operadores '+' y division entre 'size_t'. Por tanto, se cumple con los concepts
     *'Divisible' y 'Addable'*/
    return 0;
}