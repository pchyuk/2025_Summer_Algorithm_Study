#include <iostream>
#include <unordered_set> // 파이썬의 set과 유사한 자료형을 쓰기 위함
#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_set<int> remainders; // 중복되는 수를 자동 제거하는 자료형

    for(int i = 0; i < 10; i++)
    {
        int num;
        cin >> num;
        int remainder = num % 42;
        remainders.insert(remainder);
    }

    cout << remainders.size() << endl;

    return 0;
}