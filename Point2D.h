#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>
using namespace std;

class Point2D{
    // ... definición de la clase Point2D.h ...  
	public:
		double x;
		double y;
		Point2D(double x=0.0, double y=0.0);
		static double distance(const Point2D &a, const Point2D &b);
		bool operator==(const Point2D &other);
		bool operator!=(const Point2D &other);
		friend ostream& operator<<(ostream &out,const Point2D &p);




};

#endif
