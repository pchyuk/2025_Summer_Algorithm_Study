#include <iostream>

using namespace std;

int main()
{
    int H, M;
    cin >> H >> M;
    int total_minutes = H * 60 + M;
    
    total_minutes -= 45;
    if(total_minutes < 0)
    {
        total_minutes += (24 * 60);
    }

    int new_H = total_minutes / 60;
    int new_M = total_minutes % 60;

    cout << new_H << " " << new_M << "\n";

    return 0;
}