#include "include/triangles.hpp"
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream> // Untuk debugging jika diperlukan

namespace Geometry {
    Triangle::Triangle(Point2D a, Point2D b, Point2D c) : p1(a), p2(b), p3(c) {}

    float Triangle::calculateDistance(Point2D a, Point2D b) const {
        // Rumus Euclidean 3D: sqrt((x2-x1)^2 + (y2-y1)^2 + (z2-z1)^2)
        float dx = a.GetX() - b.GetX();
        float dy = a.GetY() - b.GetY();
        float dz = a.GetZ() - b.GetZ();
        return std::sqrt(dx*dx + dy*dy + dz*dz);
    }

    std::string Triangle::getTriangleType() const {
        // 1. Hitung panjang ketiga sisi
        float s1 = calculateDistance(p1, p2);
        float s2 = calculateDistance(p2, p3);
        float s3 = calculateDistance(p3, p1);

        // 2. Gunakan nilai toleransi (epsilon) untuk perbandingan float
        float eps = 1e-4;

        // Cek Sama Sisi (Equilateral)
        bool eq12 = std::abs(s1 - s2) < eps;
        bool eq23 = std::abs(s2 - s3) < eps;
        bool eq31 = std::abs(s3 - s1) < eps;

        if (eq12 && eq23) return "sama sisi";

        // Cek Siku-siku (Right-angled) menggunakan Pythagoras: a^2 + b^2 = c^2
        // Kita urutkan kuadrat sisinya dari terkecil ke terbesar
        std::vector<float> sqSides = {s1*s1, s2*s2, s3*s3};
        std::sort(sqSides.begin(), sqSides.end());
        
        // Cek apakah a^2 + b^2 mendekati c^2
        bool isRight = std::abs((sqSides[0] + sqSides[1]) - sqSides[2]) < 1e-2;
        if (isRight) return "siku-siku";

        // Cek Sama Kaki (Isosceles)
        if (eq12 || eq23 || eq31) return "sama kaki";

        // Jika tidak ada yang memenuhi
        return "sembarang";
    }
}