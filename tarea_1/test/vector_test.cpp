#include <gtest/gtest.h>
#include "../include/Vector/vector.hpp"
#include "../include/Point/point.hpp"

using namespace std;

// Testeamos la clase Vector
class VectorTest : public ::testing::Test
{
protected:
  // Creamos objetos de diferentes tipos
  Vector<int> intVector;
  Vector<float> floatVector;
  Vector<double> doubleVector;
  Vector<long int> longIntVector;
  Vector<float> floatPointtoVector;

  // Inicializamos los objetos antes de cada test
  VectorTest() : intVector(1, 2), floatVector(3.5, 4.2), doubleVector(-5.1, 3.9), longIntVector(-8, 6), floatPointtoVector(Point<float>(4.3, 1.2)) {}

  // Inicializamos los objetos antes de cada test
  void SetUp() override
  {
    // Creamos los vectores de diferentes tipos
    intVector = Vector<int>(1, 2);
    floatVector = Vector<float>(3.5, 4.2);
    doubleVector = Vector<double>(-5.1, 3.9);
    longIntVector = Vector<long int>(-8, 6);
    // Se crea un vector a partir de un objeto Point
    floatPointtoVector = Vector<float>(Point<float>(4.3, 1.2));
  }
};

// Testeamos el método magnitude de la clase Vector
TEST_F(VectorTest, TestMagnitude)
{
  // Comprobamos que la magnitud de los vectores es la esperada con una tolerancia de 0.001
  EXPECT_NEAR(intVector.magnitude(), sqrt(pow(1, 2) + pow(2, 2)), 0.001);
  EXPECT_NEAR(floatVector.magnitude(), sqrt(pow(3.5, 2) + pow(4.2, 2)), 0.001);
  EXPECT_NEAR(doubleVector.magnitude(), sqrt(pow(-5.1, 2) + pow(3.9, 2)), 0.001);
  EXPECT_NEAR(longIntVector.magnitude(), sqrt(pow(-8, 2) + pow(6, 2)), 0.001);
  EXPECT_NEAR(floatPointtoVector.magnitude(), sqrt(pow(4.3, 2) + pow(1.2, 2)), 0.001);
}

TEST_F(VectorTest, TestDotProduct)
{
  // Creamos un objeto Vector para pasar como argumento

  Vector<double> v1(-2.5, 6.7);
  Vector<int> v2(50, 30);
  Vector<float> v3(2.0, 1.0);

  // Comprobamos que el producto punto entre los vectores es el esperado
  // con una tolerancia de 0.001
  EXPECT_DOUBLE_EQ(doubleVector.dot_product(v1), -5.1 * -2.5 + 3.9 * 6.7);
  EXPECT_EQ(intVector.dot_product(v2), 1 * 50 + 2 * 30);
  EXPECT_FLOAT_EQ(floatVector.dot_product(v3), 3.5 * 2.0 + 4.2 * 1.0);
  EXPECT_FLOAT_EQ(floatPointtoVector.dot_product(v3), 4.3 * 2.0 + 1.2 * 1.0);

  // En este caso no es posible realizar el producto punto entre vectores de diferente tipo
}

TEST_F(VectorTest, TestCrossProduct)
{
  // Creamos un objeto Vector para pasar como argumento
  Vector<double> v1(-2.5, 6.7);
  Vector<int> v2(50, 30);
  Vector<float> v3(2.0, 1.0);

  // Comprobamos que el producto cruz entre los vectores es el esperado
  EXPECT_DOUBLE_EQ(doubleVector.cross_product(v1), -5.1 * 6.7 - 3.9 * -2.5);
  EXPECT_EQ(intVector.cross_product(v2), 1 * 30 - 2 * 50);
  EXPECT_FLOAT_EQ(floatVector.cross_product(v3), 3.5 * 1.0 - 4.2 * 2.0);
  EXPECT_FLOAT_EQ(floatPointtoVector.cross_product(v3), 4.3 * 1.0 - 1.2 * 2.0);

  // En este caso no es posible realizar el producto cruz entre vectores de diferente tipo
}

