#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
    int x;
    int y;
};

bool comparePoints(const Point& p1, Point& p2)
{
    if(p1.x != p2.x)
    {
        return p1.x < p2.x;
    }
    else
    {
        return p1.y < p2.y;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<Point> points(N);
    for(int i = 0; i < N; i++)
    {
        cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end(), comparePoints);
    for(int i = 0; i < N; i++)
    {
        cout << points[i].x << " " << points[i].y << "\n";
    }

    return 0;
}