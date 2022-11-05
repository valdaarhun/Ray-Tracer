#include <iostream>

#include "vectors.hpp"

using namespace std;
using namespace Vector;

int main(){
    int nx = 2000, ny = 1000;
    cout << "P3\n" << nx << ' ' << ny << "\n255\n";
    for(int j = ny - 1 ; j >= 0 ; j--){
        for(int i = 0 ; i < nx ; i++){
            Vec3 color((double)i / nx, (double)j / ny, 0.2);
            int r = color[0] * 255.99;
            int g = color[1] * 255.99;
            int b = color[2] * 255.99;
            cout << r << ' ' << g << ' ' << b << '\n';
        }
    }
}