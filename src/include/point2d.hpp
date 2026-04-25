#ifndef POINT2D_HPP
#define POINT2D_HPP

namespace Geometry {
    class Point2D {
    private:
        float _x, _y, _z;
    public:
        Point2D();
        Point2D(float x, float y, float z = 0);
        
        // Getter
        float GetX() const { return _x; }
        float GetY() const { return _y; }
        float GetZ() const { return _z; }

        // Setter
        void SetX(float x) { _x = x; }
        void SetY(float y) { _y = y; }
        void SetZ(float z) { _z = z; }

        // Operator Overloading (sesuai point2d.cpp kamu)
        Point2D operator+(const Point2D& inp);
        Point2D operator-(const Point2D& inp);
        Point2D operator*(const Point2D& inp);
    };
}

#endif