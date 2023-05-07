#include <iostream>
#include "Point/point.hpp"
#include "Vector/vector.hpp"
#include "Polygon/polygon.hpp"
#include <cmath>
#include <utility>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    // Se crean los puntos con diferentes tipos de datos
    Point<int> p1(5, 5);
    Point<int> p2(3, 4);
    Point<float> p3(2.0, -55.2);
    Point<float> p4(4.2, 2.1);
    Point<int> p5(0, 0);
    Point<float> p6(8.0, 155.2);

    // Se imprimen los puntos
    std::cout << "p1: " << p1 << std::endl;
    std::cout << "p2: " << p2 << std::endl;
    std::cout << "p3: " << p3 << std::endl;
    std::cout << "p4: " << p4 << std::endl;
    std::cout << "p5: " << p5 << std::endl;
    std::cout << "p6: " << p6 << std::endl;

    if (p1 == p5)
    {
        std::cout << "p1 == p5: True " << std::endl;
    }
    else
    {
        std::cout << "p1 == p5: False " << std::endl;
    }

    std::cout << "p1: " << p1 << std::endl;
    p1 = p2;
    std::cout << "p1 = p2, ahora p1: " << p1 << std::endl;

    // Se calcula la distancia entre dos puntos
    std::cout << "p5.distance(p2): " << p5.distance(p2) << std::endl;
    std::cout << "p6.distance(p4): " << p6.distance(p4) << std::endl;

    // Se obtienen los valores de los puntos
    std::cout << "p2[0]: " << p2[0] << std::endl;
    std::cout << "p2[1]: " << p2[1] << std::endl;
    // std::cout << "p2[2]: " << p2[2] << std::endl;

    // Inicializar un vector
    Vector<int> v1(6, 6);
    Vector<float> v2(1.0, 2.3);
    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    Vector<float> v3(2.0, 1.0);
    std::cout << "v3: " << v3 << std::endl;

    // magnitud y producto punto
    std::cout << "v3.dot(v2): " << v3.dot_product(v2) << std::endl;
    std::cout << "|v2|: " << v2.magnitude() << std::endl;

    // sobrecargar salida de datos
    std::cout << "v1: " << v1 << std::endl;

    // sobrecargar suma y resta de vectores
    std::cout << "v2 + v3: " << v2 + v3 << std::endl;
    std::cout << "v2 - v3: " << v2 - v3 << std::endl;

    // sobrecargar escalar un vector
    std::cout << "v3 * 3: " << v3 * 3.0 << std::endl;
    std::cout << "3 * v3: " << 3.0 * v3 << std::endl;

    // sobrecargar operador =
    v2 = v3;
    std::cout << "v2 = v3: " << v2 << std::endl;

    // Inicializar un vector a partir de un punto
    Vector<float> v5(Point<float>(4.3, 1.2));
    std::cout << "v5 inicializado a partir de Point<float>(4.3, 1.2): " << v5 << std::endl;

    float cross_v2_v5 = v2.dot_product(v5);
    // producto cruz
    std::cout << "v2.cross(v5): " << cross_v2_v5 << " , lo cual se interpreta como el area del paralelograma que forman estos dos vectores" << std::endl;

    std::cout << "Inicializando vector de puntos con la siguiente información..." << std::endl;

    std::vector<Point<int>> input = {Point<int>(0, 0), Point<int>(1, 1), Point<int>(2, 2), Point<int>(3, 3)};
    Polygon<int> polygon(input);
    std::cout << "polygon: " << polygon << std::endl;

    // vemos punto por punto iterando por la lista usada para inicializar el poligono
    std::cout << "Vemos punto por punto iterando por la lista usada para inicializar el poligono" << std::endl;
    for (int i = 0; i < input.size(); i++)
    {
        std::cout << "input[" << i << "]: " << input[i] << std::endl;
    }

    polygon.add_point(Point<int>(7, 7));
    std::cout << "Agregamos un nuevo punto Point<int>(7,7): " << polygon << std::endl;
    std::cout << "Cuál es el número de puntos del  poligono? " << polygon.get_points() << std::endl;
    std::cout << "Cuál es el punto 2 del  poligono? " << polygon[1] << std::endl;
    std::cout << "Cuál es el punto 5 del  poligono? " << polygon[4] << std::endl;

    // determinar counterclock wise
    std::cout << "Determinar si el poligono esta en dirección en contra del reloj..." << std::endl;
    if (polygon.is_counter_clockwise())
    {
        std::cout << "polygon.isCounterclockwise(): True" << std::endl;
    }
    else
    {
        std::cout << "polygon.isCounterclockwise(): False" << std::endl;
    }
    std::cout << "De nuevo los pts del poligono: " << polygon << std::endl;

    return 0;
}
