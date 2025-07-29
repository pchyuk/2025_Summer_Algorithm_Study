#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    queue<int> q;
    
    for(int i = 0; i < N; i++)
    {
        string command;
        cin >> command;

        if(command == "push")
        {
            int X;
            cin >> X;
            q.push(X);
        }
        else if(command == "pop")
        {
            if(q.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if(command == "size")
        {
            cout << q.size() << "\n";
        }
        else if(command == "empty")
        {
            if(q.empty())
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else if(command == "front")
        {
            if(q.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << q.front() << "\n";
            }
        }
        else if(command == "back")
        {
            if(q.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << q.back() << "\n";
            }
        }
    }
    
    return 0;
}