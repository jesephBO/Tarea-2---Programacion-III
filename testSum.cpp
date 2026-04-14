#include "core_numeric.hpp"
#include "clasesPrueba.h"

int main() {
    vector<float> data1{1.0,2.0,3.0};
    auto v1 = core_numeric::sum(data1);
    cout<<v1<<endl;
    //Al ser datos 'float' cumplen perfectamente con el concept 'Addable' y 'Restable'

    vector<int> data2{15,25,35,55,65};
    auto v2 = core_numeric::sum(data2);
    cout<<v2<<endl;
    //Al ser datos 'int' cumplen perfectamente con el concept 'Addable' y 'Restable'

    vector<string> data3{"Hola","Mundo"};
    //auto v3 = core_numeric::sum(data3);
    /*En este caso, si bien cumple el concept 'Addable' por la concatenacion de strings, no cumple con el concept
    *'Restable' ya que los strings no se pueden restar. Como se muestra en el ejemplo de la tarea*/

    vector<Esfera> data4{{4,6,6,2},{5,9,8,3},{10,10,10,7}};
    auto v4 = core_numeric::sum(data4);
    cout<<v4<<endl;
    /*En este caso se puede realizar la funcion suma ya que la clase Esfera tiene definida una sobrecarga del operador
     * '+' y '-', por lo cual se cumple perfectamente el concept 'Addable' y 'Restable'*/

    vector<Estudiante> data5{{"Jean",123,"UTEC"},{"Jeseph",567,"UNI"},{"Angel",999,"UPC"}};
    //auto v5 = core_numeric::sum(data5);
    /*En el caso de la clase Estudiante, no se cumple el concept 'Addable' ya que la clase no tiene definida una
    *sobrecarga del operador '+'. En una situacion real, no se podria juntar la informacion de dos estudiantes en un
    *nuevo estudiante*/

    vector<Matriz10x10> data6{{5,2},{1,0},{7,9},{4,8}};
    auto v6 = core_numeric::sum(data6);
    cout<<v6;
    /*Para este caso, se puede ejecutar con normalidad la funcion suma, ya que la clase Matriz10x10 tiene implementada
     una sobrecarga del operador '+' y '-', por lo cual se cumplen con los concepts 'Addable' y 'Restable'*/
    return 0;

}