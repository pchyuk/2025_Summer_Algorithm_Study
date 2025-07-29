#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<bool> submitted(31, false);

    for(int i = 0; i < 28; i++)
    {
        int student_id;
        cin >> student_id;
        submitted[student_id] = true;
    }

    for(int i = 1; i <= 30; i++)
    {
        if(!submitted[i])
        {
            cout << i << "\n";
        }
    }

    return 0;
}