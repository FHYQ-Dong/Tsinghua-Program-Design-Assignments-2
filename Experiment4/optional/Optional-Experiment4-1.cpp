#include <iostream>
#include <cmath>

template <typename T>
class vector3 {
    private:
        T x, y, z;

    template <typename U>
    friend vector3<U> operator*(const vector3<U>& v1, const vector3<U>& v2);

    public:
        vector3(T x=(T)(0), T y=(T)(0), T z=(T)(0)) : x(x), y(y), z(z) {}
        vector3(const vector3<T>& v) : x(v.x), y(v.y), z(v.z) {}
        ~vector3() {}
        void print() const {
            std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
        }
        vector3<T> operator+(const vector3<T>& v) const {
            return vector3<T>(x+v.x, y+v.y, z+v.z);
        }
        vector3<T> operator-(const vector3<T>& v) const {
            return vector3<T>(x-v.x, y-v.y, z-v.z);
        }
        vector3<T> operator*(const T& s) const {
            return vector3<T>(x*s, y*s, z*s);
        }
        vector3<T> operator/(const T& s) const {
            return vector3<T>(x/s, y/s, z/s);
        }
        T dot(const vector3<T>& v) const {
            return x*v.x + y*v.y + z*v.z;
        }
        vector3<T> cross(const vector3<T>& v) const {
            return vector3<T>(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
        }
        T length() {
            return sqrt(x*x + y*y + z*z);
        }
        vector3<T> normalize() const {
            T l = length();
            return vector3<T>(x/l, y/l, z/l);
        }
};

template <typename U>
vector3<U> operator*(const vector3<U>& v1, const vector3<U>& v2) {
    return vector3<U>(v1.y*v2.z - v1.z*v2.y, v1.z*v2.x - v1.x*v2.z, v1.x*v2.y - v1.y*v2.x);
}

inline void test() {
    vector3<int> v1(1, 2, 3);
    vector3<int> v2(4, 5, 6);
    vector3<int> v3 = v1 * v2;
    v3.print();
}

int main() {
    test();
    return 0;
}