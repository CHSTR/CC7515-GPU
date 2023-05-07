#include <gtest/gtest.h>
#include "../include/Point/point.hpp"

using namespace std;

// Testeamos la clase Point
class PointTest : public ::testing::Test
{
protected:
  // Creamos objetos de diferentes tipos
  Point<int> intPoint;
  Point<float> floatPoint;
  Point<double> doublePoint;
  Point<long int> longIntPoint;

  // Inicializamos los objetos antes de cada test
  PointTest() : intPoint(1, 2), floatPoint(3.5, 4.2), doublePoint(-5.1, 3.3), longIntPoint(-8, 6) {}

  // Inicializamos los objetos antes de cada test
  void SetUp() override
  {
    intPoint = Point<int>(1, 2);
    floatPoint = Point<float>(3.5, 4.2);
    doublePoint = Point<double>(-5.1, 3.3);
    longIntPoint = Point<long int>(-8, 6);
  }
};

// Testeamos el método distance de la clase Point
TEST_F(PointTest, TestDistance)
{
  // Creamos un objeto Point para pasar como argumento
  // sqrt(pow(p.coords.first - coords.first, 2) + pow(p.coords.second - coords.second, 2));
  // sqrt((-2.5 - -5.1)^2 + (6.7 - 3.3)^2) = 4,28
  Point<double> p(-2.5, 6.7);

  // Comprobamos que la distancia entre los puntos es la esperada
  // con una tolerancia de 0.001
  EXPECT_NEAR(doublePoint.distance(p), 4.280186912, 0.001);
}

// Testeamos el operador []
TEST_F(PointTest, TestOperatorBracket)
{
  // Comprobamos que los valores de los puntos son los esperados
  EXPECT_EQ(intPoint[0], 1);
  EXPECT_EQ(intPoint[1], 2);
  EXPECT_FLOAT_EQ(floatPoint[0], 3.5);
  EXPECT_FLOAT_EQ(floatPoint[1], 4.2);
  EXPECT_DOUBLE_EQ(doublePoint[0], -5.1);
  EXPECT_DOUBLE_EQ(doublePoint[1], 3.3);
  EXPECT_EQ(longIntPoint[0], -8);
  EXPECT_EQ(longIntPoint[1], 6);
}

// Testeamos el operador = de la clase Point
TEST_F(PointTest, TestOperatorAssign)
{
  // Creamos un objeto Point para asignar
  Point<int> p(3, 4);

  // Asignamos el objeto Point creado al objeto Point de prueba
  intPoint = p;

  // Comprobamos que los valores del objeto de prueba son los esperados
  EXPECT_EQ(intPoint[0], 3);
  EXPECT_EQ(intPoint[1], 4);

  // En el caso de asignar un objeto Point de un tipo diferente (int = float), se mantendrá el tipo original (int)
  // No así si creamos un objeto con un tipo primitivo distinto al original (Point<float> (int) = float)
  intPoint = doublePoint;
  EXPECT_EQ(intPoint[0], -5);
  EXPECT_EQ(intPoint[1], 3);

  Point<double> intPoint = doublePoint;
  EXPECT_DOUBLE_EQ(intPoint[0], -5.1);
  EXPECT_DOUBLE_EQ(intPoint[1], 3.3);
}

// Testeamos el operador == de la clase Point
TEST_F(PointTest, TestOperatorEqual)
{
  // Creamos dos objetos Point iguales
  Point<float> p1(1.2, 3.4);
  Point<float> p2(1.2, 3.4);

  // Comprobamos que los objetos Point son iguales
  EXPECT_TRUE(p1 == p2);

  // Cambiamos uno de los valores y comprobamos que los objetos Point ya no son iguales
  p2 = Point<float>(p1[0], 999);
  EXPECT_FALSE(p1 == p2);
}

// Testeamos el operador << de la clase Point
TEST_F(PointTest, TestOperatorInsertion)
{
  // Creamos un stream de salida
  std::ostringstream os;

  // Insertamos el objeto Point en el stream
  os << intPoint;

  // Comprobamos que la salida es la esperada
  EXPECT_EQ(os.str(), "(1, 2)");
}
