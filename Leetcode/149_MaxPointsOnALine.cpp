#include <iostream>
#include <vector>
using namespace std;
struct Point{
    int x;
    int y;
    Point() : x(0), y(0){} 
    Point(int a, int b) : x(a), y(b) {}
};
void compute(const vector<Point> &ptr, double &k, double &b)
{
    double SumXi = 0.0;
    double SumYi = 0.0;
    double SumXi_2 = 0.0;
    double SumXiYi = 0.0;
    int number = int(ptr.size()); 
    for (int i = 0; i < number; i++)
    {
        SumXi += ptr[i].x;
        SumYi += ptr[i].y;
        SumXi_2 += ptr[i].x * ptr[i].x;
        SumXiYi += ptr[i].x * ptr[i].y;
    }
    double temp = (number * SumXi_2 - SumXi * SumXi); 
    k = (number * SumXiYi - SumXi * SumYi) / temp;
    b = (SumXi_2 * SumYi - SumXi * SumXiYi) / temp;
}

int maxPoints(vector<Point> &points)
{
    double k = 0, b = 0;
    compute(points, k, b);
    cout << "y = " << k << " x + " << b << endl;
    return -1;
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