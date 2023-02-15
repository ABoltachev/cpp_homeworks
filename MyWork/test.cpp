#include <iostream>

template <typename T, size_t tx, size_t ty>
class Point {

private:
    size_t x = tx;
    size_t y = ty;
    T value;
public:
    Point() = default;
    void show_point() {
        std::cout << x << " " << y << std::endl;
    }
};


int main() {
    Point<int, 2, 3> p;
    size_t s = 2;
    p.show_point();

    return 0;
}