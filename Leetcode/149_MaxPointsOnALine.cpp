#include <iostream>
#include <vector>
#include <map>
using namespace std;

//Definition for a point.
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
struct Comp
{ // comparator for key (slope) in map
    bool operator()(const Point &a, const Point &b)
    {
        int64_t diff = (int64_t)a.x * b.y - (int64_t)a.y * b.x; // convert to 64bit int for int overflow
        return (int64_t)a.y * b.y > 0 ? diff > 0 : diff < 0;
    }
};
int maxPoints(vector<Point> &pts)
{
    int maxPts = 0;
    for (auto &i : pts)
    {
        map<Point, int, Comp> count;
        int dup = 0;
        for (auto &j : pts)
        {
            int curMax = (i.x == j.x && i.y == j.y) ? ++dup : ++count[Point(i.x - j.x, i.y - j.y)] + dup;
            maxPts = max(maxPts, curMax);
        }
    }
    return maxPts;
}


int main()
{
    Point pt1(1,4);
    Point pt2(2,3);
    Point pt3(3,2);
    Point pt4(4,1);
    Point pt5(1,1);
    Point pt6(5,3);
    vector<Point> points;
    points.push_back(pt1);
    points.push_back(pt2);
    points.push_back(pt3);
    points.push_back(pt4);
    points.push_back(pt5);
    points.push_back(pt6);
    cout << maxPoints(points) << endl;

    return 0;
}