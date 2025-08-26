#include <iostream>
#include <vector>
#include <stack>
#include <string>
#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    stack<int> s;
    int num = 1;
    bool result = true;
    string answer = "";

    for(size_t i = 0; i < A.size(); i++)
    {
        int number = A[i];

        if(number >= num)
        {
            while(number >= num)
            {
                s.push(num);
                num++;
                answer += "+\n";
            }
            s.pop();
            answer += "-\n";
        }
        else
        {
            if(s.empty())
            {
                result = false;
                break;
            }
            int n = s.top();
            s.pop();
            if(n > number)
            {
                cout << "NO" << endl;
                result = false;
                break;
            }
            else
            {
                answer += "-\n";
            }
        }
    }
    if(result)
    {
        cout << answer;
    }
    
    return 0;
}