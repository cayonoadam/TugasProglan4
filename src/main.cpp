#include <iostream>
#include <vector>
#include <string>
#include "include/point2d.hpp"
#include "include/triangles.hpp"

using namespace std;

using namespace Geometry; 

int main() {
    int N;
    cout << "Masukkan jumlah segitiga: ";
    
    // Validasi jika input bukan angka
    if (!(cin >> N)) {
        return 0;
    }

    vector<Triangle> triangles;

    for (int i = 0; i < N; i++) {
        vector<Point2D> temp_points;
        
        // Loop untuk mengambil 3 titik per segitiga
        for (int j = 0; j < 3; j++) {
            float x, y, z; 
            // Sekarang x, y, z sudah terdefinisi (tidak undefined lagi)
            if (cin >> x >> y >> z) {
                temp_points.push_back(Point2D(x, y, z));
            }
        }
        
        // Masukkan ke vector triangles jika titiknya lengkap (3 buah)
        if (temp_points.size() == 3) {
            triangles.push_back(Triangle(temp_points[0], temp_points[1], temp_points[2]));
        }
    }

    // Tampilkan hasil pengecekan tipe segitiga
    for (size_t i = 0; i < triangles.size(); i++) {
        cout << triangles[i].getTriangleType() << endl;
    }

    return 0;
}