#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int Result = 0;
    vector<int> A(N);
    for(int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    for(int k = 0; k < N; k++)
    {
        int find = A[k];
        int i = 0; 
        int j = N - 1;

        while(i < j)
        {
            if(A[i] + A[j] == find)
            {
                if(i != k && j != k)
                {
                    Result++;
                    break;
                }
                else if (i == k)
                {
                    i++;
                }
                else
                {
                    j--;
                }
            }
            else if(A[i] + A[j] < find)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
    }
    cout << Result << endl;
    return 0;
}