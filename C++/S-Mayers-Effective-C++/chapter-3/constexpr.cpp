#include <iostream>


using namespace std;

class Point {
    public:
        constexpr Point (double xVal = 0, double yVal = 0) noexcept : x(xVal), y(yVal)
        {}

        constexpr double xValue () const noexcept { return x; }     // Result will be known when programm compiles
        constexpr double yValue () const noexcept { return y; }     //

        constexpr void setX (double newX) noexcept { x = newX; }
        constexpr void setY (double newY) noexcept { y = newY; }

    private:
        double x, y;
};

ostream& operator << (ostream& os, const Point &p1) {
    return os << p1.xValue() << " : " << p1.yValue();
}

constexpr
Point midpoint (const Point &p1, const Point &p2) noexcept {
    return { (p1.xValue() + p2.xValue()) / 2,
             (p1.yValue() + p2.yValue()) / 2};
}

constexpr
Point reflection (const Point& p) noexcept {
    Point result;
    result.setX(-p.xValue());
    result.setY(-p.yValue());
    return result;
}

int main () {

    // Compilation error:
    // We can't give value in programm runtime.

    // int sz;
    // constexpr auto sz_i = sz;
    int sz;
    const auto sz_i = sz;

    constexpr Point p1(9.4, 27.7);  // constant in Compile Time
    constexpr Point p2(28.8, 5.3);  // Means, that in run time can not change
    constexpr auto mid = midpoint(p1, p2);
    constexpr auto reflectionMid = reflection(mid);

    cout << p1.xValue() << " : " << p1.yValue() << endl;  // Done at compile time
    cout << mid << endl;
    cout << reflectionMid << endl;
    return 0;
}