TEST_F(VectorTest, TestOperatorPlus)
{
  Vector<double> v1(-2.5, 6.7);
  Vector<int> v2(50, 30);
  Vector<float> v3(2.0, 1.0);

  // Comprobamos que la suma entre los vectores es la esperada
  EXPECT_EQ(intVector + v2, Vector<int>(1 + 50, 2 + 30));
  EXPECT_EQ(v2 + intVector, Vector<int>(1 + 50, 2 + 30));
  EXPECT_EQ(floatVector + v3, Vector<float>(3.5 + 2.0, 4.2 + 1.0));
  EXPECT_EQ(doubleVector + v1, Vector<double>(-5.1 - 2.5, 3.9 + 6.7));
  EXPECT_EQ(floatPointtoVector + v3, Vector<float>(4.3 + 2.0, 1.2 + 1.0));
}

TEST_F(VectorTest, TestOperatorSubtraction)
{
  // Creamos un objeto Vector para pasar como argumento
  Vector<double> v1(-2.5, 6.7);
  Vector<int> v2(50, 30);
  Vector<float> v3(1.5, 5.5);

  // Comprobamos que la resta entre los vectores es la esperada
  EXPECT_EQ((intVector - v2), Vector<int>(1 - 50, 2 - 30));
  EXPECT_EQ((floatVector - v3), Vector<float>(3.5 - 1.5, 4.2 - 5.5));
  EXPECT_EQ((doubleVector - v1), Vector<double>(-5.1 + 2.5, 3.9 - 6.7));
  EXPECT_EQ((floatPointtoVector - v3), Vector<float>(4.3 - 1.5, 1.2 - 5.5));

  // En este caso no es posible realizar la resta entre vectores de diferente tipo
}

TEST_F(VectorTest, TestOperatorAssign)
{
  // Creamos un objeto Vector para asignar
  Vector<int> v1(3, 4);
  Vector<double> v2(Point(86, 86));

  // Asignamos los nuevos valores a las variables intVector y doubleVector
  intVector = v1;
  doubleVector = v2;

  // Comprobamos que los valores de los vectores son los esperados
  EXPECT_EQ(intVector, v1);
  EXPECT_EQ(doubleVector, v2);
}

TEST_F(VectorTest, TestOperatorEqual)
{
  // Creamos un objeto Vector para asignar
  Vector<int> v1(1, 2);
  Vector<double> v2(Point(-5.1, 3.9));

  // Comprobamos que los valores de los vectores son los esperados
  EXPECT_TRUE(intVector == v1);
  EXPECT_TRUE(doubleVector == v2);
  EXPECT_FALSE(v1 == Vector<int>(86, 86));
  EXPECT_FALSE(v2 == Vector<double>(86, 86));
}

TEST_F(VectorTest, TestOperatorMult)
{
  // Creamos un objeto Vector para pasar como argumento
  Vector<double> v1(-2.5, 6.7);
  Vector<int> v2(50, 30);
  Vector<float> v3(1.5, 5.5);

  // Comprobamos que la multiplicación entre los vectores es la esperada
  // Se comprueba tambien la multiplicacion de escalar por vector
  EXPECT_EQ((intVector * 3), Vector<int>(1 * 3, 2 * 3));
  EXPECT_EQ((3 * intVector), Vector<int>(1 * 3, 2 * 3));
  EXPECT_EQ((floatVector * 4), Vector<float>(3.5 * 4, 4.2 * 4));
  EXPECT_EQ((4 * floatVector), Vector<float>(3.5 * 4, 4.2 * 4));
  EXPECT_EQ((doubleVector * 5), Vector<double>(-5.1 * 5, 3.9 * 5));
  EXPECT_EQ((5 * doubleVector), Vector<double>(-5.1 * 5, 3.9 * 5));
  EXPECT_EQ((floatPointtoVector * 2), Vector<float>(4.3 * 2, 1.2 * 2));
  EXPECT_EQ((2 * floatPointtoVector), Vector<float>(4.3 * 2, 1.2 * 2));
  // En este caso no es posible realizar la multiplicación entre vectores de diferente tipo
}

TEST_F(VectorTest, TestOperatorInsertion)
{
  // Creamos un stream de salida
  std::ostringstream os;

  // Insertamos el objeto Point en el stream
  os << intVector;

  // Comprobamos que el stream contiene el string esperado
  EXPECT_EQ(os.str(), "(1, 2)");
}
