#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#define endl "\n"

using namespace std;

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> min_heap;

    for(int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        if(x == 0)
        {
            if(min_heap.empty())
            {
                cout << 0 << endl;
            }
            else
            {
                cout << min_heap.top() << endl;
                min_heap.pop();
            }
        }
        else
        {
            min_heap.push(x);
        }
    }
    
    return 0;
}