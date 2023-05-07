#include <cmath>
#include "../Point/point.hpp"
#include <vector>

using namespace std;

template <typename T>
class Polygon{
    private:
        std::vector<Point<T>> points;
        int n_points;
    public:
        Polygon(std::vector<Point<T>> points){
            this->points = points;
            this->n_points = points.size();
        }

        ~Polygon(){
            // cout << "Polygon deleted" << endl;
        }

        // Se crea el método get_points para obtener la cantidad de puntos del polígono
        int get_points(){
            return n_points;
        }

        // Se crea el método add_point para agregar un punto al final del polígono
        void add_point(Point<T> p){
            points.push_back(p);
            n_points++;
        }

        // Se crea el método is_counter_clockwise para determinar la dirección
        bool is_counter_clockwise(){
            int sum = 0;
            for (int i = 0; i < n_points; i++){
                if (i == n_points - 1){
                    sum += (points[i][0] - points[0][0]) * (points[i][1] + points[0][1]);
                }else{
                    sum += (points[i][0] - points[i+1][0]) * (points[i][1] + points[i+1][1]);
                }
            }
            return sum > 0;
        }

        // Se sobrecarga el operador [] para poder acceder a los puntos del polígono
        Point<T>& operator[](int i){
            return points[i];
        }

        //Salida de datos en el formato [(x1,y1),(x2,y2),...,(xn,yn)]
        friend ostream& operator<<(ostream& os, const Polygon<T>& p){
            os << "[";
            for (int i = 0; i < p.n_points; i++)
            {
                os << p.points[i];
            }
            os << "]";
            return os;
        }

};