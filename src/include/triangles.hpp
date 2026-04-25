#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "point2d.hpp"
#include <string>

namespace Geometry {
    class Triangle {
    private:
        Point2D p1, p2, p3;
    public:
        Triangle(Point2D a, Point2D b, Point2D c);
        std::string getTriangleType() const;
        float calculateDistance(Point2D a, Point2D b) const;
    };
}

#endif