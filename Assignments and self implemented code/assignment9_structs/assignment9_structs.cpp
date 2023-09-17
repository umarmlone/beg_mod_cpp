#include <iostream>
#include <math.h>

struct Point
{
    int x;
    int y;
};

void find_distance(int x1, int y1, int x2, int y2)
{
    int distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

    std::cout << "the distance is : " << distance << std::endl;
}

void find_distance(Point first, Point second)
{
    int distance = sqrt(pow((second.x - first.x), 2) + pow((second.y - first.y), 2));

    std::cout << "the distance is : " << distance << std::endl;
}

int main()
{
    Point firstpoint;
    firstpoint.x = 4;
    firstpoint.y = 15;

    Point secondpoint = { 20,15 };

    find_distance(firstpoint, secondpoint);
    return 0;
}