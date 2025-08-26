#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L;
    cin >> N >> L;
    deque<pair<int, int>> mydeque;
    vector<int> now(N);

    for(int i = 0; i < N; i++)
    {
        cin >> now[i];
        while(!mydeque.empty() && mydeque.back().first > now[i])
        {
            mydeque.pop_back();
        }
        mydeque.push_back({now[i], i});
        if(mydeque.front().second <= i - L)
        {
            mydeque.pop_front();
        }
        cout << mydeque.front().first << " ";
    }
    cout << endl;

    return 0;
}