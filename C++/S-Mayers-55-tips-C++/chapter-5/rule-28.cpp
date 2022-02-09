// Rule #28
// Avoid returning internal data descriptors

#include "tools.h"

class Point
{
    public:
        Point(int x_, int y_) : x(x_), y(y_) {}

        void setX(int newVal)
        {
            x = newVal;
        }

        void setY(int newVal)
        {
            y = newVal;
        }
    private:
        int x, y;
};

struct RectData
{
    Point ulhc;
    Point lrhc;
};

class Rectangle
{
    public:
        const Point& upperLeft() const { return pData -> ulhc; }
        const Point& lowerRight() const { return pData -> lrhc; }
    private:
        std::shared_ptr<RectData> pData;
};

int main()
{

}
