#ifndef POINT_H
#define POINT_H

#include <cmath>
#include <iostream>

// Creamos una clase Point con un template para que pueda aceptar diferentes tipos de datos
template <class T>

// Por comodidad se declarará la clase y los métodos en inglés
class Point{
private:
    std::pair<T,T> coords;
public:

    // Constructor
    Point(T x, T y){
        coords.first = x;
        coords.second = y;
    }

    // Declaramos como friend la clase Point para que pueda acceder a los atributos privados de Point
    // cuando se crea un objeto Point a partir de otro objeto Point
    template<typename U>
    friend class Point;

    // Se crea el constructor cuando se crea un objeto Point a partir de otro objeto Point
    template<typename U>
    Point(const Point<U>& p) : coords{static_cast<T>(p.coords.first), static_cast<T>(p.coords.second)} {}

    // Destructor
    ~Point(){
        //std::cout << "Point deleted" << std::endl;
    }

    // Método para obtener la distancia entre dos puntos
    double distance(Point<T> p){
        return sqrt(pow(p.coords.first - coords.first, 2) + pow(p.coords.second - coords.second, 2));
    }
    
    // Método para obtener la distancia entre dos puntos
    T operator[] (int i){
        if (i == 0){
            return coords.first;
        }
        else if (i == 1){
            return coords.second;
        }
        else{
            std::cout << "Error: index out of range" << std::endl;
            return 0;
        }
    }
    
    // Sobrecargamos el operador = para que pueda asignar un objeto Point a otro objeto Point
    Point<T>& operator= (const Point<T>& p){
        coords.first = p.coords.first;
        coords.second = p.coords.second;
        return *this;
    }
    
    // Sobrecargamos el operador == para que pueda comparar dos objetos Point
    bool operator== (const Point<T>& p){
        return (coords.first == p.coords.first && coords.second == p.coords.second);
    }

    // Sobrecargamos el operador << para que pueda imprimir un objeto Point
    friend std::ostream& operator<<(std::ostream& os, const Point<T>& p) {
        os << "(" << p.coords.first << ", " << p.coords.second << ")";
        return os;
    }
};

#endif // POINT_H