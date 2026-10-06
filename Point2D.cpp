#include <ostream>
#include <cmath>
#include "Point2D.h"
using namespace std;


double Point2D::distance(const Point2D &a, const Point2D &b) {
    // A definir
    double result = sqrt(pow((a.x-b.x),2)-pow((a.y-b.y),2));
    return result;
}

bool Point2D::operator==(const Point2D &other) {
    // A definir
    return (this->x==other.x) && (this->y==other.y);
}

bool Point2D::operator!=(const Point2D &other) {
    // A definir
    return (this->x != other.x) || (this->y != other.y);    
}

ostream& operator<<(std::ostream &out, const Point2D &p) {
    // A definir
    out << "(" <<  p.x << ", " << p.y << ")" << endl;
    return out;
}
