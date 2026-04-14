#include "core_numeric.hpp"
#include "clasesPrueba.h"

int main() {
    vector<double> data1{1,2.7,0.3,99.97,99,10.10};
    auto v1 = core_numeric::max(data1);
    cout<<v1<<endl;

    vector<string> data2{"hola","buenas tardes","gracias","por favor",};
    //auto v2 = core_numeric::max(data2);
    //Falla el concept 'Restable' ya que las entradas son strings, es decir no son valores numericos. Como se muestra en el ejemplo

    vector<char> data3{'U','T','E','C'};
    //auto v3 = core_numeric::max(v3);
    /*Falla el concept 'Restable' ya que las entradas son chars y al restarlo devuelve un int. Sin embargo en el
     *concept se especifico que el resultado debe ser el mismo tipo de valor que los inputs*/

    vector<Matriz10x10> data4{{1,2},{3,4},{5,6}};
    auto v4 = core_numeric::max(data4);
    cout<<v4;
    /*Se puede aplicar correctamente la funcion 'max' ya que la clase 'Matriz10x10' tiene implementado una funcion
     *para comparar sus objetos. Esto se da a traves de la suma de todos los valores de la matriz y cumple con el
     *concept 'Comparable'. Asimismo, tiene una sobrecarga del operador '-', lo cual le permite cumplir con el concept
     *'Restable'*/

    vector<Estudiante> data5{{"Luis",101,"UTEC"},{"Juan",191,"UTEC"},{"Zamir",898,"ULIMA"},{"Seba",100,"UPC"}};
    //auto v5 = core_numeric::max(data5);
    /*Falla el concept 'Comparable' ya que la clase Estudiante no tiene implementado algun metodo o sobrecarga para
     *comparar objetos de la misma clase. En un contexto real no se puede determinar el máximo entre un conjunto de
     *estudiantes*/

    return 0;
}