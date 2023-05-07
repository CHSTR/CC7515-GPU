#include <cmath>
// include point.hpp
#include "../Point/point.hpp"

using namespace std;

// Creamos una clase Point con un template para que pueda aceptar diferentes tipos de datos
template <typename T>

// Creamos nuestra clase Vector
class Vector{
    private:
        T x1, y1;
    public:

        // Constructor
        Vector(T x1, T y1){
            this->x1 = x1;
            this->y1 = y1;
        }
        
        // Destructor
        ~Vector(){
            cout << "Vector deleted" << endl;
        }

        // Constructor copia desde un objeto Point
        Vector(Point<T> p){
            this->x1 = p[0];
            this->y1 = p[1];
        }

        // Para la magnitud del vector se utilizará un tipo de dato primitivo double
        // porque en el caso de utilizar un tipo de dato T, donde T es int, la magnitud puede no ser representativa.
        double magnitude(){
            return sqrt(pow(x1, 2) + pow(y1, 2));
        }

        // Para el producto punto y el producto cruz se utilizará un tipo de dato primitivo T
        T dot_product(Vector<T> v){
            return (x1 * v.x1 + y1 * v.y1);
        }

        T cross_product(Vector<T> v){
            return (x1 * v.y1 - y1 * v.x1);
        }

        // Sobrecargamos el operador + para poder sumar dos vectores cuyo tipo de dato primitivo sea el mismo
        Vector<T> operator+ (const Vector<T>& v){
            Vector<T> new_vector(x1 + v.x1, y1 + v.y1);
            return new_vector;
        }

        // Sobrecargamos el operador - para poder restar dos vectores cuyo tipo de dato primitivo sea el mismo
        Vector<T> operator- (const Vector<T>& v){
            Vector<T> new_vector(x1 - v.x1, y1 - v.y1);
            return new_vector;
        }

        // Sobrecargamos el operador = para poder asignar un objeto Vector a otro objeto Vector
        Vector<T> operator= (const Vector<T>& v){           
            x1 = v.x1;
            y1 = v.y1;
            return *this;
        }

        // Sobrecargamos el operador == para poder comparar dos objetos Vector
        bool operator== (const Vector<T>& v){
            // return (coords.first == v.coords.first && coords.second == v.coords.second);
            return (x1 == v.x1 && y1 == v.y1);
        }

        // En este caso se sobrecarga el operador * para poder multiplicar un vector por un escalar
        // y tambien para poder multiplicar un escalar por un vector
        Vector<T> operator*(const T scalar) const {
        return Vector<T>(x1 * scalar, y1 * scalar);
        }

        // scalar * vector
        friend Vector<T> operator*(const T scalar, const Vector<T>& v) {
            return Vector<T>(v.x1 * scalar, v.y1 * scalar);
        }

        // Sobrecargamos el operador << para poder imprimir un objeto Vector
        friend ostream& operator<<(ostream& os, const Vector<T>& v) {
            // os << v.coords;
            os << "(" << v.x1 << ", " << v.y1 << ")";
            return os;
        }

        // Sobrecargamos el operador == para poder comparar dos objetos Vector
        bool operator==(const Vector<T>& v) const {
            const double eps = 1e-6; // tolerancia de comparación
            return (std::abs(x1 - v.x1) < eps) && (std::abs(y1 - v.y1) < eps);
        }
};