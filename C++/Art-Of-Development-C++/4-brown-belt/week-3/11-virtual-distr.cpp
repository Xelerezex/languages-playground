#include <memory>
#include <vector>


struct Point
{
    int x, y;
};

class Shape
{
    public:
        virtual double Area() const = 0;

        virtual ~Shape() = default;  // Виртуальный деструктор
};

class Polygon : public Shape
{
    public:
        double Area() const override;

    private:
        std::vector<Point> vertices_;
};


int main()
{
    Shape* shape = new Polygon;
    delete shape;
}
