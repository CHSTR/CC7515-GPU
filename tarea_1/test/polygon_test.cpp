#include <gtest/gtest.h>
#include "../include/Polygon/polygon.hpp"
#include "../include/Vector/vector.hpp"
#include "../include/Point/point.hpp"

using namespace std;

// Testeamos la clase Polygon
class PolygonTest : public ::testing::Test
{
protected:
    // Creamos objetos de tres tipos diferentes
    Polygon<int> intPolygon;
    Polygon<float> floatPolygon;
    Polygon<double> doublePolygon;

    // Inicializamos los objetos antes de cada test
    PolygonTest() : intPolygon({Point<int>(-86, -86), Point<int>(-50, 50), Point<int>(-10, -10), Point<int>(0, 0)}),
                    floatPolygon({Point<float>(0.5, 0.5), Point<float>(1.5, -10.0), Point<float>(2.5, -25.0), Point<float>(3.5, 3.0)}),
                    doublePolygon({Point<double>(0.0, 0.0), Point<double>(1.0, 1.0), Point<double>(2.0, 2.0), Point<double>(3.0, 3.0),
                                   Point<double>(4.0, 4.0)}) {}

    // Inicializamos los objetos antes de cada test
    void SetUp() override
    {
        // Creamos los Polygones de diferentes tipos
        std::vector<Point<int>> intPolygon = {Point<int>(-86, -86), Point<int>(-50, 50), Point<int>(-10, -10), Point<int>(0, 0)};
        std::vector<Point<float>> floatPolygon = {Point<float>(0.5, 0.5), Point<float>(1.5, -10.0), Point<float>(2.5, -25.0), Point<float>(3.5, 3.0)};
        std::vector<Point<double>> doublePolygon = {Point<double>(0.0, 0.0), Point<double>(1.0, 1.0), Point<double>(2.0, 2.0), Point<double>(3.0, 3.0),
                                                    Point<double>(4.0, 4.0)};
    }
};

// Testeamos la cantidad de puntos que tiene el poligono
TEST_F(PolygonTest, TestGetPoints)
{
    // Comprobamos que la cantidad de puntos es la esperada
    EXPECT_EQ(intPolygon.get_points(), 4);
    EXPECT_EQ(floatPolygon.get_points(), 4);
    EXPECT_EQ(doublePolygon.get_points(), 5);
}

// Testeamos el metodo add_point para agregar un punto al final del poligono
TEST_F(PolygonTest, TestAddPoint)
{
    // Agregamos un punto al poligono
    intPolygon.add_point(Point<int>(86, 86));
    floatPolygon.add_point(Point<float>(-86.86, -86.86));
    doublePolygon.add_point(Point<double>(-86.86, -86.86));

    // Comprobamos que la cantidad de puntos es la esperada
    EXPECT_EQ(intPolygon.get_points(), 5);
    EXPECT_EQ(floatPolygon.get_points(), 5);
    EXPECT_EQ(doublePolygon.get_points(), 6);

    // Ahora comprobaremos que el punto agregado se encuentra en la ultima posicion
    EXPECT_TRUE(intPolygon[intPolygon.get_points() - 1] == Point<int>(86, 86));
    EXPECT_TRUE(floatPolygon[floatPolygon.get_points() - 1] == Point<float>(-86.86, -86.86));
    EXPECT_TRUE(doublePolygon[doublePolygon.get_points() - 1] == Point<double>(-86.86, -86.86));
}

// Testeamos el metodo is_counter_clockwise para determinar la dirección
TEST_F(PolygonTest, TestIsCounterClockwise)
{
    // Comprobamos que el poligono es counter clockwise
    EXPECT_FALSE(intPolygon.is_counter_clockwise());
    EXPECT_TRUE(floatPolygon.is_counter_clockwise());
    EXPECT_FALSE(doublePolygon.is_counter_clockwise());
}

// Testeamos el operador [] de la clase Polygon
TEST_F(PolygonTest, TestOperatorBracket)
{
    // Comprobamos que los valores de los puntos son los esperados
    EXPECT_TRUE(intPolygon[0] == Point<int>(-86, -86));
    EXPECT_TRUE(intPolygon[1] == Point<int>(-50, 50));
    EXPECT_TRUE(intPolygon[2] == Point<int>(-10, -10));
    EXPECT_TRUE(intPolygon[3] == Point<int>(0, 0));

    EXPECT_TRUE(floatPolygon[0] == Point<float>(0.5, 0.5));
    EXPECT_TRUE(floatPolygon[1] == Point<float>(1.5, -10.0));
    EXPECT_TRUE(floatPolygon[2] == Point<float>(2.5, -25.0));
    EXPECT_TRUE(floatPolygon[3] == Point<float>(3.5, 3.0));

    EXPECT_TRUE(doublePolygon[0] == Point<double>(0.0, 0.0));
    EXPECT_TRUE(doublePolygon[1] == Point<double>(1.0, 1.0));
    EXPECT_TRUE(doublePolygon[2] == Point<double>(2.0, 2.0));
    EXPECT_TRUE(doublePolygon[3] == Point<double>(3.0, 3.0));
    EXPECT_TRUE(doublePolygon[4] == Point<double>(4.0, 4.0));
}

// Testeamos el operador inerstion << de la clase Polygon
TEST_F(PolygonTest, TestOperatorInsertion)
{
    // Creamos un stream de salida
    std::ostringstream os;

    // Insertamos el objeto Point en el stream
    os << intPolygon;
    // Comprobamos que los valores de los puntos son los esperados
    EXPECT_EQ(os.str(), "[(-86, -86)(-50, 50)(-10, -10)(0, 0)]");
    os.str("");

    // Sobre escribimos el stream de salida
    os << floatPolygon;
    EXPECT_EQ(os.str(), "[(0.5, 0.5)(1.5, -10)(2.5, -25)(3.5, 3)]");
    os.str("");

    // Sobre escribimos el stream de salida
    os << doublePolygon;
    EXPECT_EQ(os.str(), "[(0, 0)(1, 1)(2, 2)(3, 3)(4, 4)]");
}
